#include <stdio.h>


#include <stdlib.h>


#include <string.h>


int main(int argc, char* argv[])


{


    FILE* fp;


    int Char_Count = 0, Word_Count = 0, i = 0;//���ַ����͵������ȼ���0


	char ch[100], str1[10] = "-c", str2[10] = "-w"; //��-c��-wָ���Ӧ�����������


    if ((fp =fopen("C:\\Users\\apple\\Desktop\\WordCount\\test.txt", "r"))== NULL)//�ж��ļ��ܷ�������


	{


        printf("Error!");


		exit(0);


    }


    ch[0]= fgetc(fp);//���ļ����ַ������ַ�������


    if (ch[0] != ' ' && ch[0] != ',')//�жϵ�һ���ַ��ǲ��ǵ���


        Word_Count++;


    while (ch[i] != EOF) 


	{


        putchar(ch[i]);        


        ch[i+1]=fgetc(fp);


        Char_Count++;


        if (((ch[i+1] >= 'a' && ch[i+1] <= 'z') || (ch[i+1] >= 'A' && ch[i+1] <= 'Z')) && (ch[i] == ' '|| ch[i] == ','))//���ļ��еĵ��ʼ���


        {


            Word_Count++;


        }


        i++;


    }


	if(strcmp(argv[1],str1)==0)//������-cʱ������ַ���


		printf("�ַ���:%d\n", Char_Count);


	else if(strcmp(argv[1],str2)==0)//������-wʱ�����������


		printf("������:%d\n", Word_Count);


    getchar();


	fclose(fp);


    return 0;


}