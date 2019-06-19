#pragma once

#include <iostream>

using namespace std;

/*!
 * \author T. Kattmann
 * \class Triangle
 * \brief Class for a Triangle. Holds Coordiantes and normal.
 */
class Triangle
{
  private:
    double** PointCoords; /*!< \brief Coordinates(x,y,z) for the 3 points defining a triangle. */
    double* Normal; /*!< \brief Unit normal vector computed after right hand rule. */

  public:
    /*!
     * \brief Default constructor of the class.
     */
    Triangle();

    /*!
     * \brief Destructor of the class.
     */
    ~Triangle();

    /*!
     * \brief Constructor of the class. Fills point coordinates and computes unit normal.
     * \param[in] values - 9 double array with 3*3 coordinates
     */
    Triangle(double* values);

    /*!
     * \brief Constructor of the class. Fills point coordinates and computes unit normal.
     * \param[in] values - 9 float array with 3*3 coordinates. Gets converted to double.
     */
    Triangle(float* values);

    /*!
     * \brief Sets a coordinate of a Point.
     * \param[in] Point - Point number {0,1,2}
     * \param[in] Coord - {x,y,z}-Coordinate of the Point
     * \param[in] value - Coordinate value
     */
    void SetPointCoords(int Point, int Coord, double value);

    /*
     * \brief Fills a point with the 3*3 values given in a row and computes normal.
     * \param[in] values - 9 double array with 3*3 coordinates
     */
    void SetPointCoords(double* values);

    /*!
     * \brief Default constructor.
     * \param[in] Point - Point number {0,1,2}
     * \param[in] Coord - {x,y,z}-Coordinate of the Point
     * \return Value of a Point Coordinate
     */
    double GetPointCoords(int Point, int Coord);

    /*
     * \brief Computes the unit normal of the triangle based on the right-hand-rule.
     */
    void ComputeNormal();

    /*
     * \brief Return entry of the Normal vector.
     * \param[in] Coord - {x,y,z}-Coordinate identifier {0,1,2} 
     * \return Value of the Normal Vector entry
     */
    double GetNormal(int Coord);

    /*
     * \brief Prints point coordinates in console.
     */
    void PrintPointCoords();

    /*
     * \brief Prints normal vector into console.
     */
    void PrintNormal();

};
