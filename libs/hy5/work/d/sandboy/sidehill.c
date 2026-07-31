// Room: /d/sandboy/sidehill.c

inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
绿草茵茵的一片山坡,远望去,稻田,草地,池塘,民房,树林一一在眼,大石
旁,两头水牛正在吃草,耳边传来流水潺潺.向北是一片稻田,向上则是一条
平缓的山道.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"daotian3",
  "southup" : __DIR__"shandao",
]));

	setup();
	replace_program(ROOM);
}
