// Room: /d/changan/ca17.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "长安城大街");
	set("long", @LONG
繁华的景象令你留连忘反，真不愧为“自古长安帝王都”，北面
是长安城有名的茶庄，往南是一片郁郁葱葱的枣树林。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ca1",
  "west" : __DIR__"ca",
  "south" : __DIR__"zao",
  "east" : __DIR__"dongmen",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-fan" : 1,
]));
	set("outdoors", "changan");

	setup();
	replace_program(ROOM);
}
