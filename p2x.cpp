/*
 * Name     : Dinh Tran
 * File Name: p2x.cpp
 * Date     : Feb 24, 2019
 * Purpose  : This program will take the input file with each line is
 *            line of the file contains one char and one nonnegative
 *            integer. Then organizing the characters in the proper
 *            order with The integer indicates the position of the
 *            character within the message. Then return the secret
 *            message in the file. After that ask if user want to do
 *            it again with another file.
 * Input    : A file with each line of the file contains one char
 *            and one nonnegative integer.
 * Process  : Read the file line by line then add to the linked list
 *            in order increasing of integer that appear in the end
 *            of each line. Close the file. Then print out the first
 *            character that appear on the first line in order of
 *            the linked list. Then ask if the user want to use the
 *            program again if yes run again if no then end the program
 *            with the message.
 *
 * Output   : The secret message in the file.
 */


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
 * The structure of node of the linked list
 */
struct Node {
  string data;
  Node * next;
};

void addInOrder(Node *&h, string d);
/*
 * This function will adds integer read from the each line of the file
 * to the linked list in increasing order
 *
 * Input : Linked list and value
 * Modify: create and assign the node with the value then linked the list
 * Out   : and updated linked list
 */

void printList (Node *);
/*
 * Print the complete list (on the same line) to the screen.
 *
 * Input  : Linked list
 * Modify : node
 * Output : print out the first character of each node of linked list
 */

void deleteList(Node *&);

/*
 * Deletes all the node in the linked list
 *
 * Input  : Linked list
 * Modify : Deleting all the node
 * Out    : empty linked list
 */

void merge (Node *&, Node *&, Node *&);

int main() {

  // constant yes, no answer
  const string YES = "y";
  const string NO = "n";

  // file variable
  ifstream file;

  // file value (string)
  string value;

  // file name (change while repeat)
  string fileName1, fileName2;

  // answer variable
  string answer = "y";

  // welcome message
  cout <<"\nWelCome to the Secret Messages program."
       <<" This program will take the file with the secret message.\n"
       <<"then decoded to find out the message." << endl;

  // head of linked list 1 and head of list 2
  Node * headList1 = nullptr;
  Node * headList2 = nullptr;
  Node * headMerge = nullptr;

  // when the answer is yes then continue the loop if answer is no
  // then break the loop
  while (answer == "y") {

    // get file name
    cout <<"\nEnter the fileName 1: ";
    cin >> fileName1;
    cout << endl;

    // open file 1
    file.open(fileName1);

    // read file
    if (file) {
      while (getline (file, value)) {
        addInOrder(headList1, value);
      }
    } else {
      cout << "File can not open \n" << endl;
    }
    // close file 1
    file.close();



    // file 2
    cout <<"\nEnter the fileName 2: ";
    cin >> fileName2;
    cout << endl;
    // open file 2
    file.open(fileName2);

    // read file
    if (file) {
      while (getline (file, value)) {
        addInOrder(headList2, value);
      }
    } else {
      cout << "File can not open \n" << endl;
    }
    // close file 2
    file.close();

    merge(headList1, headList2, headMerge);
    // print out the secret message
    cout << "\nSecret message of file 1: \n" << endl;
    printList (headList1);

    cout << "\nSecret message of file 2: \n" << endl;
    printList (headList2);


    cout << " merge: \n" << endl;
    printList (headMerge);
    // delete list
    deleteList (headList1);

    // delete list
    deleteList (headList2);

    // asked if user what to try again if user answer no
    // then break the loop
    cout << "\nTry again (y or n)?: ";
    cin >> answer;

    cout << endl;
  }

  // print out the thank you message.
  cout << "\nThank you for using the program! \n";

}

void merge (Node *&headList1, Node *&headList2, Node *&headMerge) {
  const string SPACE = "";
//  Node * list2 = headList2;
  Node * helper = nullptr;
  Node * currList = headList1;
  headMerge = currList;
  bool list1 = true;
  while (headList1 != nullptr && headList2 != nullptr) {
    cout <<" in the loop" << endl;
    if (headList1 -> data.substr(0,1) == SPACE ){
      cout << "check 1" << endl;
      list1 = false;
      currList = headList2;

    } else if (headList2 -> data.substr(0,1) == SPACE) {
      cout << "check 2" << endl;
      list1 = true;
      currList = headList1;

    } else {
      if (list1 == true){
        helper = currList;
        currList = currList -> next;
        headList1 = headList1 -> next;
      } else {
        helper = currList;
        currList = currList -> next;
        headList2 = headList2 -> next;
      }


    }

//    if (headList1 -> data.substr(0,1) == SPACE) {
//      helper = headList1;
//      headList1 = headList1 -> next;
//      helper -> next = headList2;
//    } else {
//      helper = headList1;
//      headList1 = headList1 -> next;
//      helper -> next = headList1;
//    }
//
//    if (headList1 -> data.substr(0,1) == SPACE) {
//      helper = headList2;
//      headList1 = headList2 -> next;
//      helper -> next = headList1;
//    } else {
//      helper = headList2;
//      headList1 = headList2 -> next;
//      helper -> next = headList2;
//    }
//
//

  }
}



//    if (list1 -> data.substr(0,1) == SPACE){
//      cout << " this is data list 1: "  << list1 -> data << endl;
//      helper = list2;
//      cout << " this is helper: " << helper << " ," << list1 << endl;
//
//    } else if (list2 -> data.substr(0,1) == SPACE ){
//      cout << " this is data list 1: " << list2 -> data << endl;
//      helper = list1;
//
//      cout << " this is helper: " << helper << " ," << list1 << endl;
//
//    } else {
//      if (helper -> data.substr(0,1) == list1 -> data.substr(0,1)) {
//        cout << " this is data list 1: " << list1 << endl;
//
//        curr -> data = helper -> data;
//        helper = helper -> next;
//        curr = curr -> next;
//        list1 = list1 -> next;
//
//      } else {
//        cout << " this is data list 2: " << list1 << endl;
//        list2 = list2 -> next;
//        curr -> data = helper -> data;
//        helper = helper -> next;
//        curr = curr -> next;
//      }
//    }
//  }

void printList (Node *h) {
  // create helper node
  Node * helper = h;

  // loop through and print the first character in the data
  while (helper != nullptr) {
    cout << helper -> data.substr(0,1) << "" ;
    helper = helper -> next;
  }
  cout << "\n" << endl;
}

void addInOrder (Node *&h, string d) {

   // create a new node and set data
  Node * newNode = new Node;
  newNode -> data = d;

  // if list is empty, assign new Node to head;
  // else, find where to add in ( non-descending) order;
  if (h == nullptr) {
    h = newNode;
    newNode -> next = nullptr;

  } else {
    Node * prev = nullptr;
    Node * curr = h;

    // find location base on the integer of the en of each line
    // of the node to add in order increasing
    while (curr != nullptr &&
        stoi(curr -> data.substr(1)) < stoi(d.substr(1))) {
      prev = curr;
      curr = curr -> next;
    }

    // if prev is nullptr, then we are adding to the beginning;
    // of the list, else, appending to end or between two existing Node;
    if (prev == nullptr) {
      h = newNode;
      newNode -> next = curr;

    } else {
      prev -> next = newNode;
      newNode -> next = curr;
    }
  }
}

void deleteList (Node *&h) {
  Node * helper;

  while (h != nullptr) {
    helper = h;
    h = h -> next;
    delete helper;
  }
}
