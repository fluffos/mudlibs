// Room: /d/yanjing/gardon1.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
墙脚落中的几株兰花在风中微微颤抖,从东面来的一条小道到了园中
的假山附近围绕而过,西面的圆洞门正对着边上的一株梅花,假山边上有个
地洞,看上去黑呼呼的.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/houtonghai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"gardon",
  "down" : __DIR__"cave",
  "east" : __DIR__"road1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
