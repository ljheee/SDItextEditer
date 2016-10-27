
// SDItextEditerView.cpp : CSDItextEditerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSDItextEditerView 构造/析构

CSDItextEditerView::CSDItextEditerView()
{
	// TODO:  在此处添加构造代码

}

CSDItextEditerView::~CSDItextEditerView()
{
}

BOOL CSDItextEditerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSDItextEditerView 绘制

void CSDItextEditerView::OnDraw(CDC* /*pDC*/)
{
	CSDItextEditerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CSDItextEditerView 打印

BOOL CSDItextEditerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSDItextEditerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CSDItextEditerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CSDItextEditerView 诊断

#ifdef _DEBUG
void CSDItextEditerView::AssertValid() const
{
	CView::AssertValid();
}

void CSDItextEditerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDItextEditerDoc* CSDItextEditerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDItextEditerDoc)));
	return (CSDItextEditerDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDItextEditerView 消息处理程序



//2.响应WM_CHAR消息，按下字符显示
void CSDItextEditerView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_strLine += (unsigned char)nChar;

	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(100,_T("宋体"),&dc);
	dc.SelectObject(font);
	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if (nChar == 0x0d){//
		m_strLine = "";
		m_ptLine.y += tm.tmHeight;
	}
	else if (nChar == 0x08){//
		COLORREF oldcol;
		oldcol = dc.SetTextColor(GetBkColor(dc.m_hDC));
		dc.TextOutW(m_ptLine.x , m_ptLine.y ,m_strLine);
		dc.SetTextColor(oldcol);

		int nCount = m_strLine.GetLength();
		nCount--;
		m_strLine = m_strLine.Left(nCount);
				
	}

	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptLine.x + sz.cx;
	pt.y = m_ptLine.y;

	SetCaretPos(pt);
	dc.TextOutW(m_ptLine.x, m_ptLine.y, m_strLine);

	CView::OnChar(nChar, nRepCnt, nFlags);
}

//3.响应WM_Lbuttondown，改变提示符位置
void CSDItextEditerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_ptLine = point;
	m_strLine = "";
	CView::OnLButtonDown(nFlags, point);
}
