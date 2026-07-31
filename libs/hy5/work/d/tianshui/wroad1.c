// Room: /d/tianshui/wroad1.c

inherit ROOM;

void create()
{
	set("short", "小镇西街");
	set("long", @LONG
青石街道向东西两头延伸，这条路比较僻静，平时也很少有
人来。北面是小镇学堂，隐约传出朗朗的读书声。南面是镇长的
家。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"school",
  "east" : __DIR__"cross",
]));
	set("objects",([
	__DIR__"npc/whet_man" :1,
]));

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
