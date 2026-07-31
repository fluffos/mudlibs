inherit ROOM;

void create()
{
	set("short", "枯井");
	set("long", @LONG
这是一口枯井，上面的辘轳已经坏掉了。井檐儿上落着几只
麻雀，见到你走过来，扑楞着翅膀飞了起来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
  "south" : __DIR__"lu11",
]));
	set("outdoors", "zuojiacun");
	setup();


	replace_program(ROOM);
}
