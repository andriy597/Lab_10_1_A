// Lab_10_1.cpp
// Лабораторна робота № 10.1. Послідовний пошук в масиві структур
// Рівень А, варіант 14
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// спеціальність студента
enum Specialnist { KOMP_NAUKY, INFORMATYKA, MAT_TA_EKON, FIZ_TA_INF, TRUD_NAVCH };

// відомості про студента
struct Student
{
    string      prizv;        // прізвище
    int         kurs;         // курс
    Specialnist spec;         // спеціальність
    int         fizyka;       // оцінка з фізики
    int         matematyka;   // оцінка з математики
    int         informatyka;  // оцінка з інформатики
};

void   Create(Student* p, const int N);
void   Print(Student* p, const int N);
string SpecStr(const Specialnist spec);
int    CountInformatykaMark(Student* p, const int N, const int mark);
double PercentPhysMathFourOrFive(Student* p, const int N);

int main()
{
    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;
    cout << endl;

    Student* p = new Student[N];   // динамічний масив структур

    Create(p, N);
    Print(p, N);

    // Завдання 1: кількість оцінок «5», «4», «3» з інформатики
    cout << "Кількість оцінок з інформатики:" << endl;
    cout << "   «5»: " << CountInformatykaMark(p, N, 5) << endl;
    cout << "   «4»: " << CountInformatykaMark(p, N, 4) << endl;
    cout << "   «3»: " << CountInformatykaMark(p, N, 3) << endl;
    cout << endl;

    // Завдання 2: процент студентів з оцінками «4» або «5» і з фізики, і з математики
    cout << "Процент студентів, які отримали і з фізики, і з математики оцінки «4» або «5»: "
        << PercentPhysMathFourOrFive(p, N) << "%" << endl;

    delete[] p;
    return 0;
}

// Формування масиву структур: введення даних з клавіатури
void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get();  // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

        cout << "     прізвище: ";             getline(cin, p[i].prizv);
        cout << "     курс: ";                 cin >> p[i].kurs;
        cout << "     спеціальність (0 - Комп'ютерні науки, 1 - Інформатика," << endl
            << "                    2 - Математика та економіка, 3 - Фізика та інформатика," << endl
            << "                    4 - Трудове навчання): ";
        cin >> spec;
        p[i].spec = (Specialnist)spec;
        cout << "     оцінка з фізики: ";      cin >> p[i].fizyka;
        cout << "     оцінка з математики: ";  cin >> p[i].matematyka;
        cout << "     оцінка з інформатики: "; cin >> p[i].informatyka;
        cout << endl;
    }
}

// Назва спеціальності за значенням переліку
string SpecStr(const Specialnist spec)
{
    switch (spec)
    {
    case KOMP_NAUKY:  return "Комп'ютерні науки";
    case INFORMATYKA: return "Інформатика";
    case MAT_TA_EKON: return "Математика та економіка";
    case FIZ_TA_INF:  return "Фізика та інформатика";
    case TRUD_NAVCH:  return "Трудове навчання";
    }
    return "";
}

// Вивід масиву структур у вигляді таблиці (із заголовком і шапкою)
void Print(Student* p, const int N)
{
    cout << "=============================================================================================" << endl;
    cout << "|                                     СПИСОК СТУДЕНТІВ                                      |" << endl;
    cout << "=============================================================================================" << endl;
    cout << "| №  | Прізвище        | Курс | Спеціальність           | Фізика | Математика | Інформатика |" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(15) << left << p[i].prizv << " "
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(23) << left << SpecStr(p[i].spec) << " "
            << "| " << setw(6) << right << p[i].fizyka << " "
            << "| " << setw(10) << right << p[i].matematyka << " "
            << "| " << setw(11) << right << p[i].informatyka << " |" << endl;
    }
    cout << "=============================================================================================" << endl;
    cout << endl;
}

// Завдання 1: послідовний пошук – кількість оцінок mark з інформатики
int CountInformatykaMark(Student* p, const int N, const int mark)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (p[i].informatyka == mark)
            k++;
    return k;
}

// Завдання 2: послідовний пошук – процент студентів, які отримали
// і з фізики, і з математики оцінки «4» або «5»
double PercentPhysMathFourOrFive(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if ((p[i].fizyka == 4 || p[i].fizyka == 5) &&
            (p[i].matematyka == 4 || p[i].matematyka == 5))
            k++;
    return 100.0 * k / N;
}