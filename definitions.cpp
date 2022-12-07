#include "definitions.h"

std::string file("");

std::vector<double>grades;


double grade;

//std::ofstream outdata;

std::string subject;



std::vector<double>NL, EN, DU, MATH, CKV, IT, NA, LV, CHEM, MAAT;



std::vector<double>& get_vector(std::string subject) { // no idea what the fuck i did here
	if (subject == "dutch") return NL;
	if (subject == "english") return EN;
	if (subject == "german") return DU;
	if (subject == "math") return MATH;
	if (subject == "ckv") return CKV;
	if (subject == "it") return IT;
	if (subject == "physics") return NA;
	if (subject == "philosophy") return LV;
	if (subject == "chemistry") return CHEM;
	if (subject == "society") return MAAT;
	else { std::cout << "unknown subject\n"; }
}

void read_data() {
	std::ifstream indata;
	std::string values;
	indata.open(file); // opens the file
	if (!indata) { // file couldn't be opened
		std::cout  << "Error: file could not be opened\n";
		abort;
	}
	indata >> values;
	while (!indata.eof()) { // keep reading until end-of-file
		std::cout << "The next value is " << values << "\n";
		indata >> values; // sets EOF flag if no value found
	}
	indata.close();
	std::cout << "End of file reached" << "\n";

	std::cout << "values: " << values << "\n=======================================================\n";
}




void export_data() {
	std::ofstream outdata;
	
	
	outdata.open(file); // opens the file	
	if (!outdata) { // file couldn't be opened
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}
	outdata << subject << "\n";
	for (int i = 0; i < get_vector(subject).size(); ++i) {
		
		outdata << "[" << i << "] " << get_vector(subject)[i] << "  Average: " << CalculateAverage() << " \n";
		std::cout << "done:    [" << i << "]  [" << get_vector(subject)[i] << "]       Avg: [" << CalculateAverage() << "]\n";

	}
	outdata.close();
}

double CalculateAverage() {

	double sum = std::accumulate(get_vector(subject).begin(), get_vector(subject).end(), 0.0);
	double average = (sum / get_vector(subject).size());
	return average;
}

void print_vector(std::string subject) {


	auto& target_vector = get_vector(subject); // get the vector
	for (auto element : target_vector) // loop over all elements
		std::cout << "[" << element << "]  "; // print all elements

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
		//std::cout << "[" << i << "]       [" << get_vector(subject)[i] << "]       Avg: [" << CalculateAverage() << "]\n";
		
		

	}
}


  

void start_grading() {
	std::cout << "\nWhich subject would you like to enter?\n";
	std::cin >> subject;
	
	std::cout << "\nsubject: " << subject << "\n";

	std::transform(subject.begin(), subject.end(), subject.begin(), [](unsigned char c) { return std::tolower(c); });


	enter_grades();
	export_data();
	
		
	}


