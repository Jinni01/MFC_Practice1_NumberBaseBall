
// NumberBaseBallDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "NumberBaseBall.h"
#include "NumberBaseBallDlg.h"
#include "afxdialogex.h"

#include <ctime>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDestroy();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CNumberBaseBallDlg ��ȭ ����



CNumberBaseBallDlg::CNumberBaseBallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNumberBaseBallDlg::IDD, pParent)
	, m_edtInput(_T("")), m_nGameSize(4)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNumberBaseBallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMBERBASEBALL_INPUT_EDT, m_edtInput);
	DDV_MaxChars(pDX, m_edtInput, 4);
	DDX_Control(pDX, IDC_NUMBERBASEBALL_RESULT_LIST, m_lstResult);
}

BEGIN_MESSAGE_MAP(CNumberBaseBallDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NUMBERBASEBALL_OUTPUT_BTN, &CNumberBaseBallDlg::OnBnClickedNumberbaseballOutputBtn)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CNumberBaseBallDlg �޽��� ó����

BOOL CNumberBaseBallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetGame();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CNumberBaseBallDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CNumberBaseBallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CNumberBaseBallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNumberBaseBallDlg::OnBnClickedNumberbaseballOutputBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTmp = _T("");
	strTmp.Format(_T("%d %d %d %d"), m_pAnswer[0],m_pAnswer[1],m_pAnswer[2],m_pAnswer[3]);
	TRACE(strTmp);
	UpdateData();
	int* pInputToIntegerArray = CStringToIntegerArray(m_edtInput);


	if(DiscriminateAnswer(pInputToIntegerArray)){
		delete[] pInputToIntegerArray;
		int nOK = AfxMessageBox(_T("�����Դϴ�!! �����Ͻðڽ��ϱ�?"), MB_YESNO);
		if ( nOK == IDYES){
			CDialogEx::OnOK();
		}
	}
	//CDialogEx::OnOK();
	else
	{
		delete[] pInputToIntegerArray;
	}
}

//�߰� ����
void CNumberBaseBallDlg::SwapInt(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int CNumberBaseBallDlg::RandomRange(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void CNumberBaseBallDlg::SetGame()
{
	srand((unsigned int)time(0));

	m_pAnswer = new int[m_nGameSize];

	int aCollection[] = {1,2,3,4,5,6,7,8,9,0};

	for(int i=0; i<m_nGameSize; ++i)
	{
		int nIndex = RandomRange(0, 9-i);
		m_pAnswer[i] = aCollection[nIndex];
		SwapInt(&aCollection[nIndex], &aCollection[9-i]);
	}
}

int* CNumberBaseBallDlg::CStringToIntegerArray(const CString& strNums)
{
	int* pCStrToIntegerArray = new int[m_nGameSize];
	int nValue = _ttoi(strNums);

	for(int i=0; i<4; ++i)
	{
		int nDivide = static_cast<int>(1000 / std::pow(10, i));
		pCStrToIntegerArray[i] = nValue / nDivide;
		nValue = nValue - (nDivide * pCStrToIntegerArray[i]);
	}

	return pCStrToIntegerArray;
}

void CNumberBaseBallDlg::RefreshInputField(){
	m_edtInput = _T("");
	UpdateData(FALSE);
}

BOOL CNumberBaseBallDlg::DiscriminateAnswer(const int* const input)
{
	int nStrike = 0, nBall = 0;
	BOOL bFlag = FALSE;

	for(int i=0; i<m_nGameSize; ++i)
	{
		for(int j=0; j<m_nGameSize; ++j)
		{
			if(input[i] == m_pAnswer[j])
			{
				if(i == j){
					nStrike++;
				}
				else{
					nBall++;
				}
			}
		}
	}
	CString strTmp = _T("");
	strTmp.Format(_T("%ds %db ( �Է°�: %s )"), nStrike, nBall, m_edtInput);
	m_lstResult.InsertString(0, strTmp);
	RefreshInputField();

	if(nStrike == m_nGameSize) bFlag = TRUE;
	return bFlag;
}


void CNumberBaseBallDlg::OnDestroy()
{
	//delete[] m_pInputToIntegerArray;
	delete[] m_pAnswer;
	CDialogEx::OnDestroy();
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CNumberBaseBallDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)             
		{   
			OnBnClickedNumberbaseballOutputBtn();
			return true;
		}
		if (pMsg->wParam == VK_ESCAPE)             
		{  
			return true;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
