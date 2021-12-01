
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
END_MESSAGE_MAP()

// CTest4View 构造/析构

CTest4View::CTest4View() noexcept
{
	// TODO: 在此处添加构造代码
	R = 1200, d = 800;
	Phi =45.0, Psi = 45.0;
	Alpha = 0.0, Beta = 0.0;
	bPlay = FALSE;
	m_ProjectionType = ProjectionType::PerspectiveProjection;
	/*cube.projection.SetEye(Phi, Psi, R, d);
	cube.ReadPoint();
	cube.ReadFacet();
	transform.SetMatrix(cube.GetVertexArrayName(), 8);*/
	double nEdge =50;
	/*xin.projection.SetEye(Phi, Psi, R, d);
	xin.ReadPoint();
	xin.ReadFacet();
	transform.SetMatrix(xin.GetVertexArrayName(), 24);*/
	//sphere.projection.SetEye(Phi, Psi, R, d);
	/*star.projection.SetEye(Phi, Psi, R, d);
	star.ReadPoint();
	star.ReadFacet();
	transform.SetMatrix(star.GetVertexArrayName(), 12);*/
	/*read.projection.SetEye(Phi, Psi, R, d);
	read.ReadPoint();
	read.ReadFacet();
	transform.SetMatrix(read.GetVertexArrayName(), 6527);*/
	read2.projection.SetEye(Phi, Psi, R, d);
	read2.ReadPoint();
	read2.ReadFacet();
	transform.SetMatrix(read2.GetVertexArrayName(), 19231);
	transform.Scale(nEdge, nEdge, nEdge);
	transform.Translate(-nEdge / 2, -nEdge / 2, -nEdge / 2);

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
		//cube.Draw(pDC);
		//xin.Draw2(pDC ,pZBuffer);
		//star.Draw(pDC);
		//sphere.Draw(pDC);
		read2.Draw(pDC,pZBuffer);
	}
	/*else if (m_ProjectionType == ProjectionType::ObliqueProjection) {
		cube.Draw2(pDC);
	}*/
	else
	{
		//star.Draw2(pDC);
		//xin.Draw2(pDC,pZBuffer);
		//sphere.Draw(pDC);
		//xin.Draw2(pDC,pZBuffer);
		read2.Draw2(pDC,pZBuffer);
	}
	delete pZBuffer;//释放内存
	/*switch (m_ProjectionType)
	{
	case ProjectionType::OrthogonalProjection:
	{
		Invalidate(FALSE);
		cube.Draw(pDC);
	}
	case ProjectionType::ObliqueProjection:
	{
		Invalidate(FALSE);
		cube.Draw2(pDC);
	}
	case ProjectionType::PerspectiveProjection:
	{
		Invalidate(FALSE);
		cube.Draw3(pDC);
	}
	default:
		break;
	}*/
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
				//cube.projection.SetEye(Phi, Psi, R, d);
				//xin.projection.SetEye(Phi, Psi, R, d);
				read2.projection.SetEye(Phi, Psi, R, d);
				//star.projection.SetEye(Phi, Psi, R, d);
				break;
			}
			case VK_DOWN: {
				R -= 50;
				//cube.projection.SetEye(Phi, Psi, R, d);
				//xin.projection.SetEye(Phi, Psi, R, d);
				read2.projection.SetEye(Phi, Psi, R, d);
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
				//cube.projection.SetEye(Phi, Psi);
				//cube.projection.InitialParameter();
				//xin.projection.SetEye(Phi, Psi);
				//xin.projection.InitialParameter();
				read2.projection.SetEye(Phi, Psi);
				read2.projection.InitialParameter();
				//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_DOWN: {
				Phi -= 5;
				//cube.projection.SetEye(Phi, Psi);
				//cube.projection.InitialParameter();
				//xin.projection.SetEye(Phi, Psi);
				//xin.projection.InitialParameter();
				read.projection.SetEye(Phi, Psi);
				read.projection.InitialParameter();//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_LEFT: {
				Psi += 5;
				//cube.projection.SetEye(Phi, Psi);
				//cube.projection.InitialParameter();
				//xin.projection.SetEye(Phi, Psi);
				//xin.projection.InitialParameter();
				read2.projection.SetEye(Phi, Psi);
				read2.projection.InitialParameter();//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			case VK_RIGHT: {
				Psi -= 5;
				//cube.projection.SetEye(Phi, Psi);
				//cube.projection.InitialParameter();
				//xin.projection.SetEye(Phi, Psi);
				//xin.projection.InitialParameter();
				read2.projection.SetEye(Phi, Psi);
				read.projection.InitialParameter();//star.projection.SetEye(Phi, Psi);
				//star.projection.InitialParameter();
				break;
			}
			default: {
				break; }
			}
			Invalidate(FALSE);
		}
		else
		{
			switch (nChar)
			{
			case VK_UP: {
				Alpha = -2;
				transform.RotateX(Alpha);
				break;
			}
			case VK_DOWN: {
				Alpha = +2;
				transform.RotateX(Alpha);
				break;
			}
			case VK_LEFT: {
				Beta = -2;
				transform.RotateY(Beta);
				break;
			}
			case VK_RIGHT: {
				Beta = +2;
				transform.RotateY(Beta);
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
