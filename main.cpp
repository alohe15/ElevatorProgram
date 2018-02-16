#include <iostream>
using namespace std;

class floor {
private:
    int flrNum; //floor where the person gets on
    int getOff; // floor where the person is going to get off
    floor* next;
    floor* prev;
    bool isvisited; //keeps track of whether a floor has been visited or not
    friend class List;
};

class List { //linked list class
private:
    floor* head;
    floor* tail;
public:
    List()
    {
        head = new floor;
        tail = new floor;
        head->prev = NULL;
        tail->next = NULL;
        head->next = tail;
        tail->prev = head;
        head->flrNum = 0;
        tail->flrNum = 11;// 11 is upper sentinel
        head->isvisited = false;
        tail->isvisited = false;
    }


    void getOn(int on,int off) { //builds the list of requests in ascending order
        floor *temp = new floor;
        floor *temp2 = head;

        //temp will store the integers we want to insert
        temp->flrNum = on;
        temp->getOff = off;

        //Updating temp2 to the right place
        while(temp->flrNum > temp2->flrNum) {
            temp2 = temp2->next;
        }

        //Linking temp in, temp2 tells us where to link it in
        temp->next = temp2;
        temp->prev = temp2->prev;
        temp2->prev->next = temp;
        temp2->prev = temp;
    }

    //Function to visit the floor and print
    void visit(floor* f)
    {
        if(f->getOff == 0) //if the floor is a get off floor
        {
            cout << "Get off at " << f->flrNum << "th floor" << endl;
        }
        else{ //if the floor is a get on floor
            cout << "Get on at " << f->flrNum << "th floor" << endl;
        }

        f->isvisited = true; //mark the floor as visited
    }

    void move() //traverse the floors while updating the list to include get off requests
    {
        floor* elevator = head->next; //setting elevator to the first floor

        //first loop to move up the list, and print out the get on and get off floors which occur in order
        while(elevator != tail)
        {
            if(elevator->getOff != 0)
            {
               visit(elevator);
                getOn(elevator->getOff, 0);
                elevator = elevator->next;
            }
            else
            {
                visit(elevator);
                elevator = elevator->next;
            }

        }

        //second loop to move down the list and print out the rest of the get off floors
        while(elevator != head)
        {
            if(elevator->getOff == 0 && elevator->isvisited == false)
            {
                visit(elevator);
                elevator = elevator->prev;
            }
            else
            {
                elevator = elevator->prev;
            }
        }
    }

};

int main()
{

    List* lst = new List; // List
    (*lst).getOn(8,2);
    (*lst).getOn(1,5);
    (*lst).getOn(9,3);
    (*lst).move();
    delete lst;
    return 0;
}
