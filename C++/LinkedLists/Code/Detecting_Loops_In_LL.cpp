/* So this is a function which can be worked under the conditions where we want to detect some loops..
    For example - Here's a linked list 
                                            2 -> 3 -> 4 -> 7 -> 11 -> NULL      As you can see there is no any cycle in it
            Let's consider this list...     4 -> 1 -> 7 -> 9 -> 3 -> 76         Here it has a cycle because 76 is pointing to 1
                                                  |_ _ _ _ _ _ _ _ _ _ |    
        It has time complexity as n
        It has space complexity as n                         
*/

#include<iostream>
#include<map>
using namespace std;

// Node must have to be created;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};



// Our Detect Cycle and Removal function in action
bool Detect_Cycle(Node* head){
    // checks for empty list
    if (head == NULL){
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;

    while(temp != NULL){

        //cycle is present
        if (visited[temp] == true){
            cout<<"Cycle present on element "<<temp -> data<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

//  Floyd Cycle Detection -> This is an algorithm which also helps us to detect the loops in a Linked List.
// There are two pointers working in it..One is slow which moves one pointer ahead and other is fast which moves 2 pointers
// ahead...The idea is simple if slow and fast met each other that means there is a loop in the List
//
// Time Complexity is n...whereas space complexity is 1

Node* floydDetect(Node* &head){
    
    // checking for empty list
    if (head == NULL){
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if (fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if (slow == fast){
            cout<<"Present at "<<slow -> data<<endl;
            return slow;
        }
    }
    return NULL;
}

// This function will give us the starting node of the loop if present...
// Algorithm and Thinking behind it - first we will be applying the same algorithm of floyd detection cycle..when both slow
// and fast will meet each other..we will keep fast at the same position and shift slow back to head...Then we will make
// both slow and fast with same pace of 1 per step...Try it with examples..it will always work

Node* StartingNode(Node* &head){

    // checking for empty list..
    if (head == NULL){
        return NULL;
    }

    // checking whether the loop is present in the List or not
    if (Detect_Cycle(head)){
        Node* intersection = floydDetect(head);
        Node* slow = head;

        while(slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }
        return slow;
    }
    else{
        cout<<"List doesn't have any loops"<<endl;
        return NULL;
    }
}

// This function will remove any loop present in it..
// The algorithm behind is about finding the previous node from where the loop started and making it NULL..

void removeLoop(Node* &head){
    // checking whether the list is empty or not
    if (head == NULL){
        return;
    }
    Node* StartofLoop = StartingNode(head);
    Node* temp = StartofLoop;

    while(temp -> next != StartofLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    
    return 0;
}