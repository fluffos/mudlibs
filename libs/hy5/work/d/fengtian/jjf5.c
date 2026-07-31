// Room: /d/fengtian/jjf5.c

inherit ROOM;

void create()
{
	set("short", "后厢房");
	set("long", @LONG
跨过天井就进了后厢房，后厢房是皇帝来后宅院休闲之处所
在，家人孩子也常常在后厢房一起聊天，这里应该是家庭的聚会
厅，所以显得很温暖。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shu",
  "west" : __DIR__"jjf4",
  "east" : __DIR__"jjf6",
  "north" : __DIR__"wo",
]));

	setup();
	replace_program(ROOM);
}
