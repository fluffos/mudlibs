// Room: /d/yandang/shandong2.c

inherit ROOM;

void create()
{
	set("short", "透天洞");
	set("long", @LONG
透天洞由来是由于在数十丈高的洞顶上有个小小的天窗,阳光从天
窗中透射下来,在暗黑的洞窟中,形成一道光路,向地上看,则有一条深约
三丈的丘壑,据说阳光始终在这丘壑中移动,神秘至极.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shandong1",
  "northeast" : __DIR__"shandong4",
]));

	setup();
	replace_program(ROOM);
}
