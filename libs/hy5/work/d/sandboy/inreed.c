// Room: /d/sandboy/inreed.c

inherit ROOM;

void create()
{
	set("short", "芦苇荡中");
	set("long", @LONG
四面都是密密麻麻的芦苇,淡黄色的芦苇顶上开满了白色的芦花,微风吹
过,芦花漫天飞舞.脚下是一片淤泥,清凉的河水刚没过脚面.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"reed",
  "west" : __DIR__"inreed1",
  "east" : __DIR__"inreed2",
]));

	setup();
	replace_program(ROOM);
}
