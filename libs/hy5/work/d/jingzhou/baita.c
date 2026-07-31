// Room: /d/jingzhou/baita.c
// congw
inherit ROOM;

void create()
{
	set("short", "白塔");
	set("long", @LONG
        这里是一座三层高的白塔,相传是前朝一位状元郎考取功名后，卫报答母恩
修建的报恩塔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "enter" : __DIR__"baita1",
  "south" : __DIR__"dongdajie1",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
