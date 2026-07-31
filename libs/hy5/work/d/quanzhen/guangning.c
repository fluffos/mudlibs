// guangning.c 广宁居
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "广宁居");
        set("long", @LONG
这里是全真七子之六郝大通的卧室，卧室很小，除了一张小床，
一张小茶几而外没有什么别的摆设。茶几晶萤透明，仔细一看，原来
几面是用整块的玉琢磨成的。茶几上摆放着几本先天课术的书，还有
一些卜卦用的金钱。
LONG
        );
        set("exits", ([
                "north" : __DIR__"piandian",
        ]));

        set("objects", ([
                __DIR__"npc/hao" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
