#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    float fileSizeMB;
    float speedMBs;
    int time, t;
    while (true) {
        std::cout << "Ввод:\n";
        std::cout << "Укажите размер файла для скачивания (МБ, >0): ";
        std::cin >> fileSizeMB;
        std::cout << "Какова скорость вашего соединения? (МБ/с, >0): ";
        std::cin >> speedMBs;
        if (fileSizeMB <= 0 || speedMBs <= 0 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            time = (int) (std::ceil(fileSizeMB / speedMBs));
            for (t = 0; t < time;t++) {
                std::cout<<"Прошло "<<t<<" сек. Скачано "<<speedMBs*t<<" из "<<fileSizeMB<<" МБ ("<<(int) ((speedMBs*t)/(fileSizeMB)*100)<<"%).\n";
            }
            std::cout<<"Прошло "<<time<<" сек. Скачано "<<fileSizeMB<<" из "<<fileSizeMB<<" МБ (100%).\n";
        }
    }
}