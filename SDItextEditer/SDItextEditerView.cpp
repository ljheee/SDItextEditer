
// SDItextEditerView.cpp : CSDItextEditerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SDItextEditer.h"
#endif

#include "SDItextEditerDoc.h"
#include "SDItextEditerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDItextEditerView

IMPLEMENT_DYNCREATE(CSDItextEditerView, CView)

BEGIN_MESSAGE_MAP(CSDItextEditerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSDItextEditerView ����/����

CSDItextEditerView::CSDItextEditerView()
{
	// TODO:  �ڴ˴���ӹ������

}

CSDItextEditerView::~CSDItextEditerView()
{
}

BOOL CSDItextEditerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSDItextEditerView ����

void CSDItextEditerView::OnDraw(CDC* /*pDC*/)
{
	CSDItextEditerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSDItextEditerView ��ӡ

BOOL CSDItextEditerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSDItextEditerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSDItextEditerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CSDItextEditerView ���

#ifdef _DEBUG
void CSDItextEditerView::AssertValid() const
{
	CView::AssertValid();
}

void CSDItextEditerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDItextEditerDoc* CSDItextEditerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDItextEditerDoc)));
	return (CSDItextEditerDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDItextEditerView ��Ϣ�������



//2.��ӦWM_CHAR��Ϣ�������ַ���ʾ
void CSDItextEditerView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC dc;
//	dc.TextOutW();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

//3.��ӦWM_Lbuttondown���ı���ʾ��λ��
void CSDItextEditerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	CView::OnLButtonDown(nFlags, point);
}
