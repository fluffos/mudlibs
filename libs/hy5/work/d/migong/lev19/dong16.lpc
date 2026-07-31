
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
		"south" : __DIR__"dong1"+(random(7)+1),
                "north" : __DIR__"dong17",
		"east" : __DIR__"dong1"+(random(7)+1),
                "west" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(3)+5),
                "southwest" : __DIR__"dong1"+(random(5)+3),
"south" : __DIR__"dong51",
	]));
if (random(2)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+5),
                "north" : __DIR__"dong1"+(random(5)+3),
"north" : __DIR__"dong51",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
