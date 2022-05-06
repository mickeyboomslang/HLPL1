#include "std_lib_facilities.h" 


constexpr char number = '8';
constexpr char quit = 'x';
constexpr char print = '=';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char result = ';';

const string declkey = "#"; // task 10 "let" changed to "#"
const string square = "sqrt";
const string power = "pow";
const string quitkey = "quit";



double expression();
double primary();
double term();
double declaration();
double statement();


class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name(string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var,val });
	return val;
}

double get_value(string s)
{
	for (const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("Set: undefined variable", s); // checks error
}



class Token {
public:
	char kind;
	double value;
	string name;
	Token() : kind(0) {}
	Token(char ch) : kind(ch), value(0) {}
	Token(char ch, double val) : kind(ch), value(val) {}
	Token(char ch, string n) : kind(ch), name(n) {}
};



class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
	case print:
	case quit:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.putback(ch);
			if (s == declkey) return Token{ let };

			else if (s == quitkey) return Token(quit);

			else if (s == square) return Token('s'); //square root method

			else if (s == power) return Token('p'); //task 9 


			else if (is_declared(s))
				return Token(number, get_value(s));
			return Token{ name,s };
		}
		error("Bad token");
	}
	return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}


Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}


void calculate()
{
	while (cin)
		try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {
	string myString = "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.";


	cout << myString << endl;
	cout << "The operators '+, -, /, *' are available\n";

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000.0); // 6th task "Add a predefined name k meaning 1000"

	calculate();

	return 0;

}
catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "exception\n";
	return 2;
}


double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	case 's': //task 7 square function 
	{
		char ch1;
		double BeSquared;
		if (cin >> ch1 && ch1 == '(')
		{
			BeSquared = expression();
		}

		else error("The function starts with (!"); //it checks error
		if (ts.get().kind == ')')
		{
			if (BeSquared >= 0)
				return sqrt(BeSquared);

			else error(" Argument cannot be smaller than 0!"); //task 8 "checks for a negative argument"
		}

		else error(" ) is missing in the end of the function!"); //checks error
	}
	case 'p':
	{
		char ch1;
		double BePowered;
		int power;

		if (cin >> ch1 && ch1 == '(') {
			BePowered = primary();

			if (cin >> ch1 && ch1 == ',') {
				power = narrow_cast<int>(primary()); // task 9
			}

			else error(" , is missing between arguments"); //checks error
		}

		else error("Enter ( first"); //checks error
		if (cin >> ch1 && ch1 == ')') {
			return pow(BePowered, power);
		}

		else error(") Needed at the end of pow");//checks error
	}
	default:
		error("Primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("Divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%: Divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("Name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= Missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}
