
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"光之幻境"NOR);
	set("long", HIG @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);


	set("exits", ([
		"east" : __DIR__"dong06",
		"south" : __DIR__"dong0"+(random(4)+4),
                "west" : __DIR__"dong05",
                "north" : __DIR__"dong0"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+4),
		"eastsouth" : __DIR__"dong0"+(random(4)+4),
                "northwest" : __DIR__"dong07",
                "southnorth" : __DIR__"dong0"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
