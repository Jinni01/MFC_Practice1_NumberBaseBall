
// NumberBaseBallDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CNumberBaseBallDlg ��ȭ ����
class CNumberBaseBallDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CNumberBaseBallDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NUMBERBASEBALL_DIALOG };

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
	CString m_edtInput;
	CListBox m_lstResult;
	afx_msg void OnBnClickedNumberbaseballOutputBtn();

	const int m_nGameSize;
	int* m_pAnswer;
	int* m_pInputToIntegerArray;
	void SwapInt(int* x, int* y);
	int RandomRange(int min, int max);
	void SetGame();
	int * CStringToIntegerArray(const CString& strNums);
	void RefreshInputField();
	BOOL DiscriminateAnswer(const int* const input);
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
