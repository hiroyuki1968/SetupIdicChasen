// SetupIdicChasenDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_)
#define AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenDlg �_�C�A���O

class CSetupIdicChasenDlg : public CDialog
{
// �\�z
public:
	CSetupIdicChasenDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSetupIdicChasenDlg)
	enum { IDD = IDD_SETUPIDICCHASEN_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupIdicChasenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;
	CFileStatus m_FileStatus;
	CString m_strIdicChasenDPath;
	CString m_strProductCodeFPath;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSetupIdicChasenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CString GetLastErrorMessage(DWORD dwLastError = NULL);
CString GetExceptionErrorMessage(CException* pEx);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_)
