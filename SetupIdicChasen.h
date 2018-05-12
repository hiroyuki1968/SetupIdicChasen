// SetupIdicChasen.h : SETUPIDICCHASEN アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_)
#define AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenApp:
// このクラスの動作の定義に関しては SetupIdicChasen.cpp ファイルを参照してください。
//

class CSetupIdicChasenApp : public CWinApp
{
public:
	CSetupIdicChasenApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetupIdicChasenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CSetupIdicChasenApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_)
