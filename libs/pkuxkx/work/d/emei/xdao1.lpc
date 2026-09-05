// Room: /u/cuer/emei/xdao1.c

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
这里就是通往蛇窟的小道，狭窄的小道蜿蜒向上延伸。  
路的两旁杂草丛生，偶尔有蛇在你脚下窜过，地上阴暗潮
湿，正是虫蛇滋生的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xdao2",
  "east" : __DIR__"beicemen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
