//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
////defined a getValue function that extracts integers from command line
//int* getValue(){
//    // i dont like this static stuff i did here, but it seemed like a quick fix...i can't use a variable length array
//    // i can implement this another way, will give it a go and send another version
//    static int values[10];
//    cout << "Enter 10 different values:" << endl;
//    for (int current = 0; current < 10; current++)
//        cin >> values[current];
//    return values;
//}
//
//// mean function
//float meanf(int * arr, int len){
//    float sum = 0;
//    // iterator is used to iterate all 10 integers
//    int iter = 0;
//    while (iter < len){
//        // deferencing is used, since arrays are just pointers to the first element
//        sum += *arr;
//        //array is traversed to do computation
//        arr++;
//        iter++;
//    }
//    return sum/len;
//}
//
////defined standard deviation function here, similar pointer arithmetics are also used here
//float stdvf(float avg, int * arr, int len){
//    int iter = 0;
//    float stdv_sum = 0;
//    while (iter < len){
//        stdv_sum += pow((*arr - avg),2);
//        arr++;
//        iter++;
//    }
//    float stdv_avg = stdv_sum / len;
//    return sqrtf(stdv_avg);
//}
//
//// defined variance function, the square of the stdvf, I brought in the cmath library
//float variancef(float stdev){
//    return pow(stdev, 2);
//}
//
//int main(){
//    int * data = getValue();
//    float mean = meanf(data, 10);
//    float stdev = stdvf(mean, data, 10);
//    float variance = variancef(stdev);
//    cout << "Your mean is: " << mean << endl;
//    cout << "Your standard deviation is: " << stdev << endl;
//    cout <<  "Your variance is: " << variance;
//
//}
