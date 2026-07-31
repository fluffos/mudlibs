// Room: /d/linzhi/silkshop.c

inherit ROOM;

void create()
{
	set("short", "八一当铺");
	set("long", @LONG
这是一间八一镇上的八一当铺。街面上行人不多，
只有几个小孩儿在一边玩耍。店里的人也不多。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"by01",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/tang" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
