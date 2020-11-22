#ifndef __WIN_BMP_H__
#define __WIN_BMP_H__	1

typedef unsigned short WIN_WORD;	//2 bytes long
typedef unsigned int WIN_DWORD;		//4 bytes long
typedef long WIN_LONG;			//4 bytes long, signed

typedef struct tagBITMAPFILEHEADER {
	WIN_WORD    bfType;
	WIN_DWORD   bfSize;
	WIN_WORD    bfReserved1;
	WIN_WORD    bfReserved2;
	WIN_DWORD   bfOffBits;
} BITMAPFILEHEADER, * PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
	WIN_DWORD  biSize;
	WIN_LONG   biWidth;
	WIN_LONG   biHeight;
	WIN_WORD   biPlanes;
	WIN_WORD   biBitCount;
	WIN_DWORD  biCompression;
	WIN_DWORD  biSizeImage;
	WIN_LONG   biXPelsPerMeter;
	WIN_LONG   biYPelsPerMeter;
	WIN_DWORD  biClrUsed;
	WIN_DWORD  biClrImportant;
} BITMAPINFOHEADER, * PBITMAPINFOHEADER;

#endif // __WIN_BMP_H__
