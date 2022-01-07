#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include  <conio.h>
#include <string>
#include <fstream>
#include <clocale>

typedef struct LIST // Структура динамического списка
{
    char dann;
    LIST* next;
}_LIST;

_LIST* deleten(_LIST* _head, char key);
void print(_LIST* _head);
_LIST* make(_LIST* _head, char b);

int main() {
    _LIST* _head = 0;
    int     n, i;
    char    b;
    char    key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "\nEnter elements:\n";

    for (i = 0; i < n; i++)
    {
        cin >> b;
        _head = make(_head, b);
    }

    cout << "Entered list: ";
    print(_head);


    cout << "Enter key (or Q to exit): ";
    cin >> key;
    switch (key)
    {
    case 'E':
        _head = deleten(_head, key);
        cout << "\nEnter List after deleting element nexted for element " << key << ": ";
        print(_head);
        break;
    case 'Q': return 0;
    default:
        cout << "No elements for deleting. You did not input \"E\" key.";
        break;
    }

    return 0;
}

_LIST* make(_LIST* _head, char b) //Формирование списка
{
    _LIST* ptr;

    if (!_head) {
        ptr = (_LIST*)calloc(1, sizeof(_LIST));
        ptr->dann = b;
        return ptr;
    }

    _head->next = make(_head->next, b);

    return _head;
}

void print(_LIST* _head) //Вывод на экран элементов списка
{
    LIST* ptr;

    if (!_head) return;
    for (ptr = _head; ptr; ptr = ptr->next) cout << ptr->dann << " \n";

}

_LIST* deleten(_LIST* _head, char key) //удаление элемента, следующего после определенным элементом
{
    _LIST* ptr;
    _LIST* tmp;

    if (!_head) return _head;

    for (ptr = _head; ptr; ptr = ptr->next) {
        if ((ptr->dann == key) && ptr->next) {
            if (ptr == _head) {
                tmp = ptr;
                ptr = ptr->next;
                tmp->next = ptr->next;
                free(ptr);
                ptr = tmp;
            }
            else {
                tmp = tmp->next;
                ptr = ptr->next;
                tmp->next = ptr->next;
                free(ptr);
                ptr = tmp;
            }
        }

        tmp = ptr;
    }

    return _head;
}