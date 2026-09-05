// Room: /d/beijing/zijin/wuyingmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"武英门"NOR);
	set("long",
HIC"从此地向北就是御林军的中军大帐，向南是御林军的扎营之处，
向西是西华门，向东是熙和门。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
 	 "south" : __DIR__"denglongku",
 	 "north" : __DIR__"guang3",
 	 "west" : __DIR__"xihuamen",
 	 "east" : __DIR__"xihemen",
]));
	set("objects", ([
		"/d/beijing/npc/shiwei" + (1 + random(6)) : 2,
		"/d/beijing/npc/shiwei" + (1 + random(6)) : 2,
		"/d/beijing/npc/shiwei" + (1 + random(6)) : 2,
		"/d/beijing/npc/shiwei" + (1 + random(6)) : 2,
	]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
