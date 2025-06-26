#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor untuk kelas Node
    Node(int val)
    {
        info = val;
        leftchild = nullptr;  // Inisialisasi anak kiri ke null
        rightchild = nullptr; // Inisialisasi anak kanan ke null
    }
};

// Kelas BinaryTree untuk mengelola operasi pada tree
class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Inisialisasi ROOT ke null saat tree pertama kali dibuat
    }

    // Fungsi untuk mencari sebuah elemen.
    void search(int element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }
    // Fungsi untuk menyisipkan node baru ke dalam tree
    void insert()
    {
        int x;
        cout << "Masukkan nilai untuk disisipkan: ";
        cin >> x;

        // Langkah 1: Buat node baru
        Node *newNode = new Node(x);

        // Langkah 2 & 3 sudah ditangani oleh constructor Node

        // Langkah 4: Cari posisi yang tepat untuk node baru
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Jika currentNode tidak null
        if (currentNode != nullptr)
        {
            cout << "Nilai " << x << " sudah ada di dalam tree." << endl;
            delete newNode; // Hapus node yang tidak jadi dipakai
            return;
        }

        // Langkah 5: Jika tree masih kosong (parent adalah null)
        if (parent == nullptr)
        {
            // Jadikan newNode sebagai ROOT
            ROOT = newNode;
            cout << "Nilai " << x << " berhasil disisipkan sebagai ROOT." << endl;
            return;
        }

        // Langkah 6 & 7: Tentukan apakah newNode akan menjadi anak kiri atau kanan dari parent
        if (x < parent->info)
        {
            // Jadikan newNode sebagai anak kiri dari parent
            parent->leftchild = newNode;
        }
        else
        {
            // Jadikan newNode sebagai anak kanan dari parent
            parent->rightchild = newNode;
        }
        cout << "Nilai " << x << " berhasil disisipkan." << endl;
    }
    
    // Fungsi untuk memeriksa apakah tree kosong
    bool isEmpty()
    {
        return ROOT == nullptr;
    }

    // Traversal Inorder (Kiri - Root - Kanan)
    void inorder(Node *ptr)
    {
        if (ptr == nullptr)
            return; // Basis rekursi

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }

    // Traversal Preorder (Root - Kiri - Kanan)
    void preorder(Node *ptr)
    {
        if (ptr == nullptr)
            return; // Basis rekursi

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    // Traversal Postorder (Kiri - Kanan - Root)
    void postorder(Node *ptr)
    {
        if (ptr == nullptr)
            return; // Basis rekursi

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

};
int main()
{
    BinaryTree tree;
    while (true)
    {
        cout << "\n--- MENU BINARY SEARCH TREE ---" << endl;
        cout << "1. Sisipkan Node Baru" << endl;
        cout << "2. Tampilkan Inorder Traversal" << endl;
        cout << "3. Tampilkan Preorder Traversal" << endl;
        cout << "4. Tampilkan Postorder Traversal" << endl;
        cout << "5. Keluar" << endl;
        cout << "\nMasukkan pilihan Anda (1-5): ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            tree.insert();
            break;
        }
        case '2':
        {
            if (tree.isEmpty())
            {
                cout << "Tree masih kosong." << endl;
            }
            else
            {
                cout << "Inorder Traversal: ";
                tree.inorder(tree.ROOT);
                cout << endl;
            }
            break;
        }
        case '3':
        {
            if (tree.isEmpty())
            {
                cout << "Tree masih kosong." << endl;
            }
            else
            {
                cout << "Preorder Traversal: ";
                tree.preorder(tree.ROOT);
                cout << endl;
            }
            break;
        }
        case '4':
        {
            if (tree.isEmpty())
            {
                cout << "Tree masih kosong." << endl;
            }
            else
            {
                cout << "Postorder Traversal: ";
                tree.postorder(tree.ROOT);
                cout << endl;
            }
            break;
        }
        }
    }
}
