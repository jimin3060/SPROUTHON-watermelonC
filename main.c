#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define limit 10
#define MAX_NAME_LEN 20

struct student
{
    char name[MAX_NAME_LEN + 1];
    char ID[100];
    char call[100];
    char mail[100];
    char password[100];
};
struct survey
{
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
};

void join(struct student* info);
void list(struct student* info, struct student* m);
void covid19_self_exam();
//void schedule_manage(struct student* info);
int main()
{
    struct student m[100];
    char id[limit + 1] = "";
    char password[limit + 1] = "";
    int key_code;
    while (1)
    {
        struct student info[10];
        int i;
        printf("1. 학생 정보 입력\n");
        printf("2. 학생 목록 확인\n");
        printf("3. 코로나 자가검진 하기\n");
        printf("4. 등교 일정 관리 하기\n");
        printf("5. 종료\n");
        printf("번호를 입력하시오: ");
        scanf("%d", &i);
        printf("\n");

        if (i == 1)
        {
            join(info);
            i = 0;
        }
        if (i == 2)
        {
            list(info, m);
        }
        if (i == 3)
        {
            covid19_self_exam();
        }
         if (i == 4)
         {
            schedule_management();
         } 
        if (i == 5)
        {
            break;
        }
    }

}
void join(struct student* info)
{
    int i, j, k;
    for (i = 0; i < 1001; i++)
    {
        printf("회원가입을 계속 하시겠습니까? 1.Yes 2.No\n");
        scanf("%d", &j);

        if (j == 1)
        {
            printf("이름을 입력하시오: ");
            scanf("%s", info[i].name);
            printf("\n");
            printf("학번을 입력하시오: ");
            scanf("%s", info[i].ID);
            printf("\n");
            printf("전화번호를 입력하시오: ");
            scanf("%s", info[i].call);
            printf("\n");
            printf("이메일을 입력하시오: ");
            scanf("%s", info[i].mail);
            printf("\n");
            printf("비밀번호 입력하시오: ");
            scanf("%s", info[i].password);
            printf("\n");

            FILE* fp;
            fp = fopen("exampleFile.txt", "a");
            if (fp == NULL) {
                printf("실패 - 종료\n");
            }
            fprintf(fp, "%s ", info[i].name);
            fprintf(fp, "%s ", info[i].ID);
            fprintf(fp, "%s ", info[i].call);
            fprintf(fp, "%s ", info[i].mail);
            fprintf(fp, "%s \n", info[i].password);
            fclose(fp);
            printf("완료\n");
        }
        if (j == 2)
            break;
    }
    system("cls");
}

void list(struct student* info, struct student* m)
{
    int i, j;
    printf("전체 회원정보를 조회하시겠습니까? 1.Yes 2. No\n");
    scanf("%d", &i);

    FILE* fp;
    fp = fopen("exampleFile.txt", "r");
    char tmp;
    int cnt = 0;
    if (fp == NULL) {
        exit(0);
    }
    if (i == 1)
    {
        while (fscanf(fp, "%c", &tmp) != EOF)
        {
            if (tmp == '\n')
                cnt++;
        }
        printf("회원 수는 %d명입니다.\n", cnt);

        fp = fopen("exampleFile.txt", "r");
        for (int k = 0; k < cnt; k++)
        {
            fscanf(fp, "%s %s %s %s %s\n", &m[k].name, &m[k].ID, &m[k].call, &m[k].mail, &m[k].password);
            printf("이름:%s 학번:%s 전화번호:%s 이메일:%s 비밀번호:%s\n", m[k].name, m[k].ID, m[k].call, m[k].mail, m[k].password);
        }
        fclose(fp);
    }
    else
        exit(0);
}
void covid19_self_exam()
{
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int a4 = 0;
    int a5 = 0;
    printf("<설문조사>");
    printf("각 설문에 대해 문항의 답을 입력하고 Enter를 누르십시오.\n");
    printf("문항의 답은 1,2로 답해주십시오.\n");

    printf("1. 학생의 몸에 열이 있나요? 1)37.5℃미만 2)37.5℃이상 및 발열감 ");
    scanf("%d", &a1);
    printf("2. 귀하에게 코로나19가 의심되는 증상이 있나요? 1)아니요 2)예 ");
    scanf("%d", &a2);
    printf("3. 귀하는 최근(14일 이내)해외여행을 다녀온 사실이 있나요? 1)아니요 2)예 ");
    scanf("%d", &a3);
    printf("4. 동거가족 중 최근(14일 이내) 해외여행을 다녀온 사실이 있나요? (단, 국제선 항공기 및 선박 승무원 등 직업특성상 매번 해외 입출국하고 의심증상이 없는 경우는 제외) 1)아니요 2)예 ");
    scanf("%d", &a4);
    printf("5. 동거가족 중 현재 자가격리 중인 가족이 있나요? 1)아니요 2)예 ");
    scanf("%d", &a5);
    printf("설문이 완료되었습니다.\n");
    printf("답변: %d, %d, %d, %d, %d\n\n", a1, a2, a3, a4, a5);
    if (a1 + a2 + a3 + a4 + a5 != 5)
    {
        printf("등교 불가능\n");
    }
    else
        printf("등교 가능\n");
    FILE* fp;
    fp = fopen("name_id.txt", "a");
    if (fp == NULL) {
        printf("실패 - 종료\n");
    }
    fprintf(fp, "1번: %d ", a1);
    fprintf(fp, "2번: %d ", a2);
    fprintf(fp, "3번: %d ", a3);
    fprintf(fp, "4번: %d ", a4);
    fprintf(fp, "5번: %d \n", a5);
    fclose(fp);
    printf("완료\n");
}

int schedule_management(void)
{
    char calendar[12 * 31 * 100][26];
    char* pData;
    char temp[100] = { 0, }, gyear[100] = { 0, };
    int i, j, week, year, month, day, th, count, lastday, tyear, mode, pos, tmonth;
    int num[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    FILE* file;
    for (i = 0; i < 26; i++)
        memset(calendar[i], 0, 12 * 31 * 100);
    pData = calendar[0];

    while (1)
    {
        printf("──────────────2020~2021년 일정 관리───────────────\n");
        printf("\n                 [1]일정 쓰기 [2]일정 확인 [0]종료 :");
        gets(temp);
        sscanf(temp, "%d", &mode);
        if (mode == 0)
            break;
        switch (mode)
        {
        case 1:
            printf("YEAR: ");
            gets(gyear);
            sscanf(gyear, "%d", &year);
            if (year > 2025 || year < 2000)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            tyear = year;
            pData = calendar[year - 2000];
            printf("MONTH: ");
            gets(temp);
            sscanf(temp, "%d", &month);
            tmonth = month;
            if (tmonth > 12 || tmonth < 1)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            lastday = num[tmonth - 1];
            if (tmonth == 2 && (!(tyear % 4) && (tyear % 100) || !(tyear % 400)))
                lastday = 29;
            if (tmonth == 2 || tmonth == 1)
            {
                tyear--;
                tmonth += 12;
            }
            th = tyear / 100;
            tyear = tyear % 100;
            week = ((21 * th / 4) + (5 * tyear / 4) + (26 * (tmonth + 1)) / 10) % 7;
            printf("\n 일 월 화 수 목 금 토 \n");
            count = 1;
            for (i = 0; i < 6; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    if (i == 0 && j < week)
                        printf("%3s", " ");
                    else
                    {
                        printf("%3d", count);
                        count++;
                    }
                    if (count > lastday)
                        break;
                }
                printf("\n");
                if (count > lastday)
                    break;
            }
            printf("\nDAY: ");
            gets(temp);
            sscanf(temp, "%d", &day);
            if (day > lastday || day < 1)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            pos = month * day * 10;
            pData = pData + pos;
            printf("\n●일정을 쓰세요.\n");
            printf("\n   %d년 %d월 %d일 :", year, month, day);
            gets(temp);
            strcpy(pData, temp);
            break;

        case 2:
            printf("YEAR: ");
            gets(temp);
            sscanf(temp, "%d", &year);
            if (year > 2025 || year < 2000)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            pData = calendar[year - 2000];
            printf("MONTH: ");
            gets(temp);
            sscanf(temp, "%d", &month);
            if (month > 12 || month < 1)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            printf("DAY: ");
            gets(temp);
            sscanf(temp, "%d", &day);
            if (day < 1)
            {
                printf("다시 입력 하세요\n");
                break;
            }
            pos = month * day * 10;
            pData = pData + pos;
            printf("\n●일정 입니다.\n");
            printf("\n   %d년 %d월 %d일 :%s\n", year, month, day, pData);
            break;
        default:
            printf("다시 입력 하세요\n");
            break;
        }
    }
    system("cls");
}
