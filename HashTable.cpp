#include <iostream>
using namespace std;
class HashTable {
public:
    struct Bucket {
        int key;
        bool occupied;

        Bucket() : key(0), occupied(false) {}
    };
    Bucket* table;
    int capacity;
    int hashFunction(int key) {
        return key % capacity;
    }
    HashTable(int size) : capacity(size) {
        table = new Bucket[capacity];
    }
    ~HashTable() {
        delete[] table;
    }
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;   
        while (table[index].occupied) {
            if (table[index].key == key) { 
                cout << "Key " << key << " already exists." << endl;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) { 
                cout << "Hash table is full. Cannot insert key: " << key << endl;
                return;
            }
        }
        table[index].key = key;
        table[index].occupied = true;
        cout << "Inserted key " << key << " at index " << index << endl;
    }
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].occupied) {
            if (table[index].key == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) { 
                return false;
            }
        }
        return false; 
    }
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i].occupied)
                cout << i << " --> " << table[i].key << endl;
            else
                cout << i << " --> " << endl;
        }
    }
};
int main() {
    int capacity;
    cout << "Enter the capacity of the hash table: ";
    cin >> capacity;  
    HashTable ht(capacity);
    int n;
    cout << "How many keys do you want to insert? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        cout << "Enter key " << i + 1 << ": ";
        cin >> key;
        ht.insert(key);
    }
    cout << "\nDisplaying hash table after insertion:" << endl;
    ht.display();
    char choice;
    do {
        cout << "\nDo you want to search for a key? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int searchKey;
            cout << "Enter the key to search for: ";
            cin >> searchKey;
            if (ht.search(searchKey)) {
                cout << "Key " << searchKey << " found in the hash table." << endl;
            } else {
                cout << "Key " << searchKey << " not found in the hash table." << endl;
            }
        }
    } while (choice == 'y' || choice == 'Y');
    return 0;
}