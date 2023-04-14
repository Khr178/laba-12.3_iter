#include <iostream>

using namespace std;

// Структура для представлення елемента списку
struct Node 
{
    int data;
    Node* prev;
    Node* next;
};

// Функція для створення нового елемента списку з заданим значенням
Node* createNode(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Функція для додавання нового елемента в кінець списку
void appendNode(Node** head, Node** tail, int value) 
{
    Node* newNode = createNode(value);
    if (*head == NULL) 
    {
        *head = *tail = newNode;
    }
    else 
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Функція для роздрукування значень елементів списку
void printList(Node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для перевірки, чи містить список пару сусідніх елементів з однаковими значеннями
bool hasDuplicate(Node* head) 
{
    while (head != NULL && head->next != NULL) 
    {
        if (head->data == head->next->data) 
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main() 
{
    // Створюємо список і заповнюємо його елементами
    Node* head = NULL;
    Node* tail = NULL;
    appendNode(&head, &tail, 1);
    appendNode(&head, &tail, 1);
    appendNode(&head, &tail, 3);
    appendNode(&head, &tail, 4);
    appendNode(&head, &tail, 5); // дубль елемента
    appendNode(&head, &tail, 6);

    // Роздрукуємо список
    cout << "List: ";
    printList(head);

    // Перевіримо, чи містить список пару сусідніх елементів з однаковими значеннями
    bool hasDup = hasDuplicate(head);
    if (hasDup) 
    {
        cout << "The list contains a pair of adjacent elements with the same value." << endl;
    }
    else 
    {
        cout << "The list does not contain a pair of adjacent elements with the same value." << endl;
    }

    return 0;
}
