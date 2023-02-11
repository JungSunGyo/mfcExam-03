#pragma once


// CDlgImage 대화 상자입니다.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_image;
	int m_nDataCount = 0;  //점들의 갯수
	CPoint m_ptData[100];
	bool		m_bDraw;
	int			m_nRadius;
	int			m_nStartX, m_nStartY;
	int			m_nCenterX, m_nCenterY;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();

private:
	void InitImage();
//	void drawData(CDC* pDC);
public:
	afx_msg void OnPaint();
	void 	drawData(CDC* pDC);
	void drawCopy(CDC* pDC);
};
