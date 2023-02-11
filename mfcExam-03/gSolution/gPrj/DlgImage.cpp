// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
	m_bDraw = false;
	m_nRadius = 100;
	m_nStartX = 0;
	m_nStartY = 0;
	m_nCenterX = 0;
	m_nCenterY = 0;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(_T("Origin Image"));
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image)
		m_image.Draw(dc, 0, 0);
		drawCopy(&dc);
	
	if (m_bDraw) {
		drawData(&dc);
		m_bDraw = false;
	}
	
	
	
}

void CDlgImage::drawData(CDC *pDC)
{
	CRect rect;
	CPen pen1, pen2;
	pen1.CreatePen(PS_SOLID, 5, RGB(0xff, 0xff, 0x00));
	CPen* oldPen = pDC->SelectObject(&pen1);
	rect.SetRect(m_nStartX, m_nStartY, m_nStartX + m_nRadius, m_nStartY + m_nRadius);
	rect.InflateRect(rect);
	pDC->Ellipse(rect);
	pen2.CreatePen(PS_SOLID, 1, RGB(0xff, 0x00, 0x00));
	oldPen = pDC->SelectObject(&pen2);
	pDC->MoveTo(m_nCenterX - 5, m_nCenterY);
	pDC->LineTo(m_nCenterX + 5, m_nCenterY);
	pDC->MoveTo(m_nCenterX, m_nCenterY - 5);
	pDC->LineTo(m_nCenterX, m_nCenterY + 5);

}

void CDlgImage::drawCopy(CDC* pDC)
{
	CRect rect;
	CPen pen3;
	pen3.CreatePen(PS_SOLID, 5, RGB(0xff, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen3);
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(5, 5);
		pDC->Ellipse(rect);

	}
}