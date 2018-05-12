// SetupIdicChasenDlg.h : ヘッダー ファイル
//

#if !defined(AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_)
#define AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenDlg ダイアログ

class CSetupIdicChasenDlg : public CDialog
{
// 構築
public:
	CSetupIdicChasenDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CSetupIdicChasenDlg)
	enum { IDD = IDD_SETUPIDICCHASEN_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupIdicChasenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;
	CFileStatus m_FileStatus;
	CString m_strIdicChasenDPath;
	CString m_strProductCodeFPath;

	// 生成されたメッセージ マップ関数
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
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPIDICCHASENDLG_H__807F2EA8_B5B9_4D43_80C7_3CF48F4CE99E__INCLUDED_)
