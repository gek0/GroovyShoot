//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImageProcessForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tprocess_winForm *process_winForm;
//---------------------------------------------------------------------------
__fastcall Tprocess_winForm::Tprocess_winForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
  /*
  *  dijalog za spremanje slike
  */
void __fastcall Tprocess_winForm::gumb_saveClick(TObject *Sender)
{
	if(image_saveDialog->Execute() == true){
		image_saveDialog->FileName;
		capture_output->Picture->SaveToFile(image_saveDialog->FileName);

		Application->MessageBoxW(L"Slika je uspješno spremljena!", L"Obavijest", MB_OK|MB_ICONINFORMATION);
	}

}
//---------------------------------------------------------------------------
  /*
  *   kreiranje glavne forme i postavljanje pocetnih postavki
  */
void __fastcall Tprocess_winForm::FormCreate(TObject *Sender)
{
		//default ponudeno ime
	UnicodeString ime_datoteke = "Groovy_" + TrenutnoVrijeme();
	image_saveDialog->FileName = ime_datoteke;

	image_saveDialog->DefaultExt = ".jpeg";
	image_saveDialog->Filter = "JPEG Image File (*.jpeg)|*.jpeg|";
							   /*"JPEG Image File (*.jpg)|*.jpg|"
							   "Portable Networks Graphics (*.png)|*.png|"
							   "Bitmaps (*.bmp)|*.bmp|"
							   "All files";*/
}
//---------------------------------------------------------------------------

void __fastcall Tprocess_winForm::FormDestroy(TObject *Sender)
{
	delete capture_output;
	delete image_saveDialog;
}
//---------------------------------------------------------------------------

void __fastcall Tprocess_winForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete capture_output;
	delete image_saveDialog;
}
//---------------------------------------------------------------------------

