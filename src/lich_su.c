#include "../include/nang_cao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void khoiTaoLichSu(LichSuLog* logList)
{
    if (logList == NULL)
        return;
    logList->head = NULL;
    logList->tail = NULL;
}

void ghiLog(LichSuLog* logList, const char noiDung[])
{
    if (logList == NULL || noiDung == NULL)
        return;
        
    NodeLog* p = (NodeLog*)malloc(sizeof(NodeLog));
    if (p == NULL)
        return;
        
    time_t now = time(NULL);
    struct tm* tg = localtime(&now);
    if (tg != NULL)
    {
        strftime(p->thoiGian, sizeof(p->thoiGian), "%H:%M:%S", tg);
    }
    else
    {
        strcpy(p->thoiGian, "Unknown");
    }
    
    strncpy(p->noiDung, noiDung, sizeof(p->noiDung) - 1);
    p->noiDung[sizeof(p->noiDung) - 1] = '\0';
    p->next = NULL;
    
    if (logList->head == NULL)
    {
        logList->head = p;
        logList->tail = p;
    }
    else
    {
        logList->tail->next = p;
        logList->tail = p;
    }
}

void hienThiLichSu(const LichSuLog* logList)
{
    if (logList == NULL || logList->head == NULL)
    {
        printf("Chua co lich su thao tac!\n");
        return;
    }
    
    NodeLog* p = logList->head;
    printf("\n========== Lich su thao tac ==========\n");

    while (p != NULL)
    {
        printf("[%s] %s\n", p->thoiGian, p->noiDung);
        p = p->next;
    }
}

bool xuatLogRaFile(const LichSuLog* logList, const char tenFile[])
{
    if (logList == NULL || tenFile == NULL)
        return false;
        
    FILE* f = fopen(tenFile, "w");
    if (f == NULL)
        return false;
        
    NodeLog* p = logList->head;
    while (p != NULL)
    {
        fprintf(f, "[%s] %s\n", p->thoiGian, p->noiDung);
        p = p->next;
    }
    
    fclose(f);
    return true;
}

void giaiPhongLichSu(LichSuLog* logList)
{
    if (logList == NULL)
        return;
        
    NodeLog* p;
    while (logList->head != NULL)
    {
        p = logList->head;
        logList->head = logList->head->next;
        free(p);
    }
    logList->tail = NULL;
}