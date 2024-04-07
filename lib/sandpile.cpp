#include "sandpile.h"

#include <iostream>

void ReadTSV(const char* path, uint64_t**& matrix, Gridsize& arguments, int& PlaceWith4) {
  std::ifstream tsvfile(path);
  int16_t WightFromFile = 0;
  int16_t LengthFromFile = 0;
  uint64_t grains;
  int CellsGrainsSand = 1;
  while (tsvfile >> WightFromFile >> LengthFromFile >> grains) {
    matrix[WightFromFile][LengthFromFile] = grains;
    if (grains >= 4) {
      PlaceWith4++;

      if (WightFromFile>= arguments.width) {
        arguments.width = WightFromFile + 1;
      }
      if (LengthFromFile >= arguments.length) {
        arguments.length = LengthFromFile + 1;
      }
      std::cout << "Processed Cells with grains sand" << " "  << CellsGrainsSand << " : " << matrix[WightFromFile][LengthFromFile] << std::endl;
      CellsGrainsSand++;
    }
  }
}

void MatrixAddition(uint64_t**& matrix, Gridsize& arguments, AddNew key) {
  uint64_t** newMatrix = nullptr;

  auto createMatrix = [&](uint16_t newWidth, uint16_t newLength) {
    uint64_t** newMat = new uint64_t*[newWidth];
    for (int16_t i = 0; i < newWidth; i++) {
      newMat[i] = new uint64_t[newLength];
      for (int16_t j = 0; j < newLength; j++) {
        newMat[i][j] = 0;
      }
    }
    return newMat;
  };

  switch (key) {
    case up:
      newMatrix = createMatrix(arguments.width + 1, arguments.length);
      break;

    case down:
      newMatrix = createMatrix(arguments.width + 1, arguments.length);
      break;

    case left:
      newMatrix = createMatrix(arguments.width, arguments.length + 1);
      break;

    case right:
      newMatrix = createMatrix(arguments.width, arguments.length + 1);
      break;
  }

  // Copy existing data to the new array
  for (int16_t i = 0; i < arguments.width; i++) {
    for (int16_t j = 0; j < arguments.length; j++) {
      if (key == up || key == down) {
        newMatrix[i + (key == up ? 1 : 0)][j] = matrix[i][j];
      } else {
        newMatrix[i][j + (key == left ? 1 : 0)] = matrix[i][j];
      }
    }
    delete[] matrix[i];
  }
  delete[] matrix;
  matrix = newMatrix;

  if (key == up || key == down) {
    arguments.width++;
  } else {
    arguments.length++;
  }
}
void Iteration(uint64_t**& matrix, Gridsize& arguments, int& PlaceWith4) {
  // хранит в себе индексы, до которых мы еще не дошли, но мы их уже сделали >=4
  std::set<std::pair<int16_t, uint16_t>> ignoring;
  std::pair<int16_t, uint16_t> temporary;
  for (int16_t i = 0; i < arguments.width; i++) {
    for (int16_t j = 0; j < arguments.length; j++) {
      temporary = std::make_pair(i, j);
      if (ignoring.count(temporary) == 1) {
        continue;
      }
      if (matrix[i][j] >= 4) {
        if (i == 0) {
          MatrixAddition(matrix, arguments, up);
          i++;
        }
        if (j == 0) {
          MatrixAddition(matrix, arguments, left);
          j++;
        }
        if (i == arguments.width - 1) {
          MatrixAddition(matrix, arguments, down);
        }
        if (j == arguments.length - 1) {
          MatrixAddition(matrix, arguments, right);
        }

        matrix[i][j] = matrix[i][j] - 4;
        matrix[i - 1][j]++;
        matrix[i][j - 1]++;
        matrix[i + 1][j]++;
        matrix[i][j + 1]++;

        if (matrix[i + 1][j] == 4) {
          temporary = std::make_pair(i + 1, j);
          ignoring.insert(temporary);
          PlaceWith4++;
        }

        if (matrix[i][j + 1] == 4) {
          temporary = std::make_pair(i, j + 1);
          ignoring.insert(temporary);
          PlaceWith4++;
        }

        if (matrix[i][j] < 4) {
          PlaceWith4--;
        }
        if (matrix[i - 1][j] == 4) {
          PlaceWith4++;
        }
        if (matrix[i][j - 1] == 4) {
          PlaceWith4++;
        }
      }
    }
  }
}

