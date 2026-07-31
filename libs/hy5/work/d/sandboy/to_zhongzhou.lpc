// Room: /d/sandboy/to_zhongzhou.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
在一望无际的平野之中,这条大道如同玉带一般,穿过绿色的农田,
向西是紫金山.东面云际中露出高山的影子.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/jinling/shanroad1",
  "east" : __DIR__"to_zhongzhou2",
]));
set("outdoors","/d/jiangnan");

	setup();
	replace_program(ROOM);
}
