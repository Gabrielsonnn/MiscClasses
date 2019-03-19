
#include<iostream>
#include<string>
#include "ioControl.h"

using namespace std;

int main() {
	ioControl io;
	string input4;

	io.Output("Please enter full name?\n");

	io.Inputstr(&input4);

	io.Output(input4, "\n");
	io.newLine();

	io.Pause();
}