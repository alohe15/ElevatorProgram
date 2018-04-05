# ElevatorProgramC++
PROBLEM STATEMENT:
We are going to develop an algorithm and implement in C++ to simulate a single elevator in a 10-story building.  There will be some simplifying assumptions that will make this a bit less complex than a real-world implementation.  The number of floors is not important, nor is the number of people getting on or getting off the elevator.  The following rules apply to movement of the elevator:
By default, the elevator will always begin to operate from the 1st floor.
The algorithm needs to support the 2 separate directions of up and down.
The algorithm needs to support the 2 separate requirements of “get on” and “get off”.
Wherever the elevator happens to be, it always continues in the same direction, unless there are no passengers and no people waiting for the elevator with “get on” requests.
When the elevator stops moving in one direction, it checks to see if there are additional “get on” requests.  The elevator does not move again until it receives a request to move.
Once the elevator starts to move, there can be no “get on” requests until the elevator has stopped and has no more pickups or drop-offs in the same direction.  In other words, the elevator does not move in the opposite direction until you receive a request to move.

The approach to simulating the elevator is as follows:

The events that you will need to simulate are described below.  The 2 event types are ‘GET ON’ and ‘MOVE.   Since they are fixed by me, you can populate them into an array if you like.  Each event can have a maximum of 3 pieces of information, as described by #2.
‘GET ON’ has 2 parameters:  the number of the floor on which a person or persons will enter the elevator and the number of the floor on which the person(s) will get off.  ‘MOVE’ has no parameters but you can assign 2 parameters with values of zeros so that the 2 events are parallel.
Implement the elevator as a doubly-linked list.  When the elevator is moving up, it follows from the head to determine where to go to next.  When it is moving down, it follows from the tail backwards.
When there are no more nodes in the same direction as the elevator is moving, it checks the array for its next requests and either moves or adds “get on” requests.  It then continues to move in the same direction it was moving, if there are now requests for that direction, or it reverses direction to pick up people.  If the entire list is empty, it returns to the 1st floor to wait.
The doubly-linked list nodes need to contain two items of information: a primary floor number to stop at and, for an arriving passenger, a secondary floor number representing the “get off”.  You cannot add the “get off” as a node until the passenger has gotten on.  Otherwise, you may try to discharge a passenger who is not yet on the elevator.
To summarize, when you pick up a ‘GET ON’ request, add it to the list, along with the ‘get off’, as an additional parameter.  When the ‘GET ON’ is satisfied, you remove its node and add the ‘get off’ node.
 

EVENT LIST

 

GET ON 4,6                         (means a person wants to get on at 4 and get off at 6)

MOVE                                  

GET ON 8,2

GET ON 1,5

GET ON 9,3

MOVE

GET ON  10,2

GET ON 7,4

MOVE

GET ON 1,7

MOVE

 

NOTE:  “MOVE” makes the elevator move(a) in the same direction if there are requests, (b) in the opposite direction if there are requests or (c) down to 1 if there are no requests in the list.

The output from this program should identify each of the elevator stops and whether people get off, get on, or both.  You should produce output when you encounter a MOVE instruction.  In other words, there should be 4 separate outputs, each identifying a set of floors and “get on” or “get off” actions.

