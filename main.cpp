#include <iostream>
using namespace std;

int get_num() {

    int guess;
    do {
        cout << "Введите четырехзначное число: ";
        cin >> guess;
    } while (guess < 1000 or guess > 9999);

    return guess;
}


int bulls_cows(int tries, int answer) {

    int bulls = 0, cows = 0, digits = answer, tmp, dt, da;

    while (digits) {

        dt = tries % 10;
        da = digits % 10;

        if (dt == da) {
            bulls++;
        }

        else {
            tmp = answer;

            while (tmp) {

                if (tmp % 10 == dt) {
                    cows++;
                }

                tmp /= 10;
            }
        }

        tries /= 10;
        digits /= 10;
    }
    return bulls * 10 + cows;
}


int main() {
    setlocale(LC_ALL, "ru");

    int answer = 1234;                                                                  // Можно задать совершенно любое четырехзначное число.Я выбрал 1234.
    int tries = 0;
    int result;

    do {
        tries = get_num();
        result = bulls_cows(tries, answer);
        cout << "Быки: " << result / 10 << ", Коровы: " << result % 10 << endl;
    
    } while (result != 40);

    cout << "Вы угадали число!" << endl;
    

    return 0; 
}