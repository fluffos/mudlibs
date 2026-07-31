// Room: /d/zuojiacun/midian.c

inherit ROOM;

void create()
{
	set("short", "米庄");
	set("long", @LONG
本地的米庄。松江大米是当地的特色。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu14",
 ])); 

	setup();
	replace_program(ROOM);
}
