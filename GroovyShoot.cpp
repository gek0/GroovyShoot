//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("ImageProcessForm.cpp", process_winForm);
USEFORM("HelpForm.cpp", help_winForm);
USEFORM("SelectAreaForm.cpp", selectArea_winForm);
USEFORM("MainForm.cpp", main_winForm);
USEFORM("AboutForm.cpp", about_winForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{

		HANDLE gMutex;
		gMutex = CreateMutex(NULL, FALSE, L"GroovyApp");

		if (gMutex == NULL)
			ShowMessage(GetLastError());
		else
			if (GetLastError() == ERROR_ALREADY_EXISTS) {
			ShowMessage("Aplikacija je veæ pokrenuta! Pogledajte da nije sakrivena.");
			return -1;
		}

		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Turquoise Gray");
		Application->CreateForm(__classid(Tmain_winForm), &main_winForm);
		Application->CreateForm(__classid(Tabout_winForm), &about_winForm);
		Application->CreateForm(__classid(Tprocess_winForm), &process_winForm);
		Application->CreateForm(__classid(TselectArea_winForm), &selectArea_winForm);
		Application->CreateForm(__classid(Thelp_winForm), &help_winForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
