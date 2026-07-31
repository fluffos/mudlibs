// Room: /d/taiwan/tree3.c

inherit ROOM;

void create()
{
	set("short", "树林边");
	set("long", @LONG
你的面前是一片浓密的树林.依稀能看到有一条小路通向林子深处.
面前的一株大树上挂了一块木牌(pai),林中隐隐流动着一层云烟.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "pai" : "        一入风波林,生死两茫茫.
            劝君回头是岸.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tree2",
  "southwest" : __DIR__"tree4",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
