#include <iostream>
using namespace std;

class Hashing
{
    int Hash_Table[11], Key;

public:
    Hashing()
    {
        for(int i = 0; i < 11; i++)
        {
            Hash_Table[i] = -1;
        }
    }

    int Hash_Func(int Key)
    {
        return Key % 11;
    }

    void Linear_Probing_Without_Replace()
    {
        cout << "Enter Key to be inserted in Hash Table : ";
        cin >> Key;
        int Hash_Address = Hash_Func(Key);
        if (Hash_Table[Hash_Address] == -1)
        {
            Hash_Table[Hash_Address] = Key;
        }
        else
        {
            int j = Hash_Address;
            while (Hash_Table[j] != -1 && j != Hash_Address)
            {
                j = (j + 1) % 11;
            }
            Hash_Table[j] = Key;
        }
    }

    int Search_Key(int Key)
    {
        int Hash_Address = Hash_Func(Key);
        if (Hash_Table[Hash_Address] == Key)
        {
            return 1;
        }
        else
        {
            int j = Hash_Address - 1;
            while (j != Hash_Address && Hash_Table[j] != -1)
            {
                if (Hash_Table[j] == Key)
                {
                    cout <<" Found at Location : " << j << endl;
                    return 1;
                }
                j = (j + 1) % 11;
            }
            cout << " Not Found" << endl;
            return -1; 
        }
    }

    void Display_Hash_Table()
    {
        for(int i = 0; i < 11; i++)
        {
            cout << Hash_Table[i] << endl;
        }
    }
};

int main()
{
    Hashing H1;
    H1.Linear_Probing_Without_Replace();
    H1.Linear_Probing_Without_Replace();
    H1.Linear_Probing_Without_Replace();
    H1.Linear_Probing_Without_Replace();
    H1.Linear_Probing_Without_Replace();
    H1.Linear_Probing_Without_Replace();
    H1.Display_Hash_Table();

    int searchKey;
    cout << "Enter Key to search in Hash Table: ";
    cin >> searchKey;
    if (H1.Search_Key(searchKey) == -1)
    {
        cout << "Key not found" << endl;
    }

    return 0;
}
