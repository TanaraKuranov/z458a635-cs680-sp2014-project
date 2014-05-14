// SameGameProjectView.h : interface of the CSameGameProjectView class
//


#pragma once


class CSameGameProjectView : public CView
{
protected: // create from serialization only
	CSameGameProjectView();
	DECLARE_DYNCREATE(CSameGameProjectView)

// Attributes
public:
	CSameGameProjectDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	/* Added for custom window size */
	void ResizeWindow();
	virtual ~CSameGameProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in SameGameProjectView.cpp
inline CSameGameProjectDoc* CSameGameProjectView::GetDocument() const
   { return reinterpret_cast<CSameGameProjectDoc*>(m_pDocument); }
#endif

