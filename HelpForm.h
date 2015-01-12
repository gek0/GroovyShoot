//---------------------------------------------------------------------------

#ifndef HelpFormH
#define HelpFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class Thelp_winForm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tabovi;
	TMemo *help_tekst;
	TButton *gumb_zatvori;
	TImage *Image1;
	TLabel *label_main;
	TLabel *label_sub;
	void __fastcall gumb_zatvoriClick(TObject *Sender);
	void __fastcall taboviChange(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	UnicodeString help_tekstovi[4];
	__fastcall Thelp_winForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thelp_winForm *help_winForm;
//---------------------------------------------------------------------------
#endif
