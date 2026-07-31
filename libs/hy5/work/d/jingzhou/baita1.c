// Room: /d/jingzhou/baita1.c
// congw
inherit ROOM;

void create()
{
	set("short", "白塔一楼");
	set("long", @LONG
这里是报恩塔一楼，由于这里地势高，让人忍不住要登高眺望。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "up" : __DIR__"baita2",
  "out" : __DIR__"baita",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
