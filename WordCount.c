#include <stdio.h>


#include <stdlib.h>


#include <string.h>


int main(int argc, char* argv[])


{


    FILE* fp;


    int Char_Count = 0, Word_Count = 0, i = 0;//将字符数和单词数先记作0


	char ch[100], str1[10] = "-c", str2[10] = "-w"; //将-c和-w指令对应的输出区别开来


    if ((fp =fopen("C:\\Users\\apple\\Desktop\\WordCount\\test.txt", "r"))== NULL)//判断文件能否正常打开


	{


        printf("Error!");


		exit(0);


    }


    ch[0]= fgetc(fp);//将文件的字符存入字符数组中


    if (ch[0] != ' ' && ch[0] != ',')//判断第一个字符是不是单词


        Word_Count++;


    while (ch[i] != EOF) 


	{


        putchar(ch[i]);        


        ch[i+1]=fgetc(fp);


        Char_Count++;


        if (((ch[i+1] >= 'a' && ch[i+1] <= 'z') || (ch[i+1] >= 'A' && ch[i+1] <= 'Z')) && (ch[i] == ' '|| ch[i] == ','))//对文件中的单词计数


        {


            Word_Count++;


        }


        i++;


    }


	if(strcmp(argv[1],str1)==0)//当输入-c时，输出字符数


		printf("字符数:%d\n", Char_Count);


	else if(strcmp(argv[1],str2)==0)//当输入-w时，输出单词数


		printf("单词数:%d\n", Word_Count);


    getchar();


	fclose(fp);


    return 0;


}