#pragma once

#include <iostream>
#include <vector>
#include "triangle.hpp"

using namespace std;

/*!
 * \author T. Kattmann
 * \class STL_tool
 * \brief Class for to read and write ASCII and binary stl-files.
 */

class STL_tool
{
  private:
    vector<Triangle> SurfTria; /*!< \brief List of Triangles with normal vector. */

  public:
    /*!
     * \brief Default constructor of the class.
     */
    STL_tool();

    /*!
     * \brief Destructor of the class.
     */
    ~STL_tool();

    /*!
     * \brief 
     */
    vector<Triangle> ReadASCII(string filename);

    /*!
     * \brief 
     */
    void WriteASCII(vector<Triangle> SurfTria, string filename);

    /*!
     * \brief 
     */
    vector<Triangle> ReadBinary(string filename);

    /*!
     * \brief 
     */
    void WriteBinary(vector<Triangle> SurfTria, string filename);

};