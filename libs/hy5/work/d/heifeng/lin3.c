// Room: /d/heifeng/lin3.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这里是山坡上一处浓密的小树林，树影婆娑，山风吹来四处
“沙沙”作响，使人总有一种危机四伏的感觉。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaolu3",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
