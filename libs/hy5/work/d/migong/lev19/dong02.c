
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"吵杂之森"NOR);
	set("long", RED @LONG
    这里是一座古老的原始森林，这里的所有树木看起来都是古老而
沧桑，彷佛历经无数岁月的磨练，但当你走在森林步道上，耳听黄莺
清脆的鸣叫并享受芬多精的薰陶。你可以在这里休息一下(save)。
和睡觉(sleep)。
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong03",
	]));
 set("valid_startroom", "1");
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(3)+3),
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
