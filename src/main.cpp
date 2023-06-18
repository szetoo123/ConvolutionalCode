#include <iostream>
#include <string>
#include <vector>

#include "example.cpp"
#include "operateGb.cpp"
#include "classofGb.hpp"


using namespace std;

int main(){
	GenMatrix GB;
	initGB(GB);
	print_example();
	readGb(GB);
	return 0;
}


