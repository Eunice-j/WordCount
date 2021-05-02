#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#include <string.h>

#define count 2
char c[count] = { '-','c' };	//�ַ�
char w[count] = { '-','w' };	//����

int Cal(FILE* file, int* charNum, int* wordNum);
int main(int argc, char* argv[])
{
	int charNum = 0, wordNum = 0;
	char file_name[20];
	char parameter[count + 1];
	FILE* file;
	scanf("%s", &parameter);
	file = fopen("input.txt", "r");
	if (file == NULL)
	{
		printf("�ļ�Ϊ�գ������ļ�·���Ƿ���ȷ������");
		return 0;
	}
	Cal(file, &charNum, &wordNum);

	if (strcmp(parameter, c) == 0) // -c
	{
		printf("�ַ�����%d\n", charNum);
	}
	else if (strcmp(parameter, w) == 0) // -w
	{
		printf("��������%d\n", wordNum);
	}	
	fclose(file);
	return 0;
}

int Cal(FILE* file, int* charNum, int* wordNum) {
	int flag = 0;//�����ǣ����ڵ�������1�����ڼ������0
	char temp;
	while ((temp = fgetc(file)) != EOF)
	{
		(*charNum)++;
		if (flag == 0 && (temp != ' ' || temp != ',')) {
			(*wordNum)++;
			flag = 1;
		}
		else if (temp == ' ' || temp == ',')
			flag = 0;
	}
	return 0;
}