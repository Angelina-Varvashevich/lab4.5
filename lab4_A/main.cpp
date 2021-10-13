
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
    if (value >= 0) {
        return log(value + 1) / log(radix) + 1;
    } else {
        return log((-1) * value + 1) / log(radix) + 2;
    }
}

int OutputStr(int value, int radix) {
    if (value % radix <= 9) {
        return value % radix + 48;
    } else {
        return value % radix + 55;
    }
}

char *Iota(char *str, int value, int radix) {/// посмотри тип функций + задание i+ ссылки
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
