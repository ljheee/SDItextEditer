
// SDItextEditerView.h : CSDItextEditerView ��Ľӿ�
//

#pragma once


class CSDItextEditerView : public CView
{
protected: // �������л�����
	CSDItextEditerView();
	DECLARE_DYNCREATE(CSDItextEditerView)

// ����
public:
	CSDItextEditerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSDItextEditerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SDItextEditerView.cpp �еĵ��԰汾
inline CSDItextEditerDoc* CSDItextEditerView::GetDocument() const
   { return reinterpret_cast<CSDItextEditerDoc*>(m_pDocument); }
#endif

