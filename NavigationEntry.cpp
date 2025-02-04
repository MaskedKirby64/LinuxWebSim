#include<iostream>
#include<iomanip>
#include<string>
#include "NavigationEntry.h"
using namespace std;

NavigationEntry::NavigationEntry(){
	m_url = "";
	m_timeStamp = 0;

}

NavigationEntry::NavigationEntry(const string& url, const int& timestamp){
	m_url = url;
	m_timeStamp = timestamp;
}


string NavigationEntry::GetURL() const{
	return m_url;
}


bool NavigationEntry::IsEmpty() const{
	if(m_url == ""){
		return true;
	}
	else{
		return false;
	}
}


void NavigationEntry::SetURL(const string& url){
	m_url = url;

} 

void NavigationEntry::SetTimeStamp(const int& time){

	m_timeStamp = time;
} 


 int NavigationEntry::GetTimeStamp() const{
 	return m_timeStamp;
 } //Returns m_timeStamp



ostream& operator<<(ostream& out, NavigationEntry& entry){

	std::cout<<"URL: "<<entry.m_url<<" Visited On:  ";
	cout<<entry.DisplayTimeStamp(entry.m_timeStamp)<<endl;

	return out;
}





