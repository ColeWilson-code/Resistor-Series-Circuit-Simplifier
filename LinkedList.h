/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    Purpose: create the LinkedList class and the Template helper class
*/

//define header
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


//library inclusions 
#include <iostream>
using namespace std; 


//template to be used with TemplateHelper class
template <typename T>


/*############################################
	Class: ListNode
	Purpose: template helper class to help move through the list
############################################*/
class ListNode
{
    private: 
        //stores data of the template type
        T data;
        
        //holds two pointers to another list node
        ListNode *next; 
        ListNode *previous; 

    public: 
        	
			//constructor 
			ListNode()
			{
				//list empty
				data = NULL; 
			}
			
			//get data at this location 
        	T getData()
        	{
				return data; 
        	}

			ListNode* getNext(){
				return next;
			}

			ListNode* getPrevious(){
				return previous;
			}

		/*
        	//iterate forward and backwards
            //forward 
            void moveForward()
            {
                data = data->next; 
            }

            //backwards 
            void moveBackward()
            {
                data = data->previous; 
            }
		*/

        //set data, next and previous 

            //data
            void setData(T var)
            {
				data = var; 
            }

            //next
            void setNext(ListNode* newNext)
            {
				data->next = newNext; 
            }

            //previous
            void setPrevious(ListNode* newPrevious)
            {
				data->previous = newPrevious; 
            }
}; 


template <typename T> //put this here again cause it got mad when I took it away

/*############################################
	Class: LinkedList
	Purpose: this is our linked list where we chain together our resistors
############################################*/
class LinkedList
{
    private: 

		ListNode<T> *head;		//List head pointer
		ListNode<T> *tail;	    //List tail pointer

    public: 
	
        /*############################################
			Function: constructor 
			Purpose: initialize the list
		#############################################*/ 
        LinkedList()
        {
			//creates an empty list by assigning NULL to head and tail
            head = NULL;
            tail = NULL;
        }

        /*############################################
			Function: destructor 
			Purpose: say goodbye to the resistors 
		#############################################*/
        ~LinkedList()
		{

		}


        /*############################################
			Function: isEmpty
			Purpose: check if the list is empty or not 
		############################################*/
		bool isEmpty(){
            return (head == NULL);
        }

  
		/*############################################
			Function: getLength
			Purpose: find length of list 
		############################################*/
		int getLength(){
            int counter = 0;
			//pointer to traverse list 
	        ListNode<T> *nodePtr;

			//put traversal pointer at head
	        nodePtr = head;
	
	        //list traversal
			//loop while the traversal pointer is not at the tail
	        while(nodePtr != tail)
	        {
		        counter++;
				//update the traversal pointer to point to the next node 
		        nodePtr = nodePtr->next;
				//check if traversal is pointing to tail to make sure last increment happens
		        if (nodePtr == tail)
		    	    counter++;
	        }
	        return counter;
        }

		/*############################################
			Function: appendNode
			Purpose: insert data at the end of the list 
		############################################*/
		void appendNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>(newData);
            //Resistor Values setData
	        newNode->data = newData;

			//setting next and previous to NULL
	        newNode->next = NULL;
	        newNode->previous = NULL;

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL ) 
	        {
				//both head and tail
	        	head = newNode;
	        	tail = newNode;
	        }
	        else  // Otherwise, insert newNode at end.
	        {
		        //set the current last node's next pointer to the new node
	        	tail->next = newNode;
	        	newNode->previous = tail;
		
	        	//now the tail is the new node
	        	tail = newNode;
	        }
        }

		/*############################################
			Function: prependNode
			Purpose: insert data at the beginning of the list 
		############################################*/
		void prependNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>(newData);
            //Resistor Values setData
	        newNode->data = newData;

			//setting next and previous to NULL
	        newNode->next = NULL;
	        newNode->previous = NULL;

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL ) 
	        {
				//both head and tail
	        	head = newNode;
	        	tail = newNode;
	        }
	        else  // Otherwise, insert newNode at end.
	        {
		        //set the current first node's previous pointer to the new node
	        	tail->next = head;
	        	newNode->previous = newNode;
		
	        	//now the tail is the new node
	        	head = newNode;
	        }
        }


		/*############################################
			Function: insertNode
			Purpose: insert the data a specific node 
		############################################*/
		void insertNode(int position, T newData){
	        //traversal pointer
			ListNode<T> *nodePtr;
			//new node pointer
	        ListNode<T> *newNode;
	
	        newNode = new ListNode<T>(newData);
	        newNode->data = newData;
	
	        if(!head)
	        {
	        	if(position != 0)
	        	{
	        		//can't insert node at position (>0) if there is not already a node
	        		cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
	        	}
	        	head = newNode;
	        	tail = newNode;
	        }
	        else
	        {
	        	nodePtr = head;
	        	int nodeCount = 0;
	        	if(position == 0)
	        	{
	        		newNode->next = head;
	        		head->previous = newNode;
	        		head = newNode;
	        	}
	        	while(nodePtr != tail && nodeCount < position)
	        	{
	        		nodeCount++;
	        		if(nodeCount == position)
	        			break;
	        		nodePtr = nodePtr->next;
	        	}
		
	        	//now nodePtr is positioned 1 node BEFORE the node we want to insert
	        	if(nodePtr->next == NULL) //we are appending this node to the end
	        		tail = newNode;

	        	//set up newNode's links
	        	newNode->next = nodePtr->next;
	        	newNode->previous = nodePtr;

	        	//change the node on the left
	        	nodePtr->next = newNode;
		
	        	//change the node on the right (if there is a node on the right)
	        	if(newNode->next)
		        {
		        	nodePtr = newNode->next; 
		        	nodePtr->previous = newNode;
		        }
	        }
        }
		

		/*############################################
			Function: deleteNode
			Purpose: delete the data a node 
		############################################*/
		 void deleteNode(int position){
			ListNode<T> *nodePtr = head;       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				cout << "The list is already empty.\n";
				return;

			// Determine if the first node is the one.
			if (position == 0)
			{
				head = nodePtr->next;
				if(head != NULL){
					head->previous == NULL; //update the previous to NULL because nothing is before it 
				}else{
					tail == NULL; //if list is empty update tail to NULL
				}
				delete nodePtr;
				return;
			}

			else
			{
				//traverse to position passed in argument 
				for(int i = 0; i < position; i++){
					nodePtr = nodePtr->next; //traversing by setting next to nodePtr and then looping
				}

				if(nodePtr->previous != NULL){
					nodePtr->previous_>next = nodePtr->next; //bypasses the current node in the next direction, this hurts my head
				}
				if(nodePtr->next != NULL){
					nodePtr->next->previous = nodePtr->previous; //bypasses the position node in the previous direction, this hurts my head
				}
				if(nodePtr == tail){
					tail = nodePtr->previous; //update tail to be the previous node
				}
				delete nodePtr;
				return;
			}
		}

		/*############################################
			Function: displayList
			Purpose: get all the values in the  list
		#############################################*/
		void displayList() const
		{
			ListNode<T> *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			if(nodePtr == NULL){
				cout << "The list does not contain any elements." << endl;
				return; 
			}

			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->getData() << endl;

				// Move to the next node.
				nodePtr = nodePtr->getNext();
			}
		}

		/*############################################
			Function: getFront
			Purpose: get value at front of list
		#############################################*/
		T getFront()
		{
			
			ListNode<T> *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			//if there is nothing there
			if(nodePtr == NULL)
			{
				cout << "The list does not contain any elements." << endl;
				return; 
			}

			//get the data at the front of the list
			return nodePtr->getData();

		}

		/*############################################
			Function: pop
			Purpose: pop the resistor at the front of list
		#############################################*/
		void pop()
		{
			ListNode<T> *nodePtr;       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
			{
				cout << "\nThe list is already empty.\n";
				return;
			}
				
			//if there is crap there then we do stuff
			head = nodePtr->next;
			
			if(head != NULL)
			{
				head->previous == NULL; //update the previous to NULL because nothing is before it 
			}

			else
			{
				tail == NULL; //if list is empty update tail to NULL
			}

			delete nodePtr;
			return;
				
		}
		
		/*############################################
			Function: StoreResistanceForMerge
			Purpose: put resistance values from linked list into array, sort the array, thereby sorting list values 
		#############################################*/
		void StoreResistanceForMerge(int length) const
		{
			//use getLength function to get size of array
			int listLength; 
			listLength = getLength(); 

			//make an array to hold resistor values
			int* resistors = new int[listLength];
			ListNode<T> *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			if(nodePtr == NULL){
				cout << "The list does not contain any elements." << endl;
				return; 
			}

			int i = 0; 
			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				resistors[i] = nodePtr->resistance;

				// Move to the next node.
				nodePtr = nodePtr->next;

				i++;
			}
			MergeSort(resistors,0, listLength);
			delete [] resistors;
		}


		void MergeSort(int arr[], int beg, int end) {
   			int mid = 0;

   			if (beg < end)  //recursive case (when beg == end then that is base case) 
   			{
				mid = (beg + end) / 2;  // Find the midpoint in the partition

				MergeSort(arr, beg, mid); //recursively sort left partition
				MergeSort(arr, mid + 1, end); //recursively sort right partition

				// Merge left and right partition in sorted order
				Merge(arr, beg, mid, end);
   			}
		}

		void Merge(int arr[], int beg, int mid, int end) {
   			int mergedSize = end - beg + 1;                // Size of merged partition
   			int mergePos = 0;                          // Position to insert merged number
   			int leftPos = 0;                           // Position of elements in left partition
   			int rightPos = 0;                          // Position of elements in right partition
   			int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                              // for merged arr
   
   			leftPos = beg;                               // Initialize left partition position
   			rightPos = mid + 1;                          // Initialize right partition position
   
   			// Add smallest element from left or right partition to merged arr
   			while (leftPos <= mid && rightPos <= end) {
    			if (arr[leftPos] < arr[rightPos]) {
        			mergedNumbers[mergePos] = arr[leftPos];
        			++leftPos;
      			}
      			else {
        			mergedNumbers[mergePos] = arr[rightPos];
        			++rightPos;
      			}
    			++mergePos;
   			}
   
   			// If left partition is not empty, add remaining elements to merged numbers
   			while (leftPos <= mid) {
    			mergedNumbers[mergePos] = arr[leftPos];
    			++leftPos;
    			++mergePos;
			}
   
			// If right partition is not empty, add remaining elements to merged numbers
			while (rightPos <= end) {
    			mergedNumbers[mergePos] = arr[rightPos];
    			++rightPos;
    			++mergePos;
			}
   
			// Copy merge number back to arr
   			for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
    			arr[beg + mergePos] = mergedNumbers[mergePos];
			}

			for(int j = 0; i < mergedSize; i++){
				cout << mergedNumbers[i] << " OHMS " << endl; 
			}
			delete [] mergedNumbers;
		}
		
		/*############################################
		Function: stream operator << 
		Purpose: make outputting easier 
		#############################################*/
        friend ostream& operator << (ostream& os, const LinkedList& L)
        {
            ListNode<T> *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;
			
			while(nodePtr){
				os << nodePtr->getData() << " ";
            	nodePtr = nodePtr->getNext();
			}
			return os;
        }
	
};
#endif 