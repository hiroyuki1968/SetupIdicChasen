// SetupIdicChasenDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "SetupIdicChasen.h"
#include "SetupIdicChasenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenDlg �_�C�A���O

CSetupIdicChasenDlg::CSetupIdicChasenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupIdicChasenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetupIdicChasenDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetupIdicChasenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupIdicChasenDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetupIdicChasenDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupIdicChasenDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenDlg ���b�Z�[�W �n���h��

BOOL CSetupIdicChasenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B

	CEdit* pEdit2 = (CEdit *)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit *)GetDlgItem(IDC_EDIT3);
	CButton* pBtn = (CButton *)GetDlgItem(IDOK);

//	char szPersonalDPath[_MAX_PATH];
//	SHGetSpecialFolderPath(m_hWnd, szPersonalDPath, CSIDL_PERSONAL, FALSE);

//	CString strPersonalDPath = szPersonalDPath;
	CString strPersonalDPath = "D:\\home";
	m_strIdicChasenDPath = strPersonalDPath + "\\Visual Studio Projects\\IdicChasen";
	m_strProductCodeFPath = m_strIdicChasenDPath + "\\ProductCode.txt";
	try {
		CString strLine;

		CString strVerHFPath = m_strIdicChasenDPath + "\\IdicChasenVer.h";

		CString strKey1 = "#define THIS_VER	";
		int nKeyLen1 = strKey1.GetLength();

		char pszVer[MAX_PATH];

		CStdioFile SfVerH(strVerHFPath, CFile::modeRead);
		while (SfVerH.ReadString(strLine)) {
			if (strLine.Left(nKeyLen1) == strKey1) {
				if (sscanf(strLine, "%*s %*s %s", pszVer) == 1)
					pEdit2->SetWindowText(pszVer);
				break;
			}
		}
		SfVerH.Close();

		if (CFile::GetStatus(m_strProductCodeFPath, m_FileStatus)) {
			CStdioFile SfProductCode(m_strProductCodeFPath, CFile::modeRead);
			SfProductCode.ReadString(strLine);
			SfProductCode.Close();
			pEdit3->SetWindowText(strLine);
		}
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
	}
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CSetupIdicChasenDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CSetupIdicChasenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetupIdicChasenDlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������

	CString strRcFPath = m_strIdicChasenDPath + "\\IdicChasen.rc";

	CString strBaseVer;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strBaseVer);
	int nBaseVerLen = strBaseVer.GetLength();
	CString strMajorBaseVer = strBaseVer.Left(nBaseVerLen - 2);
	CString strMinorBaseVer = strBaseVer.Right(2);
	int nBaseVer = atoi(strBaseVer);
	int nMajorBaseVer = atoi(strMajorBaseVer);
	int nMinorBaseVer = atoi(strMinorBaseVer);

	CString strVer;
	GetDlgItem(IDC_EDIT2)->GetWindowText(strVer);
	int nVerLen = strVer.GetLength();
	CString strMajorVer = strVer.Left(nVerLen - 2);
	CString strMinorVer = strVer.Right(2);
	int nVer = atoi(strVer);
	int nMajorVer = atoi(strMajorVer);
	int nMinorVer = atoi(strMinorVer);

	CString strFPath;
	CString strFPathC;
	CString strLine;
	CString strKey0;
	CString strKey1;
	CString strKey2;
	CString strKey3;
	int nKeyLen0;
	int nKeyLen1;
	int nKeyLen2;
	int nKeyLen3;

	strFPath = m_strIdicChasenDPath + "\\IdicChasenVer.h";
	strFPathC = strFPath + '~';
	try {
		strKey1 = "#define THIS_VER	";
		nKeyLen1 = strKey1.GetLength();

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen1) == strKey1)
				strLine = strKey1 + strVer;
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	strFPath = m_strIdicChasenDPath + "\\IdicChasen.exe.manifest";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "    version=\"";
		nKeyLen0 = strKey0.GetLength();

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				strLine.Format(strKey0 + "%d.%d.0.1\"", nMajorVer, nMinorVer);
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	strFPath = m_strIdicChasenDPath + "\\IdicChasen.rc";
	strFPathC = strFPath + '~';

	try {
		strKey0 = " FILEVERSION ";
		nKeyLen0 = strKey0.GetLength();

		strKey1 = " PRODUCTVERSION ";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "            VALUE \"FileVersion\", \"";
		nKeyLen2 = strKey2.GetLength();

		strKey3 = "            VALUE \"ProductVersion\", \"";
		nKeyLen3 = strKey3.GetLength();

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				strLine.Format(strKey0 + "%d,%d,0,1", nMajorVer, nMinorVer);
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%d,%d,0,1", nMajorVer, nMinorVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%d, %d, 0, 1\\0\"", nMajorVer, nMinorVer);
			else if (strLine.Left(nKeyLen3) == strKey3)
				strLine.Format(strKey3 + "%d, %d, 0, 1\\0\"", nMajorVer, nMinorVer);
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	strFPath = m_strIdicChasenDPath + "\\IdicChasen.aps";
	if (CFile::GetStatus(strFPath, m_FileStatus))
		if (! DeleteFile(strFPath)) {
			MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}

	strFPath = m_strIdicChasenDPath + "\\�A�C�h�����������L���O ������.txt";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "�@�@�A�C�h�����������L���O Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "�@���D�t�@�C�� IdicChasen";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "�@���D�𓀂����t�H���_�ɂł��� IdicChasen";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				strLine.Format(strKey0 + "%d.%d ������", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d.zip ��K���ȃt�H���_�ɉ𓀂��܂��B", nMajorVer, nMinorVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d �t�H���_���̃t�@�C��", nMajorVer, nMinorVer);
*/
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	strFPath = m_strIdicChasenDPath + "\\HTML Help\\IdicChasen.htm";
	strFPathC = strFPath + '~';
	try {
		strKey0 = "<H3 STYLE=\"color: #FFFFFF; background-color: #00CCFF;\"><FONT size=7><FONT color=white>�A�C�h��</FONT><FONT color=pink>����</FONT><FONT color=white>�����L���O</FONT></FONT> Ver.";
		nKeyLen0 = strKey0.GetLength();

/*
		strKey1 = "	<LI>�t�@�C�� IdicChasen";
		nKeyLen1 = strKey1.GetLength();

		strKey2 = "	<LI>�𓀂����t�H���_�ɂł��� IdicChasen";
		nKeyLen2 = strKey2.GetLength();
*/

		CStdioFile Sf(strFPath, CFile::modeRead);
		CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
		while (Sf.ReadString(strLine)) {
			if (strLine.Left(nKeyLen0) == strKey0)
				strLine.Format(strKey0 + "%d.%d <FONT color=yellow>�w���v</FONT></H3>", nMajorVer, nMinorVer);
/*
			else if (strLine.Left(nKeyLen1) == strKey1)
				strLine.Format(strKey1 + "%02d%02d.zip ��K���ȃt�H���_�ɉ𓀂��܂��B", nMajorVer, nMinorVer, nRevVer);
			else if (strLine.Left(nKeyLen2) == strKey2)
				strLine.Format(strKey2 + "%02d%02d �t�H���_���̃t�@�C�� SETUP.EXE �����s���܂��B", nMajorVer, nMinorVer, nRevVer);
*/
			SfC.WriteString(strLine + "\n");
		}
		SfC.Close();
		Sf.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
		return;
	}
	if (! DeleteFile(strFPath)) {
		MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	if (! MoveFile(strFPathC, strFPath)) {
		MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}

	if (nVer <= 121) {
		strFPath = "C:\\My Installations\\�A�C�h�����������L���O\\String Tables\\0011-Japanese\\value.shl";
		strFPathC = strFPath + '~';
		try {
			strKey0 = "PRODUCT_VERSION=";
			nKeyLen0 = strKey0.GetLength();

			CStdioFile Sf(strFPath, CFile::modeRead);
			CStdioFile SfC(strFPathC, CFile::modeCreate | CFile::modeWrite);
			while (Sf.ReadString(strLine)) {
				if (strLine.Left(nKeyLen0) == strKey0)
					strLine.Format(strKey0 + "%d.%02d.000", nMajorVer, nMinorVer);
				SfC.WriteString(strLine + "\n");
			}
			SfC.Close();
			Sf.Close();
		}
		catch (CException* pEx) {
			MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
			pEx->Delete();
			return;
		}
		if (! DeleteFile(strFPath)) {
			MessageBox("DeleteFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}
		if (! MoveFile(strFPathC, strFPath)) {
			MessageBox("MoveFile(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
			return;
		}
	}
	
	CDialog::OnOK();
}

void CSetupIdicChasenDlg::OnButton1() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������

	GUID guid = GUID_NULL;

	char szProductCode[MAX_PATH] = {0};
	DWORD dwProductCodeSize = MAX_PATH;

	if (CoCreateGuid(&guid) != S_OK) {
		MessageBox("CoCreateGuid(): " + GetLastErrorMessage(), NULL, MB_ICONSTOP);
		return;
	}
	dwProductCodeSize =
		sprintf(szProductCode, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			guid.Data1, guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
			guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]
		);

	GetDlgItem(IDC_EDIT3)->SetWindowText(szProductCode);

	try {
		CStdioFile SfProductCode(m_strProductCodeFPath, CFile::modeCreate | CFile::modeWrite);
		SfProductCode.WriteString(szProductCode);
		SfProductCode.WriteString("\n");
		SfProductCode.Close();
	}
	catch (CException* pEx) {
		MessageBox(GetExceptionErrorMessage(pEx), NULL, MB_ICONSTOP);
		pEx->Delete();
	}
	
}

CString GetLastErrorMessage(DWORD dwLastError)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwLastError ? dwLastError : GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
	);
	// Process any inserts in lpMsgBuf.
	CString strMsg((LPCTSTR)lpMsgBuf);
	// Free the buffer.
	LocalFree( lpMsgBuf );

	return strMsg;
}

CString GetExceptionErrorMessage(CException* pEx)
{
	TCHAR   szCause[255];

	pEx->GetErrorMessage(szCause, 255);
	return szCause;
}
