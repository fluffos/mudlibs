// Room: /d/changan/ca.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "长安城大街");
	set("long", @LONG
长安城历来人声鼎沸，车水马龙。小贩的吆喝声，小孩的嬉笑声
此起彼伏。还有一些江湖艺人在表演着他们的拿手绝活，吸引了好多
游手好闲的观众在围观。小贩不断在你身边叫卖着，你不禁被这繁华
的景象吸引住了。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ca18",
  "north" : __DIR__"ca7",
  "east" : __DIR__"ca17",
  "south" : __DIR__"ca12",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/xiao-fan" : 1,
  __DIR__"npc/boy" : 1,
  __DIR__"npc/girl" : 1,
  "/d/city/npc/xunbu" : 2,
]));
	set("outdoors", "changan");

	setup();
	replace_program(ROOM);
}
