// SameGameProjectView.cpp : implementation of the CSameGameProjectView class
//

#include "stdafx.h"
#include "SameGameProject.h"

#include "SameGameProjectDoc.h"
#include "SameGameProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSameGameProjectView

IMPLEMENT_DYNCREATE(CSameGameProjectView, CView)
BEGIN_MESSAGE_MAP(CSameGameProjectView, CView)
  ON_WM_LBUTTONDOWN()
  ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CSameGameProjectView construction/destruction

CSameGameProjectView::CSameGameProjectView()
{
}

CSameGameProjectView::~CSameGameProjectView()
{
}

BOOL CSameGameProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CSameGameProjectView drawing

void CSameGameProjectView::OnDraw(CDC* pDC)
{
	CSameGameProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// Save current device context state
	int nDCSave = pDC -> SaveDC();
	// Get client rectangle
	CRect rcClient;
	GetClientRect(&rcClient);
	// Get background color
	COLORREF clr = pDoc -> GetSpaceColor(-1, -1);
	// Draw the background first
	pDC -> FillSolidRect(&rcClient, clr);
	// Create drawing brush
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC -> SelectObject(&br);
	// Draw the spaces
	for(int row = 0; row < pDoc -> GetRows(); row++)
	{
		for(int col = 0; col < pDoc -> GetColumns(); col++)
		{
			// Get color for board space
			clr = pDoc -> GetSpaceColor(row, col);
			// Calculate size and position
			CRect rcBlock;
			rcBlock.top = row * pDoc -> GetHeight();
			rcBlock.left = col * pDoc -> GetWidth();
			rcBlock.right = rcBlock.left + pDoc -> GetWidth();
			rcBlock.bottom = rcBlock.top + pDoc -> GetHeight();
			// Fill in the block with color
			pDC -> FillSolidRect(&rcBlock, clr);
			// Draw outline
			pDC -> Rectangle(&rcBlock);
		}
	}
	// Restore device context settings
	pDC -> RestoreDC(nDCSave);
	br.DeleteObject();
}


// CSameGameProjectView diagnostics

#ifdef _DEBUG
void CSameGameProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CSameGameProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSameGameProjectDoc* CSameGameProjectView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSameGameProjectDoc)));
	return (CSameGameProjectDoc*)m_pDocument;
}
#endif //_DEBUG

void CSameGameProjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// Resize the window
	ResizeWindow();
}

void CSameGameProjectView::ResizeWindow()
{
	// First get a pointer to the document
	CSameGameProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc)
		return;
	// Get client area and window size
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame() -> GetWindowRect(&rcWindow);
	// Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	// Change window size based on game board
	rcWindow.right = rcWindow.left + 
		(pDoc -> GetWidth() * pDoc -> GetColumns()) + nWidthDiff;
	rcWindow.bottom = rcWindow.top + 
		(pDoc -> GetHeight() * pDoc -> GetRows()) + nHeightDiff;
	// The MoveWindow function resizes window
	GetParentFrame() -> MoveWindow(&rcWindow);
}

void CSameGameProjectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// get document pointer
	CSameGameProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// Get row and column clicked on
	int row = point.y / pDoc -> GetHeight();
	int col = point.x / pDoc -> GetWidth();
	// Delete the group of blocks
	int count = pDoc -> DeleteBlocks(row, col);
	// Check if blocks deleted
	if (count > 0)
	{
		// Redraw window
		Invalidate();
		UpdateWindow();
		// Check if game is over
		if(pDoc -> IsGameOver())
		{
			// Get remaining blocks
			int remain = pDoc -> GetRemainingCount();
			CString message;
			message.Format(_T("No more moves left!\nBlocks Remaining: %d"),
				remain);
			// Display results
			MessageBox(message, _T("Game Over"), MB_OK | MB_ICONINFORMATION);
		}
	}
	// Default
	CView::OnLButtonDown(nFlags, point);
}