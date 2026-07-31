// Room: /d/hainan/outcave.c

inherit ROOM;

void create()
{
	set("short", "山洞外");
	set("long", @LONG
身在洞外,眼前的景色令人陶醉,头上是白云飘过,眼前是花红草绿.
身后一堆高高的青草丛中是你刚爬出来的洞口.前方不远是一片令人心
醉的桃花林.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"dtotree",
  "enter" : __DIR__"cave5",
]));

	setup();
	replace_program(ROOM);
}
