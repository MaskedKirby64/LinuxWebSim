#ifndef BROWSER_H //Header guards
#define BROWSER_H //Header guards

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //For timestamps
#include <chrono> //For timestamps
#include "Stack.cpp"
#include "NavigationEntry.h"

using namespace std;

//Constants
const char DELIMITER = ',';

//This class acts like a browser and keeps track of the website you are currently
//viewing (m_currentPage), the sites you have previously viewed (m_backStack) and
//the sites you went back from (m_forwardStack).
class Browser {
 public:
  // Name: Browser (Overloaded constructor)
  // Description: Creates a new Browser with the filename passed
  // Preconditions: None
  // Postconditions: Sets m_fileName and m_currentPage to nullptr
  Browser(string filename);
  // Name: ~Browser (Destructor)
  // Description: Deallocates the items in m_backStack, m_forwardStack and
  //              m_currentPage
  // Preconditions: None
  // Postconditions: Deallocates all dynamically allocated memory
  ~Browser();
  // Name: StartBrowser
  // Description: Loads the file and calls the menu
  // Preconditions: None
  // Postconditions: Menu keeps running until exited
  void StartBrowser();
  // Name: Menu
  // Description: Menu that allows browser history to be displayed, go back,
  //              go forward, visit a site or quit.
  // Preconditions: None
  // Postconditions: When exiting, thanks user.
  void Menu();
  // Name: Visit
  // Description: Dynamically allocates a new NavigationEntry (NE).
  //              If m_currentPage is nullptr, assigns new NE to the currentPage
  //              Otherwise, pushes the currentPage into the history and updates
  //              m_currentPage to new NE
  // Preconditions: None
  // Postconditions: Adds things to m_backStack or m_currentPage
  void Visit(const string& url, int timestamp);
  // Name: NewVisit
  // Description: User enters the URL of the site visited and populates the
  //              timestamp based on the current system time (below)
  //              auto now = chrono::system_clock::now();
  //              time_t nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  //              int64_t timestamp = static_cast<int64_t>(nowAsTimeT);
  // Preconditions: None
  // Postconditions: Adds new URL to m_backStack or m_currentPage
  void NewVisit();
  // Name: Display
  // Description: Display all of then entires in the back stack and front stack
  // Preconditions: None
  // Postconditions: None
  void Display();
  // Name: Back (steps)
  // Description: Moves item from m_currentPage to m_forwardStack
  //              Moves item from m_backStack to m_currentPage
  //              If m_backStack is empty, does not fail but does nothing.
  //              While can do more than one step, normally only moves one.
  // Preconditions: m_backStack must not be empty.
  // Postconditions: Rotates items as above
  NavigationEntry Back(int steps);
  // Name: Forward (steps)
  // Description: Moves item from m_backStack to m_currentPage
  //              Moves item from m_currentPage to m_forwardStack
  //              If m_forwardStack is empty, does not fail but does nothing.
  //              While can do more than one step, normally only moves one.
  // Preconditions: m_forwardStack must not be empty
  // Postconditions: Rotates items as above
  NavigationEntry Forward(int steps);
  // Name: GetCurrentPage
  // Description: Returns the current page
  // Preconditions: None
  // Postconditions: None
  NavigationEntry GetCurrentPage() const;
  // Name: LoadFile
  // Description: Loads the file using Visit
  // Preconditions: None
  // Postconditions: Adds things to m_backStack or m_currentPage
  void LoadFile();
 private:
  Stack<NavigationEntry*> m_backStack; //History of sites you have already viewed
  Stack<NavigationEntry*> m_forwardStack; //Sites you viewed but went back from
  NavigationEntry* m_currentPage; //Site you are currently viewing
  string m_fileName; //Name of the input file to import browsing history
};

#endif
