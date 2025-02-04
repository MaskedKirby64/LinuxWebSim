/*Title: NavigationEntry.h
  Author: Prof. Dixon
  Date: 11/14/2024
  Description: This class defines information about visiting a website
*/
#ifndef NAVIGATION_ENTRY_H //Header guards
#define NAVIGATION_ENTRY_H //Header guards

#include <string> 
#include <chrono>  // for timestamps
using namespace std;

//Constants

class NavigationEntry {
 public:
  // Constructors
  NavigationEntry();
  // Name: NavigationEntry (Overloaded constructor)
  // Description: Creates a new NavigationEntry with a string and an int timestamp
  // Preconditions: None
  // Postconditions: Creates a new NavigationEntry object
  NavigationEntry(const string& url, const int& timestamp);

  // Accessors (Getters)
  string GetURL() const; //Returns the m_url
  int GetTimeStamp() const; //Returns m_timeStamp
  
  // Mutators (Setters)
  void SetURL(const string& url); //Used to set m_url
  void SetTimeStamp(const int& time); //Used to set m_timeStamp

  // Name: IsEmpty
  // Description: Returns true if m_url is empty
  // Preconditions: None
  // Postconditions: Returns true if m_url is empty else false
  bool IsEmpty() const;
  // Name: DisplayTimeStamp (Provided)
  // Description: Converts
  // Preconditions: Pass it an integer (up to 64 bits)
  // Postconditions: Returns the string equivalent of the date/time
  string DisplayTimeStamp(int64_t timestamp){
    // Convert integer timestamp to time_t
    time_t time = static_cast<time_t>(timestamp);
    // Convert time_t to tm structure for local time
    tm* localTime = localtime(&time);
    char buffer[80];
    // Format the date and time
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    // Cast formatted output as string and return
    return string(buffer);
  }
  // Name: Overloaded <<
  // Description: Prints the details of a navigation entry
  // Preconditions: None
  // Postconditions: Returns an ostream with output of a navigation entry
  // Sample output: URL:http://daler.org/ Visited On: 2018-03-02 16:48:00
  friend ostream& operator<<(ostream&, NavigationEntry&);
 private:
  string m_url;    // URL of the visited website
  int m_timeStamp; // Timestamp of the visit
};

#endif // NAVIGATION_ENTRY_H
