//Tasnim Mahmud
//txm171830@utdallas.edu
//CS 3377.501

//These are the header files
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "cdk.h"
#include <fstream>
#include <sstream>
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 18
#define MATRIX_NAME_STRING "Binary File Contents"
const int maxRecordStringLength = 25;

using namespace std;

//This begins the class for Binary File Header
class BinaryFileHeader
{
public: 
uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};
//This begins the class for Binary File Record
class BinaryFileRecord
{
public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

//Begins main 
int main()
{
  WINDOW        *window;
  CDKSCREEN     *cdkscreen;
  CDKMATRIX     *myMatrix;

  const char            *rowTitles[] = {"R0", "R1", "R2", "R3", "R4", "R5"};
  const char            *columnTitles[] = {"C0", "C1", "C2", "C3", "C4", "C5"};
  int           boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, \
			       BOX_WIDTH};
  int           boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  //this defines myMatrix
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
                          MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix == NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  drawCDKMatrix(myMatrix, true);

  ifstream binInfile ("cs3377.bin", ios::in | ios::binary);

  BinaryFileHeader *binaryHeader = new BinaryFileHeader();
  BinaryFileRecord *binaryRecord = new BinaryFileRecord();

  binInfile.read((char *) binaryHeader, sizeof(BinaryFileHeader));
  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));

  //types of string
  string MagicNumber, version, NumberOfRecords, stringlengthb,stringlengthB, stringlengthc, stringlengthC, stringlengthd, stringlengthD, stringlengthe, stringlengthE, seedMoney, leadership, entre, skillz;
  MagicNumber = "Magic: 0x";
  version = "Version: ";
  NumberOfRecords = "NumRecords: "; //this will print out the number of records
  stringlengthB = "strlen: ";  //this will print out the length of string B
  stringlengthC = "strlen: "; //this will print out the length of string C
  stringlengthD = "strlen: "; //this will print out the length of string D
  stringlengthE = "strlen: "; //this will print out the length of string E

  stringstream convert;

  convert << hex << uppercase << binaryHeader->magicNumber; //this gets the binaryHeader from magicNumber
  MagicNumber += convert.str();
  convert.str("");

  convert << dec << binaryHeader->versionNumber; //this gets the binaryHeader from versionNumber
  version += convert.str();
  convert.str("");

  convert << binaryHeader->numRecords;//this gets the binaryHeader from numRecords
  NumberOfRecords += convert.str();
  convert.str("");

  convert << binaryRecord->stringBuffer; //this gets the binaryRecord from stringBuffer
  stringlengthb = convert.str();
  convert.str("");
  convert << stringlengthb.length();
  stringlengthB += convert.str();
  convert.str("");

  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; //this gets the binaryRecord from stringBuffer
  stringlengthc = convert.str();
  convert.str("");
  convert << stringlengthc.length();
  stringlengthC += convert.str();
  convert.str("");

  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; //this gets the binaryRecord from stringBuffer
  stringlengthd = convert.str();
  convert.str("");
  convert << stringlengthd.length();
  stringlengthD += convert.str();
  convert.str("");

  binInfile.read((char *) binaryRecord, sizeof(BinaryFileRecord));
  convert << binaryRecord->stringBuffer; //this gets the binaryRecord from stringBuffer
  stringlengthe = convert.str();
  convert.str("");
  convert << stringlengthe.length();
  stringlengthE += convert.str();
  convert.str("");

  setCDKMatrixCell(myMatrix, 1, 1, MagicNumber.c_str());       //this will set the matrix cell for Magic Number
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());           //this will set the matrix cell for version
  setCDKMatrixCell(myMatrix, 1, 3, NumberOfRecords.c_str());   //this will set the matrix cell for Number of Records
  setCDKMatrixCell(myMatrix, 2, 1, stringlengthB.c_str());     //this will set the matrix cell for string length B
  setCDKMatrixCell(myMatrix, 2, 2, stringlengthb.c_str());     //this will set the matrix cell for string length b
  setCDKMatrixCell(myMatrix, 3, 1, stringlengthC.c_str());     //this will set the matrix cell for string length C
  setCDKMatrixCell(myMatrix, 3, 2, stringlengthc.c_str());     //this will set the matrix cell for string length c
  setCDKMatrixCell(myMatrix, 4, 1, stringlengthD.c_str());     //this will set the matrix cell for string length D
  setCDKMatrixCell(myMatrix, 4, 2, stringlengthd.c_str());     //this will set the matrix cell for string length d
  setCDKMatrixCell(myMatrix, 5, 1, stringlengthE.c_str());     //this will set the matrix cell for string length E
  setCDKMatrixCell(myMatrix, 5, 2, stringlengthe.c_str());     //this will set the matrix cell for string length e
  drawCDKMatrix(myMatrix, true);       //this will draw out the matrix 

  unsigned char x;
  cin >> x;

  endCDK();
}

