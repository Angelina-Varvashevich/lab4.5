#include <iostream>// variant 5
#include <cmath>

using namespace std;

void PrintTheMostUniqueWord(char *str_b) {
    int ch;
    int result = 0;
    int begin_w = 0;
    int end_w = 0;
    int begin = 0;
    int end = 0;
    for (int i = 0; i <=  strlen(str_b) ; i++) {
        if ((str_b[i] == ' ') || (str_b[i] == '\0')) {
            ch = 0;
            for (int j = begin_w; j < i; j++) {
                ch++;
                for (int k = begin_w; k < j; k++) {
                    if (str_b[j] == str_b[k]) {
                        ch--;
                        break;
                    }
                }
            }
            if (ch >= result) {
                result = ch;
                begin = begin_w;
                end = end_w;
            }
            begin_w = i + 1;
        }
        end_w = i;
    }
    for (int i = begin; i <= end; i++)
        cout << str_b[i];
}

int main() {
    char *str_b = new char[300];
    cout << "Input the string ";
    cin.getline(str_b, 300);
    PrintTheMostUniqueWord(str_b);
    return 0;
}