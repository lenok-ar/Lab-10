/**************************
 * Автор: Арестова Е.Е.   *
 * Дата: 03.11.2024       *    
 **************************/


#include <iostream>
#include <string>  
#include <algorithm> 

using namespace std;

string sum(string num1, string num2) {

    string result;
    int carry = 0; 
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 < len2) {
        swap(num1, num2);
        swap(len1, len2);
    }

    for (int i = 0; i < len1; i++) {
        int digit1 = num1[len1 - 1 - i] - '0'; 
        int digit2;

        if (i < len2) {
            digit2 = num2[len2 - 1 - i] - '0'; 
        }
        else {
            digit2 = 0; 
        }

        int sum = digit1 + digit2 + carry; 
        carry = sum / 10;
        result.push_back((sum % 10) + '0'); 
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
    }

string differense(string num1, string num2) {

    string result;
    int borrow = 0; 
    int len1 = num1.size();
    int len2 = num2.size();

    if (len1 < len2 || (len1 == len2 && num1 < num2)) {
        return "Первое число должно быть больше или равно второму числу";
    }

    for (int i = 0; i < len1; i++) {
        int digit1 = num1[len1 - 1 - i] - '0'; 
        int digit2;

        if (i < len2) {
            digit2 = num2[len2 - 1 - i] - '0'; 
        }
        else {
            digit2 = 0; 
        }

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1; 
        }
        else {
            borrow = 0; 
        }

        result.push_back((digit1 - digit2) + '0'); 
    }

    reverse(result.begin(), result.end());
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin()); 
    }

    if (result.empty()) {
        return "0";
    }
    else {
        return result;
    }
}

string multiplication(string num1, string num2) {

    if (num1 == "0" || num2 == "0") {
        return "0"; 
    }

    int len1 = num1.size();
    int len2 = num2.size();
    string result(len1 + len2, '0'); 

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); 
            int sum = mul + (result[i + j + 1] - '0'); 
            result[i + j + 1] = (sum % 10) + '0'; 
            result[i + j] += sum / 10; 
        }
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin()); 
    }

    return result; 
}
  
int main() {
    setlocale(LC_ALL, "RU");

    string num1, num2;

    cout << "Введите первое число (более 20 цифр): ";
    cin >> num1;
    cout << "Введите второе число (более 20 цифр): ";
    cin >> num2;

    cout << "Сумма: " << sum(num1, num2) << endl;
    cout << "Разность: " << differense(num1, num2) << endl;
    cout << "Произведение: " << multiplication(num1, num2) << endl;

    return 0;
}
