#include <iostream>
#include <cmath>
#include "../include/triangle.hpp"

using namespace std;

Triangle::Triangle() {

  /* Allocate memory for point coordinates. */
  PointCoords = new double* [3];
  for(int i = 0; i < 3; i++ ) {
    PointCoords[i] = new double[3];
  }

  /* Allocate memory for normal vector. */
  Normal = new double [3];
}

Triangle::~Triangle() {

  /* Deallocate Point Coordinates. */
  if (PointCoords != NULL && false) {
    for (int i = 0; i < 3; i++) {
      delete [] PointCoords[i];
    }
    delete [] PointCoords;
  }

  /* Deallocate normal vector. */
  if (Normal != NULL && false) { delete [] Normal; }
}

Triangle::Triangle(double* values) : Triangle() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      PointCoords[i][j] = values[i*3+j];
    }
  }
  ComputeNormal();
}

Triangle::Triangle(float* values) : Triangle() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      PointCoords[i][j] = (double)values[i*3+j];
    }
  }
  ComputeNormal();
}

void Triangle::SetPointCoords(int Point, int Coord, double value) { PointCoords[Point][Coord] = value; }

void Triangle::SetPointCoords(double* values) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      PointCoords[i][j] = values[i*3+j];
    }
  }
  ComputeNormal();  
}

double Triangle::GetPointCoords(int Point, int Coord) { return PointCoords[Point][Coord]; }

void Triangle::ComputeNormal() {
  /* Details: https://www.khronos.org/opengl/wiki/Calculating_a_Surface_Normal */
  /* Follows right hand rule */
  /* U = P1 - P0 ; V = P2 - P0 : n = U x V */

  double U[3];
  double V[3];

  for (int i = 0; i < 3; i++) {
    U[i] = PointCoords[1][i] - PointCoords[0][i];
    V[i] = PointCoords[2][i] - PointCoords[0][i];
  }

  Normal[0] = U[1]*V[2] - U[2]*V[1];
  Normal[1] = U[2]*V[0] - U[0]*V[2];
  Normal[2] = U[0]*V[1] - U[1]*V[0];

  /* Make a unit normal by dividing by the norm. */
  double norm = 0.0;
  for (int i = 0; i < 3; i++) {
    norm += Normal[i]*Normal[i];
  }
  norm = sqrt(norm);

  for (int i = 0; i < 3; i++) { Normal[i] /= norm; }

}

double Triangle::GetNormal(int Coord) { return Normal[Coord]; }

void Triangle::PrintPointCoords() {
  cout << "Triangle point coordinates:" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "Point " << i << ": [ ";
    cout << PointCoords[i][0] << ", " << PointCoords[i][1] << ", " << PointCoords[i][2];
    cout << " ]" << endl;        
  }
} 

void Triangle::PrintNormal() {
  cout << "Triangle normal vector: ";
  cout << "[ " << Normal[0] << ", " << Normal[1] << ", " << Normal[2] << " ]" << endl;
}
