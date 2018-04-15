# Microsoft Developer Studio Generated NMAKE File, Based on Ã∞≥‘…ﬂ.dsp
!IF $(CFG)" == "
CFG=Ã∞≥‘…ﬂ - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Ã∞≥‘…ﬂ - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Ã∞≥‘…ﬂ - Win32 Release" && "$(CFG)" != "Ã∞≥‘…ﬂ - Win32 Debug"
!MESSAGE ÷∏∂®µƒ≈‰÷√ "$(CFG)" Œﬁ–ß.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Ã∞≥‘…ﬂ.mak" CFG="Ã∞≥‘…ﬂ - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Ã∞≥‘…ﬂ - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Ã∞≥‘…ﬂ - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF $(OS)" == "Windows_NT
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# ø™ º◊‘∂®“Â∫Í
OutDir=.\Release
# Ω· ¯◊‘∂®“Â∫Í

ALL : "$(OUTDIR)\Ã∞≥‘…ﬂ.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\SpeedDialog.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.obj"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.pch"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.res"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂDlg.obj"
	-@erase "$(OUTDIR)\Ã∞≥‘…ﬂ.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Ã∞≥‘…ﬂ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Ã∞≥‘…ﬂ.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ã∞≥‘…ﬂ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Ã∞≥‘…ﬂ.pdb" /machine:I386 /out:"$(OUTDIR)\Ã∞≥‘…ﬂ.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\SpeedDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂ.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂDlg.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂ.res"

"$(OUTDIR)\Ã∞≥‘…ﬂ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# ø™ º◊‘∂®“Â∫Í
OutDir=.\Debug
# Ω· ¯◊‘∂®“Â∫Í

ALL : "$(OUTDIR)\Ã∞≥‘…ﬂ.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\SpeedDialog.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.obj"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.pch"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂ.res"
	-@erase "$(INTDIR)\Ã∞≥‘…ﬂDlg.obj"
	-@erase "$(OUTDIR)\Ã∞≥‘…ﬂ.exe"
	-@erase "$(OUTDIR)\Ã∞≥‘…ﬂ.ilk"
	-@erase "$(OUTDIR)\Ã∞≥‘…ﬂ.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\Ã∞≥‘…ﬂ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\Ã∞≥‘…ﬂ.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ã∞≥‘…ﬂ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=msimg32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Ã∞≥‘…ﬂ.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Ã∞≥‘…ﬂ.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\SpeedDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂ.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂDlg.obj" \
	"$(INTDIR)\Ã∞≥‘…ﬂ.res"

"$(OUTDIR)\Ã∞≥‘…ﬂ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Ã∞≥‘…ﬂ.dep")
!INCLUDE "Ã∞≥‘…ﬂ.dep"
!ELSE 
!MESSAGE Warning: cannot find "Ã∞≥‘…ﬂ.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Release" || "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Debug"
SOURCE=.\AboutDialog.cpp

"$(INTDIR)\AboutDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ã∞≥‘…ﬂ.pch"


SOURCE=.\HelpDialog.cpp

"$(INTDIR)\HelpDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ã∞≥‘…ﬂ.pch"


SOURCE=.\SpeedDialog.cpp

"$(INTDIR)\SpeedDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ã∞≥‘…ﬂ.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Ã∞≥‘…ﬂ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ã∞≥‘…ﬂ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ã∞≥‘…ﬂ - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\Ã∞≥‘…ﬂ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ã∞≥‘…ﬂ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=".\Ã∞≥‘…ﬂ.cpp"

"$(INTDIR)\Ã∞≥‘…ﬂ.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ã∞≥‘…ﬂ.pch"


SOURCE=".\Ã∞≥‘…ﬂ.rc"

"$(INTDIR)\Ã∞≥‘…ﬂ.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=".\Ã∞≥‘…ﬂDlg.cpp"

"$(INTDIR)\Ã∞≥‘…ﬂDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ã∞≥‘…ﬂ.pch"



!ENDIF 

