#include <iostream>
using namespace std;

#define MAXSIZE 100

class Array
{
private:
    int arr[MAXSIZE];
    int size;

public:
    // ConstructoR
    Array()
    {
        size = 0;
    }

    // Read Array
    void readArray()
    {
        cout << "Enter the number of elements: ";
        cin >> size;

        if (size > MAXSIZE)
        {
            cout << "Array size exceeds maximum limit!" << endl;
            size = MAXSIZE;
        }

        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // Insert Element
    void insert(int pos, int value)
    {
        if (size == MAXSIZE)
        {
            cout << "Array is Full!" << endl;
            return;
        }

        if (pos < 0 || pos > size)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        for (int i = size; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos] = value;
        size++;

        cout << "Element Inserted Successfully." << endl;
    }

    // Delete Element
    void deleteElement(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        for (int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << "Element Deleted Successfully." << endl;
    }

    // Search Element
    void search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                cout << "Element found at index " << i << endl;
                return;
            }
        }

        cout << "Element not found." << endl;
    }

    // Display Array
    void display()
    {
        if (size == 0)
        {
            cout << "Array is Empty!" << endl;
            return;
        }

        cout << "Array Elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Sort Array (Ascending Order)
    void sort()
    {
        int temp;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "Array Sorted Successfully." << endl;
    }
};

int main()
{
    Array a;

    int choice, pos, value;

    do
    {
        cout << "\n===== ARRAY ADT MENU =====" << endl;
        cout << "1. Read Array" << endl;
        cout << "2. Insert Element" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Sort Array" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.readArray();
            break;

        case 2:
            cout << "Enter Position (0-based index): ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> value;
            a.insert(pos, value);
            break;

        case 3:
            cout << "Enter Position to Delete (0-based index): ";
            cin >> pos;
            a.deleteElement(pos);
            break;

        case 4:
            cout << "Enter Value to Search: ";
            cin >> value;
            a.search(value);
            break;

        case 5:
            a.display();
            break;

        case 6:
            a.sort();
            break;

        case 7:
            cout << "Program Exited." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
