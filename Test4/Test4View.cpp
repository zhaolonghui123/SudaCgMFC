
// Test4View.cpp: CTest4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test4.h"
#endif

#include "Test4Doc.h"
#include "Test4View.h"
#define PI 3.14159265

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest4View

IMPLEMENT_DYNCREATE(CTest4View, CView)

BEGIN_MESSAGE_MAP(CTest4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_HUITU_1, &CTest4View::OnOrthogonalProjection)
	ON_COMMAND(ID_32772, &CTest4View::OnObliqueProjection)
	ON_COMMAND(ID_32773, &CTest4View::OnPerspectiveProjection)

	ON_COMMAND(ID_32774, &CTest4View::OnViewTransform1)
	ON_COMMAND(ID_32775, &CTest4View::OnViewTransform2)
	ON_COMMAND(ID_32776, &CTest4View::OnCube)
	ON_COMMAND(ID_32777, &CTest4View::OnXin)
	ON_COMMAND(ID_32779, &CTest4View::OnSphere)
	ON_COMMAND(ID_32780, &CTest4View::OnViewTransform3)
END_MESSAGE_MAP()

// CTest4View 构造/析构

CTest4View::CTest4View() noexcept
{
	// TODO: 在此处添加构造代码
	R = 1200, d = 800;
	Phi =45.0, Psi = 45.0;
	Alpha = 0.0, Beta = 0.0;
	T = 0;
	bPlay = FALSE;

	m_ProjectionType = ProjectionType::PerspectiveProjection;
	m_ModelType = ModelType::CRead;
	xin.projection.SetEye(Phi, Psi, R, d);
	xin.ReadPoint();
	xin.ReadFacet();
	cube.projection.SetEye(Phi, Psi, R, d);
	cube.ReadPoint();
	cube.ReadFacet();
	sphere.projection.SetEye(Phi, Psi, R, d);
	read2.projection.SetEye(Phi, Psi, R, d);
	read2.ReadPoint();
	read2.ReadFacet();
		
	transform1.SetMatrix(cube.GetVertexArrayName(), 8);
	double nEdge1 = 200;

		
	transform2.SetMatrix(xin.GetVertexArrayName(), 24);
	double nEdge2 = 100;

	transform3.SetMatrix(read2.GetVertexArrayName(), 19231);
	double nEdge3 = 50;

	/*star.projection.SetEye(Phi, Psi, R, d);
	star.ReadPoint();
	star.ReadFacet();
	transform.SetMatrix(star.GetVertexArrayName(), 12);*/
	/*read.projection.SetEye(Phi, Psi, R, d);
	read.ReadPoint();
	read.ReadFacet();
	transform.SetMatrix(read.GetVertexArrayName(), 6527);*/
	transform1.Scale(nEdge1, nEdge1, nEdge1);
	transform1.Translate(-nEdge1 / 2, -nEdge1 / 2, -nEdge1 / 2);

	transform2.Scale(nEdge2, nEdge2, nEdge2);
	transform2.Translate(-nEdge1 / 2, -nEdge2 / 2, -nEdge2 / 2);

	transform3.Scale(nEdge3, nEdge3, nEdge3);
	transform3.Translate(-nEdge3 / 2, -nEdge3 / 2, -nEdge3 / 2);

}

CTest4View::~CTest4View()
{
}

BOOL CTest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTest4View 绘图

void CTest4View::DrawObject(CDC* pDC)
{
	CZBuffer* pZBuffer = new CZBuffer;//申请内存
	pZBuffer->InitialDepthBuffer(5000, 5000, 5000);//初始化深度缓冲器
	//xin.Draw2(pDC, pZBuffer);
	if (m_ProjectionType == ProjectionType::OrthogonalProjection) {
		if (m_ModelType == ModelType::CCube) {
			cube.Draw(pDC, pZBuffer);
		}
		else if (m_ModelType == ModelType::CXin) {
			xin.Draw(pDC, pZBuffer);
		}
		else if (m_ModelType == ModelType::CSphere) {
			sphere.Draw(pDC, pZBuffer);
		}
		else
		{
			read2.Draw(pDC, pZBuffer);
		}
	}
	else
	{
		if (m_ModelType == ModelType::CCube) {
			cube.Draw2(pDC, pZBuffer);
		}
		else if (m_ModelType == ModelType::CXin) {
			xin.Draw2(pDC, pZBuffer);
		}
		else if (m_ModelType == ModelType::CSphere) {
			sphere.Draw(pDC, pZBuffer);
		}
		else
		{
			read2.Draw2(pDC, pZBuffer);
		}
	}
	delete pZBuffer;//释放内存
}

void CTest4View::DoubleBuffer(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap NewBitmap, * pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = memDC.SelectObject(&NewBitmap);
	memDC.FillSolidRect(rect, pDC->GetBkColor());
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	DrawObject(&memDC);
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
}

void CTest4View::OnDraw(CDC* pDC)
{
	CTest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}


// CTest4View 打印

BOOL CTest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTest4View 诊断

#ifdef _DEBUG
void CTest4View::AssertValid() const
{
	CView::AssertValid();
}

void CTest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest4Doc* CTest4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest4Doc)));
	return (CTest4Doc*)m_pDocument;
}
#endif //_DEBUG






void CTest4View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!bPlay)
	{
		if (m_ProjectionType == ProjectionType::ViewTransform1)
		{
			switch (nChar)
			{
			case VK_UP: {
				R += 50;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi, R, d);
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi, R, d);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi, R, d);
				}
				//star.projection.SetEye(Phi, Psi, R, d);
				break;
			}
			case VK_DOWN: {
				R -= 50;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi, R, d);
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi, R, d);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi, R, d);
				}
				//star.projection.SetEye(Phi, Psi, R, d);
				break;
			}
			default: {
				break; }
			}
			Invalidate(FALSE);
		}
		else if(m_ProjectionType == ProjectionType::ViewTransform2)
		{
			switch (nChar)
			{
			case VK_UP: {
				Phi += 5;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi);
					cube.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi);
					xin.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi);
					read2.projection.InitialParameter();
				}
				//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_DOWN: {
				Phi -= 5;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi);
					cube.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi);
					xin.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi);
					read2.projection.InitialParameter();
				}//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_LEFT: {
				Psi += 5;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi);
					cube.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi);
					xin.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi);
					read2.projection.InitialParameter();
				}//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_RIGHT: {
				Psi -= 5;
				if (m_ModelType == ModelType::CCube) {
					cube.projection.SetEye(Phi, Psi);
					cube.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CXin) {
					xin.projection.SetEye(Phi, Psi);
					xin.projection.InitialParameter();
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					read2.projection.SetEye(Phi, Psi);
					read2.projection.InitialParameter();
				}//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			default: {
				break; }
			}
			Invalidate(FALSE);
		}
		else if (m_ProjectionType == ProjectionType::ViewTransform3) 
		{
			switch (nChar)
			{
			case VK_UP: {
				T = +2;
				if (m_ModelType == ModelType::CCube) {
					transform1.Translate(T, 0, 0);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.Translate(T, 0, 0);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.Translate(T, 0, 0);
				}
				break;
			}
			case VK_DOWN: {
				T = -2;
				if (m_ModelType == ModelType::CCube) {
					transform1.Translate(T, 0, 0);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.Translate(T, 0, 0);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.Translate(T, 0, 0);
				}
				break;
			}
			case VK_LEFT: {
				T = -2;
				if (m_ModelType == ModelType::CCube) {
					transform1.Translate(0, T, 0);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.Translate(0, T, 0);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.Translate(0, T, 0);
				}
				break;
			}
			case VK_RIGHT: {
				T = +2;
				if (m_ModelType == ModelType::CCube) {
					transform1.Translate(0, T, 0);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.Translate(0, T, 0);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.Translate(0, T, 0);
				}
				break;
			}
			default: 
			{
				break; 
			}Invalidate(FALSE);
			}
		}
		else
		{
			switch (nChar)
			{
			case VK_UP: {
				Alpha = -2;
				if (m_ModelType == ModelType::CCube) {
					transform1.RotateX(Alpha);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.RotateX(Alpha);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.RotateX(Alpha);
				}
				break;
			}
			case VK_DOWN: {
				Alpha = +2;
				if (m_ModelType == ModelType::CCube) {
					transform1.RotateX(Alpha);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.RotateX(Alpha);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.RotateX(Alpha);
				}
				break;
			}
			case VK_LEFT: {
				Beta = -2;
				if (m_ModelType == ModelType::CCube) {
					transform1.RotateY(Beta);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.RotateY(Beta);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.RotateY(Beta);
				}
				break;
			}
			case VK_RIGHT: {
				Beta = +2;
				if (m_ModelType == ModelType::CCube) {
					transform1.RotateY(Beta);
				}
				else if (m_ModelType == ModelType::CXin) {
					transform2.RotateY(Beta);
				}
				else if (m_ModelType == ModelType::CSphere) {

				}
				else
				{
					transform3.RotateY(Beta);
				}
				break;
			}
			default: {
				break; }
			}
			Invalidate(FALSE);
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTest4View::OnOrthogonalProjection()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::OrthogonalProjection;
	Invalidate(FALSE);
}


void CTest4View::OnObliqueProjection()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::ObliqueProjection;
	Invalidate(FALSE);
}


void CTest4View::OnPerspectiveProjection()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::PerspectiveProjection;
	Invalidate(FALSE);
}




void CTest4View::OnViewTransform1()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::ViewTransform1;
	Invalidate(FALSE);
}


void CTest4View::OnViewTransform2()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::ViewTransform2;
	Invalidate(FALSE);
}


void CTest4View::OnCube()
{
	// TODO: 在此添加命令处理程序代码
	m_ModelType = ModelType::CCube;
	Invalidate(FALSE);
}


void CTest4View::OnXin()
{
	// TODO: 在此添加命令处理程序代码
	m_ModelType = ModelType::CXin;
	Invalidate(FALSE);
}


void CTest4View::OnSphere()
{
	// TODO: 在此添加命令处理程序代码
	m_ModelType = ModelType::CSphere;
	Invalidate(FALSE);
}


void CTest4View::OnViewTransform3()
{
	// TODO: 在此添加命令处理程序代码
	m_ProjectionType = ProjectionType::ViewTransform3;
	Invalidate(FALSE);
}
