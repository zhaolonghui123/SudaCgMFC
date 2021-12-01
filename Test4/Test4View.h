
// Test4View.h: CTest4View 类的接口
//

#pragma once
#include "Fence.h"
#include"P2.h"
#include"Transform2.h"
#include"Cube.h"
#include"Transform3.h"
#include"P3.h"
#include"Projection.h"
#include"Xin.h"
#include"CStar.h"
#include"Sphere.h"
#include"Read1.h"
#include"Read2.h"
class CTest4View : public CView
{
protected: // 仅从序列化创建
	CTest4View() noexcept;
	DECLARE_DYNCREATE(CTest4View)

// 特性
public:
	CTest4Doc* GetDocument() const;

// 操作
public:
	void DrawObject(CDC* pDC);
	void DoubleBuffer(CDC* pDC);
	enum class ProjectionType
	{
		PerspectiveProjection, ObliqueProjection, OrthogonalProjection, ViewTransform1, ViewTransform2
	}m_ProjectionType;

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
	virtual ~CTest4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CFence fence[5];
	//CTransform2 transform[5];
	CP2 CenterPoint[5];
	CTransform3 transform;
	CCube cube;
	CStar star;
	CXin xin;
	CRead1 read;
	CRead2 read2;
	CSphere sphere;
	double Alpha, Beta;
	double Phi, Psi;
	double R, d;
	BOOL bPlay;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnHuitu1();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnOrthogonalProjection();
	afx_msg void OnObliqueProjection();
	afx_msg void OnPerspectiveProjection();
	afx_msg void OnViewTransform1();
	afx_msg void OnViewTransform2();
};

#ifndef _DEBUG  // Test4View.cpp 中的调试版本
inline CTest4Doc* CTest4View::GetDocument() const
   { return reinterpret_cast<CTest4Doc*>(m_pDocument); }
#endif

