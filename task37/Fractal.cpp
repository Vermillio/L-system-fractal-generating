//L system contains of axiom, rules and interpretation. Given it, build the fractal of given degree.

#include "Fractal.h"

#include <iterator>

using namespace std;

void frctl::LSystem::setRules(map<char, string> _rules)
{
	rules = _rules;
}

void frctl::LSystem::addRule(char _from, string _to)
{
	rules.insert({_from, _to});
}

void frctl::LSystem::setAxiom(string _axiom)
{
	axiom = _axiom;
}

void frctl::LSystem::print(int _gen)
{
	cout << getGen(_gen);
}

void frctl::LSystem::apply(int l, int r)
{
//	if (curGen > gen)
//		return;
	map<char, string>::iterator it;
	int i = l;
	while (i <= r)
	{
		it = rules.find(axiom[i]);
		if (it != rules.end())
		{
			axiom[i] = it->second[0];
			axiom.insert(axiom.begin() + i + 1, it->second.begin() + 1, it->second.end());
			if (curGen <= gen)
			{
				++curGen;
				apply(i, i + it->second.size() - 1);
				--curGen;
			}
			i += it->second.size();
		}
		else ++i;
	}
}

string frctl::LSystem::getGen(int _gen)
{
	gen = _gen;
	curGen = 0;
	string tmp = axiom;
	apply(0, axiom.size() - 1);
	swap(tmp, axiom);
	return tmp;
}

void frctl::LSystem::readFile(string filename)
{
}

void frctl::LSystem::consoleInput()
{
	cout << "Enter axiom : ";
	cin >> axiom;

	cout << "Enter rules " << endl;
	int i = -1;
	pair<char, string> rule;
	do {
		++i;
		cout << "Rule #" << i + 1 << ": ";
		cin >> rule.first;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << " -> ";
		getline(cin, rule.second);
		if (rule.first == ' ' || rule.second == "" || rule.second == " ")
			break;
		rules.insert(rule);
	} while (true);
}

void frctl::LSystem::demo()
{
	bool choise;
	cout << "Console input - 0, read file - 1 : " << endl;
	cin >> choise;
	if (!choise)
		consoleInput();
	else {
		string filename;
		cout << "Enter filename: " << endl;
		cin >> filename;
		readFile(filename);
	}
	unsigned int gen;
	cout << "Enter generation: " << endl;
	cin >> gen;
	print(gen);
}
