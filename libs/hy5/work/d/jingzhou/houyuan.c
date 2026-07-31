// Room: /d/jingzhou/houyuan.c
// congw
inherit ROOM;

void create()
{
	set("short", "衙门后院");
	set("long", @LONG
这里是衙门的后院，打扫得非常干净，四周是过人的围墙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "north" : __DIR__"ymzhengting",
 ]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
