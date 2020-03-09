#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void RemoveSpaces(string& line) {
    int shift = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            ++shift;
        } else {
            swap(line[i], line[i - shift]);
        }
    }
    line.resize(line.length() - shift);
}

string derivative(string line) {
    RemoveSpaces(line);

    if (line.empty()) {
        cout << "";
        return 0;
    }

    map <pair<int, string>, int> polynomial;
    int sign = 1;
    bool wasMulti = isalpha(line[0]);
    bool wasDegree = false;
    int coefficient = 0;
    string variable;
    int degree = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == '+' || line[i] == '-') {
            if (coefficient == 0) {
                coefficient = 1;
            }
            if (degree == 0) {
                degree = 1;
            }
            coefficient *= sign;
            if (!variable.empty()) {
                coefficient *= degree--;
                if (degree == 0) {
                    variable = "";
                    //-x^2+x+y^3+z
                }
                polynomial[{degree, variable}] += coefficient;
            }
            sign = line[i] == '+' ? 1 : -1;
            wasMulti = isalpha(line[i + 1]);
            wasDegree = false;
            coefficient = 0;
            variable = "";
            degree = 0;
        } else {
            if (line[i] == '*') {
                wasMulti = true;
            } else if (line[i] == '^') {
                wasDegree = true;
            } else if (!wasMulti) {
                coefficient *= 10;
                coefficient += line[i] - '0';
            } else if (wasMulti && !wasDegree) {
                variable += line[i];
            } else {
                degree *= 10;
                degree += line[i] - '0';
            }
        }
    }
    if (coefficient == 0) {
        coefficient = 1;
    }
    if (degree == 0) {
        degree = 1;
    }
    coefficient *= sign;
    if (!variable.empty()) {
        coefficient *= degree--;
        if (degree == 0) {
            variable = "";
        }
        polynomial[{degree, variable}] += coefficient;
    }

//    while (getline(sin, box, '+')) {
//        bool wasMulti = isalpha(box.front());
//        bool wasDegree = false;
//
//        int coefficient = 0;
//        string variable;
//        int degree = 0;
//
//        for (auto& i : box) {
//            if (i == '*') {
//                wasMulti = true;
//            } else if (i == '^') {
//                wasDegree = true;
//            } else if (!wasMulti) {
//                coefficient *= 10;
//                coefficient += i - '0';
//            } else if (wasMulti && !wasDegree) {
//                variable += i;
//            } else {
//                degree *= 10;
//                degree += i - '0';
//            }
//        }
//        if (coefficient == 0) {
//            coefficient = 1;
//        }
//        if (degree == 0) {
//            degree = 1;
//        }
//        if (!variable.empty()) {
//            polynomial[{degree, variable}] += coefficient;
//        }
//    }

    for (auto rit = polynomial.rbegin(); rit != polynomial.rend(); ++rit) {
        const auto& i = *rit;
        degree = i.first.first;
        variable = i.first.second;
        coefficient = i.second;

        if (coefficient == 0) {
            continue;
        }

        if (rit != polynomial.rbegin() && coefficient > 0) {
            cout << "+";
        }

        if (degree == 0) {
            cout << coefficient;
        } else {
            if (coefficient != 1 && coefficient != -1) {
                cout << coefficient << "*";
            } else if (coefficient == -1) {
                cout << "-";
            }
            cout << variable;
            if (degree != 1) {
                cout << "^" << degree;
            }
        }
    }
}







int main() {
    string line;
    getline(cin, line);


    return 0;
}