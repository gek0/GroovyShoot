//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SelectAreaForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TselectArea_winForm *selectArea_winForm;
//---------------------------------------------------------------------------
__fastcall TselectArea_winForm::TselectArea_winForm(TComponent* Owner)
	: TForm(Owner)
{
		//pocetne postavke forme i incijalizacija varijabli
	selectArea_winForm->Width = Screen->Width;
	selectArea_winForm->Height = Screen->Height;
	selectArea_winForm->BorderStyle = bsNone;

	vrh = lijevo = duzina = sirina = 0;
	misKliknut = false;
}
//---------------------------------------------------------------------------
 /*
 *  pritiskom misa zapamti pocetne kordinate; udaljenost od vrha i lijevog ruba ekrana
 */
void __fastcall TselectArea_winForm::select_slikaMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	vrh = lijevo = 0;

	if(Button == mbLeft){
		misKliknut = true;
		vrh = X;
		lijevo = Y;
		podrucje->Visible = true;
	}
	else{
		Application->MessageBoxW(L"Koristite lijevu tipku miša za oznaèavanje podruèja slike!",
								 L"Obavijest", MB_OK|MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
 /*
 *  nakon odabira pospremi kordinate u varijable i iskoristi u glavnoj formi za rezanje slike
 */
void __fastcall TselectArea_winForm::select_slikaMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	duzina = sirina = 0;
	misKliknut = false;
	podrucje->Visible = false;

	duzina = X - vrh;
	sirina = Y - lijevo;

	selectArea_winForm->Close();

		//vrati varijable s dimenzijama u glavnu formu
	main_winForm->OdreziSliku();
}
//---------------------------------------------------------------------------
  /*
  *  pomicanjem misa zapamti dimenzije slike
  */
void __fastcall TselectArea_winForm::select_slikaMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	try {
		if(misKliknut == true){
			podrucje->SetBounds(vrh, lijevo, X - vrh, Y - lijevo);
		}
	}
	catch(...){
		Application->MessageBoxW(L"Morate povlaèiti mišem prema donjem lijevom kutu!",
								 L"Obavijest", MB_OK|MB_ICONINFORMATION);
	}

}
//---------------------------------------------------------------------------
  /*
  *  pokretanje forme
  */
void __fastcall TselectArea_winForm::FormActivate(TObject *Sender)
{
	Application->MessageBoxW(L"Za oznaèavanje podruèja slike povlaèite lijevom tipkom miša prema donjem desnom kutu ekrana.",
							 L"Obavijest", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

