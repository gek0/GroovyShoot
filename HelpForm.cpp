//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HelpForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thelp_winForm *help_winForm;
//---------------------------------------------------------------------------
__fastcall Thelp_winForm::Thelp_winForm(TComponent* Owner)
	: TForm(Owner)
{
	tabovi->Tabs->Add("Hrvatski");
	tabovi->Tabs->Add("English");
	tabovi->Tabs->Add("Italiano");

	help_tekst->Lines->Clear();

	help_tekstovi[0] = "Dobrodošli u GroovyShoot!\n\n"

						"Ova aplikacija služi za slikanje Vašeg ekrana te spremanje u 3 najèešæa formata (.bmp, .png i .jpeg).\n"
						"p.s ako odaberete .jpeg, sliku možete imati i u crno-bijelom formatu.\n\n"

						"Nude se 3 opcije:\n"
						"1) Full Window ili slika cijelog ekrana\n"
						"2) Active Window ili slika samo aktivnog prozora\n"
						"3) Custom Window ili slika podruèja na ekranu koju oznaèite\n\n"

						"Odabir direktorija gdje æe se slika spremiti je obavezan!\n\n"

						"Takoðer, postoji i opcija automatskog slikanja ekrana u gore odreðeni direktorij\n"
						 " - sve opcije odabrane iznad se odnose i na automatko spremanje\n"
						 " - vremenski period slikanja je izmeðu 1 i 100 sekundi\n"
						 " - broj slika je izmeðu 1 i 1000\n\n"

						"NAPOMENA: automatski slikati možete samo cijeli ekran ili aktivni prozor!\n\n"

						"Uživajte u aplikaciji i hvala na korištenju! :)\n";

	help_tekstovi[1] = "Welcome to GroovyShoot!\n\n"

						"This application purpose is to capture your desktop screen in 3 most common image formats (.bmp, .png and .jpeg).\n"
						"p.s if you choose .jpeg, you can save the image in black and white format.\n\n"

						"There are 3 options:\n"
						"1) Full Window (Full Screen Capture)\n"
						"2) Active Window (capture only the active window on the screen)\n"
						"3) Custom Window (manually set screen area size and position to capture)\n\n"

						"Choosing of the save directory is mandatory!\n\n"

						"Also, there is an auto-capture option in the above chosen save directory\n"
						 " - all option selected above apply to auto-capture\n"
						 " - time period in auto-capture is between 1 and 100 seconds\n"
						 " - number of images to capture is between 1 and 1000\n\n"

						"REMARK: you can auto-capture only the Full or Active Window!\n\n"

						"Enjoy the application and thanks for using it! :)\n";

	help_tekstovi[2] = "Benvenuti a GroovyShoot!\n\n"

						"Lo scopo di questa applicazione e quello di catturare il vostro desktop in 3 formati di immagini piu comuni (.bmp, .png e .jpeg).\n"
						"ps se si sceglie .jpeg, e possibile salvare l immagine in formato bianco e nero.\n\n"

						"Ci sono 3 opzioni:\n"
						"1) Finestra completa (Screen Capture Full)\n"
						"2) Finestra attiva (cattura solo la finestra attiva sullo schermo)\n"
						"3) Parte della finestra (potete scegliere le dimensioni dello schermo e la posizione di catturare manualmente)\n\n"

						"La scelta della cartella in cui si salva l immagine e obbligatoria!\n\n"

						"Inoltre, c e anche la opzione auto-cattura nella cartella scelta sopra\n"
						 " - Tutte opzione selezionate sopra si applicano per l auto-cattura\n"
						 " - Il periodo di tempo per l auto-cattura e tra 1 e 100 secondi\n"
						 " - Il numero di immagini da catturare e tra 1 e 1000\n\n"

						"NOTA: si puo auto-catturare solo la finestra completa o attiva!\n\n"

						"Godetevi la applicazione e grazie per il suo utilizzo! :)\n";

	help_tekstovi[3] = "\0";

	help_tekst->Lines->Text = help_tekstovi[0];

}
//---------------------------------------------------------------------------
 /*
 *  zatvaranje forme
 */
void __fastcall Thelp_winForm::gumb_zatvoriClick(TObject *Sender)
{
   help_winForm->Close();
   help_tekst->Lines->Clear();
}
//---------------------------------------------------------------------------
 /*
 *  promjena tabova
 */
void __fastcall Thelp_winForm::taboviChange(TObject *Sender)
{
   if(tabovi->TabIndex == 0){
		help_tekst->Lines->Clear();
		help_tekst->Lines->Text = help_tekstovi[0];
   }
   else if(tabovi->TabIndex == 1){
		help_tekst->Lines->Clear();
		help_tekst->Lines->Text = help_tekstovi[1];
   }
   else if(tabovi->TabIndex == 2){
		help_tekst->Lines->Clear();
		help_tekst->Lines->Text = help_tekstovi[2];
   }
}
//---------------------------------------------------------------------------
  /*
  *  ponovni prikaz forme mora prikazati hrvatski help tekst u prvom tabu
  */
void __fastcall Thelp_winForm::FormActivate(TObject *Sender)
{
   help_tekst->Lines->Text = help_tekstovi[0];
}
//---------------------------------------------------------------------------

