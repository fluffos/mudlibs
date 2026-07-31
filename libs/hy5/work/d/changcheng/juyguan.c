// Room: /d/wizhome/incahome/juyguan.c
// Date: inca 98/08/13

#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{

        set("short","居庸关");
        set("long", WHT@LONG
这里就是长城上著名的雄关==居庸关。这里风景优美，满山遍野的枫树，
一到秋天所有的枫叶都变成了红色，把这里变成了一片红色的海洋。当年，
康熙皇帝到这里游玩时，被这美丽的景色吸引，亲笔提下了“居庸叠翠”四
个大字。
由于从这里向北通向关外，向西可以去西域，许多从京城逃出来的罪犯
都是从这里逃出去，所以城墙上贴满了官府的告示(gaoshi),而守卫的官兵
也戒备森严，随时盘问着可疑的人。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "west"           :__DIR__"changcheng1.c",
          "east"           :__DIR__"badaling.c",
          "north" : "/d/menggu/huanglu1",
          // "north"          :__DIR__"guanwai.c",
                "south"          :__DIR__"nroad2.c",
        ]));

        set("objects", ([
            "d/city/npc/wujiang" : 1,
            "d/city/npc/bing" : 5,
	]));
        setup();

}


string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         黑潮判官\n          无  心\n";
}

