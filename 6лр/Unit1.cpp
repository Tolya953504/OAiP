//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tree A;
TTreeNode *Node;// = new TTreeNode;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	Memo1->Lines->Clear();
	for(int i = 0; i < 20; i++)
	{
		if(StringGrid1->Cells[0][i].IsEmpty())  //Подсчитываем, сколько ячеек в StringGrid занято
		{
			n = i;
            break;
		}
    }
	for(int i = 0; i < n; i++)
	{
		A.root = A.insert(A.root, StrToInt(StringGrid1->Cells[0][i]), StringGrid1->Cells[1][i]); //Заполнение
	}
	A.treeprintPost(A.root);
   //	Memo1->Lines->Add(A.S);
}
//----------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Label1->Caption = " ";
	A.root = A.remove(A.root, StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	A.treeprintPost(A.root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	A.Free(A.root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	A.root = A.insert(A.root, StrToInt(StringGrid2->Cells[0][0]), StringGrid2->Cells[1][0]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	A.Output1q(A.root, Node);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1Click(TObject *Sender)
{

	Node = TreeView1->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	A.treeprintPre(A.root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	A.treeprintInf(A.root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Label1->Caption = " ";
	A.Search(A.root, StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
    A.ZeroNumb();
	A.NumberOfNodes(A.root);
}
//---------------------------------------------------------------------------

