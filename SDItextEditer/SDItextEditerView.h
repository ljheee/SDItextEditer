
// SDItextEditerView.h : CSDItextEditerView 类的接口
//

#pragma once


class CSDItextEditerView : public CView
{
protected: // 仅从序列化创建
	CSDItextEditerView();
	DECLARE_DYNCREATE(CSDItextEditerView)

// 特性
public:
	CSDItextEditerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSDItextEditerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SDItextEditerView.cpp 中的调试版本
inline CSDItextEditerDoc* CSDItextEditerView::GetDocument() const
   { return reinterpret_cast<CSDItextEditerDoc*>(m_pDocument); }
#endif

