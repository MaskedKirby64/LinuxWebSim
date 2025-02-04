#include<iostream>
#include<string>
#include "Browser.h"
using namespace std;

Browser::Browser(string filename){
	m_fileName = filename;
	m_currentPage = nullptr;
}

Browser::~Browser(){
	m_fileName = "";
	delete m_currentPage;
	m_currentPage = nullptr;   
}

void Browser::LoadFile(){

	  string ts;
    string url;
        ifstream file(m_fileName);
        while(getline(file,url,DELIMITER)){
                getline(file,ts);
                int y = stoi(ts);
                NavigationEntry * entry = new NavigationEntry(url,y);
                m_backStack.Push(entry);
        }
  }

void Browser::StartBrowser(){
  //load in data
	LoadFile();
	Menu();  
 	
  }

void Browser::Menu(){
  	bool flag = true;
	  m_currentPage = m_backStack.Pop();
	  cout<<"Welcome to The Browser History Simulator\n"<<endl;
		
   while(flag){
	//load the first website
    cout<<"Current Website: "<<endl;   
	  cout<<*m_currentPage<<endl;   
	   
	  int choice;
	  cout<<"What would you like to do?"<<endl;
	  cout<<"1. Display Browser History\n2. Go Back\n3. Go Forward\n4. Visit a site\n5.quit "<<endl;
	  cin>>choice;
	  if(choice == 1){Display();}
	  if(choice == 2){Back(1);}
	  if(choice == 3){Forward(1);}
	  if(choice == 4){
		  string url;
		  int ts = 0;
		  cout<<"Enter the URL of the new site:\n"<<endl;
		  cin>>url;
		  Visit(url,ts);
	}
	if(choice == 5){
		cout<<"Ending Browser History Simulator"<<endl;
		flag = false;}
	
   
	
    }
       
  }
void Browser::Display(){
	cout<<"**Back Stack**"<<endl;
	if(m_backStack.IsEmpty()){
		cout<<"Empty\n"<<endl;
	}
	else{	
		for(size_t i = 0; i<m_backStack.GetSize(); i++){
			cout<<*m_backStack.At(i)<<endl;
		}
	}
	cout<<"**Forward Stack**"<<endl;
	if(m_forwardStack.IsEmpty()){
		cout<<"Empty\n"<<endl;
	}
	else{
		for(size_t i = 0; i<m_forwardStack.GetSize(); i++){
			cout<<*m_forwardStack.At(i)<<endl;
		}
       }	
}
NavigationEntry Browser::Back(int steps){
	//if the forward stack isnt empty
	if(!m_backStack.IsEmpty()){
		for(int i = 0; i<steps; i++){
			//pop 1 off the backStack
			NavigationEntry* fromTheStack = m_backStack.Pop();
			//push the current page onto the forward stack
			m_forwardStack.Push(m_currentPage);
			m_currentPage = fromTheStack;
	        	return *m_currentPage;	
		}
	
	
	}
	else{
	
		return *m_currentPage;
	}
	
	return *m_currentPage;

}


NavigationEntry Browser::Forward(int steps){
	if(!m_forwardStack.IsEmpty()){
		for(int i = 0; i<steps; i++){
			NavigationEntry * fromTheForwardStack = m_forwardStack.Pop();
			m_backStack.Push(m_currentPage);
			m_currentPage = fromTheForwardStack;
			return *m_currentPage;
		}	
	}

	else{
	   
	     return *m_currentPage;	

	}

	return *m_currentPage;
}


  void Browser::Visit(const string& url, int timestamp){
 	//creating new entry
	NavigationEntry * entry = new NavigationEntry(url,timestamp);
	if(m_currentPage == nullptr){
			entry = m_currentPage;
	}

	else{
		m_backStack.Push(entry);
		m_currentPage = entry;
	
	}

  }

// Name: NewVisit
  // Description: User enters the URL of the site visited and populates the
  //              timestamp based on the current system time (below)
  //              auto now = chrono::system_clock::now();
  //              time_t nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  //              int64_t timestamp = static_cast<int64_t>(nowAsTimeT);
  // Preconditions: None
  // Postconditions: Adds new URL to m_backStack or m_currentPage
void Browser::NewVisit(){

	//bool flag =true;


	string new_url;
	cout<<"What new URL do you want to go to? "<<endl;
	cin>>new_url;
  

	auto now = chrono::system_clock::now();
	time_t nowAsTimeT = chrono::system_clock::to_time_t(now);
	int64_t timestamp = static_cast<int64_t>(nowAsTimeT);
	Visit(new_url,timestamp);


}





