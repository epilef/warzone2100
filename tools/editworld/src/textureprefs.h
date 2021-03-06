/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2012  Warzone 2100 Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

	$Revision$
	$Id$
	$HeadURL$
*/

#ifndef __INCLUDED_TEXTUREPREFS_H__
#define __INCLUDED_TEXTUREPREFS_H__

/////////////////////////////////////////////////////////////////////////////
// CTexturePrefs dialog

class CTexturePrefs : public CDialog
{
// Construction
public:
	CTexturePrefs(CWnd* pParent = NULL);   // standard constructor
	void SetTextureSize(DWORD TextureWidth,DWORD TextureHeight);
	void GetTextureSize(DWORD *TextureWidth,DWORD *TextureHeight);

// Dialog Data
	//{{AFX_DATA(CTexturePrefs)
	enum { IDD = IDD_TEXTUREPREFS };
	DWORD	m_TextureWidth;
	DWORD	m_TextureHeight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTexturePrefs)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTexturePrefs)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // __INCLUDED_TEXTUREPREFS_H__
