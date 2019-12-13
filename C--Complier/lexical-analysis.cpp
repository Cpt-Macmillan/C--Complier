#include "lexical-analysis.h"

//�ж��Ƿ�Ϊ�հ��ַ� �����޸�����ֵ
int isBC(char ch) {
	switch (ch) 
	{
		case ' ':
			column++;
			break;
		case '\t':
			column += 4;
			break;
		case '\r':
		case '\n':
			line++;
			column = 1;
			break;
		default:
			return 0;
	}
	return 1;
}

//�ж��Ƿ�Ϊ������ �Ƿ���1 ���򷵻�0
int Reserve(string strToken) {
	int i;
	for (i = 0; i < 6; i++) {
		if (strToken.compare(key[i]) == 0) {
			return 1;
		}
	}
	return 0;
}

//����ȡ�ļ�����һ���ַ�
void Retract(fstream &source) {
	if (!source.eof()) {
		source.seekg(-1, ios::cur);
	}
}

//�ʷ�����
int lexicalanalysis(fstream &in, fstream &out)
{
	line = 1; column = 1;
	string strToken;
	char ch;
	while (!in.eof())
	{
		ch = in.get();
		if (in.fail())
			break;
		if (ch < 0) {
			fout << "Error Occured at " << line << ", " << column << ";" << endl;
			fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
			return 1;
			
		}
		if (isBC(ch)) { //�����հ��ַ�
			strToken = "";
		}
		else if (isalpha(ch)) { //������ĸ

			while (isalpha(ch) || isdigit(ch)) { //��ȡ����token ֱ����һ���հ��ַ�
				strToken.push_back(ch);
				column++;
				ch = in.get();
			}

			if (Reserve(strToken)) { //�ж�token�Ƿ�Ϊ������
				//fout << strToken << ", RESERVED" << endl;
				out << strToken << " RESERVED" << " " << line << " " << column - strToken.length() << endl;
			}
			else {
				// fout << strToken << ", ID" << endl;
				out << strToken << " ID" << " " << line << " " << column - strToken.length() << endl;
			}

			strToken = "";
			Retract(in);
		}
		else if (isdigit(ch)) { //��������
			while (isdigit(ch)) {	//��ȡ������
				strToken.push_back(ch);
				column++;
				ch = in.get();
				if (ch < 0) {
					fout << "Error Occured at line:" << line << ", column:" << column << ";" << endl;
					fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
					return 1;
				}
			}
			//����֮�������ĸ ���ִ����ʽ��ID ����
			if (isalpha(ch)) {
				fout << "[Lexical ERROR] " << " [" << line << "," << column - strToken.length() << "] " << "Invalid ID: "<<endl;
				fout << "Probable Reason: ����֮�������ĸ�ǲ�����ġ�" << endl;
				return 1;
				while (isalpha(ch) || isdigit(ch)) {
					strToken.push_back(ch);
					column++;
					ch = in.get();
					if (ch < 0) {
						fout << "Error Occured at " << line << ", " << column << ";" << endl;
						fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
						return 1;
					}
				}

				fout << "\"" << strToken << "\"" << endl;
				out << "^ " << strToken << " ID " << line << " " << column - strToken.length() << endl;
				fout << "[Lexical ERROR] " << " [" << line << "," << column - strToken.length() << "] " << "Invalid ID: "<<endl;
				return 1;
				out << "\"" << strToken << "\"" << endl;
			}
			else {
				//fout << strToken << ", INT" << endl;
				out << strToken << " NUM" << " " << line << " " << column - strToken.length() << endl;
			}

			Retract(in);
			strToken = "";
		}
		else {
			switch (ch) //����OP���ַ�
			{ 
				case '=':
					column++;
					ch = in.get();
					if (ch < 0) {
						fout << "Error Occured at " << line << ", " << column << ";" << endl;
						fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
						return 1;
					}
					if (ch == '=')
					{
						column++;
						out << "== COP" << " " << line << " " << column - 2 << endl;
					}
					else {
						out << "=  AOP" << " " << line << " " << column - 1 << endl;
						Retract(in);
					}
					break;
				case '<':
					column++;
					ch = in.get();
					if (ch < 0) {
						fout << "Error Occured at " << line << ", " << column << ";" << endl;
						fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
						return 1;
					}
					if (ch == '=') {
						column++;
						//fout << "<=, COP" << endl;
						out << "<= COP" << " " << line << " " << column - 2 << endl;
					}
					else {
						//fout << "<, COP" << endl;
						out << "<  COP" << " " << line << " " << column - 1 << endl;
						Retract(in);
					}
					break;
				case '>':
					column++;
					ch = in.get();
					if (ch < 0) {
						fout << "Error Occured at " << line << ", " << column << ";" << endl;
						fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
						return 1;
					}
					if (ch == '=') {
						column++;
						//fout << ">=, COP" << endl;
						out << ">=  COP" << " " << line << " " << column - 2 << endl;
					}
					else {
						//fout << ">, COP" << endl;
						out << ">  COP" << " " << line << " " << column - 1 << endl;
						Retract(in);
					}
					break;
				case '!':
					column++;
					ch = in.get();
					if (ch < 0) {
						fout << "Error Occured at " << line << ", " << column << ";" << endl;
						fout << "Probable Reason: ȫ���ַ��ǲ�������ġ�" << endl;
						return 1;
					}
					if (ch == '=') {
						column++;
						out << "!=  COP" << " " << line << " " << column - 2 << endl;
					}
					else
					{
						//fout << "[Lexical ERROR] " << " [" << line << "," << column << "] " << "Invalid COP ";
						fout << "[Lexical ERROR] " << " [" << line << "," << column - 1 << "] " << "Invalid COP "<<endl;
						return 1;
						Retract(in);
					}
					break;
				case '+':
				case '-':
				case '/':
				case '*':
					column++;
					//fout << ch << ", OOP" << endl;
					out << ch << " OOP" << " " << line << " " << column - 1 << endl;
					break;
				case ';':
					column++;
					//fout << ch << ", EOP" << endl;
					out << ch << " EOP" << " " << line << " " << column - 1 << endl;
					break;
				case '(':
				case ')':
				case ',':
				case '[':
				case ']':
				case '{':
				case '}':
					column++;
					//fout << ch << ", SOP" << endl;
					out << ch << " SOP" << " " << line << " " << column - 1 << endl;
					break;
				default:	//δʶ��ɹ�����Ϣ ��ʾ������Ϣ
					column++;
					//fout << ch << ", UNKNOWN" << endl;
					fout << "[Lexical ERROR] " << " [" << line << "," << column - 1 << "] " << "UNKNOW EXPRESSION " << ch << endl;
					return 1;
			}
		}
	}
	out << "# # " << line + 1 << " 1";
	return 0;
}

void fixlex(void)
{
	fstream in, out;
	string temp;
	vector<struct Token>tokens;
	vector<struct Token>::iterator vec;
	Token token;
	in.open(file_lex, ios::in);
	while (!in.eof())
	{
		in >> token.re >> token.type >> token.line >> token.colume;
		if (in.fail())
			break;
		tokens.push_back(token);
	}
	for (vec = tokens.begin();vec != tokens.end();vec++)
	{
		if (vec->type == "ID" && (vec + 1)->re == "(")
			vec->type = "IDF";
		if (vec->type == "ID" && (vec + 1)->re == "=")
			vec->type = "ID1";
	}
	in.close();
	out.open(file_lex, ios::out);
	for (vec = tokens.begin();vec != tokens.end();vec++)
		out << vec->re << " " << vec->type << " " << vec->line << " " << vec->colume << endl;
	out.close();
}