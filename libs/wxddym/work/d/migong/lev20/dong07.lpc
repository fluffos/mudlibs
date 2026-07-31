
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
		"east" : __DIR__"dong0"+(random(5)+4),
		"north" : __DIR__"dong03",
                "west" : __DIR__"dong0"+(random(5)+4),
                "south" : __DIR__"dong08",
	]));
if (random(2)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(5)+4),
		"southwest" : __DIR__"dong08",
                "westnorth" : __DIR__"dong0"+(random(5)+4),
                "northeast" : __DIR__"dong02",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong08",
                "north" : __DIR__"dong05",
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
