#include<stdio.h>


enum SchoolName {A, B, C, D, E};
enum SexType {Man, Woman};
struct Book
{
    char item[10];//项目
    SexType sex;//性别
    SchoolName school;//校名
    float score;//分数
};
struct Sum
{
    float  ManSum;//男总分
    float  WomanSum;//女总分
    float TotalSum;//团体总分
};
const int n=6;
Book sport_book[n];
Sum result[5];

int main()
{
    int i;
    for(i = 0; i < n; i++)
    {
        scanf(sport_book[i].item, (int&)sport_book[i].sex);
        scanf((int&)sport_book[i].school, sport_book[i].score);
        result[sport_book[i].school].TotalSum += sport_book[i].score;
        if(sport_book[i].sex == Man)
        {
            result[sport_book[i].school].ManSum += sport_book[i].score;
        }
        else
        {
            result[sport_book[i].school].WomanSum += sport_book[i].score;
        }
    }
    for(i = A; i <= E; i++)
    {
        printf(....);
    }
    return 0;
}
