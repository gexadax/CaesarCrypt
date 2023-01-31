#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    char oper;
    do {
        cout << "Введите символ выбора операции \n (шифрование(encrypt) или дешифрование(decrypt)) \n (e)ncrypt, (d)ecrypt): ";
        cin >> oper;
        if (oper == 'q') {
            break;
        }
        if (oper != 'e' && oper != 'd') {
            cout << "Введен недопустимый символ, пожалуйста введите только 'e' или 'd'" << endl;
            continue;
        }
        int n;
        cout << "Введите длину строки: ";
        cin >> n;
        char* input = new char[n];
        cout << "Введите строку: ";
        for (int i = 0; i < n; i++) {
            cin >> input[i];
            if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))) {
                cout << "Введен недопустимый символ, пожалуйста введите только буквы" << endl;
                return 0;
            }
        }
        int x;
        cout << "Введите сдвиг по таблице ASCII: ";
        cin >> x;
        if (x < 1 || x > 25) {
            cout << "Введено недопустимое значение сдвига, пожалуйста введите значение от 1 до 25" << endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                if (oper == 'e') {
                    input[i] = (input[i] - 'a' + x) % 26 + 'a';
                }
                else if (oper == 'd') {
                    input[i] = (input[i] - 'a' - x + 26) % 26 + 'a';
                }
            }
            else if (input[i] >= 'A' && input[i] <= 'Z') {
                if (oper == 'e') {
                    input[i] = (input[i] - 'A' + x) % 26 + 'A';
                }
                else if (oper == 'd') {
                    input[i] = (input[i] - 'A' - x + 26) % 26 + 'A';
                }
            }
        }
        cout << "Результат: ";
        for (int i = 0; i < n; i++) {
            cout << input[i];
        }
        cout << "\nПродолжить - y, выйти - q: " << endl;
        cin >> oper;
        delete[] input;
    } while (oper != 'q');
    return 0;
}
