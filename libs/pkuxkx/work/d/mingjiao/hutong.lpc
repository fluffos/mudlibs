// Room: /d/mingjiao/hutong.c

inherit ROOM;

void create()
{
	set("short", "小胡同");
	set("long", @LONG
这是一条非常狭窄而又潮湿的小胡同，
    南边是一间小屋，西面是一条石阶，东面有几个少年。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"fandian",
  "south" : __DIR__"xiaowu",
  "west" : __DIR__"shijie1",
  "east" : __DIR__"hutong2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
