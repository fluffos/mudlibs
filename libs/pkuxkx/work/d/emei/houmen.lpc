// Room: /u/cuer/emei/houmen.c

inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", @LONG
这里是峨嵋派千佛庵的后门了，这地方很安静，没
有什么人，出后门就是峨嵋派的后山了。静修庵，九老
洞，药王洞和金顶都是从这出去的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan/shandao",
  "south" : __DIR__"houyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
