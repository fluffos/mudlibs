// Room: /d/sandboy/river.c

inherit ROOM;

void create()
{
	set("short", "长江边上");
	set("long", @LONG
滚滚长江水,奔流入海,北风吹来,带着微微的江水的气息,青青的绿
草把江岸点缀得分外美丽,江的对端就是兵家必争之地---竞陵.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"to_sandboy",
  "south" : __DIR__"shulin",
]));
	set("outdoors", "/d/jiangnan");

	setup();
	replace_program(ROOM);
}
