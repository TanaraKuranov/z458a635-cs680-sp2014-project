// SameGameProjectDoc.h : interface of the CSameGameProjectDoc class
//


#pragma once

#include "SameGameBoard.h"


class CSameGameProjectDoc : public CDocument
{
protected: // create from serialization only
	CSameGameProjectDoc();
	virtual ~CSameGameProjectDoc();
	DECLARE_DYNCREATE(CSameGameProjectDoc)

// Attributes
public:

// Operations
public:
	/* Added functions */
	COLORREF GetSpaceColor(int row, int col)
	{ return m_board.GetSpaceColor(row, col); }
	void SetupBoard(void) { m_board.SetupBoard(); }
	int GetWidth(void) { return m_board.GetWidth(); }
	int GetHeight(void) { return m_board.GetHeight(); }
	int GetColumns(void) { return m_board.GetColumns(); }
	int GetRows(void) { return m_board.GetRows(); }
	void DeleteBoard(void) { m_board.DeleteBoard(); }
	bool IsGameOver(void) { return m_board.IsGameOver(); }
	int DeleteBlocks(int row, int col)
	{ return m_board.DeleteBlocks(row, col); }
	int GetRemainingCount()
	{ return m_board.GetRemainingCount(); }

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

protected:
	/* Instance of game board */
	SameGameBoard m_board;

// Implementation
public:
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


