#pragma once


// CDlgImage ��ȭ �����Դϴ�.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_image;
	int m_nDataCount = 0;  //������ ����
	CPoint m_ptData[100];
	bool		m_bDraw;
	int			m_nRadius;
	int			m_nStartX, m_nStartY;
	int			m_nCenterX, m_nCenterY;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
