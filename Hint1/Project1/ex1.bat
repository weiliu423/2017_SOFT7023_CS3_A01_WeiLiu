cl.exe /Fovisible.obj /Tcvisible.c /c
cl.exe /Fopal.obj /Tcpal.c /c
cl.exe /Foex1.obj /Tcex1.c /c
cl.exe /Feex1.exe ex1.obj pal.obj visible.obj /link 