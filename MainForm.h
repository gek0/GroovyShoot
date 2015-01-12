//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include "cdiroutl.h"
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <ctime>
#include <jpeg.hpp>
#include <memory>
#include <Vcl.Imaging.pngimage.hpp>
#include <registry.hpp>
#include "HtmlHelpViewer.hpp"
#include "reinit.hpp"
//---------------------------------------------------------------------------
class Tmain_winForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *Menu;
	TMenuItem *About;
	TMenuItem *helpDialog;
	TMenuItem *aboutDialog;
	TMenuItem *Options;
	TMenuItem *Language;
	TMenuItem *langHR;
	TMenuItem *langEN;
	TMenuItem *langIT;
	TMenuItem *Tray;
	TGroupBox *type_group2;
	TRadioButton *type1;
	TRadioButton *type2;
	TRadioButton *type3;
	TButton *gumb_main;
	TTrayIcon *TrayIcon1;
	TGroupBox *auto_group;
	TEdit *input_timer;
	TLabel *label_timer;
	TScrollBar *slider_timer;
	TButton *gumb_start;
	TEdit *input_amount;
	TScrollBar *slider_amount;
	TLabel *label_amount;
	TGroupBox *type_group1;
	TComboBox *select_color;
	TGroupBox *dir_group;
	TGroupBox *format_group;
	TEdit *input_dir;
	TButton *gumb_dir;
	TComboBox *select_format;
	TSaveDialog *spremi_sliku;
	void __fastcall aboutDialogClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall gumb_mainClick(TObject *Sender);
	void __fastcall TrayClick(TObject *Sender);
	void __fastcall TrayIcon1Click(TObject *Sender);
	void __fastcall input_timerChange(TObject *Sender);
	void __fastcall slider_timerChange(TObject *Sender);
	void __fastcall gumb_startClick(TObject *Sender);
	void __fastcall input_amountChange(TObject *Sender);
	void __fastcall slider_amountChange(TObject *Sender);
	void __fastcall select_colorChange(TObject *Sender);
	void __fastcall select_formatChange(TObject *Sender);
	void __fastcall gumb_dirClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall helpDialogClick(TObject *Sender);
	void __fastcall langHRClick(TObject *Sender);
	void __fastcall langENClick(TObject *Sender);
	void __fastcall langITClick(TObject *Sender);

private:	// User declarations
	int timer_value;
	int broj_slika;
	int boja_postavka;
	int format_slika;
	UnicodeString direktorij;
	UnicodeString ime_datoteke;

public:		// User declarations
	__fastcall Tmain_winForm(TComponent* Owner);
	const UnicodeString TrenutnoVrijeme(){
		time_t now = time(0);
		struct tm tstruct;
		char buffer[40];

		tstruct = *localtime(&now);
		strftime(buffer, sizeof(buffer), "%d.%m.%Y_%H%S", &tstruct);

		return buffer;
	}

	void OdreziSliku();
};
//---------------------------------------------------------------------------
extern PACKAGE Tmain_winForm *main_winForm;
//---------------------------------------------------------------------------
#endif
