#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
    int ch, count = 1;
    FILE *p;   

   
    if (argc != 3){
        printf("��ʹ�ø�ʽ: %s �ļ���",argv[0]);
        exit(1);   
    }

    // �ж��ܷ�ɹ����ļ�
    if ((p = fopen(argv[2],"r")) == NULL){  //��argv[1]��ֵ��ָ��p
        printf("���ļ� %s ʧ��",argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count = 0;
        while((ch = getc(p)) != EOF) { 
            count++;
        }
        printf("�ַ�����%d��\n", count);
    } else {
        while((ch = getc(p)) != EOF) {
            if ((ch == ' ') || (ch == ',')) 
			count++;
        }
        printf("��������%d��\n", count);
    }
    fclose(p);
    return 0;
}
