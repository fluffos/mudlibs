
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
		"east" : __DIR__"dong0"+(random(6)+2),
		"south" : __DIR__"dong0"+(random(6)+3),
                "west" : __DIR__"dong0"+(random(6)+3),
                "north" : __DIR__"dong1"+(random(3)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"north" : __DIR__"dong1"+(random(3)+3),
                "south" : __DIR__"dong05",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong05",
                "east" : __DIR__"dong1"+(random(3)+3),
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(8),
              "/clone/box/gboxm" : 1,
              __DIR__"npc/lev3" : random(8),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
