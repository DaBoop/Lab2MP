// Main      


#include <iostream>
#include <tchar.h>
#include <iomanip> 


#include "Combi1.h"
#include "Combi2.h"
#include "Combi3.h"
#include "Combi4.h"
#include "Salesman.h"

#include <time.h> 
#include <random>
#include <ctime>

#define N (sizeof(AA)/2)
#define M 3


void booleanTest();
void combinationTest();
void permutationTest();
void kpermutationTest();
void salesmanTest();
int randomVal(void);

int _tmain(int argc, _TCHAR* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    //std::cout << randomVal() << std::endl;
    std::cout << "Введите номер генератора:\n1 - булеан\n2 - сочетания\n3 - перестановки\n4 - размещения\n5 - хадукен\n";
    int t;
    std::cin >> t;

   
    switch (t)
    {
    case 1: booleanTest(); break;
    case 2: combinationTest(); break;
    case 3: permutationTest(); break;
    case 4: kpermutationTest(); break;
    case 5: salesmanTest(); break;
    }
    system("pause");
    return 0;
}


void booleanTest()
{

    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    combi1::subset s1(sizeof(AA) / 2);     // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                         // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                  // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;
}
void combinationTest()
{
    setlocale(LC_ALL, "rus");
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi2::xcombination xc(sizeof(AA) / 2, 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";
        for (int i = 0; i < n; i++)
            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;

}
void permutationTest()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi3::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";
        for (int i = 0; i < p.n; i++)
            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
        std::cout << "}";
        n = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;

}
void kpermutationTest()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)
        std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    combi4::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0) {
        std::cout << std::endl << std::setw(2) << s.na << ": { ";
        for (int i = 0; i < 3; i++)
            std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;

}
void salesmanTest()
{
    
    // std::cout << randomVal();
    /*
    const int n = 5;
    int d[n][n] = { //0   1    2    3     4        
                   {  0,  45, INF,  25,   50},    //  0
                   { 45,   0,  55,  20,  100},    //  1
                   { 70,  20,   0,  10,   30},    //  2 
                   { 80,  10,  40,   0,   10},    //  3
                   { 30,  50,  20,  10,    0} };   //  4 
    int r[n];                     // результат 
    */
    clock_t  t1 = 0, t2 = 0;

    t1 = clock();
    for (int n = 5; n < 13; n++)
    {
        int** d = new int*[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = randomVal();
            }
        }

        int* r = new int [n];
        int s = salesman(
            n,          // [in]  количество городов 
            (int*)d,          // [in]  массив [n*n] расстояний 
            r           // [out] массив [n] маршрут 0 x x x x  

        );
       // std::cout << std::endl << "-- Задача коммивояжера -- ";

        t2 = clock();
        std::cout << std::endl << "-- количество  городов: " << n;
        std::cout << std::endl << "-- матрица расстояний : ";
        for (int i = 0; i < n; i++) {
            std::cout << std::endl;
            for (int j = 0; j < n; j++)
                if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";
                else std::cout << std::setw(3) << "INF" << " ";
        }
        
        std::cout << std::endl << "-- оптимальный маршрут: ";
        for (int i = 0; i < n; i++) std::cout << r[i] << "-->"; std::cout << 0;
        std::cout << std::endl << "-- длина маршрута     : " << s;
        std::cout << std::endl << "-- время: " << t2 - t1 << "\n";

    }
}

int randomVal(void)
{

      int res = rand() % INF + 1;
      return res;
}