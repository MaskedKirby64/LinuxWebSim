#include "Browser.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

int64_t GetCurTime();

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a browser history file to be loaded." << endl;
    cout << "Usage: ./proj5 proj5_data1.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string browserHistory = argv[1];
  //  NavigationEntry *newNE = new NavigationEntry("www.google.com",GetCurTime());
  Browser b(browserHistory);
  b.StartBrowser();
  return 0;
}

int64_t GetCurTime(){
  // Get the current time as a time_point
  auto now = chrono::system_clock::now();
  
  // Convert time_point to time_t, which represents time in seconds since the epoch
  time_t nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  
  // Convert to int64_t if needed for a larger range, or int32_t for standard Unix timestamp (32-bit)
  int64_t timestamp = static_cast<int64_t>(nowAsTimeT);
  return timestamp;
}
