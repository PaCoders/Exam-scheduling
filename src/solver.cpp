/* ========================================================================
					SOLVER OF EXAM SCHEDULING
					Francisco Chanivet Sánchez
   ========================================================================
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <cmath>
#include "generator.h"
#include "translator.h"

using namespace std;

bool no_colour_underbound(const list<int>& cv, int b){
	bool valid = true;
	list<int>::const_iterator it = cv.cbegin();
	
	while(it != cv.cend() && valid){
		if(*it < b){
			valid = false;
		}
		++it;
	}
	return valid;
}


int backGCP(const vector< vector<int> >& G,int k, int B, vector<list<int>>& C, int vertex){
	if(vertex == G.size()){
		return k;
	}
	for(int i = vertex; i < G[vertex].size(); i++){ //For all subjects, we want to check if it's underbound of B
			if(no_colour_underbound(C[i],B)){
				return B;
			}
	}
	//With variable vertex, we select the vertex that we want
	
	list<int>::iterator it = C[vertex].begin();
	
	while(it != C[vertex].end()){ //All availables colours in vertex v
		if(*it < B){
			for(int j = vertex; j < G[vertex].size(); j++){ //All adjacents vertex of v
				if(G[vertex][j] == 1 && vertex != j){
					C[j].remove(*it);
				}
			}
			
			B = backGCP(G,max(k,*it),B,C,vertex+1); //We call the function removing vertex v of the graph
			
			for(int j = vertex; j < G[vertex].size(); j++){ //All adjacents vertex of v
				if(G[vertex][j] == 1 && vertex != j){ //In this part, we insert the color to all adjacents vertex in C
					C[j].push_front(*it);
					C[j].sort();
				}
			}
		}
		
		++it;
	}
	
	return B;
}

// Main program where we execute the solver of the assignment
int main(){
	//At first, we define the initial parameters
	int n_asig = 5;
	vector< vector<int> > G;
	generator(n_asig);
	translator(G);
	vector<list<int>> C(n_asig);
	list<int> subjects;
	for(size_t i = 0; i < n_asig; i++) subjects.push_back(i);
	
	for(size_t i = 0; i < C.size(); i++){
		C[i] = subjects;
	}

	int B = backGCP(G,0,G.size() + 1,C,0);
	
	
	cout<<"Number of days: "<<B<<endl;
	
}
