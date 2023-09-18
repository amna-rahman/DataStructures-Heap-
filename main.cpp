//bc220406761

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class representing a product
class Product {
private:
    string name;        // Name of the product
    int frequency;      // Frequency or number of times the product has been searched

public:
    // Default constructor
    Product() : name(""), frequency(0) {}

    // Parameterized constructor
    Product(const string& productName, int productFrequency) : name(productName), frequency(productFrequency) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter for frequency
    int getFrequency() const {
        return frequency;
    }

    // Increment the frequency of the product by 1
    void incrementFrequency() {
        frequency++;
    }
};

// Class representing a Heap
class Heap {
private:
    int currentSize;            // Current number of elements in the heap
    int capacity;               // Maximum capacity of the heap
    vector<Product> array;      // Array to store the elements of the heap

    // Helper function to percolate down an element in the heap
    void percolateDown(int hole) {
        int child;
        Product tmp = array[hole];

        for (; hole * 2 <= currentSize; hole = child) {
            child = hole * 2;
            if (child != currentSize && array[child + 1].getFrequency() > array[child].getFrequency())
                child++;
            if (array[child].getFrequency() > tmp.getFrequency())
                array[hole] = array[child];
            else
                break;
        }

        array[hole] = tmp;
    }

public:
    // Constructor to initialize the heap with a given size
    Heap(int size) {
        currentSize = 0;
        capacity = size;
        array.resize(capacity + 1);
    }

    // Build the heap by percolating down all non-leaf nodes
    void buildHeap() {
        for (int i = currentSize / 2; i > 0; i--)
            percolateDown(i);
    }

    // Update the frequency of a product in the heap
    void updateFrequency(const string& productName) {
        for (int i = 1; i <= currentSize; i++) {
            if (array[i].getName() == productName) {
                array[i].incrementFrequency();
                percolateDown(i);
                cout << "Frequency updated successfully." << endl;
                return;
            }
        }

        cout << "Product not found." << endl;
    }

    // Display the products in the heap
    void traverse() {
        for (int i = 1; i <= currentSize; i++) {
            cout << array[i].getName() << " (" << array[i].getFrequency() << ") ";
            if (i != currentSize)
                cout << ", ";
        }
        cout << endl;
    }

    // Get the product with the highest frequency (top of the heap)
    Product getMax() const {
        if (currentSize > 0)
            return array[1];
        else
            return Product();
    }

    // Check if the heap is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Check if the heap is full
    bool isFull() const {
        return currentSize == capacity;
    }

    // Insert a product into the heap
    void insert(const Product& product) {
        if (isFull()) {
            cout << "Heap is full. Cannot insert more products." << endl;
            return;
        }

        int hole = ++currentSize;

        for (; hole > 1 && product.getFrequency() > array[hole / 2].getFrequency(); hole /= 2)
            array[hole] = array[hole / 2];

        array[hole] = product;
    }
};

// Main function
int main() {
    Heap heap(10);
    Product p1("P1", 15);
    Product p2("P2", 14);
    Product p3("P3", 13);
    Product p4("P4", 10);
    Product p5("P5", 16);
    Product p6("P6", 9);
    Product p7("P7", 12);

    // Insert products into the heap
    heap.insert(p1);
    heap.insert(p2);
    heap.insert(p3);
    heap.insert(p4);
    heap.insert(p5);
    heap.insert(p6);
    heap.insert(p7);

    // Display the current products with their frequencies
    cout << "Current Products with their frequencies" << endl;
    cout << "P1 = " << p1.getFrequency() << ", P2 = " << p2.getFrequency() << ", P3 = " << p3.getFrequency()
         << ", P4 = " << p4.getFrequency() << ", P5 = " << p5.getFrequency() << ", P6 = " << p6.getFrequency()
         << ", P7 = " << p7.getFrequency() << endl;
         int choice;
    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "Enter 1 to create Heap" << endl;
        cout << "Enter 2 to search for a product and update its frequency" << endl;
        cout << "Enter 3 to see the product with the highest frequency" << endl;
        cout << "Enter 0 to terminate the program" << endl;
        cin >> choice;

        if (choice == 1) {
            heap.buildHeap();
            cout << "Heap Created: ";
            heap.traverse();
        } else if (choice == 2) {
            string productName;
            cout << "Enter the product you want to search or type 'No' to exit: ";
            cin >> productName;

            if (productName == "No")
                break;

            heap.updateFrequency(productName);
            heap.buildHeap();
            cout << "Updated Heap: ";
            heap.traverse();
        } else if (choice == 3) {
            if (!heap.isEmpty()) {
                Product topProduct = heap.getMax();
                cout << "Top product: " << topProduct.getName() << " (" << topProduct.getFrequency() << ")" << endl;
            } else {
                cout << "No products in the heap." << endl;
            }
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}



