// Room: /d/yandang/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
从芙蓉镇出来,沿着山路向前,两边都是高大的树林,树叶在秋风
中簌簌颤栗,路旁的野草随风飘舞,夕阳在山,一股凄凉的感觉油然而
生,青山依旧在,几度夕阳红.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedao2",
  "north" : __DIR__"jiudian",
]));

	setup();
	replace_program(ROOM);
}
