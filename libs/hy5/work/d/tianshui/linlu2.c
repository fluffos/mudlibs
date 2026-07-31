// Room: /u/xiaozhen/linlu2.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
这里是一片寂静的小树林，一阵微风吹来，树叶沙沙的做响。
脚下是一条黄土小路，路边的地上布满了落叶，看样子这条小路
是经常有人走。前面是一个土坡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"linlu3",
  "southwest" : __DIR__"linlu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
