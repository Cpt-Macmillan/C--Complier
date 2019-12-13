#include"global.h"

//打开filename文件 提供程序的输入
int infile(fstream &in, string filename)
{
	in.open(filename, ios::in);
	if (!in)
	{
		fout << "文件" << filename << "打开失败!" << endl;
		return 0;
	}
	return 1;
}

//打开filename文件 提供结果的输出
int outfile(fstream &out, string filename)
{
	out.open(filename, ios::out);
	if (!out)
	{
		fout << "文件" << filename << "打开失败!" << endl;
		return 0;
	}
	return 1;
}

//关闭输入输出文件
void closefile(fstream &file1, fstream &file2)
{
	file1.close();
	file2.close();
}

//输出文件内容
void readfile(string filename)
{
	char temp;
	fstream file;
	infile(file, filename);
	file >> noskipws;
	while (!file.eof())
	{
		file >> temp;
		fout << temp;
		if (file.fail())
			break;
	}
	fout << endl;
}

//输出分割线
void divideline()
{
	fout << "------------------------------------------" << endl;
}

//各过程处理以及界面输出
int precedure(const string& period, int num, const string& filein, const string& fileout,int (*func)(fstream &,fstream &), const string& content,CComplier &w)
{
	int error;
	fout << "period:" << period << "\tstep:" << num << "\tcontent:" << content << endl;
	fout << "\tresource_file:\t\t\"" << filein << "\"" << endl;
	fout << "\tdestination_file:\t\"" << fileout << "\"" << endl;
	if (infile(in, filein) && outfile(out, fileout)) {
		error = func(in, out);
		if (error) return 1;
	}
	else {
		
		return 1;
	}
	closefile(in, out);
	fout << content<<"完成" << endl;
	divideline();
	w.step_finish("正在进行"+period+"...");
	return 0;
}

//去除字符串前后多余的空格
void fix(string &str)
{
	if (str[0] == ' ')
		str.assign(str, 1, str.length() - 1);		//首字符为空格
	if (str[str.length() - 1] == ' ')
		str.assign(str, 0, str.length() - 1);		//末字符为空格
}

