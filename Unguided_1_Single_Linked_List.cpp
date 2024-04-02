#include <iostream>
using namespace std;

// Raihan Ramadhan
// 231110204
// IF-11-A

struct Node
{
    string nama;
    int usia;
    Node *next;
};

class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertDepan(string nama, int usia)
    {
        Node *temp = new Node;
        temp->nama = nama;
        temp->usia = usia;
        temp->next = head;
        head = temp;
        if (tail == NULL)
        {
            tail = head;
        }
    }

    void insertBelakang(string nama, int usia)
    {
        Node *temp = new Node;
        temp->nama = nama;
        temp->usia = usia;
        temp->next = NULL;
        if (tail != NULL)
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            head = tail = temp;
        }
    }

    void insertTengah(string nama, int usia, string namaSetelah)
    {
        Node *temp = new Node;
        temp->nama = nama;
        temp->usia = usia;
        Node *current = head;
        while (current != NULL && current->nama != namaSetelah)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            temp->next = current->next;
            current->next = temp;
        }
        else
        {
            cout << "Node dengan nama " << namaSetelah << " tidak ditemukan." << endl;
        }
    }

    void hapusData(string nama)
    {
        Node *temp = head, *prev = NULL;
        while (temp != NULL && temp->nama != nama)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        if (prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }

    void ubahData(string namaLama, string namaBaru, int usiaBaru)
    {
        Node *current = head;
        while (current != NULL && current->nama != namaLama)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            current->nama = namaBaru;
            current->usia = usiaBaru;
        }
    }

    void tampilkanData()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << "Nama: " << current->nama << ", Usia: " << current->usia << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList list;
    // Masukkan data sesuai instruksi
    list.insertDepan("Raihan", 19);
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);

    // Operasi sesuai instruksi
    list.hapusData("Akechi");
    list.insertTengah("Futaba", 18, "John");
    list.insertDepan("Igor", 20);
    list.ubahData("Michael", "Reyn", 18);
    list.tampilkanData();

    return 0;
}