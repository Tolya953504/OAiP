//---------------------------------------------------------------------------
#pragma once
#include <vcl.h>
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif
struct node // ��������� ��� ������������� ����� ������
{
	int key;
	AnsiString str;
	unsigned char height;
	node* left;
	node* right;
	node(int k, AnsiString str1) { key = k; left = right = 0; height = 1; str = str1;}
};
class Tree
{
	private:
	int numb = 0;
	public:
	node* root;
	void ZeroNumb(); //��������� numb
    void NumberOfNodes(node* root);
	void Search(node* root, int key); //����� ��������
	void Output1q(node* root,TTreeNode *item);   //����� ���������� ��� TTreeView
	void Free(node *&root);      //������� ������
	void treeprintInf(node* root);  //��������� �����
	void treeprintPost(node *tree);  //������������� �����
	void treeprintPre(node *tree); //������������ �����
	unsigned char height(node* p);      //�������������� ���������� � ������
	int bfactor(node* p);    //������, ������� ������ �� ������ ������������ ������
	void fixheight(node* p);    //���������� � ������ ������ (����)
	node* rotateright(node* p); // ������ ������� ������ p
	node* rotateleft(node* q); // ����� ������� ������ q
	node* insert(node* p, int k, AnsiString str); // ������� ����� k � ������ � ������ p
	node* findmin(node* p); // ����� ���� � ����������� ������ � ������ p
	node* removemin(node* p); // �������� ���� � ����������� ������ �� ������ p
	node* remove(node* p, int k); // �������� ����� k �� ������ p
	node* balance(node* p); // ������������ ���� p
};


