//
// Created by ardyc-user on 22.09.2022.
//

#include <iostream>
#include <fstream>
#include "windows.h"
#include "cmath"

using namespace std;

void hw41() {
    cout << "Введите 10 чисел\n";
    int a[10];
    for (int i = 0; i < 10; i++) {
        int k = 0;
        cin >> k;
        a[i] = k;
    }

    ofstream file;
    file.open("41.txt");
    for (int i = 0; i < 10; i++) {
        file << a[i] << " ";
    }

    file.close();


    ifstream ifile;
    ifile.open("41.txt");
    int sum = 0;
    int c = 0;

    while (ifile >> c) {
        sum += c;
    }
    cout << "Сумма: " << sum;
    ifile.close();

}

//«Знак числа»
int sign42(int x) {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

void hw42() {
    cout << "Введите x\n";
    int x = 0;
    cin >> x;
    cout << "Результат выполнения подпрограммы-функции: " << sign42(x);
}

void round43() {
    cout << "Введите радиус круга\n";
    int r;
    cin >> r;
    cout << "Площадь круга: " << (r * r * 3.1415);
}

void triangle43() {
    cout << "Введите сторону и высоту к ней\n";
    int a, h;
    cin >> a >> h;
    cout << "Площадь треугольника: " << (1 / 2.0 * a * h);
}


void pr43() {
    cout << "Введите две стороны\n";
    int a, h;
    cin >> a >> h;
    cout << "Площадь прямоугольника: " << (a * h);
}

void hw43() {
    cout << "Что вы хотите вычислить:\n1.Площадь круга\n2.Площадь треугольника\n3.Площадь прямоугольника\n";
    int q = 0;
    cin >> q;
    switch (q) {
        case 1: {
            round43();
            break;
        }
        case 2: {
            triangle43();
            break;
        }
        case 3: {
            pr43();
            break;
        }
        default: {
            cout << "Неизвестная команда";
        }
    }
}

void hw44() {
    cout << "Былая слава 1912\n";
    for (int i = 0; i < 13; i++) {
        if (i < 6) {
            for (int k = 0; k < 8; k++) {
                cout << "* ";
            }
            for (int k = 0; k < 84; k++) {
                if (i % 2 == 0) {
                    cout << "_";
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        } else {
            for (int k = 0; k < 100; k++) {
                if (i % 2 == 0) {
                    cout << "_";
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        }

    }
}

void hw45() {
    cout << "График синуса y = sin(x)\n";
    cout << "^" << endl;
    for (int j = 5; j >= -5; j -= 1) {
        cout << "|";
        for (int i = 0; i < 360; i += 5) {
            if (j == 0) {
                if (i == 355) {
                    cout << ">";
                } else
                    cout << "-";

            } else {
                double sinx = sin(3.14 * i / 180.0);
                if (sinx < j / 5.0 && sinx > (j / 5.0 - 0.1)) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

}

int hw46(char romain) {
    switch (romain) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}


void hw46() {
    cout << "Введите число в римской системе счисления\n";
    string a;
    cin >> a;

    int res = 0;
    for (int i = 0; i < a.length(); i++) {
        const int f = hw46(a[i]);
        if (i + 1 < a.length()) {
            const int f1 = hw46(a[i + 1]);
            if (f < f1) {
                res += f1 - f;
                i += 1;
            } else {
                res += f;
            }
        } else {
            res += f;
        }
    }
    cout << res;

}

long int f47(int s) {
    if (s == 0) {
        cout << 0;
        return 0;
    }
    long int k = (25173 * f47(s - 1) + 13849) % 65537;
    cout << k << endl;
    return k;

}

void hw47() {
    f47(10);
}

void hw48() {
    int product_matrix[3][4] = {{5,  2, 0, 10},
                                {3,  5, 2, 5},
                                {20, 0, 0, 0}};
    double price_matrix[4][2] = {{1.2, 0.5},
                                 {2.8, 0.4},
                                 {5.0, 1.0},
                                 {2.0, 1.5}};
    double res[3][2] = {{0, 0},
                        {0, 0},
                        {0, 0}};

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 2; col++) {
            for (int inner = 0; inner < 4; inner++) {
                res[row][col] += product_matrix[row][inner] * price_matrix[inner][col];
            }
        }
    }
    double min_p = 9999;
    double max_p = -9999;

    double min_k = 9999;
    double max_k = -9999;

    double sum_pk = 0;
    double sum_k = 0;
    double sum_p = 0;

    for (int i = 0; i < 3; ++i) {
        double pk = res[i][0] - res[i][1];
        double p = res[i][0];
        double k = res[i][1];
        if (pk < min_p) {
            min_p = pk;
        }
        if (pk > max_p) {
            max_p = pk;
        }

        if (k < min_k) {
            min_k = k;
        }
        if (k > max_k) {
            max_k = k;
        }

        sum_pk += pk;
        sum_p += p;
        sum_k += k;
    }

    cout << "Максимальная прибыль " << max_p << endl;
    cout << "Минимальная прибыль " << min_p << endl;

    cout << "Максимальная комиссия " << max_k << endl;
    cout << "Минимальная комиссия " << min_k << endl;

    cout << "Общая прибыль " << sum_pk << endl;
    cout << "Общая комиссия " << sum_k << endl;
    cout << "Общая сумма денег " << sum_p << endl;


}

int getSymbolCode(char c) {
    string all_s = "0123456789ABCDEF";
    for (int i = 0; i < all_s.length(); ++i) {
        if (c == all_s[i])
            return i;
    }
    cout << "Неизвестная сс";
    exit(-1);
    return -1;
}

int getIntSymbol(int c) {
    string all_s = "0123456789ABCDEF";
    if (c >= all_s.length()) {
        cout << "Неизвестная сс";
        exit(-1);
    }
    return all_s[c];
}

string hw49(int n, int m, string a) {
    int toDes = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        if (getSymbolCode(a[i]) >= n) {
            cout << "Неравильный вход\n";
            exit(-1);
        }
        toDes += getSymbolCode(a[i]) * pow(n, a.length() - i - 1);
    }

    string num = "";
    while (toDes > 0) {
        num += getIntSymbol(toDes % m);
        toDes = toDes / m;
    }
    string rev = "";
    for (int i = 0; i < num.length(); ++i) {
        rev += num[num.length() - 1 - i];
    }
    return rev;
}

void hw49() {

    int n, m;
    string a;
    cout << "Введите изначальную сс\n";
    cin >> n;

    cout << "Введите целевую сс\n";
    cin >> m;

    cout << "Число\n";
    cin >> a;

    cout << hw49(n, m, a);

}


void hw51() {
    cout << "Введите 2 числа \n";
    int a, b, k, m;
    cin >> a >> b;
    k = a;
    m = b;
    while (max(a, b) % min(a, b) != 0) {
        if (a > b) {
            a = max(a, b) % min(a, b);
        } else {
            b = max(a, b) % min(a, b);
        }
    }

    while (max(k, m) - min(k, m) != 0) {
        if (k > m) {
            k = max(k, m) - min(k, m);
        } else {
            m = max(k, m) - min(k, m);
        }
    }
    cout << min(a, b) << endl;
    cout << min(k, m);
}


void hw52() {
    int n;
    cout << "Введите n\n";
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n + 1; i++) {
        a[i] = i;
    }
    for (int p = 2; p < n + 1; p++) {
        if (a[p] != 0) {
            cout << a[p] << " ";
            for (int j = p * p; j < n + 1; j += p) {
                a[j] = 0;
            }
        }
    }
}

void hw53_1() {
    string a;
    char delimetr = ' ';
    char delimetr_new;

    cout << "Введите строку \n";
    getline(cin, a);
    cout << "Введите новый разделитель\n";
    cin >> delimetr_new;

    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == delimetr) {
            a[i] = delimetr_new;
        }
    }
    cout << a;
}

void hw53_2() {
    string a;
    char delimetr = ' ';

    cout << "Введите строку \n";
    getline(cin, a);

    string now_word = "";
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == delimetr || a[i] == '\n') {
            cout << now_word << endl;
            now_word = "";
        } else {
            now_word += a[i];
        }
    }
    cout << now_word;
}

void hw54_1() {
    double n, y = 0;
    cout << "Введите n" << endl;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        double t = 0;
        for (int j = 1; j <= i; ++j) {
            t += sin(j);
        }
        y += i / t;
        cout << i << "/" << t;
    }
    cout << "Ответ y = " << y;
}

void hw54_20() {
    int n = 0;
    cout << "Введите количество элементов массива\n";
    cin >> n;
    string matrix[n];
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        matrix[i] = hw49(2, 4, a);
    }
    for (int i = 0; i < n; ++i) {
        cout << matrix[i] << " ";
    }

}

void getDataFromString(string a, string &name, int &cost, int &min_v, int &max_v) {
    string word = "";
    bool fName = false;
    bool fCost = false;
    bool fMinV = false;
    bool fMaxV = false;

    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == ',') {
            if (!fName) {
                fName = true;
                name = word;
                word = "";
            } else if (!fCost) {
                fCost = true;
                cost = stoi(word);
                word = "";
            } else if (!fMinV) {
                fMinV = true;
                min_v = stoi(word);
                word = "";
            } else if (!fMaxV) {
                fMaxV = true;
                max_v = stoi(word);
                word = "";
            }
        } else {
            word += a[i];
        }
    }
    if (!fMaxV) {
        fMaxV = true;
        max_v = stoi(word);
        word = "";
    }
}

void hw55_1() {
    string n;
    cout << "Введите название файла\n";
    cin >> n;

    ifstream ifile;
    ifile.open(n);

    string c = "";
    int max_cost = 0;
    string max_name = "";

    while (getline(ifile, c)) {
        string name;
        int cost;
        int min_v;
        int max_v;

        getDataFromString(c, name, cost, min_v, max_v);

        if (cost <= 400 && min_v <= 8 && max_v >= 8) {
            cout << "Подходит для детей 8 лет и до 400р " << name << endl;
        }
        if (cost > max_cost) {
            max_cost = cost;
            max_name = name;
        }
        if (min_v <= 4 && max_v >= 4 && min_v <= 10 && max_v >= 10) {
            cout << "Подходит для детей 4 и 10 лет " << name << endl;
        }
//        cout << name << " " << cost << " " << min_v << " " << max_v << " " << endl;

    }
    cout << "Максимальная цена у " << max_name << ", которая стоит " << max_cost;

    ifile.close();


}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    hw52();
}
