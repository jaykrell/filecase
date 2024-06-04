!ifndef TOP
!error run bld.cmd instead of nmake, or nmake in parent directory
!endif

.SUFFIXES:

all: exe1.exe exe2.exe
  .\exe1
  .\exe2

clean:
  -del *.exe *.obj *.lib *.pdb *.ilk 2>nul

exe.obj: exe.cpp Makefile
  cl /nologo /MD /c exe.cpp

# link lib1 then lib2
exe1.exe: lib1.lib lib2.lib exe.obj
  link /nologo /out:exe1.exe exe.obj lib1.lib lib2.lib /incremental:no

# link lib2 then lib1
exe2.exe: lib1.lib lib2.lib exe.obj
  link /nologo /out:exe2.exe exe.obj lib2.lib lib1.lib /incremental:no

# include path is relative
lib1.obj: lib\lib.cpp Makefile h.h
  cl /nologo /MD /c /FC /I. lib\lib.cpp /Fo$@ /DLIB=file1

lib1.lib: lib1.obj Makefile
  link /lib /nologo lib1.obj /out:$@

# /I full path but lowercased, does not match file system
lib2.obj: lib\lib.cpp Makefile h.h
  cl /nologo /MD /c /FC /I$(TOP:U=u) lib\lib.cpp /Fo$@ /DLIB=file2

lib2.lib: lib2.obj Makefile
  link /lib /nologo lib2.obj /out:$@
