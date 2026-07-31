// Room: /d/fengtian/w_gate.c

inherit ROOM;

void create()
{
	set("short", "盛京西门");
	set("long", @LONG
这里是盛京的西门户，也是盛京与关内以及蒙古地区连接干
道的门户，在城门的一旁，帖着一个布告。西城门没有北门
那么宏伟，不过也是壁垒森严了，不少官兵在这里检查过往
的路人。
LONG
	);



	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guanlu1",
  "west" : __DIR__"out_fengtian_w",
]));

	set("objects",([
		__DIR__"npc/city_guard" : 3,
]));

        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
