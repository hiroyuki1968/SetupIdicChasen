// SetupIdicChasen.h : SETUPIDICCHASEN �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_)
#define AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CSetupIdicChasenApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� SetupIdicChasen.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CSetupIdicChasenApp : public CWinApp
{
public:
	CSetupIdicChasenApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetupIdicChasenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CSetupIdicChasenApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETUPIDICCHASEN_H__0AAEDCDC_A261_4EF8_B2FB_521B25F3AD71__INCLUDED_)
