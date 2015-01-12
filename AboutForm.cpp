//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tabout_winForm *about_winForm;
//---------------------------------------------------------------------------
__fastcall Tabout_winForm::Tabout_winForm(TComponent* Owner)
	: TForm(Owner)
{
		//postavke za kontakt mailom
	InternetSendMail1->Subject = "GroovyShoot";
	InternetSendMail1->UTF8Encoded = true;

	InternetSendMail1->Recipients->Add();
	InternetSendMail1->Recipients->Recipients[0]->Address = "mburisa@tvz.hr";
}

