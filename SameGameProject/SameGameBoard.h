#pragma once

class SameGameBoard
{
public:
	/* Base Constructor */
	SameGameBoard(void);
	/* Base Destructor */
	~SameGameBoard(void);
	/* Function to randomly setup the board
	Plan to have option for number of colors later */
	void SetupBoard(void);
	/* Get color at location on board */
	COLORREF GetSpaceColor(int row, int col);
	/* Accessor functions */
	int GetWidth(void) const { return m_nWidth; }
	int GetHeight(void) const { return m_nHeight; }
	int GetColumns(void) const { return m_nColumns; }
	int GetRows(void) const { return m_nRows; }
	/* Delete board and free up memory */
	void DeleteBoard(void);
	/* Is the game over? */
	bool IsGameOver(void) const;
	/* Get number of remaining blocks */
	int GetRemainingCount(void) const { return m_nRemaining; }
	/* Function to delete blocks */
	int DeleteBlocks(int row, int col);
private:
	/* Function to create board and allocate memory */
	void CreateBoard(void);
	/* Direction enumeration (for deleting blocks) */
	enum Direction
	{
		DIRECTION_UP,
		DIRECTION_DOWN,
		DIRECTION_LEFT,
		DIRECTION_RIGHT
	};
	/* Recursive function for deleting blocks */
	int DeleteAdjacentBlocks(int row, int col, int color, 
							Direction direction);
	/* Fuction to compact board after block deletion */
	void CompactBoard(void);
	/* 2D array pointer */
	int** m_arrBoard;
	/* list of colors, 0 is background */
	COLORREF m_arrColors[4];
	/* Board size */
	int m_nColumns;
	int m_nRows;
	int m_nHeight;
	int m_nWidth;
	int m_nRemaining;
};
