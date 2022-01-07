#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include  <conio.h>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

struct Magaz
{
    char nazva[60];
    char adresa[60];
    char chas_roboti[60];
    char tip_tovaru[60];
    void Input(Magaz& magaz);           //‘ункци¤ ввода данных в структуру
    Magaz* Next;                          //јдрес на следующий элемент
};

class List
{
    Magaz* Head;                          //”казатель на начало списка
public:
    List() :Head(NULL) {};                    // онструктор по умолчанию (Head=NULL)
    ~List();                                //ѕрототип деструктора
    void Add(Magaz& magaz);             //ѕрототип функции добавлени¤ элемента в список
    void Red(Magaz& magaz, int num);
    void Del1(Magaz& magaz);
    void Del2(Magaz& magaz);
    void Show();                            //ѕрототип функции вывода списка на экран
};

/*‘”Ќ ÷»я «јѕќЋЌ≈Ќ»я ƒјЌЌџ’ ѕќ —“”ƒ≈Ќ“”*/
void Magaz::Input(Magaz& magaz)
{
    cout << "\nЌазва магазину: ";
    cin.getline(nazva, 60);
    cout << "јдреса магазину: ";
    cin.getline(adresa, 60);              
    cout << "„ас роботи: ";
    cin.getline(chas_roboti, 60);               
    cout << "“ип товару: ";
    cin.getline(tip_tovaru, 60);
}

List::~List()                              //ƒеструктор класса List
{
    while (Head != NULL)                //ѕока по адресу есть хоть что-то
    {
        Magaz* temp = Head->Next;     //—разу запоминаем указатель на адрес следующего элемента структуры
        delete Head;                    //ќсвобождаем пам¤ть по месту начала списка
        Head = temp;                    //ћен¤ем адрес начала списка
    }
}

/*‘”Ќ ÷»я ƒќЅј¬Ћ≈Ќ»я Ќќ¬ќ… —“–” “”–џ ¬ —ѕ»—ќ */
void List::Add(Magaz& magaz)
{
    Magaz* temp = new Magaz;           //¬ыделение пам¤ти под новую структуру
    temp->Next = Head;                     //”казываем, что адрес следующего элемента это начало списка
// опирование содержимого параметра student в только что созданную переменную
    strcpy(temp->nazva, magaz.nazva);
    strcpy(temp->adresa, magaz.adresa);
    strcpy(temp->chas_roboti, magaz.chas_roboti);
    strcpy(temp->tip_tovaru, magaz.tip_tovaru);
    Head = temp;                           //—мена адреса начала списка
}

void List::Red(Magaz& magaz, int num)
{
    Magaz* temp = new Magaz;
    int i= 0;
    while (i != num)
    {
        i++;
    }
    if (i = num)
    temp = temp->Next;
    delete temp;
}
/*‘”Ќ ÷»я  Ћј——ј LIST ƒЋя ¬џ¬ќƒј —ѕ»— ј Ќј Ё –јЌ*/
void List::Show()
{
    Magaz* temp = Head;                  //ќбъ¤вл¤ем указатель и изначально он указывает на начало
    cout<< "Ќазва магазину:\t" << "јдреса магазину:\t" << "„ас роботи:\t" << "“ип товару:\n";
    while (temp != NULL)                   //ѕока по адресу на начало хоть что-то есть
    {
        //¬ыводим все элементы структуры
        cout << temp->nazva  << "\t\t";     
        cout << temp->adresa << "\t\t";   
        cout << temp->chas_roboti << "\t\t";    
        cout << temp->tip_tovaru << endl; 
        temp = temp->Next;
    }
    cout << endl;
}

void List::Del1(Magaz& magaz)
{
    Magaz* temp = new Magaz;
    temp = temp->Next;
}

void List::Del1(Magaz& magaz)
{
    Magaz* temp = Head;
    temp = temp->Next;
    delete(temp->nazva, magaz.nazva);
    delete(temp->adresa, magaz.adresa);
    delete(temp->chas_roboti, magaz.chas_roboti);
    delete(temp->tip_tovaru, magaz.tip_tovaru);
}

int main()
{
    setlocale(LC_ALL, "rus");
    Magaz magaz;                          //ќбъ¤вили переменную, тип которой —тудент
    int N, m, r, num;                                    //ќбъ¤вили переменную - число студентов
    List lst;                                 //ќбъ¤вили переменную типа —писок. ќна выступает как контейнер данных
    cout << "¬ведiть кiлькiсть записiв:\n";
    cin >> N;                               //¬вели число студентов
    cin.ignore();                           //»гнорируем клавишу Enter
    for (int i = 0; i < N; i++)
    {
        magaz.Input(magaz);                //ѕередаем в функцию заполнени¤ переменную студент
        lst.Add(magaz);                      //ƒобавл¤ем заполненную структуру в список
    }
    cout << endl;
    lst.Show();                             //ѕоказываем список на экране
    
    cout << "¬ведiть 1 ¤кщо бажаете додати ще 1 елемент\n"; 
    cin >> m;
    cin.ignore();
    if (m == 1)
    {
        magaz.Input(magaz);               
        lst.Add(magaz);   
        lst.Show();
    }
    cout << "¬ведiть 1 ¤кщо бажаете редагувати елемент\n";
    cin >> r;
    if (r == 1)
    {
    cout << "¬ведiть номер елемента\n";
        cin >> num;
        for (int i = 0; i < num - 1; i++)
        {
            lst.Del1(magaz);
        }
        lst.Del2(magaz);
        cin.ignore();
        lst.Show();
    }
    cin.ignore().get();
    return 0;
}
