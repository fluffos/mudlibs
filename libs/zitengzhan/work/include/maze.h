// nanf 2011-04
#ifndef _MAZE_H_
#define _MAXE_H_

#define MAX_WIDTH 20
#define MAX_HEIGHT 20
#define CHECK_INTERVAL 10


class maze_settings 
{
    string maze_name; // 副本的名称
    string maze_room; // 副本房间文件
    string boss_room; // boo房间文件
    string short_desc; // 副本房间的短描述
    string long_desc; // 副本房间的长描述
    int width; // 副本最大宽度
    int height; // 副本最大高度
    int life_time; // 迷宫的生存时间
    string boss; // boss文件名
    int boss_since; // 至少搜索多少个房间开始出现boss，如果负数，是从剩余多少个起
    int boss_ok; // boss已经产生
    string* npc; // 迷宫中npc文件名（数组）
    int npc_rate; // npc出现的概率
    int max_npc; // 如果出现npc，同一地点小怪的数量上限
    int min_npc; // 如果出现npc，同一地点小怪的数量下限（小于1视为1）
    int initx; // 玩家进入点x   0表示随机
    int inity; // 玩家进入点y   0表示随机
    string entry_dir; // 入口点方位 east west south north 0表示没有
    int entry_pos; // 入口点位置   负数表示倒过来数
    int entryx; // 入口点x坐标
    int entryy; // 入口点y坐标
    int entrymx; // 入口点数据x坐标
    int entrymy; // 入口点数据y坐标
    string exit_dir; // 出口点方位 east west south north 0表示没有
    int exit_pos; // 出口点位置    负数表示倒过来数
    int exitx; // 出口点x坐标
    int exity; // 出口点y坐标
    int exitmx; // 出口点数据x坐标
    int exitmy; // 出口点数据y坐标
    string exit_link; // 出口的连接地点
}

#endif

