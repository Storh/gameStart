// 01firstGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//推箱子
//固定地图+可以移动
//可以判断游戏接受+重启游戏
//自行设置地图长度+自动生成地图
//自动生成的地图不一定有解
//一关关的关卡+分数

//健壮性问题

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//新建一个枚举类型来记录可能出现的状态
enum mapObject {
    mapWall,// 地图的墙
    mapSpace,// 地图上的空地
    mapGoal,// 地图上的目标点
    mapBox,// 地图上的箱子
    mapBoxInGoal,// 箱子在目标点上
    mapPeople,// 地图上的人
    mapPeopleInGoal,// 人到了目标点上的时候会有一点变化来表示站在目标点上
    unKnow// 当前为换行
};

//地图，#表示为墙，.为目标点，p为人，o为箱子
string gameMap="\
########\n\
#  . .p#\n\
#  o o #\n\
#      #\n\
########";

void init(mapObject* state, string map, int width, int height) {
    mapObject t;//临时变量
    int i = 1;
    for (auto c : map) {
        switch (c) {
        case '#':t = mapWall; break;
        case ' ':t = mapSpace; break;
        case '.':t = mapGoal; break;
        case 'o':t = mapBox; break;
        case 'O':t = mapBoxInGoal; break;
        case 'p':t = mapPeople; break;
        case 'P':t = mapPeopleInGoal; break;
        default: t = unKnow; break;
        }
        if (t != unKnow)
            state[i++] = t;
    }
}

void drow(mapObject* state, int width, int height) {
    const char font[] = { '#', ' ', '.', 'o', 'O', 'p', 'P', '\n' };
    for (int i = 1; i <= width * height; i++) {
        auto c = state[i];
        cout << font[c];
        if (i % width == 0) cout << endl;
    }
}

void update(mapObject* state, char input, int width, int height) {
    int x, y, o, oa, os, od, ow;
    for (int i = 1; i <= width * height; i++) {
        if (state[i] == mapPeople || state[i] == mapPeopleInGoal)
        {
            x = i % width, y = i-1 / width;
            o = i, oa = i - 1, od = i + 1, os = i + width, ow = i - width;
        }
            
    }
    if (input == 'a') {
        //左边是空的
        if (state[oa] == mapSpace|| state[oa] == mapGoal) {
            if(state[oa] == mapSpace)  state[oa] = mapPeople;
            else state[oa] = mapPeopleInGoal;
            if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
            else state[o] = mapSpace;
        }
        //左边有箱子
        if (state[oa] == mapBox|| state[oa] == mapBoxInGoal) {
            int noa = oa - 1;
            if (state[noa] == mapSpace || state[noa] == mapGoal) {
                if (state[noa] == mapSpace)  state[noa] = mapBox;
                else state[noa] = mapBoxInGoal;
                if (state[oa] == mapBox)  state[oa] = mapPeople;
                else state[oa] = mapPeopleInGoal;
                if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
                else state[o] = mapSpace;
            }
        }
    }
    if (input == 'd') {
        //右边是空的
        if (state[od] == mapSpace || state[od] == mapGoal) {
            if (state[od] == mapSpace)  state[od] = mapPeople;
            else state[od] = mapPeopleInGoal;
            if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
            else state[o] = mapSpace;
        }
        //右边有箱子
        if (state[od] == mapBox || state[od] == mapBoxInGoal) {
            int nod = od + 1;
            if (state[nod] == mapSpace || state[nod] == mapGoal) {
                if (state[nod] == mapSpace)  state[nod] = mapBox;
                else state[nod] = mapBoxInGoal;
                if (state[od] == mapBox)  state[od] = mapPeople;
                else state[od] = mapPeopleInGoal;
                if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
                else state[o] = mapSpace;
            }
        }
    }
    if (input == 'w') {
        if (state[ow] == mapSpace || state[ow] == mapGoal) {
            if (state[ow] == mapSpace)  state[ow] = mapPeople;
            else state[ow] = mapPeopleInGoal;
            if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
            else state[o] = mapSpace;
        }
        if (state[ow] == mapBox || state[ow] == mapBoxInGoal) {
            int now = ow - width;
            if (state[now] == mapSpace || state[now] == mapGoal) {
                if (state[now] == mapSpace)  state[now] = mapBox;
                else state[now] = mapBoxInGoal;
                if (state[ow] == mapBox)  state[ow] = mapPeople;
                else state[ow] = mapPeopleInGoal;
                if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
                else state[o] = mapSpace;
            }
        }
    }
    if (input == 's') {
        if (state[os] == mapSpace || state[os] == mapGoal) {
            if (state[os] == mapSpace)  state[os] = mapPeople;
            else state[os] = mapPeopleInGoal;
            if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
            else state[o] = mapSpace;
        }
        if (state[os] == mapBox || state[os] == mapBoxInGoal) {
            int nos = os + width;
            if (state[nos] == mapSpace || state[nos] == mapGoal) {
                if (state[nos] == mapSpace)  state[nos] = mapBox;
                else state[nos] = mapBoxInGoal;
                if (state[os] == mapBox)  state[os] = mapPeople;
                else state[os] = mapPeopleInGoal;
                if (state[o] == mapPeopleInGoal) state[o] = mapGoal;
                else state[o] = mapSpace;
            }
        }
    }
}

int main()
{
    //设置地图的大小
    int mapWidth = 8, mapHeight = 5;
    //新建一个state用来存储地图
    mapObject* state = new mapObject[mapWidth * mapHeight];
    char input;
    init(state, gameMap, mapWidth, mapHeight);
    while (1) {
        drow(state, mapWidth, mapHeight);
        cout << "w ↑；a ←；s ↓；d →；" << endl;
        cin >> input;
        update(state, input, mapWidth, mapHeight);
    }
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
