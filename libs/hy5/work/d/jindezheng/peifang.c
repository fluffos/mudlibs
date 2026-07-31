// Room: /d/jindezheng/peifang.c

inherit ROOM;

void create()
{
	set("short", "工房");
	set("long", @LONG
从树林子出来,眼前是一排青砖大瓦房,再进去,里面许多人正忙着制 
胎,就是把陶土或瓷土和上水,作成碗,盆,缸,勺......等的泥胎,然后才放 
到砖窑中烧出成品. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gongjiang.c" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}
