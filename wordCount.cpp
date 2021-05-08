#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
    int ch, count = 1;
    FILE *p;   

   
    if (argc != 3){
        printf("请使用格式: %s 文件名",argv[0]);
        exit(1);   
    }

    // 判断能否成功打开文件
    if ((p = fopen(argv[2],"r")) == NULL){  //将argv[1]赋值给指针p
        printf("打开文件 %s 失败",argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count = 0;
        while((ch = getc(p)) != EOF) { 
            count++;
        }
        printf("字符数：%d个\n", count);
    } else {
        while((ch = getc(p)) != EOF) {
            if ((ch == ' ') || (ch == ',')) 
			count++;
        }
        printf("单词数：%d个\n", count);
    }
    fclose(p);
    return 0;
}
