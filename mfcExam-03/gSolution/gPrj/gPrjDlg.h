
// gPrjDlg.h : ��� ����
//
#include "DlgImage.h"

#pragma once


// CgPrjDlg ��ȭ ����
class CgPrjDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CgPrjDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CDlgImage *m_pDlgImage;
	CDlgImage *m_pDlgImgResult;


// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPRJ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	CImage m_Image;
	void callFunc(int n);
	afx_msg void OnBnClickedBtnTest();
	afx_msg void OnBnClickedBtnMakePattern();

	afx_msg void OnBnClickedBtnGetData();
	afx_msg void OnBnClickedBtnCircle();
	afx_msg void OnBnClickedBtnPaint();
	bool IsInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius);
};
