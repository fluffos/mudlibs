// Room: /d/fengtian/rou.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
肉铺里弥漫着一种重重的血腥味，肉案上横七竖八的摆放着
不少猪肉和牛肉，苍蝇嗡嗡的在肉铺里飞着，肉铺老板猪肉荣在
大声的叫卖。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd5",
]));

	setup();
	replace_program(ROOM);
}
