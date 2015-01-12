#include "AktivniProzorCapture.h"

 /*
 *  funkcija za ulovit sliku ekrana, glavna funkcija koju poziva funkcija za ulovit aktivni prozor
 */
void ScreenCapture(TBitmap *theBitmap, const TRect thisArea, const bool IncludeCursor = false){

	 const CDESKTOP_HWND = 0;
	 HDC hdcDesktop;
	 TCursorInfo theCursorInfo;
	 TIcon *theIcon = new TIcon();
	 TIconInfo *theIconInfo = new TIconInfo();

	 theBitmap->Width = thisArea.Right - thisArea.Left;
	 theBitmap->Height = thisArea.Bottom - thisArea.Top;
	 hdcDesktop = GetWindowDC(CDESKTOP_HWND);
	 BitBlt(theBitmap->Canvas->Handle, 0, 0, thisArea.Right, thisArea.Bottom,
			hdcDesktop, thisArea.Left, thisArea.Top, SRCCOPY);
	 theBitmap->Modified = true;

	 ReleaseDC(CDESKTOP_HWND, hdcDesktop);
	 if (IncludeCursor == true) {
		 try {
			 theCursorInfo.cbSize = sizeof(theCursorInfo);
			 if (theCursorInfo.flags == CURSOR_SHOWING) {
				 theIcon->Handle = CopyIcon(theCursorInfo.hCursor);
				 if (GetIconInfo(theIcon->Handle, theIconInfo)) {
					 theBitmap->Canvas->Draw
						 (theCursorInfo.ptScreenPos.x -int
						 (theIconInfo->xHotspot) - thisArea.Left,
						 theCursorInfo.ptScreenPos.y -int(theIconInfo->yHotspot)
						 - thisArea.Top, theIcon);

					 DeleteObject(theIconInfo->hbmMask);
					 DeleteObject(theIconInfo->hbmColor);
				 }
			 }
		 }
		 catch (...) {
			 ShowMessage(L"Dogodila se greška!");
		 }
	 }
}


 /*
 *  funkcija za ulovit aktivni prozor
 */
void ScreenCaptureAktivni(TBitmap *theBitmap, const bool IncludeCursor = true){
	 TRect WindowRect;
	 HWND hwndForegroundWindow;

	 hwndForegroundWindow = GetForegroundWindow();
	 GetWindowRect(hwndForegroundWindow, &WindowRect);

	 ScreenCapture(theBitmap, WindowRect, IncludeCursor);
}
