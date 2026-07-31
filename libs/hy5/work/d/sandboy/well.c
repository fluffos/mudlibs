// Room: /d/sandboy/well.c

inherit ROOM;

void create()
{
	set("short", "水井");
	set("long", @LONG
一口古老的水井,上面搭着小小的亭子,一个辘轳安装在井沿上方,低头
看时,清澈的井水倒印出你的影子,森森的寒气从水井中冒出来.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"huangni",
  "south" : __DIR__"undertree",
]));

	setup();
	replace_program(ROOM);
}
