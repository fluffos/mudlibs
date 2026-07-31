// Room: /d/fengtian/lian.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
皇帝行宫一定要有练武场了，毕竟是皇帝嘛，四四方方的练武
场放着七十二种兵器，都擦的明晃晃的，皇帝时常在这里晨练，
而且皇帝行宫还有枪棒教头教下人练武。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf4",
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
