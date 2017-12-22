#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


namespace frctl
{

	class LSystem
	{
		int gen, curGen;
		vector<char> alphabet;
		string axiom;
		map<char, string> rules;
	public:

		void setRules(map<char, string> _rules);
		void addRule(char _from, string _to);
		void setAxiom(string _axiom);
		void print(int _gen);
		void apply(int l, int r);
		string getGen(int _gen);
		void readFile(string filename);
		void consoleInput();
		void demo();
	};
}