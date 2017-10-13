cl.exe /Fovisible.obj /Tcvisible.c /c
cl.exe /Fopal.obj /Tcpal.c /c
cl.exe /Foex2.obj /Tcex2.c /c
cl.exe /Feex2.exe ex2.obj pal.obj visible.obj /link 