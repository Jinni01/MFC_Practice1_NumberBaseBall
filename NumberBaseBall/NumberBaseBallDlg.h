
// NumberBaseBallDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CNumberBaseBallDlg 대화 상자
class CNumberBaseBallDlg : public CDialogEx
{
// 생성입니다.
public:
	CNumberBaseBallDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NUMBERBASEBALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
