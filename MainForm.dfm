object main_winForm: Tmain_winForm
  Left = 0
  Top = 0
  HelpContext = 30
  Caption = 'GroovyShoot'
  ClientHeight = 422
  ClientWidth = 419
  Color = clBtnFace
  Constraints.MaxHeight = 480
  Constraints.MaxWidth = 435
  Constraints.MinHeight = 480
  Constraints.MinWidth = 435
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  HelpFile = 'groovyshoot_help.chm'
  Menu = Menu
  OldCreateOrder = False
  Position = poDesktopCenter
  ScreenSnap = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object type_group2: TGroupBox
    Left = 16
    Top = 8
    Width = 185
    Height = 97
    Caption = 'Screen Type'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object type1: TRadioButton
      Left = 48
      Top = 24
      Width = 134
      Height = 17
      Caption = 'Full Window'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object type2: TRadioButton
      Left = 48
      Top = 47
      Width = 134
      Height = 17
      Caption = 'Active Window'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object type3: TRadioButton
      Left = 48
      Top = 70
      Width = 134
      Height = 17
      Caption = 'Custom Window'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object gumb_main: TButton
    Left = 128
    Top = 184
    Width = 161
    Height = 25
    Caption = 'Capture'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = gumb_mainClick
  end
  object auto_group: TGroupBox
    Left = 16
    Top = 240
    Width = 385
    Height = 134
    Caption = 'Automatic Capture'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    object label_timer: TLabel
      Left = 16
      Top = 24
      Width = 123
      Height = 15
      Caption = 'Timer interval (1-100sec):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
    end
    object label_amount: TLabel
      Left = 16
      Top = 75
      Width = 110
      Height = 15
      Caption = 'Image count (1-1000):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
    end
    object input_timer: TEdit
      Left = 320
      Top = 40
      Width = 41
      Height = 23
      MaxLength = 3
      NumbersOnly = True
      TabOrder = 0
      OnChange = input_timerChange
    end
    object slider_timer: TScrollBar
      Left = 16
      Top = 45
      Width = 257
      Height = 17
      Min = 1
      PageSize = 0
      Position = 1
      TabOrder = 1
      OnChange = slider_timerChange
    end
    object input_amount: TEdit
      Left = 320
      Top = 88
      Width = 41
      Height = 23
      MaxLength = 4
      NumbersOnly = True
      TabOrder = 2
      OnChange = input_amountChange
    end
    object slider_amount: TScrollBar
      Left = 16
      Top = 96
      Width = 257
      Height = 17
      Max = 1000
      Min = 1
      PageSize = 0
      Position = 1
      TabOrder = 3
      OnChange = slider_amountChange
    end
  end
  object gumb_start: TButton
    Left = 128
    Top = 380
    Width = 161
    Height = 25
    Caption = 'Start Capture'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = gumb_startClick
  end
  object type_group1: TGroupBox
    Left = 16
    Top = 111
    Width = 185
    Height = 59
    Caption = 'Color Settings (JPEG only)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    object select_color: TComboBox
      Left = 16
      Top = 24
      Width = 153
      Height = 23
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = select_colorChange
      Items.Strings = (
        'Color'
        'Grayscale')
    end
  end
  object dir_group: TGroupBox
    Left = 216
    Top = 8
    Width = 185
    Height = 97
    Caption = 'Directory Settings'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    object input_dir: TEdit
      Left = 13
      Top = 21
      Width = 161
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object gumb_dir: TButton
      Left = 56
      Top = 50
      Width = 75
      Height = 25
      Caption = 'Choose'
      TabOrder = 1
      OnClick = gumb_dirClick
    end
  end
  object format_group: TGroupBox
    Left = 216
    Top = 111
    Width = 185
    Height = 59
    Caption = 'Image Format'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    object select_format: TComboBox
      Left = 16
      Top = 24
      Width = 153
      Height = 23
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI Light'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = select_formatChange
      Items.Strings = (
        'Bitmap'
        'JPEG'
        'PNG')
    end
  end
  object Menu: TMainMenu
    Left = 8
    Top = 376
    object Options: TMenuItem
      Caption = 'Options'
      object Tray: TMenuItem
        Caption = 'Hide to tray'
        OnClick = TrayClick
      end
      object Language: TMenuItem
        Caption = 'Language'
        object langHR: TMenuItem
          Caption = 'Croatian'
          OnClick = langHRClick
        end
        object langEN: TMenuItem
          Caption = 'English'
          OnClick = langENClick
        end
        object langIT: TMenuItem
          Caption = 'Italian'
          OnClick = langITClick
        end
      end
    end
    object About: TMenuItem
      Caption = 'About'
      object helpDialog: TMenuItem
        Caption = '&Help'
        ShortCut = 16456
        OnClick = helpDialogClick
      end
      object aboutDialog: TMenuItem
        Caption = '&About'
        ShortCut = 16449
        OnClick = aboutDialogClick
      end
    end
  end
  object TrayIcon1: TTrayIcon
    Animate = True
    AnimateInterval = 2500
    OnClick = TrayIcon1Click
    Left = 48
    Top = 376
  end
  object spremi_sliku: TSaveDialog
    Left = 376
    Top = 376
  end
end
