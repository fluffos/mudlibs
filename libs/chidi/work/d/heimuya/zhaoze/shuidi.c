// /d/xiakedao/duchuan.c
#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", HIR"混"HIB"乱"HIW"空"HIG"间");
        set("long",@LONG
突然时空发生扭曲，你还没来得及反应，被河面一阵旋风吹了进来。
你定睛一看，糟糕！这里是什么地方？你心里不由得一阵发慌！
突然，一阵惊天动地的响声把你惊醒，只见你身旁不远处，站着一个飘浮
的人影。
LONG);   
           set("exits", ([ 
        "out" : __DIR__"shx",
]));
        set("objects",([
                "/d/boss/shouwei2" : 1,
        ]));
        setup();
	   set("no_clean_up", 0);
        setup();
}