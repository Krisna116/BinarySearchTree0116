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