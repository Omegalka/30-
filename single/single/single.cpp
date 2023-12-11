#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class SinglyLinkedList
{
public:
    struct Node
    {
        int data = 0;
        Node* next = nullptr;
    };

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    void AddToHead(int data)
    {
        Node* newElem = new Node();
        newElem->data = data;
        newElem->next = head;
        if (head == nullptr)
        {
            tail = newElem;
        }
        head = newElem;
        count++;
    }

    void AddToTail(int data)
    {
        Node* newElem = new Node();
        newElem->data = data;
        if (tail == nullptr)
        {
            head = newElem;
        }
        else
        {
            tail->next = newElem;
        }
        tail = newElem;
        count++;
    }

    void InsertInto(int data, int position)
    {
        if (position >= count)
        {
            AddToTail(data);
            return;
        }
        else if (position <= 0)
        {
            AddToHead(data);
            return;
        }

        Node* newElem = new Node();
        newElem->data = data;
        int i = 1;
        Node* beforeNew = head;
        while (i++ != position)
        {
            beforeNew = beforeNew->next;
        }
        newElem->next = beforeNew->next;
        beforeNew->next = newElem;

        count++;
    }

    void DeleteFromHead()
    {
        if (count == 0)
        {
            // cout << "Empty list!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void DeleteFromTail()
    {
        if (count == 0) {
            // cout << "Empty list!\n";
            return;
        }
        DeleteByIndex(count - 1);
    }

    void DeleteByIndex(int position)
    {
        if (position <= 0)
        {
            DeleteFromHead();
            return;
        }

        if (position >= count)
        {
            position = count - 1;
        }

        int i = 1;
        Node* beforeDel = head;
        while (i++ != position)
        {
            beforeDel = beforeDel->next;
        }
        Node* sacrifice = beforeDel->next;
        beforeDel->next = sacrifice->next;
        delete sacrifice;
        count--;
        if (beforeDel->next == nullptr)
        {
            tail = beforeDel;
        }
    }

    void Clear()
    {
        while (head != nullptr)
        {
            DeleteFromHead();
        }
    }

    void Print() const
    {
        if (count == 0)
        {
            cout << "Empty list!\n";
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int GetCount() const
    {
        return count;
    }

    int IndexOf(int data) const
    {
        if (count == 0)
        {
            // cout << "Empty list!\n";
            return -1;
        }
        Node* temp = head;
        int i = 0;
        while (i < count)
        {
            if (data == temp->data)
            {
                return i;
            }
            i++;
            temp = temp->next;
        }

        return -1;
    }

    bool IsEmpty() const
    {
        return count == 0;
    }

    int LastIndexOf(int value) const
    {
        if (count == 0)
            return -1;

        Node* current = head;
        int lastIndex = -1;
        int currentIndex = 0;

        while (current != nullptr)
        {
            if (current->data == value)
                lastIndex = currentIndex;

            current = current->next;
            currentIndex++;
        }

        return lastIndex;
    }

    void Reverse()
    {
        if (count <= 1)
            return;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void SortAsc()
    {
        if (count <= 1)
            return;

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr)
        {
            index = current->next;

            while (index != nullptr)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }

                index = index->next;
            }

            current = current->next;
        }
    }

    void Shuffle()
    {
        if (count <= 1)
            return;

        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = count - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);

            // Swap elements at i and j
            Node* node_i = GetNodeAt(i);
            Node* node_j = GetNodeAt(j);

            int temp = node_i->data;
            node_i->data = node_j->data;
            node_j->data = temp;
        }
    }

    int* ToArray() const
    {
        if (count == 0)
            return nullptr;

        int* arr = new int[count];
        Node* current = head;
        int i = 0;

        while (current != nullptr)
        {
            arr[i++] = current->data;
            current = current->next;
        }

        return arr;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= count)
        {
            cout << "Index out of bounds!\n";
            exit(EXIT_FAILURE);
        }

        Node* current = GetNodeAt(index);
        return current->data;
    }

    friend ostream& operator<<(ostream& os, const SinglyLinkedList& list)
    {
        if (list.count == 0)
        {
            os << "Empty list!\n";
            return os;
        }

        Node* current = list.head;
        while (current != nullptr)
        {
            os << current->data << " ";
            current = current->next;
        }

        return os;
    }

private:
    Node* GetNodeAt(int index) const
    {
        if (index < 0 || index >= count)
        {
            cout << "out of bounds\n";
        }
        Node*
    }
};

int main()
{
    SinglyLinkedList sll;

    sll.AddToTail(10);
    sll.AddToTail(20);
    sll.AddToTail(30);
    sll.AddToTail(40);
    sll.Print();

    sll.AddToHead(50);
    sll.AddToHead(60);
    sll.AddToHead(70);
    sll.AddToHead(80);
    sll.Print();

    cout << "count: " << sll.GetCount() << "\n";
    cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";

    sll.InsertInto(-1, -1);
    sll.Print();
    sll.InsertInto(3, 3);
    sll.Print();
    sll.InsertInto(44, 44);
    sll.Print();

    sll.DeleteFromHead();
    sll.DeleteFromHead();
    sll.DeleteFromHead();
    sll.Print();

    sll.DeleteFromTail();
    sll.DeleteFromTail();
    sll.DeleteFromTail();
    sll.Print();

    sll.DeleteByIndex(0);
    sll.DeleteByIndex(1);
    sll.DeleteByIndex(2);
    sll.Print();

    sll.Clear();
    sll.Print();

    cout << "Is Empty: " << (sll.IsEmpty() ? "true" : "false") << "\n";

    sll.AddToTail(10);
    sll.AddToTail(20);
    sll.AddToTail(30);
    sll.AddToTail(20);
    sll.AddToTail(40);
    sll.Print();

    cout << "Last Index of 20: " << sll.LastIndexOf(20) << "\n";

    sll.Reverse();
    cout << "Reverse: ";
    sll.Print();

    sll.SortAsc();
    cout << "Sort: ";
    sll.Print();

    sll.Shuffle();
    cout << "Shuffle: ";
    sll.Print();

    int* arr = sll.ToArray();
    cout << "Array: ";
    for (int i = 0; i < sll.GetCount(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";


    sll[1] = 100;
    cout << "value at index 1: ";
    sll.Print();

    cout << "List: " << sll << "\n";
}

