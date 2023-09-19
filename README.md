# DataStructures-Heap-

## A program using C++ to build a heap data structure that can efficiently build heap, as well as sort them according to frequency. 

## Problem Statement:
Suppose you're working on a large-scale e-commerce platform, where a lot of users are simultaneously searching for products. 
One crucial component of your platform is the recommendation engine, which suggests products to users based on their search history. For this system, you are assigned a task to develop a program that arrange the products according to their search frequency. For this program, you need to use a heap data structure that keeps track of the product searched frequently.

The working of system is as follows:

Whenever a user searches for a product, their search history is incremented by 1 and added to a heap. The heap is sorted by the frequency of the product's searches. Products with more searches appear higher up in the heap.
Suppose we have following products, with their current frequencies of searches,

P1 =15, P2=14, P3=13, P4= 10, P5= 16, P6=9, P7= 12

You have to perform following operations,
    • Build a heap of the above products by the frequency of the product's searches (save both product name and frequency).
    • When a user searches a product, the frequency will increment by 1 and show the updated heap.
    • Show the top product with maximum search history along with frequency without removing it.
To implement this use case, you'll need to use C++ to build a heap data structure that can efficiently build heap, as well as sort them according to frequency. 

## Important Instructions:
You need to fulfill the following requirement while solving the assignment task. 
    1. For the construction of heap use only class, the use of struct will be considered an invalid solution.   
Hint: The structure of classes which you need to create in the required program is given below. 
![image](https://github.com/amna-rahman/DataStructures-Heap-/assets/109412864/e7aaa52e-8b9b-4558-ad7a-29776c662456)

## Sample Output:
![image](https://github.com/amna-rahman/DataStructures-Heap-/assets/109412864/95d80353-1036-4b49-97a9-1dc19804b30f)


![image](https://github.com/amna-rahman/DataStructures-Heap-/assets/109412864/a35a8619-5df4-488f-ba1d-431666c364f1)
