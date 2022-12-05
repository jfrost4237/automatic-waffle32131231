#include "definitions.h"

std::string file("");

std::vector<double>grades;


double grade;

std::ofstream outdata;

std::string subject;



std::vector<double>NL, EN, DU, MATH, CKV, IT, NA, LV, CHEM, MAAT;

//void export_data() {
//
//	for (int i = 0; i < NL.size(); ++i) {
//
//		std::cout << "done\n";
//		outdata << NL[i] << "\n";
//	}
//}

std::vector<double>& get_vector(std::string subject) {
	if (subject == "Dutch") return NL;
	if (subject == "English") return EN;
	if (subject == "German") return DU;
	if (subject == "Math") MATH.push_back(grade);
	if (subject == "CKV") CKV.push_back(grade);
	if (subject == "IT") IT.push_back(grade);
	if (subject == "Physics") NA.push_back(grade);
	if (subject == "Philosophy") LV.push_back(grade);
	if (subject == "Chemistry") CHEM.push_back(grade);
	if (subject == "Society") MAAT.push_back(grade);
}


void enter_grades(){
	int amount_of_grades = 0;

	std::cout << "How many grades do you want to enter?\n";
	std::cin >> amount_of_grades;
	std::cout << "\nEnter grades: ";

	for (int i = 0; i < amount_of_grades; i++) {
		std::cin >> grade;
		std::cout << "\n";
		get_vector();


		/*for (int i = 0; i < NL.size(); ++i) {
			std::cout << "done\n";
			outdata << NL[i] << "\n";
		}*/

	}
}


  

void push_back_grade(std::vector<double>& grades) {
	std::cout << "Which subject would you like to enter?\n";
	std::cin >> subject;
	
	std::cout << "\nsubject: " << subject << "\n";

	enter_grades();

		outdata.open(file); // opens the file	
		if (!outdata) { // file couldn't be opened
			std::cerr << "Error: file could not be opened" << std::endl;
			exit(1);
		}
		
	}


