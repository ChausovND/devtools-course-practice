// Copyright 2022 Chausov Nikita

#include <iostream>
#include <string>

#include "include/BullsAndCows_app.h"

int main(int argc, const char** argv) {
  CLPApplication app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
