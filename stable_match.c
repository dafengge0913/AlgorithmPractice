#include <stdio.h>

#define N 4
#define NO_ONE -1
#define MAX 99999

typedef struct
{
    char *name;
    int next;    // 下一个尝试
    int current; // 当前选择
    int perfect[N];
} Person;

int getPos(Person p, int index)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (p.perfect[i] == index)
        {
            return i;
        }
    }
    return MAX;
}

int isStableMatch(Person *boys, Person *girls)
{
    int b, g;
    Person girl;
    for (b = 0; b < N; b++)
    {
        // 男孩当前选择 在他偏好列表中的位置
        int gPos = getPos(boys[b], boys[b].current);
        // 遍历更喜欢的女孩
        for (g = 0; g < gPos; g++)
        {
            int gid = boys[b].perfect[g];
            girl = girls[gid];
            // 如果女孩喜欢男孩 超过当前选择 则不稳定
            if (getPos(girl, b) < getPos(girl, girl.current))
            {
                return 0;
            }
        }
    }
    return 1;
}

void printResult(Person *boys, Person *girls)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%s -> %s \n", boys[i].name, girls[boys[i].current].name);
    }
    printf("------------\n");
}

void searchStableMatch(int index, Person *boys, Person *girls)
{
    if (index == N)
    {
        if (isStableMatch(boys, girls) == 1)
        {
            printResult(boys, girls);
        }
        return;
    }
    int i;
    for (i = 0; i < N; i++)
    {
        int gid = boys[index].perfect[i];
        if (girls[gid].current == NO_ONE)
        {
            boys[index].current = gid;
            girls[gid].current = index;
            searchStableMatch(index + 1, boys, girls);
            boys[index].current = NO_ONE;
            girls[gid].current = NO_ONE;
        }
    }
}

int main()
{
    Person boys[] = {
        {"1", 0, NO_ONE, {0, 3, 2, 1}},
        {"2", 0, NO_ONE, {0, 1, 2, 3}},
        {"3", 0, NO_ONE, {0, 2, 3, 1}},
        {"4", 0, NO_ONE, {1, 0, 3, 2}}};

    Person girls[] = {
        {"A", 0, NO_ONE, {2, 3, 1, 0}},
        {"B", 0, NO_ONE, {2, 1, 3, 0}},
        {"C", 0, NO_ONE, {0, 2, 3, 1}},
        {"D", 0, NO_ONE, {1, 3, 2, 0}}};

    searchStableMatch(0, boys, girls);

    return 0;
}
