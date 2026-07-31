// Room: /d/tianshui/sroad1.c

inherit ROOM;

void create()
{
	set("short", "小镇南街");
	set("long", @LONG
这里是南街，北面便是小镇的中央广场。每逢赶集的日子，
这里就热闹非凡。西面是戏台，东面是一家茶馆，游手好闲的人
在那里喝茶聊天。
LONG
	);
	set("outdoors", "tianshui");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cross",
  "west" : __DIR__"xitai",
  "south" : __DIR__"sroad2",
  "east" : __DIR__"chaguan",
]));

	setup();
	replace_program(ROOM);
}
