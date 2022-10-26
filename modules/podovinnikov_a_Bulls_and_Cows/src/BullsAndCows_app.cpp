// Copyright 2022 Chausov Nikita

#include "include/BullsAndCows_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/BullsAndCows.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    BullsCows a(argv[2]);
    a.SetPlayerNum(argv[2]);
    a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
    // ASSERT_EQ(a.GetBulls(), 4);
    // ASSERT_EQ(a.GetCows(), 0);
    os << a.GetBulls() << " " << a.GetCows();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    BullsCows a(argv[2]);
    a.SetPlayerNum(argv[3]);
    a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
    // ASSERT_EQ(a.GetBulls(), 0);
    // ASSERT_EQ(a.GetCows(), 3);
    os << a.GetBulls() << " " << a.GetCows();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    BullsCows a(argv[2]);
    a.SetPlayerNum(argv[3]);
    a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
    // ASSERT_EQ(a.GetBulls(), 1);
    // ASSERT_EQ(a.GetCows(), 3);
    os << a.GetBulls() << " " << a.GetCows();
    std::cout << os.str() << std::endl;
    return "success";
  }
  return "success";
}

std::string CLPApplication::help() {
  std::string help = "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
