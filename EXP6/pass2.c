#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
char label[30],adddr[30],opcode[10],hexcode[30];
char t1[20],t2[20],t3[20],t4[20],address[10],operand[10],length[10],size[10],a[10],ad[10];
int s=-1,o=-1,i,j;
struct optab{
    char opcode[10];
    char hexcode[10];
}ot[30];

struct symtab{
    char label[10];
    char addr[10];
}st[30];

void read_optab(){
    while(1){
        o++;
        fscanf(fp3,"%s\t%s",ot[o].opcode,ot[o].hexcode);
        if(getc(fp3)==EOF)
            break;
    }
}

void read_symtab(){
    while(1){
        s++;
        fscanf(fp2,"%s\t%s",st[s].label,st[s].addr);
        if(getc(fp2)==EOF)
            break;
    }
}

void read_line(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    strcpy(t4,"");
    fscanf(fp1,"%s",t1);
    if(getc(fp1)!='\n'){
        fscanf(fp1,"%s",t2);
        if(getc(fp1)!='\n'){
            fscanf(fp1,"%s",t3);
            if(getc(fp1)!='\n')
                fscanf(fp1,"%s",t4);
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")!=0){
        strcpy(address,t1);
        strcpy(label,t2);
        strcpy(opcode,t3);
        strcpy(operand,t4);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0 && strcmp(t4,"")==0){
        strcpy(address,t1);
        strcpy(label,"");
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0 && strcmp(t4,"")==0){
            strcpy(address,t1);
            strcpy(label,"");
            strcpy(opcode,t1);
            strcpy(operand,"");
    }
}
void main(){
    fp1=fopen("intermediate.txt","r");
    fp2=fopen("symtab.txt","r");
    fp3=fopen("optab.txt","r");
    fp4=fopen("length.txt","r");
    fp5=fopen("assemlist.txt","w");
    fp6=fopen("objcode.txt","w");
    fscanf(fp4,"%s %s",length,size);
    read_optab();
    read_symtab();
    fscanf(fp1,"%s %s %s",label,opcode,operand);
    char start[10];
    strcpy(start,operand);
    if(strcmp(opcode,"START")==0){
        fprintf(fp5,"%s\t\t%s\t%s\n",label,opcode,operand);
        fprintf(fp6,"H^%s ^00%s^0000%s\n",label,operand,length);
        fprintf(fp6,"T^00%s%x",operand,atoi(size));
        read_line();
    }
    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"BYTE")==0){
            fprintf(fp5,"%s\t%s\t%s\t%s\t",address,label,opcode,operand);
            sprintf(ad,"%x",operand[2]);
            fprintf(fp5,"%s\n",ad);
            fprintf(fp6,"^%s",ad);
        }
        else if(strcmp(opcode,"WORD")==0){
            sprintf(a,"%x",atoi(operand));
            fprintf(fp5,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,a);
            fprintf(fp6,"^00000%s",a);
        }
        else if(strcmp(opcode,"RESB")==0 || (strcmp(opcode,"RESW")==0)){
            sprintf(a,"%x",atoi(operand));
            fprintf(fp5,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,a);
        }
        else{
            j=0;
            while(strcmp(opcode,ot[j].opcode)!=0)
                j++;
            i=0;
            while(strcmp(operand,st[i].label)!=0)
                i++;
            fprintf(fp5,"%s\t%s\t%s\t%s\t%s%s\n",address,label,opcode,operand,ot[j].hexcode,st[i].addr);
            fprintf(fp6,"^%s%s",ot[j].hexcode,st[i].addr);
        }
        read_line();
    }
    fprintf(fp5,"\t%s\t%s\t%s",label,opcode,operand);
    fprintf(fp6,"\nE^00%s",start);
}
