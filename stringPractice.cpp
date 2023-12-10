#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str1[6] = "Hello";
    char str2[8] = "Goodbye";
    strncpy(str1, str2, 2);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << strlen(str1) << endl;
    cout << strncmp(str1, str2, 2) << endl;
}
