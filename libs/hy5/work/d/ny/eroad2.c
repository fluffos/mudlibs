
// Room: /d/snow/eroad2.c

inherit ROOM;

void create()
{
	set("coor",({1200,4700,10}));
	set("short", "黄土小径");
	set("long",
"这是一条普通的黄土小径，小径往西南通往一处山间的平地，从这里可以望见不少房屋错落\n"
"在平地上，往东北则一路上山。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"eroad3",
  "southwest" : __DIR__"eroad1",
]));
	set("outdoors", "ny");

	set("objects", ([
		__DIR__"npc/dog": 2 ]) );

	setup();
	replace_program(ROOM);
}
