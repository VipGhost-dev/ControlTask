#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//Программа записывает в одномерный динамичесчкий целочисленный массив цифры заданного целого числа, являющихся при этом индексами соответствующих им элементов массива.
//Элементы массива заполняются значением "-1". При заполнении массива цифрами из целого чилсла на их индексы, пустые элементы массива остаются заполнеными значением "-1". 

// Функция безопасного ввода
template<typename T>
T safe_input(const string& prompt) {
    T input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input Error! Please enter a valid value." << endl;
        }
    }
    return input;
}

// Функция отображения массива
void display_array(const vector<int>& arr) {
    cout << "Array: ";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

// Функция записи в массив
void write_to_array(int num, vector<int>& array) {
    stringstream ss;
    ss << abs(num);
    string num_str = ss.str(); //Перевод в строку
    
    for (char digit : num_str) {
        int index = digit - '0';
        array[index] = index;
    }
}

int main() {
    // Ввод целого числа
    int input_number = safe_input<int>("Please enter a number: ");

    // Создание динамического массива
    vector<int> dynamic_array(10, -1);  // Инициализация массива значениями -1

    // Отображение массива до записи
    display_array(dynamic_array);

    // Запись в массив
    write_to_array(input_number, dynamic_array);

    // Отображение массива после записи
    display_array(dynamic_array);

    return 0;
}
