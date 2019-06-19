#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include "../include/STL_tool.hpp"

STL_tool::STL_tool() { }

STL_tool::~STL_tool() { }

vector<Triangle> STL_tool::ReadASCII(string filename) {
  SurfTria.clear();
  ofstream STLfile;
  STLfile.open(filename);

  // Todo

  STLfile.close();
  cout << "Done reading ASCII STL file." << endl;

  return SurfTria;
}

void STL_tool::WriteASCII(vector<Triangle> SurfTria, string filename) {
  // open file
  ofstream STLfile;
  STLfile.open(filename);

  // Write necessary header
  STLfile << "solid \n";

  // Loop over all Triangles and write normal + point positions
  for (unsigned int i = 0; i < SurfTria.size(); i++) {
    STLfile << "  facet normal " << SurfTria[i].GetNormal(0) << " " << SurfTria[i].GetNormal(1) << " " << SurfTria[i].GetNormal(2) << "\n";
    STLfile << "    outer loop\n";
    STLfile << "      vertex " << SurfTria[i].GetPointCoords(0,0) << " " << SurfTria[i].GetPointCoords(0,1)<< " " << SurfTria[i].GetPointCoords(0,2) << "\n";
    STLfile << "      vertex " << SurfTria[i].GetPointCoords(1,0) << " " << SurfTria[i].GetPointCoords(1,1)<< " " << SurfTria[i].GetPointCoords(1,2) << "\n";
    STLfile << "      vertex " << SurfTria[i].GetPointCoords(2,0) << " " << SurfTria[i].GetPointCoords(2,1)<< " " << SurfTria[i].GetPointCoords(2,2) << "\n";
    STLfile << "    endloop\n";
    STLfile << "  endfacet\n";
  }  

  // Write necessary end and close file
  STLfile << "endsolid ";
  STLfile.close();
  cout << "ASCII STL file written." << endl;
}

vector<Triangle> STL_tool::ReadBinary(string filename) {
  SurfTria.clear();

  FILE* file;
  file = fopen(filename.c_str(

  ), "r");
  float tri_array[9];

  if(file != NULL) {
    fseek(file, 80, SEEK_CUR); // 80 char start

    // int (4byte) #tris
    int tris = 0;
    fread(&tris, 1*sizeof(int), 1, file);

    // Read all tris coords, push back to vector. Normal gets computed automatically.
    for (int i = 0; i < tris; i++)
    {
      fseek(file, sizeof(float)*3, SEEK_CUR); // normal
      fread(tri_array, sizeof(float), 9, file);
      fseek(file, 2, SEEK_CUR); // useless unsigned short
      
      SurfTria.push_back(Triangle(tri_array));      
    }
  } else {
    cout << "Error opening file!" << endl;
  }
  fclose(file);

  cout << "Done reading Binary STL file." << endl;
  return SurfTria;
}

void STL_tool::WriteBinary(vector<Triangle> SurfTria, string filename) {
  FILE* file;
  file = fopen(filename.c_str(), "w");
  float tri_array[12];

  if(file != NULL) {
    // 80 chat/byte header
    char start[80] = "";
    fwrite(start, sizeof(char), 80, file);

    // int (4byte) #tris
    unsigned long tris = SurfTria.size();
    fwrite(&tris, 1*sizeof(int), 1, file);

    // Loop all tris, Write normal and then 3 points.
    for (unsigned long i = 0; i < tris; i++)
    {
      // normal
      tri_array[0] = (float) SurfTria[i].GetNormal(0);
      tri_array[1] = (float) SurfTria[i].GetNormal(1);
      tri_array[2] = (float) SurfTria[i].GetNormal(2);

      // point coords
      for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 3; j++) {
          tri_array[3 + k*3 + j] = (float) SurfTria[i].GetPointCoords(k, j);
        }
      }
      
      // 0 between the tris 
      fwrite(tri_array, sizeof(float), 12, file);
      short int end = 0;
      fwrite(&end, sizeof(short int), 1, file);
      
    }
  }
  fclose(file);

  cout << "Binary STL file written." << endl; 
}