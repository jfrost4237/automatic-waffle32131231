#include "include.h"



extern std::string file;

extern std::vector<double>grades;

extern std::vector<double>NL;
extern std::vector<double>EN;
extern std::vector<double>DU;
extern std::vector<double>MATH;
extern std::vector<double>CKV;
extern std::vector<double>IT;
extern std::vector<double>BIO;
extern std::vector<double>NA;
extern std::vector<double>LV;
extern std::vector<double>CHEM;
extern std::vector<double>MAAT;




//extern std::ofstream outdata;

extern double grade;

extern std::string subject;

void export_data();

std::vector<double>& get_vector(std::string subject);

void enter_grades();

void push_back_grade();

