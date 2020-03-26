#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#define Map_MAX 100
long long int speed = 0;
int position_x, position_y;
int saet_hight, seat_width;
int bullet_x, bullet_y;
int enemy_x, enemy_y;
int Map[Map_MAX][Map_MAX];
int score;
void starup()
{
    saet_hight = 20;
    seat_width= 30;
    position_x = saet_hight / 2;
    position_y = seat_width/ 2;
    bullet_x = 0;
    bullet_y = position_y;
    enemy_x = 2;
    enemy_y = position_y - 1;
    score = 0;

}
void startMap()
{
    int i, j;
    for (i = 1; i <= saet_hight - 1; i++)
    {
        Map[i][1] = 4;
        for (j = 2; j <= seat_width- 1; j++)
            Map[i][j] = 0;
        Map[i][seat_width] = 4;
    }
    i = saet_hight;
    for (j = 1; j <= seat_width; j++)
        Map[i][j] = 3;

    Map[bullet_x][bullet_y] = 5;
    Map[position_x - 1][position_y] = 1;
    i = position_x;
    for (j = position_y - 2; j <= position_y + 2; j++)
        Map[i][j] = 1;
    Map[position_x + 1][position_y - 1] = 1;
    Map[position_x + 1][position_y + 1] = 1;
    Map[enemy_x][enemy_y] = 2;
    Map[enemy_x - 1][enemy_y - 1] = 2;
    Map[enemy_x - 1][enemy_y + 1] = 2;
}
void HideCursor()//隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)//清理一部分屏幕
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void updateWithoutInput()
{
    if (bullet_x > 0)
        bullet_x--;
    if ((bullet_x == enemy_x) && (bullet_y == enemy_y))
    {
        score++;
        enemy_x = 0;
        enemy_y = rand() % seat_width;
        bullet_x = 0;
    }
    if (enemy_x > saet_hight)
    {
        enemy_x = 0;
        enemy_y = rand() % seat_width;
    }
    if (speed == 1)
        for (int i = 1; i <= 10000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                speed = 1;
            }
        }
    speed = 0;
    if (speed == 0)
    {
        enemy_x++;
        speed = 1;
    }
}
void updateWithInput()//与输入有关的更新
{
    char input;
    if (kbhit())//在VC6.0++下，为_kbhit()
    {
        input = getch();//在VC6.0++下为_getch();
        if (input == 'a')
            position_y--;
        if (input == 's')
            position_x++;
        if (input == 'd')
            position_y++;
        if (input == 'w')
            position_x--;
        if (input == ' ')
        {
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
    }
}
void show()//展示的内容
{
    gotoxy(0, 0);
    int i, j;
    for (i = 1; i <= saet_hight; i++)
    {
        for (j = 1; j <= seat_width; j++)
        {
            if (Map[i][j] == 0)
                printf(" ");
            if (Map[i][j] == 1)
                printf("*");
            if (Map[i][j] == 2)
                printf("#");
            if (Map[i][j] == 3)
                printf("~");
            if (Map[i][j] == 4)
                printf("|");
            if (Map[i][j] == 5)
                printf("|");
        }
        printf("\n");
    }
    printf("\n你的得分:%d\n\n", score);
    printf("操作说明: ASDW分别操作 左下右上四个的移动\n");
    printf("**空格是发出子弹**\n");
}
int main()
{
    starup();
    while (1)
    {
        HideCursor();
        startMap();
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
