/* ========================================================================
					GENERATOR OF RANDOM EXAM SCHEDULING
					Francisco Chanivet Sánchez
   ========================================================================
*/

#ifndef _GENERATOR_H
#define _GENERATOR_H


#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

void generator(int k){
	std::ofstream file("file/exams.txt");
	
	if(!file){ //We throw an exception if we open the file and it fails
		exit(EXIT_FAILURE);
	}
		
	file<<"c FILE: exams.txt\n";
	file<<"c --- Random Exam Scheduling ---\n";
	
	srand(time(NULL));
	file<<"p edge "<<k<<" "<<k<<std::endl;
	int nC,nA;
	for(int i = 0; i < k; i++){
		nC = rand() % k;
		for(int j = 0; j < nC; j++){
			nA = rand() % k;
			while(nA == i)
				nA = rand() % k;
			file<<"e "<<i<<" "<<nA<<std::endl;
		}
	}
	 
	file.close();
	
}

#endif
