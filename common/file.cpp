/**
file.cpp contains snippets for handling files as Roveri wants.
 */

#include <iostream>
#include <fstream>

using namespace std;

void read() {
  fstream streamname;
  // open a file to read from
  streamname.open("filename", ios::in);

  if (streamname.fail()) {
	cout << "Error opening file. " << endl;
	streamname.close();
	exit(1);
  }

  int LENGTH = 100;
  char buffer[LENGTH];
  // read word by word
  while (streamname >> buffer) {
	cout << "read: " << buffer << endl;
  }

  streamname.close();
}

void write() {
  fstream streamname;
  // open a file to write to
  streamname.open("filename", ios::out);

  if (streamname.fail()) {
	cout << "Error opening file. " << endl;
	streamname.close();
	exit(1);
  }

  streamname << "whatever you want to write" << endl;
  streamname.close();
}

int main (int argc, char *argv[]) {
  read();
  write();
  return 0;
}
