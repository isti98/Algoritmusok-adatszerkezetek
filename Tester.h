
#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef TESTER_H
#define TESTER_H

class Tester
{
	public:
				Tester			():counter(0){}
		void 		runCheck		(const string& s){ cout<<s<<" "<<counter<<endl; counter++;}
		
	protected:
		unsigned int 	counter;
	
	private:
	
};

#endif
