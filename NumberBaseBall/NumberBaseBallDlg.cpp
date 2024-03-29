
// NumberBaseBallDlg.cpp : 구현 파일
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CNumberBaseBallDlg 대화 상자



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


// CNumberBaseBallDlg 메시지 처리기

BOOL CNumberBaseBallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetGame();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CNumberBaseBallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CNumberBaseBallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNumberBaseBallDlg::OnBnClickedNumberbaseballOutputBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strTmp = _T("");
	strTmp.Format(_T("%d %d %d %d"), m_pAnswer[0],m_pAnswer[1],m_pAnswer[2],m_pAnswer[3]);
	TRACE(strTmp);
	UpdateData();
	int* pInputToIntegerArray = CStringToIntegerArray(m_edtInput);


	if(DiscriminateAnswer(pInputToIntegerArray)){
		delete[] pInputToIntegerArray;
		int nOK = AfxMessageBox(_T("정답입니다!! 종료하시겠습니까?"), MB_YESNO);
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

//추가 라인
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
	strTmp.Format(_T("%ds %db ( 입력값: %s )"), nStrike, nBall, m_edtInput);
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

BOOL CNumberBaseBallDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
