// Room: /d/linzhi/fruitshop.c

inherit ROOM;

void create()
{
	set("short", "特产铺帐房");
	set("long", @LONG
这是一间八一镇上的水果特产铺。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"by01",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/clone/npc/man" : 1,
 	__DIR__"npc/yang3" : 1,
]));
	setup();
	replace_program(ROOM);
}
