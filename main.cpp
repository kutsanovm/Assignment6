#include "sort.h"
#include <iostream>
#include <fstream>
#include<string>
#include <ctime> //http://www.codebind.com/cpp-tutorial/cpp-program-display-current-date-time/
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		time_t t = time(NULL);
  	tm* timePtr = localtime(&t);

		sort luke = sort(argv[1]);

		cout << "\n" << "INSERTION SORT" << endl;
		cout << "START TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		luke.insertSort(luke.arr);
		cout << "END TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<< endl;

		cout << "\n" << "BUBBLE SORT" << endl;
		cout << "START TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		luke.bubbleSort(luke.arr);
		cout << "END TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<< endl;

		cout << "\n" << "QUICK SORT" << endl;
		cout << "START TIME: " <<(timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		luke.quickSort(luke.arr, luke.arr[0], luke.arr[0]);
		cout << "END TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<<endl;

		cout << "\n" << "SELECTION SORT" << endl;
		cout << "START TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		luke.selectionSort(luke.arr, luke.arr[0]);
		cout << "END TIME: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<<endl;
	}
	return 0;
}
