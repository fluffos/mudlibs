// Room: /d/lumaji/yuan.c

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
这是一个宽大的院子，南北两侧全是各种各样的马匹，一些
马贩子样的人物正在东首的草棚中聚集着，不时地争吵着什么。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"juan",
  "east" : __DIR__"jishi",
  "west" : __DIR__"lu6",
]));
	set("outdoors", "lumaji");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
