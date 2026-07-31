
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"光之幻境"NOR);
	set("long", HIY @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 
LONG NOR);


	set("exits", ([
		"eastnorth" : __DIR__"dong0"+(random(9)+1),
		"southeast" : __DIR__"dong0"+(random(9)+1),
                "westnorth" : __DIR__"dong0"+(random(9)+1),
                "northwest" : __DIR__"dong10",
	]));
if (random(2)==0)
	set("exits", ([
                "southwest" : __DIR__"dong10",
		"northeast" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "westsouth" : __DIR__"dong10",
		"eastnorth" : __DIR__"dong0"+(random(9)+1),
	]));

         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
