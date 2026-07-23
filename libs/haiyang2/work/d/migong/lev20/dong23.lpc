
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"天使之城"NOR);
	set("long", HIW @LONG
神圣的力量在这个城市无处不在，温和的太阳光照在
到处可见的神像上，使的整个城市允满了闪耀的光辉。
这就是众神所庇护的城市，天使之城。传说中不灭的城
市。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong22",
                "north" : __DIR__"dong31",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
