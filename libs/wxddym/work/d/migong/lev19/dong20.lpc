
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"吵杂之森"NOR);
	set("long", HIG @LONG
    这里是一座古老的原始森林，这里的所有树木看起来都是古老而
沧桑，彷佛历经无数岁月的磨练，但当你走在森林步道上，耳听黄莺
清脆的鸣叫并享受芬多精的薰陶。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
                "west" : __DIR__"dong17",
		"east" : __DIR__"dong0"+(random(8)+1),
		"south" : __DIR__"dong0"+(random(7)+1),
                "north" : __DIR__"dong21",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(8)+1),
                "west" : __DIR__"dong21",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(8)+1),
                "north" : __DIR__"dong21",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(6),
              __DIR__"npc/lev4" : random(6),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
