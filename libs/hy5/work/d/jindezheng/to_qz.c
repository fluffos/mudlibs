// Room: /d/jindezheng/to_qz.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiaofu.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"lu2",
  "northeast" : "/d/quanzhen/guandao1",
]));

	setup();
	replace_program(ROOM);
}
