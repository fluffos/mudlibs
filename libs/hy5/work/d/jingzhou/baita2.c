// Room: /d/jingzhou/baita2.c
// congw
inherit ROOM;

void create()
{
	set("short", "白塔二楼");
	set("long", @LONG
这里是报恩塔二楼，由于这里地势高，一阵微风吹来,说不出的凉爽,
荆州城的风光也尽收眼底。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "down" : __DIR__"baita1",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
