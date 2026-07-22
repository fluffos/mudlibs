#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"眠龙洞尽头"NOR);
	set("long", RED @LONG
    这里已经是洞穴的尽头了，四周都是滚烫的岩浆，一个
庞然大物正蹲在路中央，口中散发着阵阵火焰。 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong3",
		                	]));
            set("objects", ([
             __DIR__"npc/boss" : 1,
             __DIR__"npc/lev1" : 1,
             __DIR__"npc/lev2" : 1,
             __DIR__"npc/lev3" : 1,
             __DIR__"npc/lev4" : 1,
             __DIR__"npc/lev5" : 1,
             "/clone/box/gbox" : 10,
         ]));
	set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}
