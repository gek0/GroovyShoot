object process_winForm: Tprocess_winForm
  Left = 0
  Top = 0
  Caption = 'GroovyShoot - ScreenCapture'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object capture_output: TImage
    AlignWithMargins = True
    Left = 5
    Top = 38
    Width = 625
    Height = 256
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alClient
    ExplicitLeft = 224
    ExplicitTop = 88
    ExplicitWidth = 105
    ExplicitHeight = 105
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 635
    Height = 33
    ButtonHeight = 23
    Caption = 'ToolBar1'
    TabOrder = 0
    object gumb_save: TButton
      Left = 0
      Top = 0
      Width = 153
      Height = 23
      Caption = 'Save Image'
      TabOrder = 0
      OnClick = gumb_saveClick
    end
  end
  object image_saveDialog: TSavePictureDialog
    InitialDir = '.'
    Left = 584
    Top = 248
  end
end
