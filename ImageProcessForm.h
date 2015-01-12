//---------------------------------------------------------------------------

#ifndef ImageProcessFormH
#define ImageProcessFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ToolWin.hpp>
#include <ctime>
#include <string>
//---------------------------------------------------------------------------
class Tprocess_winForm : public TForm
{
__published:	// IDE-managed Components
	TImage *capture_output;
	TSavePictureDialog *image_saveDialog;
	TToolBar *ToolBar1;
	TButton *gumb_save;
	void __fastcall gumb_saveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall Tprocess_winForm(TComponent* Owner);
		//dohvati trenutno vrijeme i datum
	const UnicodeString TrenutnoVrijeme(){
		time_t now = time(0);
		struct tm tstruct;
		char buffer[40];

		tstruct = *localtime(&now);
		strftime(buffer, sizeof(buffer), "%d.%m.%Y_%H%S", &tstruct);

		return buffer;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE Tprocess_winForm *process_winForm;
//---------------------------------------------------------------------------
#endif
