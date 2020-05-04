object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 299
  ClientWidth = 604
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 193
    Top = 146
    Width = 3
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 512
    Top = 247
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 409
    Height = 73
    Lines.Strings = (
      'Start working, the sun is still high...')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 342
    Top = 87
    Width = 75
    Height = 25
    Caption = 'Insert All'
    TabOrder = 1
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 289
    Top = 165
    Width = 208
    Height = 120
    ColCount = 2
    DefaultColWidth = 90
    FixedCols = 0
    RowCount = 20
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goAlwaysShowEditor]
    TabOrder = 2
  end
  object Button2: TButton
    Left = 185
    Top = 165
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 185
    Top = 202
    Width = 75
    Height = 21
    TabOrder = 4
  end
  object Button3: TButton
    Left = 8
    Top = 94
    Width = 74
    Height = 25
    Caption = 'ShowPost'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 342
    Top = 118
    Width = 75
    Height = 25
    Caption = 'Delete All'
    TabOrder = 6
    OnClick = Button4Click
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 196
    Width = 171
    Height = 27
    ColCount = 2
    DefaultColWidth = 83
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
    TabOrder = 7
  end
  object Button5: TButton
    Left = 56
    Top = 165
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 8
    OnClick = Button5Click
  end
  object TreeView1: TTreeView
    Left = 432
    Top = 8
    Width = 164
    Height = 151
    Indent = 19
    TabOrder = 9
    OnClick = TreeView1Click
  end
  object Button6: TButton
    Left = 521
    Top = 165
    Width = 75
    Height = 25
    Caption = 'TreeView'
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 88
    Top = 94
    Width = 75
    Height = 25
    Caption = 'ShowPref'
    TabOrder = 11
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 169
    Top = 94
    Width = 75
    Height = 25
    Caption = 'ShowInf'
    TabOrder = 12
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 185
    Top = 229
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 13
    OnClick = Button9Click
  end
  object Edit2: TEdit
    Left = 112
    Top = 260
    Width = 171
    Height = 21
    TabOrder = 14
  end
  object Button10: TButton
    Left = 512
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Num of Nodes'
    TabOrder = 15
    OnClick = Button10Click
  end
end
