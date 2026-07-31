// Room: /d/menggu/qinwei2.c

inherit ROOM;

void create()
{
	set("short", "博尔术营帐");
	set("long", @LONG
博尔术勇力过人,被称为蒙古人中的英雄,年轻时曾同铁木真一起追杀
马盗,他的营帐中只是几条毡子随便堆放,一杆长枪,一把铁胎弓,外加九壶
铁箭,博尔术箭法神通,上阵带箭之多,无人可及
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/boerhu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));

	setup();
	replace_program(ROOM);
}
