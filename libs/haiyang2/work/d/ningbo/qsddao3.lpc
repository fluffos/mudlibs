// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "青石官道");
        set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
long);
set("outdoors", "ningbo");
set("exits",([
"south" : __DIR__"qsddao4",
"northeast" : __DIR__"qsddao2",
]));
setup();
//replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");;
}
int do_go()
{
if(random(6)){
this_player()->move(this_object());
return 1;
}
} 