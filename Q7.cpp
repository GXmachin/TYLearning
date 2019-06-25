#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//defined a getValue function that extracts integers from command line and uses value to modify existing array
void getValue(int arr[], int size)
{
    cout << "Enter 10 different values:" << endl;
    for (int current = 0; current < 10; current++)
        cin >> arr[current];
}

//overloaded for string array
int * getValue(string arr[], int size)
{
    cout << "Enter 10 different values:" << endl;
    //i have read conversion types, still need to figure out another way
    static int array1[10];
    for (int current = 0; current < size; current++)
     {
            cin >> arr[current];
            array1[current] = stoi(arr[current]);
     }
    return array1;
}

// mean function
float meanf(int * arr, int len)
{
    float sum = 0;
    // iterator is used to iterate all 10 integers
    int iter = 0;
    while (iter < len)
    {
        // dereferencing is used, since arrays are just pointers to the first element
        sum += *arr;
        //array is traversed to do computation
        arr++;
        iter++;
    }
    return sum/len;
}

//defined standard deviation function here, similar pointer arithmetic are also used here
float stdvf(float avg, int * arr, int len){
    int iter = 0;
    float stdv_sum = 0;
    while (iter < len)
    {
	stdv_sum += pow((*arr - avg),2);
        arr++;
        iter++;
    }
    float stdv_avg = stdv_sum / len;
    return sqrtf(stdv_avg);
}

// defined variance function, the square of the stdvf, I brought in the cmath library
float variancef(float stdev){
    return pow(stdev, 2);
}

int main()
{
    int int_arr[10];
    getValue(int_arr,10);

    //using overloaded int
    float mean = meanf(int_arr, 10);
    float stdev = stdvf(mean, int_arr, 10);
    float variance = variancef(stdev);
    cout << "Your mean is: " << mean << endl;
    cout << "Your standard deviation is: " << stdev << endl;
    cout <<  "Your variance is: " << variance << endl;


    //overloaded with string
    string str_arr[10];
    int * int_arr1 = getValue(str_arr, 10);
    float mean_s = meanf(int_arr1, 10);
    float stdev_s = stdvf(mean, int_arr1, 10);
    float variance_s = variancef(stdev);
    cout << "Your mean is: " << mean_s << endl;
    cout << "Your standard deviation is: " << stdev_s << endl;
    cout <<  "Your variance is: " << variance_s << endl;
}
