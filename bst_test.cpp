//
// Created by Karen Axon
// File: p2.cpp
// Date: October 15, 2020
// Purpose: Client program to test the BST template class from BST.h.
// Input: An integer and a string file from the user.
// Process: The data from two files is inserted into an integer BST and a
// string BST. The functionality of the BST is tested. It is assumed that
// numbers 10, 20, 40 and 70 are always in the integers input file and
// "mary lue", "gene", "bea" and "uma" are always in the strings input file.
// Output: Standard output.

#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void displayHello();
// This function displays a message to standard output.
// IN: none
// MODIFY: none
// OUT: Standard output

void displayGoodbye();
// This function displays a message to standard output.
// IN: none
// MODIFY: none
// OUT: Standard output

string getFilename();
// This function takes input from the user.
// IN: A file name
// MODIFY: None
// OUT: Returns the name of the file.

template <typename T>
void populateIntBST(const string&, BST<T> &bst);
// This function opens, read an integer file and inserts the elements into an
// integer BST.
// IN: A string file name and a BST object.
// MODIFY: Opens and closes the file. It inserts the elements into the BST
// object.
// OUT: It modifies the BST object.

template <typename T>
void populateStringBST(const string&, BST<T> &);
// This function opens, read a string file and inserts the elements into a
// string BST.
// IN: A string file name and a BST object.
// MODIFY: Opens and closes the file. It inserts the elements into the BST
// object.
// OUT: It modifies the BST object.

template <typename T>
void displayTestInsert(BST<T> &);
// This function tests the insert functionality of the BST class.
// IN: A BST object
// MODIFY: None
// OUT: Standard output

template <typename T>
void displayTraversals(BST<T> &);
// This function tests the pre order, in order and post order traversal
// functionality of the BST class.
// IN: A BST object
// MODIFY: None
// OUT: Standard output

template <typename T>
void displayAncestors(BST<T> &, T testArr[], int size);
// This function tests the ancestors functionality of the BST
// class. The assumption is that numbers 10, 20, 40 and 70 are always in the
// integers input file and "mary lue", "gene", "bea" and "uma" are always in
// the strings input file. These are hard coded to test the functionality.
// IN: A BST object, an integers array, a size of the array constant
// MODIFY: None
// OUT: Standard output

template <typename T>
void displayContains(BST<T> &, T testArr[], int size);
// This function tests the contains functionality of the BST
// class. The assumption is that numbers 10, 20, 40 and 70 are always in the
// integers input file and "mary lue", "gene", "bea" and "uma" are always in
// the strings input file. These are hard coded to test the functionality.
// IN: A BST object, an integers array, a size of the array constant
// MODIFY: None
// OUT: Standard output

template <typename T>
void displayDelete(BST<T> &, T delArr[], int size);
// This function tests the delete functionality of the BST class. The assumption
// is that numbers 10, 20, 40 and 70 are always in the integers input file
// and "mary lue", "gene", "bea" and "uma" are always in the strings input file.
// These are hard coded to test the functionality.
// IN: A BST object
// MODIFY: None
// OUT: Standard output

int main() {
    string filename;
    const int SIZE = 6;
    const int DEL_SIZE = 3;

    // BST objects
    BST<int> intBST;
    BST<string> strBST;

    // Tests Arrays
    int testInts[SIZE] = {10, 20, 40, 70, 15, -2};
    string testStr[SIZE] = {"mary lue", "gene", "bea", "uma", "luis", "john"};
    int delInts[DEL_SIZE] = {20, 60, 50};
    string delStr[DEL_SIZE] = {"gene", "bea", "uma"};

    displayHello();

    // ** TEST INTEGER BST **
    cout << "\n** CREATE INTEGER BST **" << endl;
    displayTestInsert(intBST);

    // Get user input for the integer file
    cout << "\nEnter the name of the integer file: ";
    filename = getFilename();

    // Insert integers into BST
    populateIntBST(filename, intBST);

    // Display insert test
    displayTestInsert(intBST);

    // Display traversals
    displayTraversals(intBST);

    // Display ancestors
    displayAncestors(intBST, testInts, SIZE);

    // Display contains
    displayContains(intBST, testInts, SIZE);

    // Display delete
    displayDelete(intBST, delInts, DEL_SIZE);
    displayTraversals(intBST);
    //displayTestInsert(intBST);

    // ** TEST STRING BST **
    cout << "\n** CREATE STRING BST **" << endl;
    displayTestInsert(strBST);

    // Get user input for the string file
    cout << "\nEnter the name of the string file: ";
    filename = getFilename();

    // Insert strings into BST
    populateStringBST(filename, strBST);

    // Display insert test
    displayTestInsert(strBST);

    // Display traversals
    displayTraversals(strBST);

    // Display ancestors
    displayAncestors(strBST, testStr, SIZE);

    // Display contains
    displayContains(strBST, testStr, SIZE);

    // Display delete
    //displayDelete(strBST, delStr, DEL_SIZE);
    strBST.remove("gene");
    displayTraversals(strBST);
}

void displayHello() {
    cout << "\nWelcome to the Binary Search Tree (BST) program!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "You will be instructed to enter the name of an\n"
            "integer and a strings file. The data from the\n"
            "files will be used to populate two BSTs. Then\n"
            "stats about the elements in relation to the BST\n"
            "and their positions will be displayed." << endl;
}

void displayGoodbye() {
    cout << "\nThank you for using the Binary Search Tree program. Goodbye!"
         << endl;
}

string getFilename() {
    string filename;

    // Get input from user
    getline(cin, filename);

    return filename;
}

template <typename T>
void populateIntBST(const string& file, BST<T> &bst) {
    string line;        // Captures elements in file
    int num;            // String converted to integer
    ifstream inputFile;

    // Display the elements from the file
    cout << "\nInserting in this order: ";

    // open and read from file
    inputFile.open(file);
    if (inputFile) {
        while (inputFile.peek() != EOF) {
            getline(inputFile,  line);

            // Convert the strings to integers.
            stringstream ss(line);
            do {
                for (int i = 0; i < 1; i++) {
                    ss >> num;
                    // Create nodes for each integers in the BST.
                    bst.insert(num);
                    cout << num << " ";
                }
            } while (ss && ss >> num);
        }
    } else {
        cout << "\nERROR: cannot open " << file << " file.\n";
    }

    inputFile.close();
}

template <typename T>
void populateStringBST(const string& file, BST<T> &bst) {
    string line;        // Captures elements in file
    ifstream inputFile;

    // Display the elements from the file
    cout << "\nInserting in this order: ";

    // open and read from file
    inputFile.open(file);
    if (inputFile) {
        while (inputFile.peek() != EOF) {
            getline(inputFile,  line);
            bst.insert(line);
            cout << line << " ";
        }
    } else
        cout << "\nERROR: cannot open " << file << " file.\n";

    inputFile.close();
}

template<typename T>
void displayTestInsert(BST<T> &obj) {
cout << "# of nodes:   " << obj.size() << endl;
cout << "# of leaves:  " << obj.getLeafCount() << endl;
cout << "tree height:  " << obj.getHeight() << endl;

if(obj.empty())
    cout << "tree empty?   true" << endl;
else
    cout << "tree empty?   false" << endl;
}

template <typename T>
void displayTraversals(BST<T> &obj) {
    cout << "\n** TEST TRAVERSALS **" << endl;
    cout << "pre-order:  " << obj.getPreOrderTraversal() << endl;
    cout << "in-order:   " << obj.getInOrderTraversal() << endl;
    cout << "post-order: " << obj.getPostOrderTraversal() << endl;
}

template <typename T>
void displayAncestors(BST<T> &obj, T testArr[], int size) {
    cout << "\n** TEST ANCESTORS **" << endl;
    cout << "A blank space will display if there are no ancestors."
    << endl;
    for (int i = 0; i < size; i++) {
        cout << "ancestors of " << testArr[i] << ": " <<
            obj.getAncestors(testArr[i]) <<endl;
    }
}

template <typename T>
void displayContains(BST<T> &obj, T testArr[], int size){
    cout << "\n** TEST CONTAINS **" << endl;
    for (int i = 0; i < size; i++) {
        if (obj.contains(testArr[i]) == 1)
            cout << "contains " << testArr[i] << ": true" << endl;
        else
            cout << "contains " << testArr[i] << ": false" << endl;
    }
}

template<typename T>
void displayDelete(BST<T> &obj, T delArr[], int size){
    cout << "\n** TEST DELETE **" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Deleting " << delArr[i] << endl;
        obj.remove(delArr[i]);
    }
}




