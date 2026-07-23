// Room: /d/jindezheng/shulin1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG
	);
	set("no_sleep", 1);
	set("no_dazuo", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street3",
  "southwest" : __DIR__"shulin2",
]));
	set("outdoors", "jindezheng");

	setup();
	replace_program(ROOM);
}
