//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "AboutForm.h"
#include "HelpForm.h"
#include "ImageProcessForm.h"
#include "SelectAreaForm.h"
#include "AktivniProzorCapture.h"

/*
* TODO:
*		auto capture ne povuce direktorij za spremanje
*/
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cdiroutl"
#pragma link "Vcl.HTMLHelpViewer"
#pragma resource "*.dfm"
Tmain_winForm *main_winForm;
	//varijable za capture korisnicki odredenog podrucja
Graphics::TCanvas *ScrCanvas_select = new Graphics::TCanvas;
HDC dc_select;
//---------------------------------------------------------------------------
__fastcall Tmain_winForm::Tmain_winForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
 /*
 *  screen capture korisnicki odredenog podrucja
 */
void Tmain_winForm::OdreziSliku(){
	 process_winForm->capture_output->Picture = NULL;
	 process_winForm->capture_output->Picture->Bitmap->Width = selectArea_winForm->duzina;
	 process_winForm->capture_output->Picture->Bitmap->Height = selectArea_winForm->sirina;

	 TRect kopija;
	 TRect rt = Rect(selectArea_winForm->vrh, selectArea_winForm->lijevo, selectArea_winForm->duzina + selectArea_winForm->vrh, selectArea_winForm->sirina + selectArea_winForm->lijevo);
	 kopija = rt;
	 kopija.Offset(-selectArea_winForm->vrh, -selectArea_winForm->lijevo);
	 process_winForm->capture_output->Picture->Bitmap->Canvas->CopyRect(kopija, ScrCanvas_select, rt);

	 Show();
	 Application->BringToFront();

			//provjera odabranog formata slike
	   if(format_slika == 0){
		   spremi_sliku->Execute();
		   process_winForm->capture_output->Picture->Bitmap->SaveToFile(spremi_sliku->FileName);
	   }
	   else if(format_slika == 1){
			 //alokacija jpeg objekta za kompresiju
		   std::auto_ptr<TJPEGImage> JPEG(new TJPEGImage());
				//provjeri postavku boje slike
		   if(boja_postavka == 1) JPEG->Grayscale = true;
		   else JPEG->Grayscale = false;

		   try{
			   JPEG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   JPEG->CompressionQuality = 80;
			   JPEG->Compress();
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   JPEG->SaveToFile(spremi_sliku->FileName);
	   }
	   else{
		   std::auto_ptr<TPngImage> PNG(new TPngImage());

		   try{
			   PNG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   PNG->CompressionLevel = 8;
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   PNG->SaveToFile(spremi_sliku->FileName);
	   }
}
//---------------------------------------------------------------------------
 /*
 *   kreiranje glavne forme
 */
void __fastcall Tmain_winForm::FormCreate(TObject *Sender)
{
	//pocetni odabir tipa screenshota
   type1->Checked = true;

	//timer pocetne postavke
   this->timer_value = 1;
   input_timer->Text = timer_value;
   slider_timer->Position = timer_value;

	//broj slika za automatsko slikanje
   this->broj_slika = 1;
   input_amount->Text = broj_slika;

   	//odabir boje slike
   select_color->ItemIndex = 0;
   select_color->Text = select_color->Items->Strings[select_color->ItemIndex];

	//odabir formata slike
   select_format->ItemIndex = 1;
   this->format_slika = select_format->ItemIndex;
   select_format->Text = select_format->Items->Strings[select_format->ItemIndex];

   		//default ponudeno ime i filteri za spremanje slike
	this->ime_datoteke = "Groovy_" + TrenutnoVrijeme();
	spremi_sliku->FileName = ime_datoteke;

	spremi_sliku->DefaultExt = ".jpeg";
	spremi_sliku->Filter = "Bitmap (*.bmp)|*.bmp|"
						   "JPEG Image File (*.jpeg)|*.jpeg|"
						   "Portable Networks Graphics (*.png)|*.png|";

		//citanje postavki iz .ini datoteke
	TIniFile *ini = new TIniFile("C:\\Users\\GroovySettings.ini");
		Left = ini->ReadInteger("Glavni prozor", "Lijevo", 0);
		Top = ini->ReadInteger("Glavni prozor", "Gore", 0);
		input_dir->Text = ini->ReadString("Postavke GUI-a", "Direktorij", "");
		input_amount->Text = ini->ReadInteger("Postavke GUI-a", "Broj slika", 1);
		input_timer->Text = ini->ReadInteger("Postavke GUI-a", "Timer", 1);
	delete ini;

}
//---------------------------------------------------------------------------
  /*
  *  pokretanje about dijaloga iz glavnog izbornika
  */
void __fastcall Tmain_winForm::aboutDialogClick(TObject *Sender)
{
   about_winForm->ShowModal();
}
//---------------------------------------------------------------------------
 /*
 *  pokretanje help dijaloga iz glavnog izbornika
 */
void __fastcall Tmain_winForm::helpDialogClick(TObject *Sender)
{
   help_winForm->ShowModal();
}

//---------------------------------------------------------------------------
  /*
  *  pokretanje programa preko glavnog guma, provjera tipa slike i otvaranje u drugoj formi
  */
void __fastcall Tmain_winForm::gumb_mainClick(TObject *Sender)
{
		//ocisti TImage komponentu
	process_winForm->capture_output->Picture = NULL;

	if(input_dir->Text.Trim().Length() == 0){
		Application->MessageBoxW(L"Morate odabrati direktorij!", L"Obavijest", MB_OK|MB_ICONINFORMATION);
		return;
	}

		//cijeli ekran
   if(type1->Checked == true){
		//sakrivanje glavne forme
	   main_winForm->Hide();
	   Sleep(500);

		//ulovi cijeli ekran i spremi u canvas objekt
	   HDC dc = GetDC(0);
	   Graphics::TCanvas *ScrCanvas = new Graphics::TCanvas;
	   ScrCanvas->Handle = dc;

		//postavi sirinu/visinu slike na dimenzije ekrana
	   process_winForm->capture_output->Picture->Bitmap->Width = Screen->Width;
	   process_winForm->capture_output->Picture->Bitmap->Height = Screen->Height;

		//postavi velicinu i kopiraj sliku u image formu
	   TRect rt = Rect(0, 0, Screen->Width, Screen->Height);
	   process_winForm->capture_output->Picture->Bitmap->Canvas->CopyRect(rt, ScrCanvas, rt);

		//provjera odabranog formata slike
	   if(format_slika == 0){
		   spremi_sliku->Execute();
		   process_winForm->capture_output->Picture->Bitmap->SaveToFile(spremi_sliku->FileName);
	   }
	   else if(format_slika == 1){
			 //alokacija jpeg objekta za kompresiju
		   std::auto_ptr<TJPEGImage> JPEG(new TJPEGImage());
				//provjeri postavku boje slike
		   if(boja_postavka == 1) JPEG->Grayscale = true;
		   else JPEG->Grayscale = false;

		   try{
			   JPEG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   JPEG->CompressionQuality = 80;
			   JPEG->Compress();
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   JPEG->SaveToFile(spremi_sliku->FileName);
	   }
	   else{
		   std::auto_ptr<TPngImage> PNG(new TPngImage());

		   try{
			   PNG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   PNG->CompressionLevel = 8;
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   PNG->SaveToFile(spremi_sliku->FileName);
	   }

		//dealokacija memorije za bitmapu
	   delete ScrCanvas;
	   //process_winForm->capture_output->Picture->Bitmap = NULL;
	   ReleaseDC(NULL, dc);

		//prikaz slike u formi i vracanje glavne forme
	   Show();
	   Application->BringToFront();
	   return;
   }
		//aktivni prozor
   else if(type2->Checked == true){
		//sakrivanje glavne forme
	   main_winForm->Hide();
	   Sleep(2000);

	   TBitmap *thisBitmap = new TBitmap();
	   ScreenCaptureAktivni(thisBitmap, true);

	   process_winForm->capture_output->Width = thisBitmap->Width;
	   process_winForm->capture_output->Height = thisBitmap->Height;
	   process_winForm->capture_output->Picture->Assign(thisBitmap);

		//provjera odabranog formata slike
	   if(format_slika == 0){
		   spremi_sliku->Execute();
		   process_winForm->capture_output->Picture->Bitmap->SaveToFile(spremi_sliku->FileName);
	   }
	   else if(format_slika == 1){
			 //alokacija jpeg objekta za kompresiju
		   std::auto_ptr<TJPEGImage> JPEG(new TJPEGImage());
				//provjeri postavku boje slike
		   if(boja_postavka == 1) JPEG->Grayscale = true;
		   else JPEG->Grayscale = false;

		   try{
			   JPEG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   JPEG->CompressionQuality = 80;
			   JPEG->Compress();
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   JPEG->SaveToFile(spremi_sliku->FileName);
	   }
	   else{
		   std::auto_ptr<TPngImage> PNG(new TPngImage());

		   try{
			   PNG->Assign(process_winForm->capture_output->Picture->Bitmap);
			   PNG->CompressionLevel = 8;
		   }
		   catch(...){
			   ShowMessage("Error: greška prilikom konverzije slike.");
		   }

		   spremi_sliku->Execute();
		   PNG->SaveToFile(spremi_sliku->FileName);
	   }

		//vracanje glavne forme
	   Show();
	   Application->BringToFront();
	   return;
   }
		//proizvoljno podrucje ekrana
   else if(type3->Checked == true){
	   main_winForm->Hide();
	   Sleep(500);

	   dc_select = GetDC(0);
	   ScrCanvas_select->Handle = dc_select;
	   Sleep(500);

	   selectArea_winForm->Show();
   }
}
//---------------------------------------------------------------------------
  /*
  *  sakrivanje glavne forme ("Hide to tray")
  */
void __fastcall Tmain_winForm::TrayClick(TObject *Sender)
{
   TrayIcon1->Visible = true;
   main_winForm->Hide();
}
//---------------------------------------------------------------------------
  /*
  *  ponovni prikaz forme
  */
void __fastcall Tmain_winForm::TrayIcon1Click(TObject *Sender)
{
   Show();
   Application->BringToFront();
   TrayIcon1->Visible = false;
}
//---------------------------------------------------------------------------
   /*
   *  promjena postavke boje
   */
void __fastcall Tmain_winForm::select_colorChange(TObject *Sender)
{
	this->boja_postavka = select_color->ItemIndex;
}
//---------------------------------------------------------------------------
   /*
   *  promjena formata slike
   */
void __fastcall Tmain_winForm::select_formatChange(TObject *Sender)
{
	 this->format_slika = select_format->ItemIndex;
}
//---------------------------------------------------------------------------
  /*
  *  promjena input polja pomice slider timer-a
  */
void __fastcall Tmain_winForm::input_timerChange(TObject *Sender)
{
	 //prazan tekst nosi vrijednost 1, a veci od 100 se postavlja na 100
	if(input_timer->Text.Trim().Length() == 0)
		timer_value = 1;
	else if(input_timer->Text.ToInt() > 100)
		timer_value = 100;
	else timer_value = input_timer->Text.ToInt();

	slider_timer->Position = timer_value;
}
//---------------------------------------------------------------------------
  /*
  *   pomicanje slidera timer-a mjenja tekst unutar input polja
  */
void __fastcall Tmain_winForm::slider_timerChange(TObject *Sender)
{
	UnicodeString value = slider_timer->Position;
	input_timer->Text = value;
}
//---------------------------------------------------------------------------
  /*
  *   promjena kolicine slika za automatsko spremanje
  */
void __fastcall Tmain_winForm::input_amountChange(TObject *Sender)
{
	 //prazan tekst nosi vrijednost 1, a veci od 1000 se postavlja na 1000
	if(input_amount->Text.Trim().Length() == 0)
		broj_slika = 1;
	else if(input_amount->Text.ToInt() > 1000)
		broj_slika = 1000;
	else broj_slika = input_amount->Text.ToInt();

	slider_amount->Position = broj_slika;
}
//---------------------------------------------------------------------------
  /*
  *   pomicanje slidera brojaca mjenja tekst unutar input polja
  */
void __fastcall Tmain_winForm::slider_amountChange(TObject *Sender)
{
	UnicodeString amount = slider_amount->Position;
	input_amount->Text = amount;
}
//---------------------------------------------------------------------------

  /*
  *  pokretanje automatskog spremanja slika
  */
void __fastcall Tmain_winForm::gumb_startClick(TObject *Sender)
{
	 //dijalog s provjerom
	int odgovor = Application->MessageBoxW(L"Ako ste sigurni da imate dovoljno mjesta na hard disku \ni da želite nastaviti, kliknite 'Yes', u suprotom 'No'.",
										   L"Jeste li sigurni?", MB_YESNO|MB_ICONINFORMATION|MB_DEFBUTTON1);
	if(odgovor == IDYES){
		main_winForm->Hide();
		Sleep(500);

		int inkrement_ime = 0;

		for(int i = 0; i < this->broj_slika; i++){
			spremi_sliku->InitialDir = direktorij;

			if(type1->Checked == true){
				//generiraj ime datoteke
				++inkrement_ime;
				UnicodeString ime_datoteke = "Groovy_" + TrenutnoVrijeme() + inkrement_ime + "_";

				// alociranje memorije za bitmapu
				HDC dc = GetDC(0);
				Graphics::TCanvas *ScrCanvas = new Graphics::TCanvas;
				ScrCanvas->Handle = dc;

				// postavi sirinu/visinu slike na dimenzije ekrana
				process_winForm->capture_output->Picture->Bitmap->Width =
					Screen->Width;
				process_winForm->capture_output->Picture->Bitmap->Height =
					Screen->Height;

				// postavi velicinu i kopiraj sliku u image formu
				TRect rt = Rect(0, 0, Screen->Width, Screen->Height);
				process_winForm->capture_output->Picture->Bitmap->Canvas->
					CopyRect(rt, ScrCanvas, rt);

				// provjera odabranog formata slike
				if (format_slika == 0) {
					spremi_sliku->FileName = ime_datoteke + ".bmp";
					process_winForm->capture_output->Picture->Bitmap->SaveToFile(spremi_sliku->FileName);
				}
				else if (format_slika == 1) {
					// alokacija jpeg objekta za kompresiju
					std::auto_ptr<TJPEGImage>JPEG(new TJPEGImage());
					// provjeri postavku boje slike
					if (boja_postavka == 1)
						JPEG->Grayscale = true;
					else
						JPEG->Grayscale = false;

					try {
						JPEG->Assign(process_winForm->capture_output->Picture->Bitmap);
						JPEG->CompressionQuality = 80;
						JPEG->Compress();
					}
					catch (...) {
						ShowMessage("Error: greška prilikom konverzije slike.");
						delete ScrCanvas;
						ReleaseDC(NULL, dc);

						return;
					}

					spremi_sliku->FileName = ime_datoteke + ".jpeg";
					JPEG->SaveToFile(spremi_sliku->FileName);
				}
				else {
					std::auto_ptr<TPngImage>PNG(new TPngImage());

					try {
						PNG->Assign(process_winForm->capture_output->Picture->Bitmap);
						PNG->CompressionLevel = 8;
					}
					catch (...) {
						ShowMessage("Error: greška prilikom konverzije slike.");
						delete ScrCanvas;
						ReleaseDC(NULL, dc);

						return;
					}

					spremi_sliku->FileName = ime_datoteke + ".png";
					PNG->SaveToFile(spremi_sliku->FileName);
				}

				// dealokacija memorije za bitmapu
				delete ScrCanvas;
				ReleaseDC(NULL, dc);
				process_winForm->capture_output->Picture = NULL;

				// cekanje po odabiru korisnika
				Sleep(timer_value * 1000);
			}

				/****** aktivni prozor ********/
			else if(type2->Checked == true){
				//generiraj ime datoteke
				++inkrement_ime;
				UnicodeString ime_datoteke = "Groovy_" + TrenutnoVrijeme() + inkrement_ime + "_";

				TBitmap *thisBitmap = new TBitmap();
				ScreenCaptureAktivni(thisBitmap, true);

				process_winForm->capture_output->Width = thisBitmap->Width;
				process_winForm->capture_output->Height = thisBitmap->Height;
				process_winForm->capture_output->Picture->Assign(thisBitmap);

				// provjera odabranog formata slike
				if (format_slika == 0) {
					spremi_sliku->FileName = ime_datoteke + ".bmp";
					process_winForm->capture_output->Picture->Bitmap->SaveToFile(spremi_sliku->FileName);
				}
				else if (format_slika == 1) {
					// alokacija jpeg objekta za kompresiju
					std::auto_ptr<TJPEGImage>JPEG(new TJPEGImage());
					// provjeri postavku boje slike
					if (boja_postavka == 1)
						JPEG->Grayscale = true;
					else
						JPEG->Grayscale = false;

					try {
						JPEG->Assign(process_winForm->capture_output->Picture->Bitmap);
						JPEG->CompressionQuality = 80;
						JPEG->Compress();
					}
					catch (...) {
						ShowMessage("Error: greška prilikom konverzije slike.");
						return;
					}

					spremi_sliku->FileName = ime_datoteke + ".jpeg";
					JPEG->SaveToFile(spremi_sliku->FileName);
				}
				else {
					std::auto_ptr<TPngImage>PNG(new TPngImage());

					try {
						PNG->Assign(process_winForm->capture_output->Picture->Bitmap);
						PNG->CompressionLevel = 8;
					}
					catch (...) {
						ShowMessage("Error: greška prilikom konverzije slike.");
						return;
					}

					spremi_sliku->FileName = ime_datoteke + ".png";
					PNG->SaveToFile(spremi_sliku->FileName);
				}

				// cekanje po odabiru korisnika
				Sleep(timer_value * 1000);
			}
		}
			 //prikaz slike u formi i vracanje glavne forme
			Show();
			Application->BringToFront();
			Application->MessageBoxW(L"Slike su uspješno spremljene!", L"Obavijest", MB_OK|MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
   /*
   *   odabir direktorija za spremanje slike
   */
void __fastcall Tmain_winForm::gumb_dirClick(TObject *Sender)
{
	UnicodeString direktorij = "";
	SelectDirectory(L"Odaberi direktorij za spremanje slike...", L"C:\"", direktorij);

	input_dir->Text = direktorij;
	spremi_sliku->InitialDir = direktorij;
}
//---------------------------------------------------------------------------
 /*
 *  zatvaranje forme i brisanje varijabli, spremanje postavki u .ini datoteku
 */
void __fastcall Tmain_winForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete ScrCanvas_select;
	ReleaseDC(NULL, dc_select);
	process_winForm->capture_output->Picture = NULL;

		//pisanje postavki u .ini datoteku
	try{
		TIniFile *ini = new TIniFile("C:\\Users\\GroovySettings.ini");
			ini->WriteInteger("Glavni prozor", "Lijevo", Left);
			ini->WriteInteger("Glavni prozor", "Gore", Top);
			ini->WriteString("Postavke GUI-a", "Direktorij", input_dir->Text);
			ini->WriteInteger("Postavke GUI-a", "Broj slika", input_amount->Text.ToInt());
			ini->WriteInteger("Postavke GUI-a", "Timer", input_timer->Text.ToInt());
		delete ini;
	}
	catch(...){
		return;
	}
}
//---------------------------------------------------------------------------
  /*
  *  postavljanje hrvatske lokalizacije forme
  */
void __fastcall Tmain_winForm::langHRClick(TObject *Sender)
{
	const CROATIAN = (SUBLANG_CROATIAN_CROATIA << 10 | LANG_CROATIAN);
	if(LoadNewResourceModule(CROATIAN))
		ReinitializeForms();

 			//vracanje postavki za format slike i boju
	   select_color->ItemIndex = this->boja_postavka;
	   select_format->ItemIndex = this->format_slika;
}
//---------------------------------------------------------------------------
  /*
  *  postavljanje engleske lokalizacije forme
  */
void __fastcall Tmain_winForm::langENClick(TObject *Sender)
{
	const ENGLISH = (SUBLANG_ENGLISH_US << 10 | LANG_ENGLISH);
	if(LoadNewResourceModule(ENGLISH))
		ReinitializeForms();

			//vracanje postavki za format slike i boju
	   select_color->ItemIndex = this->boja_postavka;
	   select_format->ItemIndex = this->format_slika;
}
//---------------------------------------------------------------------------
  /*
  *  postavljanje talijanske lokalizacije forme
  */
void __fastcall Tmain_winForm::langITClick(TObject *Sender)
{
	const ITALIAN = (SUBLANG_ITALIAN << 10 | LANG_ITALIAN);
	if(LoadNewResourceModule(ITALIAN))
		ReinitializeForms();

			//vracanje postavki za format slike i boju
	   select_color->ItemIndex = this->boja_postavka;
	   select_format->ItemIndex = this->format_slika;
}
//---------------------------------------------------------------------------

