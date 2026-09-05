// Modified by iszt@pkuxkx, 2007-04-03

#include <ansi.h>

inherit ROOM;

void create ()
{
        set("short",HIM"乱葬岗"NOR);
	set("outdoors","xiangyang");
	set("long", HIC @LONG
这里是土匪山寨的后山专门扔死人的地方，周围尸骸累累，散发着恶臭。你
禁不住要呕吐起来，还是快走的好。
LONG NOR);
 	set("exits", ([
		"westdown" : __DIR__"lingzhip"          
	]));

        setup();
	replace_program(ROOM);
}
