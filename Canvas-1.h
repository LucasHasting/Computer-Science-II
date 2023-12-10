/*
Name: Lucas Hasting
Project Number: 3
File Name: Canvas.h
Project Description: Allows the user to draw on a grid with a size chosen by the user by typing in a number as a position
Course: CS 255
Instructor: Janet Jenkins
*/

#ifndef _CANVAS_H
#define _CANVAS_H

#include <iostream>
using namespace std;

const int ROW = 4;
const int COL = 4;
class Canvas{
    int **board = nullptr;
	char **image = nullptr;
	int row = ROW;
    int col = COL;
	bool check;
	int lastPos;
public:
	Canvas();
	Canvas(const int size);
	Canvas(Canvas &canvas);
	Canvas(const int r, const int c);
	~Canvas();
	Canvas &operator=(Canvas &canvas);
	void Init();
	void AllocateImage();
	void DeallocateImage();
	void AllocateBoard();
	void DeallocateBoard();
	void DrawImage()const;
	void DrawBoard()const;
	void Reset();
	int InputPos()const;
	void Draw(const int pos);
	void Undo();
};

#endif
