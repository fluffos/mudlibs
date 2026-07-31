// Room: /d/jindezheng/shulin2.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前 
方似乎还升起一缕青烟. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/songque.c" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shulin1",
  "west" : __DIR__"zuanjiao",
  "south" : __DIR__"peifang",
  "southwest" : __DIR__"lu1",
]));
	set("outdoors", "/d/jindezheng");

	setup();
	replace_program(ROOM);
}
