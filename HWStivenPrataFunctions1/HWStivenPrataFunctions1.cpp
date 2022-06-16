#include <iostream>

using namespace std;
struct applicant {
    char name[30];
    int credit_ratings[3];
};

template <typename T1, typename T2>
auto summ(T1 a, T2 b) -> decltype(a+b)
{
    decltype(a+b) res = a + b;
    return res;
}

void change_arr(int* arr, int* end, int target);
void show_array(const int* arr, int size);
double find_max(const double* arr, int size);
int replacer(char* str, char a, char b);
int judge(int (*pf)(const char a));
void show_applicant(applicant &a);

string string_converter(const string& str1, const string& adder);

int main()
{
    string str1 = "Hello, world!";
    string str2 = "@@@";
    string str3 = string_converter(str1, "@@@");
    int my_array[10]{ 1,2,3,4,5,6,7,8,9,10 };
    double double_array[10]{ 1.2,2.1,3.6,41.3,5.34,6.98,7.16,8.90,9,10 };
    int* start = &my_array[0];
    int* end = &my_array[0] + 10;
    show_array(my_array, 10);
    change_arr(start, end, 5);
    show_array(my_array, 10);
    double max = find_max(double_array, 10);
    cout << max << endl;

    char mystr[] = "Hello my name is artem";
    cout << mystr << endl;
    replacer(mystr, 'a', 'j');
    replacer(mystr, 'e', 'E');
    cout << mystr << endl;

    cout << "taco"[2] << endl << *"pizza" << endl;

    applicant john{ "John", {1,3,10} };
    show_applicant(john);
    double a = 0.3, b = 0.5, c;
    c = summ(a, b);
    cout << c << endl;
    cout << str3 << endl;
}

void change_arr(int* start, int* end, int target)
{
    while (start < end) {
        *start = target;
        start++;
    }
}

void show_array(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double find_max(const double* arr, int size)
{
    double max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int replacer(char* str, char a, char b) {
    int counter = 0;
    while (*str != '\0')
    {
        
        if (*str == a) {
            *str = b;
            counter++;
        }
        str++;
    }
    return counter;
}

void show_applicant(applicant &a)
{
    cout << "Name of applicant " << a.name << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Credit rating " << i + 1 << ": " << a.credit_ratings[i] << endl;
    }
}

string string_converter(const string& str1, const string& adder)
{
    string final_str = adder + " " + str1 + " " + adder;
    return final_str;
}
