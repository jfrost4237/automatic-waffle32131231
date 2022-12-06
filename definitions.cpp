#include "definitions.h"

std::string file("");

std::vector<double>grades;


double grade;

//std::ofstream outdata;

std::string subject;



std::vector<double>NL, EN, DU, MATH, CKV, IT, NA, LV, CHEM, MAAT;



std::vector<double>& get_vector(std::string subject) { // no idea what the fuck i did here
	if (subject == "Dutch" or "dutch") return NL;
	if (subject == "English" or "english") return EN;
	if (subject == "German" or "german") return DU;
	if (subject == "Math" or "Math") return MATH;
	if (subject == "CKV") return CKV;
	if (subject == "IT") return IT;
	if (subject == "Physics" or "physics") return NA;
	if (subject == "Philosophy" or "philosophy") return LV;
	if (subject == "Chemistry" or "chemistry") return CHEM;
	if (subject == "Society" or "society") return MAAT;
}

void export_data() {
	std::ofstream outdata;
	
	
	outdata.open(file); // opens the file	
	if (!outdata) { // file couldn't be opened
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}
	for (int i = 0; i < get_vector(subject).size(); ++i) {
		outdata.open(file);
		outdata << get_vector(subject)[i] << "\n";
		std::cout << "done:    [" << i << "]  [" << get_vector(subject)[i] << "]\n";
	}
	outdata.close();
}

void enter_grades(){
	int amount_of_grades = 0;

	std::cout << "How many grades do you want to enter?\n";
	std::cin >> amount_of_grades;
	

	for (int i = 0; i < amount_of_grades; i++) {
		std::cout << "Enter grade    [" << i << "]:      ";
		std::cin >> grade;
		std::cout << "\n";
		get_vector(subject).push_back(grade);
		std::cout << "[" << i << "]                [" << get_vector(subject)[i] << "]\n\n";
		

		

	}
}


  

void push_back_grade() {
	std::cout << "\nWhich subject would you like to enter?\n";
	std::cin >> subject;
	
	std::cout << "\nsubject: " << subject << "\n";

	enter_grades();
	export_data();
	
		
	}


