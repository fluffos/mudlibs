// Room: /d/tianshui/wroad2.c

inherit ROOM;

void create()
{
	set("short", "小镇西街");
	set("long", @LONG
青石街道向东西两头延伸，这条路比较僻静，平时也很少有
人来。南北两面各有一所普通的民宅。西面就是这一带的名寺乾
圣寺了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minju",
  "west" : __DIR__"simiao",
  "south" : __DIR__"gongjiang",
  "east" : __DIR__"wroad1",
]));
	set("outdoors", "tianshui");
	set("objects",([
"/clone/npc/man" : 3,
]));
	setup();
	replace_program(ROOM);
}
