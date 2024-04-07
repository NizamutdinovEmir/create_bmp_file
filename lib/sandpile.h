
#ifndef LABWORK3__SANDPILE_H_
#define LABWORK3__SANDPILE_H_
#include <cstdint>
#include "parsing.h"
#include <deque>
#include <fstream>
#include <set>

enum AddNew {
  up = 0, left = 1, down = 2, right = 3
};

struct Gridsize {
  int16_t length = 0;
  int16_t width = 0;
};

// считываем данные из tsv файла
void ReadTSV(const char* path, uint64_t**& matrix, Gridsize& arguments,
                  int &PlaceWith4);

void MatrixAddition(uint64_t**& matrix, Gridsize& arguments, AddNew key);

void Iteration(uint64_t**& matrix, Gridsize& arguments, int& PlaceWith4);
#endif //LABWORK3__SANDPILE_H_
