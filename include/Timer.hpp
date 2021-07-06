#pragma once
#include <iostream>
#include <chrono>
#include <string>

struct Timer {

  Timer(std::string&& _name){
    name = _name;
    beggining = std::chrono::high_resolution_clock::now();
  }
  Timer(){
    beggining = std::chrono::high_resolution_clock::now();
  }

  ~Timer(){
    using namespace std::chrono;

    auto final = high_resolution_clock::now();

    auto start = time_point_cast<microseconds>(beggining).time_since_epoch().count();
    auto end = time_point_cast<microseconds>(final).time_since_epoch().count();

    auto deltaTime = end - start;
    double ms = deltaTime * 0.001;

    if (!name.empty()) std::cout << name << ": ";
    std::cout << deltaTime << "us (" << ms << "ms)" << std::endl;
  }

private:
  std::string name;
  std::chrono::time_point<std::chrono::high_resolution_clock> beggining;
};