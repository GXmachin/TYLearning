#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct student
{
    string name;
    int age;
};

void stdtData(student* aStudent, int number)
{
    cout << "Enter student name:" << endl;
    for (int i=0; i < number; i++)
    {
        cin >> aStudent[i].name;
    }

    cout << "Enter student age:" << endl;
    for (int i=0; i < number; i++)
    {
        cin >> aStudent[i].age;
    }
}

// mean function from last code
float meanf(student * arr, int len)
{
    float sum = 0;
    // iterator is used to iterate all 10 integers
    int iter = 0;
    while (iter < len){
        // dereferencing is used, since arrays are just pointers to the first element
        sum += arr->age;
        //array is traversed to do computation
        arr++;
        iter++;
    }
    return sum/len;
}


// simply used my last function with a little to tweak to dereference student's member
float stdvf(float avg, student * arr, int len)
{
    int iter = 0;
    float stdv_sum = 0;
    while (iter < len){
        stdv_sum += pow((arr->age - avg),2);
        arr++;
        iter++;
    }
    float stdv_avg = stdv_sum / len;
    return sqrtf(stdv_avg);
}

// I used while to extract index of oldest student, this index is returned and used to get student's info
// idx is index
int maxAgeInfo(student * arr, int len)
{
    int idx_max = 0;
    int iter = 0;
    float maxAge = arr->age; // assume first element is highest age
    while (iter < len)
    {
        idx_max = maxAge < arr->age ? iter: idx_max;
        arr++;
        iter++;
    }
    return idx_max;
}

int main()
{
    int number;
    cout << "Enter number of student: " << endl;
    cin >> number;
    student * myStudent;
    myStudent = new student[number];
    stdtData(myStudent, number);
    int seniorStdtIdx = maxAgeInfo(myStudent, number);
    cout << "The oldest student is " << myStudent[seniorStdtIdx].name << " and he is "
            << myStudent[seniorStdtIdx].age << " years" << endl;
    float meanAge = meanf(myStudent, number);
    cout << "The average age is " << meanAge << " years" << endl;
    float stdevAge = stdvf(meanAge, myStudent, number);
    cout << "The standard deviation of students ages is: " << stdevAge << endl;
}
