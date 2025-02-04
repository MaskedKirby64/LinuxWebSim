#include <iostream>
#include <stdexcept>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
  m_data = data;
  m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
  return m_data;
}


//Sets the data in a Node
template <class T>
void Node<T>::SetData(const T& data ) {
  m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
  return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
  m_next = next;
}

//**********Stack Class Declaration***********
template <typename T> //Indicates linked list is templated
class Stack {
public:
  // Name: Stack (Default constructor)
  // Description: Creates a new Stack object
  // Preconditions: None
  // Postconditions: Creates a new Stack object
  Stack(){
	 m_size = 0;
  	 m_top = nullptr;
  
  }
  // Name: ~Stack
  // Description: Stack destructor - deallocates all nodes in linked list
  // Preconditions: None
  // Postconditions: All nodes are deleted. Size is 0. No memory leaks.
  ~Stack(){
	
	 while(m_top != nullptr){
		T var = Pop();
		delete var;
	}

  	m_top = nullptr;
  
  }
  // Name: Stack (Copy constructor)
  // Description: Creates a new Stack object based on existing stack
  // Preconditions: None
  // Postconditions: Creates a new Stack object from existing stack
  //                 in separate memory space
  Stack(const Stack& source){
  	Node<T> * curr = source.m_top;
  	while(curr->GetNext() != nullptr){
	      Push(curr->GetData());
	      curr = curr->GetNext();
	}
  
  }
  // Name: Stack<T>& operator= (Assignment operator)
  // Description: Makes two stacks identical based on source.
  // Preconditions: None
  // Postconditions: Two stacks with same number of nodes and same values
  //                 in each node in a separate memory space
  Stack<T>& operator=(const Stack& other){
  	
	if(this != &other){
		if(!IsEmpty()){ //checking left hand stack
			for(size_t i = 0; i<m_size; i++){
                		if( m_top != nullptr){
                        		Pop();
                  		}
        		}	
				
		}	
        	
		Node<T> * curr = other.m_top;
		while(curr->GetNext() != nullptr){
			Push(curr->GetData());	
			curr = curr->GetNext();
		}
          
	    }
 
		
 
		return *this;
	}
  
  // Name: Push
  // Description: Adds a new node to the top of the stack
  // Preconditions: None
  // Postconditions: Adds a new node to the top of the stack
  void Push(const T& value){
  	  
	  Node<T> * newNode = new Node<T>(value);

          if(IsEmpty()){
	      	m_top = newNode;
	  }

	  else{
  	          newNode->SetNext(m_top);
		  m_top = newNode;

    	  }	
	       m_size++;
  }
  // Name: Pop
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Temporarily stores data from node at the top of the stack.
  //              Removes the node from the top of the stack. Returns the stored data.
  // Preconditions: Stack has at least one node
  // Postconditions: See description 
  T Pop(){
  	if(m_size == 0){
		throw runtime_error("Stack is empty");
	}
  	
	else if(m_top->GetNext() == nullptr){
		Node<T> * curr = m_top;
		T data = curr->GetData();
		delete m_top;
		m_top = nullptr;	
		m_size = 0;
		return data;
			
	}
	else{
	
		
		Node<T> * curr = m_top;
		T data = curr->GetData();
		Node<T> * newTop = m_top->GetNext();
		delete m_top;
		m_top = newTop;
		m_size--;
		return data;
	}
  }
  // Name: Peek
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Returns the stored data from top node.
  // Preconditions: Stack has at least one node
  // Postconditions: See description
  T Peek() const{
  
	if(m_size == 0){
		throw runtime_error("Stack is empty");
		
	}
	else{
 		return m_top; 	
  	}
  
 
  }
  // Name: At
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Returns stored data from number of the node passed to function.
  //              At(3) would return the data from the fourth node.
  // Preconditions: Stack has at least one node
  // Postconditions: Returns data from number of node starting at m_top
  T At(int num){
  	if(m_size == 0){
		throw runtime_error("Stack is empty");
	}
	
  if(num == 0){
    return m_top->GetData();
  }
  
  else{
    int i = 0;
    Node <T> * m_curr = m_top;
		while(i < num){
      m_curr = m_curr->GetNext();		
      i+=1;
    }

	
    return m_curr->GetData();
	  
  }
  	
 }
  // Name: IsEmpty
  // Description: Returns if the stack has any nodes.
  // Preconditions: Stack has at least one node
  // Postconditions: If stack has no nodes, returns true. Else false.
  bool IsEmpty() const{
  
  	if(m_size == 0){
		return true;
	
	}
  	else{
		return false;
		
	}
  
  
  }
  // Name: RemoveBottom
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Temporarily stores data from node at the bottom of the stack.
  //              Removes node from bottom of the stack. Returns the stored data.
  //              Similar to Pop but opposite end of stack
  // Preconditions: Stack has at least one node
  // Postconditions: Removes node from bottom of stack and returns data
  T RemoveBottom(){
  	if(m_size ==0){
		throw runtime_error("Stack is empty");
	
	}
  	else{
		
		Node<T> * curr = m_top;
		int i = 0;
		while(i<m_size){
			curr = curr->GetNext();
			i++;
		}
	
		T value = curr->GetData();
		delete curr;
		curr = nullptr;
		return value;
	}
  
  
  }
  // Name: Display
  // Description: If stack is empty, outputs that the stack is empty
  //              Otherwise, iterates through stack and displays data in each node
  // Preconditions: Stack has at least one node
  // Postconditions: Displays data from each node in stack
  void Display(){
  	if(m_size == 0){
		cout<<"The stack is empty"<<endl;
	}
  
  	else{
		
		Node<T> * curr = m_top;
		while(curr!=nullptr){
			cout<<curr->GetData()<<endl;
			curr = curr->GetNext();
		}
	
	}
  }
  // Name: GetSize
  // Description: Returns the number of nodes in the stack
  // Preconditions: None
  // Postconditions: Returns the number of nodes in the stack.
  size_t GetSize() const {
  	return m_size;
 
  }
private:
  Node<T>* m_top; //Top node in stack
  size_t m_size; //Number of nodes in stack
};

//*********************STACK FUNCTIONS IMPLEMENTED HERE******************
