#include "global.h"


//������Ϣ����ļ�
fstream fout("debug.txt", ios::out);

int compiler_main(CComplier &w)
{
	fout << "resource file:" << "Saved in \"" << resource << "\"" << endl;
	divideline();
	//Ԥ���� 
	//P1 1.ɾ��ע�� 2.ɾ������հ��ַ� 
	if(precedure(period[1], 1, resource, file_nozs, delzs, content1[1],w)) return 1;
	if(precedure(period[1], 2, file_nozs, file_clear, delblank, content1[2],w)) return 1;
	//P1 �﷨���� 3.���﷨����|����  4.���first,follow��
	if(precedure(period[1], 3, file_grammar, file_ll1grammar, delleftrecursion, content1[3],w))return 1;
	if(precedure(period[1], 4, file_ll1grammar, file_ad_grammar, splitgrammar, content1[4],w))return 1;
	if(precedure(period[1], 5, file_ad_grammar, file_vn_vt, cal_vn_vt, content1[5],w)) return 1;
	if(precedure(period[1], 6, file_ad_grammar, file_ff, cal_first_follow, content1[6],w))return 1;
	if(precedure(period[1], 7, file_ad_grammar, file_mtable, cal_mtable, content1[7],w))return 1;
	//�ʷ�����
	if (precedure(period[2], 1, file_clear, file_lex, lexicalanalysis, content2, w)) {
		fout << "�ʷ�������������3 lexical.txt�Ի�ø�����Ϣ"<<endl;
		return 1;
	}
	fixlex();
	//�������
	if (precedure(period[3], 1, file_lex, file_showstack, make_tree, content3[1], w)) {
		fout << "�﷨������������10 stack.txt�Ի�ø�����Ϣ��"<<endl;
		return 1;
	}
	if(precedure(period[3], 2, file_lex, file_symtable, calsymboltable, content3[2],w)) {
		fout << "�﷨������������10 stack.txt�Ի�ø�����Ϣ��"<<endl;
		return 1;
	}
	//�м��������
	if(precedure(period[4], 1, file_lex, file_midcode, midcode, content4[1],w)) return 1;
	if(precedure(period[4], 2, file_midcode, file_optimize, optimize, content4[2],w)) return 1;
	w.step_finish("Sematic Analysis Done!");
	return 0;
}