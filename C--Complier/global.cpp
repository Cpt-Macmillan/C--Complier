#include"global.h"

//��filename�ļ� �ṩ���������
int infile(fstream &in, string filename)
{
	in.open(filename, ios::in);
	if (!in)
	{
		fout << "�ļ�" << filename << "��ʧ��!" << endl;
		return 0;
	}
	return 1;
}

//��filename�ļ� �ṩ��������
int outfile(fstream &out, string filename)
{
	out.open(filename, ios::out);
	if (!out)
	{
		fout << "�ļ�" << filename << "��ʧ��!" << endl;
		return 0;
	}
	return 1;
}

//�ر���������ļ�
void closefile(fstream &file1, fstream &file2)
{
	file1.close();
	file2.close();
}

//����ļ�����
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

//����ָ���
void divideline()
{
	fout << "------------------------------------------" << endl;
}

//�����̴����Լ��������
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
	fout << content<<"���" << endl;
	divideline();
	w.step_finish("���ڽ���"+period+"...");
	return 0;
}

//ȥ���ַ���ǰ�����Ŀո�
void fix(string &str)
{
	if (str[0] == ' ')
		str.assign(str, 1, str.length() - 1);		//���ַ�Ϊ�ո�
	if (str[str.length() - 1] == ' ')
		str.assign(str, 0, str.length() - 1);		//ĩ�ַ�Ϊ�ո�
}

