// Room: /d/linzhi/shop.c

inherit ROOM;

void create()
{
	set("short", "杂货商帐房");
	set("long", @LONG
这是一间八一镇上的杂货商帐房。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"by03",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 1,
 	__DIR__"npc/yang" : 1,
]));
	setup();
	replace_program(ROOM);
}
