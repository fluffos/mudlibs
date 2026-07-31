// Room: /d/linzhi/by12.c

inherit ROOM;

void create()
{
	set("short", "易贡湖岸");
	set("long", @LONG
你来到易贡湖岸，只见湖水清澈见底，几只叫不出名的大鸟
正在湖面上自由地飞翔。你将手伸入湖中，一种冰凉的快感袭上
心头，看来水很干净，可以饮用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by11",
  "north" : __DIR__"yg01",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("resource/water", 1); 
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
