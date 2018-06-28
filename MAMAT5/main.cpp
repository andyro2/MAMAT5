#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdexcept>
#include "func.h"
#include "polynom.h"
#include "ratfunc.h"
#include "compfunc.h"

using namespace std;

const int MAXLINE = 256;



int main() {

	map<string, func*> func_list;
	char func_cmd[MAXLINE], func_name[MAXLINE], func_value[MAXLINE];
	char* token;

	while (!cin.eof()) {
		cin >> func_cmd >> func_name >> func_value;
		if (!strcmp(func_cmd, "//")) {
			continue;
		}

		if (!strcmp(func_cmd, "SetPolynom")) {
			int order;
			int* coefs;
			token = strtok(func_value, ",");
			order = atoi(token);
			token = strtok(NULL, ",");
			coefs = new int[order + 1];
			for (int i = 0; i <= order && token; i++) {
				coefs[i] = atof(token);
				token = strtok(NULL, ",");

			}
			func_list[func_name] = new polynom(order, coefs);
			delete[] coefs;
		}

		//if (!strcmp(func_cmd, "SetCompFunc")) {
		//	func* outer;
		//	func* inner;
		//	char* outer_name = strtok(func_value, ",");
		//	char* inner_name = strtok(NULL, ",");
		//	try {
		//		outer = func_list.at(outer_name);
		//		inner = func_list.at(inner_name);
		//		func_list[string(outer_name) + "(" + string(inner_name) + ")"] = new compfunc(*outer, *inner);
		//	}
		//	catch (exception& e) {
		//		cout << "Error SetCompFunc:" << e.what() << endl;
		//	}
		//}
		if (!strcmp(func_cmd, "AddPoint")) {
			token = strtok(func_value, ",");
			try {
				*(func_list.at(func_name)) << atoi(token);
			}
			catch (exception& e) {
				cout << "Error AddPoint:" << e.what() << endl;
			}
			while (token = strtok(NULL, ",")) {
				try {
					*(func_list.at(func_name)) << atoi(token);
				}
				catch (exception& e) {
					cout << "Error AddPoint:" << e.what() << endl;
				}
			}
		}

		if (!strcmp(func_cmd, "MathPolynom")) {
			char *Op;
			polynom *f1, *f2;
			try {
				token = strtok(func_value, ",");
				f1 = (polynom*)func_list.at(token);
				Op = strtok(NULL, ",");
				token = strtok(NULL, ",");
				f2 = (polynom*)func_list.at(token);
				switch (*Op) {
				case '+':
					func_list[func_name] = new polynom((*f1) + (*f2));
					break;
				case '-':
					func_list[func_name] = new polynom((*f1) - (*f2));
					break;
				case '*':
					func_list[func_name] = new polynom((*f1)*(*f2));
					break;
				case '/':
					func_list[func_name] = new ratfunc(*f2, *f1);
				}
			}
			catch (exception& e) {
				cout << "Error MathPolynom: " << e.what() << endl;
			}
		}

		if (!strcmp(func_cmd, "MathRatFunc")) {
			char Op;
			ratfunc *f1, *f2;
			try {
				token = strtok(func_value, ",");
				f1 = (ratfunc*)func_list.at(token);
				token = strtok(NULL, ",");
				Op = *token;
				token = strtok(NULL, ",");
				f2 = (ratfunc*)func_list.at(token);
				switch (Op) {
				case '+':
					func_list[func_name] = new ratfunc((*f1) + (*f2));
					break;
				case '-':
					func_list[func_name] = new ratfunc((*f1) - (*f2));
					break;
				case '*':
					func_list[func_name] = new ratfunc((*f1)*(*f2));
					break;
//				case '/':
//					func_list[func_name] = new ratfunc((*f1) / (*f2));
				}
			}
			catch (exception& e) {
				cout << "Error MathRatFunc:" << e.what() << endl;
			}
		}

		if (!strcmp(func_cmd, "Print")) {
			if (strcmp(func_name, "All")) {//not all
				try {
					cout << func_name << "(x)=" << *(func_list[func_name]) << endl;
				}
				catch (exception& e) {
					cout << "Error Print:" << e.what() << endl;
				}
			}
			else {
				for (map<string, func*>::iterator it = func_list.begin();
					it != func_list.end(); ++it) {
					cout << it->first << "(x)=" << *(it->second) << endl;
				}
			}
		}
	}// end of file

	for (map<string, func*>::iterator it = func_list.begin();
		it != func_list.end(); ++it) {
		delete it->second;
	}
	return 0;
}
