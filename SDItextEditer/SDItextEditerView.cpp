
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
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSDItextEditerView ����/����

CSDItextEditerView::CSDItextEditerView()
{
	// TODO:  �ڴ˴���ӹ������
	m_nLength = 0;
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

void CSDItextEditerView::OnDraw(CDC* pDC)
{
	CSDItextEditerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	LOGBRUSH logBrush;
	brush.CreateBrushIndirect(&logBrush);
	CBrush *POldBrush = (CBrush*)pDC->SelectObject(&brush);
	CPen *pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);

	pDC->Pie(CRect(100, 100, 300, 300), CPoint(0, 0), CPoint(50, 200));

	pDC->SelectObject(POldBrush);
	pDC->SelectObject(pOldPen);

	CString str;
	str.LoadStringW(IDS_STR1);
	pDC->TextOutW(100,150 , str);

	CSize sz = pDC->GetTextExtent(str);
	CRect rect;
	rect.top = 150;
	rect.left = 100;
	rect.bottom = 150 + sz.cy;
	rect.right = 100 + sz.cx;

	pDC->BeginPath();//ͼ��
	pDC->Rectangle(rect);
	pDC->EndPath();

	pDC->SelectClipPath(RGN_AND);
	pDC->TextOutW(100,150,str);
	pDC->DrawText(str , CRect(100,200,200,300), 0 );


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
	CClientDC dc(this);

	CFont font;
	font.CreatePointFont(100,_T("����"),&dc);
	dc.SelectObject(font);
	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if (nChar == 0x0d){//�س���������
		m_strLine = "";
		m_ptLine.y += tm.tmHeight;
	}
	else if (nChar == 0x08){//Backspace����ɾ�����ñ���ɫ����ԭ�ַ��������ַ�����ȡǰ�˲��ػ�
		COLORREF oldcol;
		oldcol = dc.SetTextColor(GetBkColor(dc.m_hDC));
		dc.TextOutW(m_ptLine.x , m_ptLine.y ,m_strLine);
		dc.SetTextColor(oldcol);

		int nCount = m_strLine.GetLength();
		nCount--;
		m_strLine = m_strLine.Left(nCount);	
	}
	else
	m_strLine += (unsigned char)nChar;//׷���ַ�

	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptLine.x + sz.cx;
	pt.y = m_ptLine.y;

	SetCaretPos(pt);//�ƶ���ʾ��
	dc.TextOutW(m_ptLine.x, m_ptLine.y, m_strLine);//��ʾ�ַ����˴��Ǿֲ�����

	CView::OnChar(nChar, nRepCnt, nFlags);
}

//3.��ӦWM_Lbuttondown���ı���ʾ��λ��
void CSDItextEditerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_ptLine = point;
	m_strLine = "";
	CView::OnLButtonDown(nFlags, point);
}


void CSDItextEditerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nLength += 5;
	CString str;
	str.LoadStringW(IDS_STR1);

	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	if (m_nLength > sz.cx){
		m_nLength = 0;
		dc.SetTextColor(RGB(255 , 0,0));
		dc.TextOutW(100,300,str);
	}
	dc.DrawText(str,CRect(100,300,100+m_nLength, 300+sz.cy), 0 );

	CView::OnTimer(nIDEvent);
}
