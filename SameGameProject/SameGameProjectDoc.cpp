// SameGameProjectDoc.cpp : implementation of the CSameGameProjectDoc class
//

#include "stdafx.h"
#include "SameGameProject.h"

#include "SameGameProjectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSameGameProjectDoc

IMPLEMENT_DYNCREATE(CSameGameProjectDoc, CDocument)
BEGIN_MESSAGE_MAP(CSameGameProjectDoc, CDocument)
END_MESSAGE_MAP()


// CSameGameProjectDoc construction/destruction

CSameGameProjectDoc::CSameGameProjectDoc()
{
}

CSameGameProjectDoc::~CSameGameProjectDoc()
{
}

BOOL CSameGameProjectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Set or reset game board
	m_board.SetupBoard();

	return TRUE;
}




// CSameGameProjectDoc serialization

void CSameGameProjectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CSameGameProjectDoc diagnostics

#ifdef _DEBUG
void CSameGameProjectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSameGameProjectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSameGameProjectDoc commands
