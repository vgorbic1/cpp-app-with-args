#include <vector>
#include <string>
#include <exception>
#include <fstream>


#include "arguments.hpp"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

using std::exception;


struct MyArguments {
	bool help = false;
	string test = "";
	// add more argument variables here ...
};

MyArguments parseArguments(int argc, char **argv){

	Arguments args(argc, argv);

	args.addArgument("help,h", "prints usage");
	args.addArgument("test,t", "writes entered string");
	// add more arguments here ...

	MyArguments a;

	if (args.has("help")){
		cout << args.usage() << endl;
		exit(0);
	}

	if (argc == 1) {
		cout << args.usage() << endl;
		exit(0);
	}

	a.test = args.get("test").as<string>();

	return a;
}

void printArguments(MyArguments &a){
	try {

		cout << "== params ==" << endl;
		cout << "test: \t" << a.test << endl;
		// add more parameters descriptions to print here ...
		cout << "============" << endl;


	} catch(exception &e){
		cout << "ERROR: " << e.what() << endl;
		exit(1);
	}
}


int main(int argc, char **argv){

	try {
		MyArguments a = parseArguments(argc, argv);

		printArguments(a);

		cout << "This is the line with entered parameter: " << a.test << endl;

        // implement other arguments behavior here ...

	}catch(exception &e){
		cout << "ERROR: " << e.what() << endl;
		return 1;
	}

	return 0;
}

