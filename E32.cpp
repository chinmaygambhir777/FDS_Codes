/*Name: Anuj Gholve
Class: SE2
Roll Number: 77
PRN Number: F24122007

Problem Statement
Pizza parlor accepting maximum M orders. Orders are
served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the
system using circular queue using array
*/

#include <iostream>
using namespace std;

#define SIZE 5

class Pizza {
    int porder[SIZE];
    int front, rear;

public:
    Pizza() {
        front = rear = -1;
    }

    int qfull() {
        return front == (rear + 1) % SIZE;
    }

    int qempty() {
        return front == -1;
    }

    void accept_order(int item) {
        if (qfull()) {
            cout << "\nVery Sorry !!!! No more orders. ... \n";
        } else {
            if (front == -1) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % SIZE;
            }
            porder[rear] = item;
        }
    }

    void serve_order() {
        if (qempty()) {
            cout << "\nSorry !!! order is not there. \n";
        } else {
            //cout << "\nOrder served";
            
                int item = porder[front];
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % SIZE;
                }
                cout << "Order served successfully! Order ID: " << item << endl;
            
            //cout << "\nTotal amount to pay: " << 100;
            cout << "\nThank you, visit again...\n";
        }
    }

    void order_in_queue() {
        if (qempty()) {
            cout << "\nSorry !! There is no pending order...\n";
        } else {
            cout << "\nFollowing orders are to deliver...\n";
            int temp = front;
            while (temp != rear) {
                cout << "\t" << porder[temp];
                temp = (temp + 1) % SIZE;
            }
            cout << "\t" << porder[temp];
        }
    }
};

int main() {
    Pizza p1;
    int ch, k;

    do {
        cout << "\n\t***** Welcome To Pizza Parlor *******\n";
        cout << "\n1. Accept order\n2. Serve Order\n3. Pending Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nWhich Pizza would you like to have today?\n";
                cout << "1. Veg Soya Pizza\n2. Veg Butter Pizza\n3. Egg Pizza\n";
                cout << "Please enter your order: ";
                cin >> k;
                p1.accept_order(k);
                break;

            case 2:
                            
                p1.serve_order();
                break;

            case 3:
                
                p1.order_in_queue();
                break;

            case 4:
                cout << "\nEnd of program\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
                break;
        }
    } while (ch != 4);

    return 0;
}
