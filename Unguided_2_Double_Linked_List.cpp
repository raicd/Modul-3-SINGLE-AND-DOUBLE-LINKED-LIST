#include <iostream>
#include <iomanip>
using namespace std;

// Raihan Ramadhan
// 2311102040
// IF-11-A

struct Node
{
    string namaProduk;
    int harga;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *head, *tail;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Fungsi untuk menambahkan data di depan
    void tambahDataDepan(string namaProduk, int harga)
    {
        Node *temp = new Node;
        temp->namaProduk = namaProduk;
        temp->harga = harga;
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL)
        {
            head->prev = temp;
        }
        head = temp;
        if (tail == NULL)
        {
            tail = head;
        }
    }

    // Fungsi untuk menambahkan data di belakang
    void tambahDataBelakang(string namaProduk, int harga)
    {
        Node *temp = new Node;
        temp->namaProduk = namaProduk;
        temp->harga = harga;
        temp->next = NULL;
        temp->prev = tail;
        if (tail != NULL)
        {
            tail->next = temp;
        }
        tail = temp;
        if (head == NULL)
        {
            head = tail;
        }
    }

    // Fungsi untuk menambahkan data di urutan tertentu
    void tambahDataTertentu(string namaProduk, int harga, string namaProdukSetelah)
    {
        Node *current = head;
        while (current != NULL && current->namaProduk != namaProdukSetelah)
        {
            current = current->next;
        }
        if (current != NULL && current->next != NULL)
        {
            Node *temp = new Node;
            temp->namaProduk = namaProduk;
            temp->harga = harga;
            temp->next = current->next;
            temp->prev = current;
            current->next->prev = temp;
            current->next = temp;
        }
    }

    // Fungsi untuk menghapus data
    void hapusData(string namaProduk)
    {
        Node *temp = head;
        while (temp != NULL && temp->namaProduk != namaProduk)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev;
        }
        delete temp;
    }

    // Fungsi untuk mengupdate data
    void updateData(string namaProdukLama, string namaProdukBaru, int hargaBaru)
    {
        Node *current = head;
        while (current != NULL && current->namaProduk != namaProdukLama)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            current->namaProduk = namaProdukBaru;
            current->harga = hargaBaru;
        }
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanData()
    {
        Node *current = head;
        cout << "Toko Skincare Purwokerto\n";
        cout << left << setw(20) << "Nama Produk"
             << "Harga\n";
        while (current != NULL)
        {
            cout << left << setw(20) << current->namaProduk << current->harga << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menghapus seluruh data
    void hapusSemuaData()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu()
{
    cout << "Toko Skincare Purwokerto\n";
    cout << "1. Tambah Data\n";
    cout << "2. Hapus Data\n";
    cout << "3. Update Data\n";
    cout << "4. Tambah Data Urutan Tertentu\n";
    cout << "5. Hapus Data Urutan Tertentu\n";
    cout << "6. Hapus Seluruh Data\n";
    cout << "7. Tampilkan Data\n";
    cout << "8. Exit\n";
}

int main()
{
    DoubleLinkedList list;
    int pilihan, harga;
    string namaProduk, namaProdukSetelah, namaProdukLama, namaProdukBaru;

    // Tambahkan data awal
    list.tambahDataBelakang("Originote", 60000);
    list.tambahDataBelakang("Somethinc", 150000);
    list.tambahDataBelakang("Skintific", 100000);
    list.tambahDataBelakang("Wardah", 50000);
    list.tambahDataBelakang("Hanasui", 30000);

    do
    {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nama Produk: ";
            cin >> namaProduk;
            cout << "Masukkan Harga: ";
            cin >> harga;
            list.tambahDataBelakang(namaProduk, harga);
            break;
        case 2:
            cout << "Masukkan Nama Produk yang akan dihapus: ";
            cin >> namaProduk;
            list.hapusData(namaProduk);
            break;
        case 3:
            cout << "Masukkan Nama Produk Lama: ";
            cin >> namaProdukLama;
            cout << "Masukkan Nama Produk Baru: ";
            cin >> namaProdukBaru;
            cout << "Masukkan Harga Baru: ";
            cin >> harga;
            list.updateData(namaProdukLama, namaProdukBaru, harga);
            break;
        case 4:
            cout << "Masukkan Nama Produk: ";
            cin >> namaProduk;
            cout << "Masukkan Harga: ";
            cin >> harga;
            cout << "Masukkan Nama Produk setelah produk ini: ";
            cin >> namaProdukSetelah;
            list.tambahDataTertentu(namaProduk, harga, namaProdukSetelah);
            break;
        case 5:
            cout << "Masukkan Nama Produk yang akan dihapus: ";
            cin >> namaProduk;
            list.hapusData(namaProduk);
            break;
        case 6:
            list.hapusSemuaData();
            cout << "Seluruh data telah dihapus.\n";
            break;
        case 7:
            list.tampilkanData();
            break;
        case 8:
            cout << "Terima kasih sudah belanja skincare disini:)\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 8);

    return 0;
}