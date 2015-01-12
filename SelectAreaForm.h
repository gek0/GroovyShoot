//---------------------------------------------------------------------------

#ifndef SelectAreaFormH
#define SelectAreaFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TselectArea_winForm : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TImage *select_slika;
	TShape *podrucje;
	void __fastcall select_slikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall select_slikaMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall select_slikaMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	  int vrh;
	  int lijevo;
	  int duzina;
	  int sirina;
	  bool misKliknut;
	__fastcall TselectArea_winForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TselectArea_winForm *selectArea_winForm;
//---------------------------------------------------------------------------
#endif
