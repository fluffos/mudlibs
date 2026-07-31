// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "奈河桥");
        set("long", @LONG
许多人只知道奈何桥，却不知道奈河桥，其实奈河桥名来自奈河，奈河
贯穿地府，内有冤魂，过枉死城后则只有金色鲤鱼，桥上通体翡翠，巧
夺天工，桥身雕刻得极为精细，不愧为鬼神妙手。由此过去便是地府最
后一站，孟婆驿。
LONG
        );
        set("exits", ([
		"north" : __DIR__"pingan",
		"south" : __DIR__"mengpo",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-90);
	set("coor/z",-290);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
