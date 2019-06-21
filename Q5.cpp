//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//// template
//template <class d, class i>
//void multiple(d number, i power){
//    double new_number = number;
//    int new_power = power;
//    // for look from Q4
//    for (int current_iter=1; current_iter<=new_power; current_iter++)
//        cout <<  "Multiple " << current_iter << " for " << new_power  << " is "<< new_number * current_iter << endl;
//}
//
//// template specialization
//template <>
//void multiple(string number, string power){
//    double new_number;
//    int new_power;
//
//    stringstream(number) >> new_number;
//    stringstream(power) >> new_power;
//    for (int current_iter=1; current_iter<=new_power; current_iter++)
//        cout <<  "Multiple " << current_iter << " for " << new_power  << " is "<< new_number * current_iter << endl;
//}
//// template specialization
//template <>
//void multiple(string number, int power){
//    double new_number;
//    stringstream(number) >> new_number;
//    for (int current_iter=1; current_iter<=power; current_iter++)
//        cout <<  "Multiple " << current_iter << " for " << power  << " is "<< new_number * current_iter << endl;
//}
////template specialization
//template <>
//void multiple(double number, string power){
//    int new_power;
//    stringstream(power) >> new_power;
//    for (int current_iter=1; current_iter<=new_power; current_iter++)
//        cout <<  "Multiple " << current_iter << " for " << new_power  << " is "<< number * current_iter << endl;
//}
//
//int main(){
//
//    //variable declaration
//    string D;
//    string I;
//
//    //a bunch of i/o statements
//    cout << "Enter string D: " << endl;
//    cin >> D;
//    cout << "Enter string I: " << endl;
//    cin >> I;
//    multiple<string, string>(D, I);
//
//    // another variable declaration to test template
//    int In;
//    cout << "Enter string D: " << endl;
//    cin >> D;
//    cout << "Enter integer In: " << endl;
//    cin >> In;
//
//    //function call
//    multiple<string, int>(D, In);
//
//
//}
