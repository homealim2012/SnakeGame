# Microsoft Developer Studio Generated NMAKE File, Based on ̰����.dsp
!IF $(CFG)" == "
CFG=̰���� - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ̰���� - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "̰���� - Win32 Release" && "$(CFG)" != "̰���� - Win32 Debug"
!MESSAGE ָ�������� "$(CFG)" ��Ч.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "̰����.mak" CFG="̰���� - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "̰���� - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "̰���� - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF $(OS)" == "Windows_NT
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "̰���� - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# ��ʼ�Զ����
OutDir=.\Release
# �����Զ����

ALL : "$(OUTDIR)\̰����.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\SpeedDialog.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\̰����.obj"
	-@erase "$(INTDIR)\̰����.pch"
	-@erase "$(INTDIR)\̰����.res"
	-@erase "$(INTDIR)\̰����Dlg.obj"
	-@erase "$(OUTDIR)\̰����.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\̰����.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\̰����.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\̰����.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\̰����.pdb" /machine:I386 /out:"$(OUTDIR)\̰����.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\SpeedDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\̰����.obj" \
	"$(INTDIR)\̰����Dlg.obj" \
	"$(INTDIR)\̰����.res"

"$(OUTDIR)\̰����.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "̰���� - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# ��ʼ�Զ����
OutDir=.\Debug
# �����Զ����

ALL : "$(OUTDIR)\̰����.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\SpeedDialog.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\̰����.obj"
	-@erase "$(INTDIR)\̰����.pch"
	-@erase "$(INTDIR)\̰����.res"
	-@erase "$(INTDIR)\̰����Dlg.obj"
	-@erase "$(OUTDIR)\̰����.exe"
	-@erase "$(OUTDIR)\̰����.ilk"
	-@erase "$(OUTDIR)\̰����.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\̰����.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\̰����.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\̰����.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=msimg32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\̰����.pdb" /debug /machine:I386 /out:"$(OUTDIR)\̰����.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\SpeedDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\̰����.obj" \
	"$(INTDIR)\̰����Dlg.obj" \
	"$(INTDIR)\̰����.res"

"$(OUTDIR)\̰����.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("̰����.dep")
!INCLUDE "̰����.dep"
!ELSE 
!MESSAGE Warning: cannot find "̰����.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "̰���� - Win32 Release" || "$(CFG)" == "̰���� - Win32 Debug"
SOURCE=.\AboutDialog.cpp

"$(INTDIR)\AboutDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\̰����.pch"


SOURCE=.\HelpDialog.cpp

"$(INTDIR)\HelpDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\̰����.pch"


SOURCE=.\SpeedDialog.cpp

"$(INTDIR)\SpeedDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\̰����.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "̰���� - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\̰����.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\̰����.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "̰���� - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\̰����.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\̰����.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=".\̰����.cpp"

"$(INTDIR)\̰����.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\̰����.pch"


SOURCE=".\̰����.rc"

"$(INTDIR)\̰����.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=".\̰����Dlg.cpp"

"$(INTDIR)\̰����Dlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\̰����.pch"



!ENDIF 

