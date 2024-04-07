

#ifndef LABWORK3__CREATE_BMP_H_
#define LABWORK3__CREATE_BMP_H_

#include <cstdint>
#include "parsing.h"
#include "sandpile.h"
#include <iostream>
#include <cstring>
#include <fstream>

std::string GetPath(const char* path);

void ToNumbers4(int x, uint8_t numbers_4[]);

void CreateBmp(const char *path, uint64_t**& matrix, Gridsize& arguments);

#endif //LABWORK3__CREATE_BMP_H_
