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
		NumberOfNodes(root->left); //Рекурсивная функция для левого поддерева
		NumberOfNodes(root->right); //Рекурсивная функция для правого поддерева
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
		Search(tmp->left, key); //Рекурсивная функция для левого поддерева
		Search(tmp->right, key); //Рекурсивная функция для правого поддерева
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
		tmpItem=Form1->TreeView1->Items->AddChild(item,IntToStr(tmp->key));   //Добавление в Tree
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
		//Пока не встретится пустой узел
		treeprintPost(tree->left); //Рекурсивная функция для левого поддерева
		treeprintPost(tree->right); //Рекурсивная функция для правого поддерева
		Form1->Memo1->Lines->Add(IntToStr(tree->key) + " " + tree->str);
	}
}
void Tree::treeprintPre(node *tree)
{
	if (tree!=NULL)
	{
		//Пока не встретится пустой узел
		Form1->Memo1->Lines->Add(IntToStr(tree->key) + " " + tree->str);
		treeprintPre(tree->left); //Рекурсивная функция для левого поддерева
		treeprintPre(tree->right); //Рекурсивная функция для правого поддерева
	}
}
void Tree::treeprintInf(node* root)
{
	node* tmp = root;
	if (tmp!=NULL)
	{ //Пока не встретится пустой узел
		treeprintInf(tmp->left); //Рекурсивная функция для левого поддерева
		Form1->Memo1->Lines->Add(IntToStr(tmp->key) + " " + tmp->str);
		treeprintInf(tmp->right); //Рекурсивная функция для правого поддерева
	}
}
unsigned char Tree::height(node* p)      //Предоставление информации о высоте
{
	return p?p->height:0;
}

int Tree::bfactor(node* p)        //Фактор, который влияет на способ балансировки дерева
{
	return height(p->right)-height(p->left);
}

void Tree::fixheight(node* p)      //Информация о высоте дерева (учёт)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

node* Tree::rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* Tree::rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* Tree::balance(node* p) // балансировка узла p
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
	return p; // балансировка не нужна
}

node* Tree::insert(node* p, int k, AnsiString str) // вставка ключа k в дерево с корнем p
{
	if( !p ) return new node(k, str);
	if( k < p->key )
		p->left = insert(p->left,k,str);
	else
		p->right = insert(p->right,k, str);
	return balance(p);
}

node* Tree::findmin(node* p) // поиск узла с минимальным ключом в дереве p
{
	return p->left?findmin(p->left):p;
}

node* Tree::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if( p->left == 0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* Tree::remove(node* p, int k) // удаление ключа k из дерева p
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
