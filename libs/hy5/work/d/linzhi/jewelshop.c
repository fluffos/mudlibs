// Room: /d/linzhi/jewelshop.c

inherit ROOM;

void create()
{
	set("short", "藏药商帐房");
	set("long", @LONG
这是一间八一镇上的藏药商帐房。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"by07",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/clone/npc/man" : 1,
 	__DIR__"npc/yang2" : 1,
]));
	setup();
	replace_program(ROOM);
}
