// Room: /d/kunlun/wft.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "望峰亭");
	set("long", @LONG
长长的阶梯也终将到了尽头, 阶梯的尽头矗立著一座山门, 山门上龙飞凤
舞地写了三个字, 笔力苍劲有力显得气势非凡。山风吹来带著丝丝的寒意, 令
你有股高处不胜寒的感觉。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 2,
]));
	set("outdoors", "wft");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhp",
  "south" : __DIR__"zwf",
  "north" : __DIR__"klpsm",
  "west" : __DIR__"ssy",
]));

	setup();
	replace_program(ROOM);
}
