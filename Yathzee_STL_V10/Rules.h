#ifndef RULES_H
#define RULES_H

#include <fstream>  
using namespace std;

class RuleBook {
private:
	//string text;
public:
	string text;
	RuleBook() { text = " "; }
	void setString(string word) { text = word; }
	string getString()const { return text; }
	void prtRules(fstream& );
};


#endif /* RULES_H */

