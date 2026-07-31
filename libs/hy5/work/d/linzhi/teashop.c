// Room: /d/linzhi/teashop.c

inherit ROOM;

void create()
{
	set("short", "八一钱庄");
	set("long", @LONG
这是一间八一镇上的八一钱庄。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"by15",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/qian" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
