#include <vector>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include "../include/surface_creation.hpp"

using namespace std;

vector<Triangle> CreateTriangleSphere(double radius, int zsections, int circu_points) {
  /* Declarations */
  vector<Triangle> TriaSphere;
  double points[9];
  double phi, psi;

  /* Catch bad input */
  if (radius <= 0.0 ||
      zsections < 3 ||
      circu_points < 3) {
    throw invalid_argument("Bad input arguments.\n");
  }
  
  /* Build lower traingles connected to bottom point at (0,0,-radius) */
  for (int i = 0; i < circu_points; i++)
  {
    phi = M_PI - M_PI/(zsections-1);
    points[0] = 0;
    points[1] = 0;
    points[2] = -radius;

    psi = 2*M_PI/circu_points*i; // turn in angle direction, i.e. cc seen from above
    points[3] = radius*sin(phi)*cos(psi);
    points[4] = radius*sin(phi)*sin(psi);
    points[5] = radius*cos(phi);

    psi = 2*M_PI/circu_points*(i+1);
    points[6] = radius*sin(phi)*cos(psi);
    points[7] = radius*sin(phi)*sin(psi);
    points[8] = radius*cos(phi);

    TriaSphere.push_back(Triangle(points));
  }

  /* Build middle layer triangles, i.e. always divide quad into 2 tris */
  for (int j = 0; j < zsections - 3; j++) {
    for (int i = 0; i < circu_points; i++) {
      // lower triangle
      phi = M_PI - (1 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*i;
      points[0] = radius*sin(phi)*cos(psi);;
      points[1] = radius*sin(phi)*sin(psi);
      points[2] = radius*cos(phi);

      phi = M_PI - (1 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*(i+1);
      points[3] = radius*sin(phi)*cos(psi);
      points[4] = radius*sin(phi)*sin(psi);
      points[5] = radius*cos(phi);

      phi = M_PI - (2 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*i;
      points[6] = radius*sin(phi)*cos(psi);
      points[7] = radius*sin(phi)*sin(psi);
      points[8] = radius*cos(phi);

      TriaSphere.push_back(Triangle(points));

      //uppertriangle
      phi = M_PI - (2 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*i;
      points[0] = radius*sin(phi)*cos(psi);;
      points[1] = radius*sin(phi)*sin(psi);
      points[2] = radius*cos(phi);

      phi = M_PI - (2 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*(i+1);
      points[3] = radius*sin(phi)*cos(psi);
      points[4] = radius*sin(phi)*sin(psi);
      points[5] = radius*cos(phi);

      phi = M_PI - (1 + j) * M_PI/(zsections-1);
      psi = 2*M_PI/circu_points*(i+1);
      points[6] = radius*sin(phi)*cos(psi);
      points[7] = radius*sin(phi)*sin(psi);
      points[8] = radius*cos(phi);

      TriaSphere.push_back(Triangle(points));
    }
  }
  
  /* Build upper traingles connected to top point at (0,0,radius) */
  for (int i = 0; i < circu_points; i++)
  {
    phi =  M_PI/(zsections-1);
    points[0] = 0;
    points[1] = 0;
    points[2] = radius;

    psi = 2*M_PI/circu_points*i;
    points[3] = radius*sin(phi)*cos(psi);
    points[4] = radius*sin(phi)*sin(psi);
    points[5] = radius*cos(phi);

    psi = 2*M_PI/circu_points*(i+1);
    points[6] = radius*sin(phi)*cos(psi);
    points[7] = radius*sin(phi)*sin(psi);
    points[8] = radius*cos(phi);

    TriaSphere.push_back(Triangle(points));
  }

  return TriaSphere;
}