//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "北大街");
        set("long", @LONG
这里是洛阳内城最整洁的一条大路，街道宽敞而干净，汉白玉砌的路
面被雨水冲得光明如镜，大路两侧的瓦房高大而宏伟，分明便是巨富宅院。
双人合抱的杨树十步一株，整齐的排在两边。西边是方圆数百里内无人不
知，无人不晓的望星楼，东边是专卖洛阳唐三彩的唐三彩专卖店。
LONG
        );

        set("exits", ([
               "east" : __DIR__"tangsancai",   
               "west" : __DIR__"wangxinglou1",  
               "south" : __DIR__"center",  
               "north" : __DIR__"beidajie2",          
        ]));
        set("objects", ([

        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

