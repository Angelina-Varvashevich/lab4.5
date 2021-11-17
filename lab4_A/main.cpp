
#include <iostream>// variant 5
#include <cmath>

using namespace std;

void ControlRadix(int radix) {
    if (radix >= 2 && radix <= 36) {
    } else {
        cout << "!!!Enter a number from 2 to 36!!!";
    }
}

int LengthStr(int radix, int value) {
    int size_for_positive = log(value + 1) / log(radix) + 1;
    int size_for_negative =log((-1) * value + 1) / log(radix) + 2;
    return (value >= 0) ? (size_for_positive) : (size_for_negative);
}

int OutputStr(int value, int radix) {
    int reduction_number =value % radix + 48;
    int reduction_letter =value % radix + 55;
    return (value % radix <= 9) ? (reduction_number) : (reduction_letter);
}

char *Iota(char *str, int value, int radix) {
    int size = LengthStr(radix, value) - 1;
    str[LengthStr(radix, value)] = '\0';
    if (value < 0) {
        str[0] = (char) 45;
        value = (-1) * value;
    }
    while (value != 0) {
            str[size] = (char) OutputStr(value, radix);
            value = value / radix;
            size--;
    }
     return str;
}

int main() {
    int value;
    int radix;
    cout << "Enter an integer number "<<endl;
    cin >> value;
    cout << "Enter a number from 2 to 36, by which the conversion will take place  "<< endl;
    cin >> radix;
    ControlRadix(radix);
    char *str = new char[LengthStr(radix, value) + 1];
    cout << Iota(str, value, radix);
    delete []str;
    return 0;
}
