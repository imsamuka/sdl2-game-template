#pragma once
#include <string>
#include <iostream>

struct Debug {
  inline static void ShowLog(const std::string& message)
  {
    std::cout << message << std::endl;
  }

  inline static void ShowLogNL(const std::string& message)
  {
    std::cout << message;
  }
};



