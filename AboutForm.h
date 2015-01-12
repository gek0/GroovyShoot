//---------------------------------------------------------------------------

#ifndef AboutFormH
#define AboutFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ExtActns.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class Tabout_winForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *label_name;
	TLabel *label_version;
	TLabel *label_author;
	TLabel *label_contact;
	TLabel *label1;
	TLabel *label2;
	TLabel *label3;
	TButton *gumb_contact;
	TActionList *ActionList1;
	TSendMail *InternetSendMail1;
	TImage *image_logo;
private:	// User declarations
public:		// User declarations
	__fastcall Tabout_winForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tabout_winForm *about_winForm;
//---------------------------------------------------------------------------
#endif
