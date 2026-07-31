// Room: /d/sandboy/to_wudang.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条穿过树林的小路,一直通向西面的茅草丛中,远处大山隐隐,据说
哪就是武当山,山中住着神仙.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"trees2",
  "west" : __DIR__"to_wudang2",	
]));
set("outdoors","/d/jiangnan");

	setup();
	replace_program(ROOM);
}
