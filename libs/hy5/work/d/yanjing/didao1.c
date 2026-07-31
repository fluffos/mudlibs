// Room: /d/yanjing/didao1.c

inherit ROOM;

void create()
{
	set("short", "地道内");
	set("long", @LONG
这地道隐在地面之下四五丈深处,却没有些潮湿的气象,看来另有排水
的管道,双手所及处,都是硬泥土.此外就是黑黑的一团.一股冷风从北面吹
来,隐隐带着血腥之气.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave1",
  "south" : __DIR__"cave",
]));

	setup();
	replace_program(ROOM);
}
