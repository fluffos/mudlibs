// Room: /d/linzhi/smithshop.c

inherit ROOM;

void create()
{
	set("short", "器工匠帐房");
	set("long", @LONG
这是一间八一镇上的器工匠帐房。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"by14",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/smith" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
