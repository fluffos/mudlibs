
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"古代遗迹"NOR);
	set("long", RED @LONG
   这里是个危险的区域，很大且很容易迷路，在这荒野中尽然有
一座小木屋，你可以在这里休息一下(save)。
和睡觉(sleep)。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong03",
	]));
 set("valid_startroom", "1");
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(3)+2),
                "north" : __DIR__"dong0"+(random(4)+1),
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong03",
	]));

         set("objects", ([
"/d/migong/lev16/npc/obj/food2" : 1,
"/d/migong/lev16/npc/obj/water1" : 1,
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
