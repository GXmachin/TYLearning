#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST
{
    private:
        struct BinaryNode
        {
            int value;
            BinaryNode* left;
            BinaryNode* right;
            BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}

            static BinaryNode* insert(int v, BinaryNode* t)
            {
              if(t == NULL)
              {
                t = new BinaryNode(v);
              }
              else if (v < t->value)
                t->left = insert(v, t->left);
              else if (v > t->value)
                t->right = insert(v, t->right);
              else
                t->value = v;
              return t;
            }

            static BinaryNode* remove(int v, BinaryNode* t)
            {
                if(t)
                {
                    if(v < t->value)
                        t->left = remove(v, t->left);
                    else if(t->value < v)
                        t->right = remove(v, t->right);
                    else if(t->left != NULL && t->right != NULL)
                    {
                      t->value = find_min(t->right)->value;
                      t->right = remove(t->value, t->right);
                    }
                    else
                    {
                      BinaryNode* oldNode = t;
                      t = (t->left != NULL) ? t->left: t->right;
                      delete oldNode;
                    }
              }
              return t;
            }

            static BinaryNode* find_min(BinaryNode* t)
            {
                if(t == NULL)
                    return NULL;
                if(t->left == NULL)
                    return t;
                return find_min(t->left);
            }

            static int get_height(BinaryNode* node)
            {
                if(!node){return -1;}
                int left_h = get_height(node->left);
                int right_h = get_height(node->right);
                return 1 + max(left_h, right_h);
            }

            static void height(BinaryNode* node, string& nodes, string& edges, char& c_node, char& c_node2)
            {
                if(!node){return;}
                queue<BinaryNode*>keys;
                keys.push(node);

                while(!keys.empty())
                {
                    BinaryNode* key = keys.front();
                    keys.pop();
                    int height_ = get_height(key);
                    int value = key->value;
                    if(key->left)
                    {
                        keys.push(key->left);
                        c_node2++;
                        edges +=  " ";
                        edges +=  c_node;
                        edges += " -> ";
                        edges += c_node2;
                        edges += ";\n";
                    }
                    if(key->right)
                    {
                        keys.push(key->right);
                        c_node2++;
                        edges +=  " ";
                        edges +=  c_node;
                        edges += " -> ";
                        edges += c_node2;
                        edges += ";\n";
                    }
                    nodes += " ";
                    nodes += c_node;
                    nodes += " [color = lightblue, style = filled, label=\"key=";
                    nodes += to_string(value);
                    nodes += ", h=";
                    nodes += to_string(height_);
                    nodes += "\"];\n";
                    c_node++;
                }
            }

            static void destruct(BinaryNode* node)
            {
                if(node)
                {
                    destruct(node->left);
                    destruct(node->right);
                    delete node;
                }
            }
        };

    public:
        BST(): root(NULL), order(0) {}
        ~BST()
        {
            BinaryNode::destruct(root);
        }
        void insert(int v) { root = BinaryNode::insert(v, root); }
        void remove(int v) { root = BinaryNode::remove(v, root); }
        void height(ofstream& ofs)
        {
            string nodes = "";
            string edges = "";
            char c_node = 'a';
            char c_node2 = c_node;
            BinaryNode::height(root, nodes, edges, c_node, c_node2);
            ofs << "digraph G {\n\n  // nodes\n";
            ofs << nodes;
            ofs << "  // edges\n\n";
            ofs << edges;
            ofs << "}\n";
        }
        void display() { display(root); }
        void display( BinaryNode* t )
        {
        // in-order traversal with indented display.
            static int depth = 0;
            ++ depth;
            if ( t == NULL ) return;
            if ( t->right != NULL ) display(t->right);
            for( int i = 0; i != depth; ++i )
              cout << "\t";
            cout << t->value << " " << endl;
            if ( t->left != NULL )
              display(t->left);
            --depth;
        }

        /** this is lab4-5 implementations
            pre, post ,in and height**/


        void preorder(ofstream& ofs)
        {
            string str = "";
            string edges = "";
            preorder(root, str, edges);
            ofs << "digraph G {\n\n  // nodes\n";
            ofs << str;
            ofs << "  // edges\n\n";
            ofs << edges;
            ofs << "}\n";


        }
        void preorder(BinaryNode* node, string& str, string& edges)
        {
            if(!node){return;}
            order++;
            str += " ";
            str += "k";
            str += to_string(node->value);
            str += " [color = lightblue, style = filled, label=\"key=";
            str += to_string(node->value);
            str += ", pre=";
            str += to_string(order);
            str += "\"];\n";
            if(node->left)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->left->value));
                edges += ";\n";
            }
            if(node->right)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->right->value));
                edges += ";\n";
            }
            preorder(node->left, str, edges);
            preorder(node->right, str, edges);

        }
        void inorder(ofstream& ofs)
        {
            string str = "";
            string edges = "";
            inorder(root, str, edges);
            ofs << "digraph G {\n\n  // nodes\n";
            ofs << str;
            ofs << "  // edges\n\n";
            ofs << edges;
            ofs << "}\n";
        }
        void inorder(BinaryNode* node, string& str, string& edges)
        {
            if(!node){return;}
            inorder(node->left, str, edges);
            order++;
            str += " ";
            str += "k";
            str += to_string(node->value);
            str += " [color = lightblue, style = filled, label=\"key=";
            str += to_string(node->value);
            str += ", in=";
            str += to_string(order);
            str += "\"];\n";
            if(node->left)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->left->value));
                edges += ";\n";
            }
            if(node->right)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->right->value));
                edges += ";\n";
            }
            inorder(node->right, str, edges);
        }
        void postorder(ofstream& ofs)
        {
            string str = "";
            string edges = "";
            postorder(root, str, edges);
            ofs << "digraph G {\n\n  // nodes\n";
            ofs << str;
            ofs << "  // edges\n\n";
            ofs << edges;
            ofs << "}\n";
        }
        void postorder(BinaryNode* node, string& str, string& edges)
        {
            if(!node){return;}
            postorder(node->left, str, edges);
            postorder(node->right, str, edges);
            order++;
            str += " ";
            str += "k";
            str += to_string(node->value);
            str += " [color = lightblue, style = filled, label=\"key=";
            str += to_string(node->value);
            str += ", post=";
            str += to_string(order);
            str += "\"];\n";
            if(node->left)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->left->value));
                edges += ";\n";
            }
            if(node->right)
            {
                edges +=  " ";
                edges +=  ("k" + to_string(node->value));
                edges += " -> ";
                edges += ("k" + to_string(node->right->value));
                edges += ";\n";
            }
        }

    private:
        BinaryNode* root;
        int order;
};


#endif // BST_H_INCLUDED
