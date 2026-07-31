// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "青石官道");
        set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。往西北面就是杭州城了。
long);
set("outdoors", "ningbo");
set("exits",([
"southeast" : __DIR__"shilu",
"northwest" : __DIR__"qsddao1",
]));
setup();
replace_program(ROOM);
}
