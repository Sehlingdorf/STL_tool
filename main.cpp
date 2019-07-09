#include <iostream>
#include <vector>
#include "include/triangle.hpp"
#include "include/STL_tool.hpp"
#include "include/surface_creation.hpp"

using namespace std;

int main() {

  STL_tool stl;
  vector<Triangle> sphere = CreateTriangleSphere(1.0, 10, 10);
  stl.WriteASCII(sphere, "ascii.stl");
  stl.WriteBinary(sphere, "binary.stl");
  sphere = stl.ReadBinary("binary.stl");
  stl.WriteASCII(sphere, "ascii2.stl");
  sphere = stl.ReadASCII("ascii2.stl");
  stl.WriteASCII(sphere, "ascii3.stl");

  return 0;
}
