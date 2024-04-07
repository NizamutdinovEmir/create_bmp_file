
#ifndef LABWORK3__PARSING_H_
#define LABWORK3__PARSING_H_
#include <cstdint>
#include <iostream>
#include <cstring>
#include <fstream>

struct ParseOptions {
  char* input = "C:\\Users\\emirn\\ClionProjects\\labwork3\\test.tsv";
  char* output = "C:\\Users\\emirn\\ClionProjects\\labwork3";
  size_t max_iter = 0;
  size_t freq = 0;
};

void ParseArguments(int argc, char** argv, ParseOptions& arguments_parsing);
#endif //LABWORK3__PARSING_H_
