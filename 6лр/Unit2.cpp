//---------------------------------------------------------------------------

#pragma hdrstop
 #include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Tree::NumberOfNodes(node* root)
{
	//node* tmp = root;
	if (root != NULL)
	{
		if((root->left != 0) && (root->right != 0))
			numb++;
		NumberOfNodes(root->left); //����������� ������� ��� ������ ���������
		NumberOfNodes(root->right); //����������� ������� ��� ������� ���������
	}
	Form1->Label2->Caption = "Number: " + IntToStr(numb);
}
void Tree::ZeroNumb()
{
    numb = 0;
}
void Tree::Search(node* root, int key)
{
	node* tmp = root;
   /* if( !tmp )
	{
		Form1->Label1->Caption = "No such key";
		return;
	}  */
	if (tmp!=NULL)
	{
		if(tmp->key == key)
		{
			Form1->Edit2->Text = tmp->str;
			return;
		}
		Search(tmp->left, key); //����������� ������� ��� ������ ���������
		Search(tmp->right, key); //����������� ������� ��� ������� ���������
	}
	if( !tmp )
	{
		Form1->Label1->Caption = "No such key";
		return;
	}
}
void Tree::Output1q(node* root,TTreeNode *item)
{
	TTreeNode *tmpItem;
	node* tmp = root;
	if (tmp != NULL)
	{
		tmpItem=Form1->TreeView1->Items->AddChild(item,IntToStr(tmp->key));   //���������� � Tree
		Output1q(tmp->left,tmpItem);
		Output1q(tmp->right,tmpItem);
	}
}
void Tree::Free(node *&root)
{
	if (root->left)
	{
		Free(root->left);
	}
	if (root->right)
	{
		Free(root->right);
	}
	root=NULL;
}
void Tree::treeprintPost(node *tree)
{
	if (tree!=NULL)
	{
		//���� �� ���������� ������ ����
		treeprintPost(tree->left); //����������� ������� ��� ������ ���������
		treeprintPost(tree->right); //����������� ������� ��� ������� ���������
		Form1->Memo1->Lines->Add(IntToStr(tree->key) + " " + tree->str);
	}
}
void Tree::treeprintPre(node *tree)
{
	if (tree!=NULL)
	{
		//���� �� ���������� ������ ����
		Form1->Memo1->Lines->Add(IntToStr(tree->key) + " " + tree->str);
		treeprintPre(tree->left); //����������� ������� ��� ������ ���������
		treeprintPre(tree->right); //����������� ������� ��� ������� ���������
	}
}
void Tree::treeprintInf(node* root)
{
	node* tmp = root;
	if (tmp!=NULL)
	{ //���� �� ���������� ������ ����
		treeprintInf(tmp->left); //����������� ������� ��� ������ ���������
		Form1->Memo1->Lines->Add(IntToStr(tmp->key) + " " + tmp->str);
		treeprintInf(tmp->right); //����������� ������� ��� ������� ���������
	}
}
unsigned char Tree::height(node* p)      //�������������� ���������� � ������
{
	return p?p->height:0;
}

int Tree::bfactor(node* p)        //������, ������� ������ �� ������ ������������ ������
{
	return height(p->right)-height(p->left);
}

void Tree::fixheight(node* p)      //���������� � ������ ������ (����)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

node* Tree::rotateright(node* p) // ������ ������� ������ p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* Tree::rotateleft(node* q) // ����� ������� ������ q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* Tree::balance(node* p) // ������������ ���� p
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // ������������ �� �����
}

node* Tree::insert(node* p, int k, AnsiString str) // ������� ����� k � ������ � ������ p
{
	if( !p ) return new node(k, str);
	if( k < p->key )
		p->left = insert(p->left,k,str);
	else
		p->right = insert(p->right,k, str);
	return balance(p);
}

node* Tree::findmin(node* p) // ����� ���� � ����������� ������ � ������ p
{
	return p->left?findmin(p->left):p;
}

node* Tree::removemin(node* p) // �������� ���� � ����������� ������ �� ������ p
{
	if( p->left == 0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* Tree::remove(node* p, int k) // �������� ����� k �� ������ p
{
	if( !p )
	{
		Form1->Label1->Caption = "No such key";
		return 0;
	}
	if( k < p->key )
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);
	else //  k == p->key
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if( !r ) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
