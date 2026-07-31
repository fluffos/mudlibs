
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "富人天堂");
        set("long", @LONG
这里便是赌大小的地方了，有个流里流气的坏小子不怀好
意地盯着你的钱包。墙上贴着张规则说明(rule)。
LONG
        );

        set("exits", ([
                "west" : __DIR__"duchang",
                "east" : __DIR__"ershi",                
        ]));
        set("no_fight",1);

        set("item_desc",([
             "rule" : "这里可是有钱人来玩的地方，穷小子\n"+
                      "赶紧滚蛋，要想玩先给钱。买大买小\n"+
                      "悉听君便，也不限制压多少钱。\n"
                 ]));
        set("objects",([
                __DIR__"npc/xingge" : 1,
        ]));

                            
        setup();
        replace_program(ROOM);
}


 
