#include "global.h"


//报错信息输出文件
fstream fout("debug.txt", ios::out);

int compiler_main(CComplier &w)
{
	fout << "resource file:" << "Saved in \"" << resource << "\"" << endl;
	divideline();
	//预处理 
	//P1 1.删除注释 2.删除多余空白字符 
	int i = 1;
	if (precedure(period[1], 1, resource, file_nozs, delzs, content1[1], w)) { return 1; w.set_visible_buttons(i); }
	if (precedure(period[1], 2, file_nozs, file_clear, delblank, content1[2],w)) { return 1; w.set_visible_buttons(i); }
	i = 2;
	//P1 语法分析 3.将语法根据|分离  4.求出first,follow集
	if(precedure(period[1], 3, file_grammar, file_ll1grammar, delleftrecursion, content1[3],w)) { return 1; w.set_visible_buttons(i); }
	if(precedure(period[1], 4, file_ll1grammar, file_ad_grammar, splitgrammar, content1[4],w)) { return 1; w.set_visible_buttons(i); }

	if(precedure(period[1], 5, file_ad_grammar, file_vn_vt, cal_vn_vt, content1[5],w)) { return 1; w.set_visible_buttons(i); }
	if(precedure(period[1], 6, file_ad_grammar, file_ff, cal_first_follow, content1[6],w)) { return 1; w.set_visible_buttons(i); }
	if(precedure(period[1], 7, file_ad_grammar, file_mtable, cal_mtable, content1[7],w)){ return 1; w.set_visible_buttons(i); }
	//词法分析
	if (precedure(period[2], 1, file_clear, file_lex, lexicalanalysis, content2, w)) {
		fout << "词法分析出错，查看“词法分析结果”以获得更多信息"<<endl;
		i = 3;
		w.set_visible_buttons(i);
		return 1;
	}
	i = 3;
	fixlex();
	//翻译程序
	i = 10;
	if (precedure(period[3], 1, file_lex, file_showstack, make_tree, content3[1], w)) {
		fout << "语法分析出错，查看“语法分析栈”以获得更多信息。"<<endl;
		w.set_visible_buttons(i);
		return 1;
	}
	
	if(precedure(period[3], 2, file_lex, file_symtable, calsymboltable, content3[2],w)) {
		fout << "语法分析出错，查看“语法分析栈”以获得更多信息。"<<endl;
		w.set_visible_buttons(i);
		return 1;
	}
	i = 13;
	//中间代码生成
	if(precedure(period[4], 1, file_lex, file_midcode, midcode, content4[1],w)) return 1;
	if(precedure(period[4], 2, file_midcode, file_optimize, optimize, content4[2],w)) return 1;
	w.step_finish("Sematic Analysis Done!");
	w.set_visible_buttons(i);
	return 0;
}