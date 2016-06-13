
// MapiMuleIIView.cpp : implementation of the CMapiMuleIIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MapiMuleII.h"
#endif

#include "MapiMuleIIDoc.h"
#include "MapiMuleIIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapiMuleIIView

IMPLEMENT_DYNCREATE(CMapiMuleIIView, CView)

BEGIN_MESSAGE_MAP(CMapiMuleIIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMapiMuleIIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMapiMuleIIView construction/destruction

CMapiMuleIIView::CMapiMuleIIView()
{
	// TODO: add construction code here

}

CMapiMuleIIView::~CMapiMuleIIView()
{
}

BOOL CMapiMuleIIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMapiMuleIIView drawing

void CMapiMuleIIView::OnDraw(CDC* /*pDC*/)
{
	CMapiMuleIIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMapiMuleIIView printing


void CMapiMuleIIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMapiMuleIIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMapiMuleIIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMapiMuleIIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMapiMuleIIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMapiMuleIIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMapiMuleIIView diagnostics

#ifdef _DEBUG
void CMapiMuleIIView::AssertValid() const
{
	CView::AssertValid();
}

void CMapiMuleIIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapiMuleIIDoc* CMapiMuleIIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapiMuleIIDoc)));
	return (CMapiMuleIIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMapiMuleIIView message handlers
