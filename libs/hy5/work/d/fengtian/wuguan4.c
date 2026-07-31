// Room: /d/fengtian/wuguan4.c

inherit ROOM;

void create()
{
	set("short", "右跨院");
	set("long", @LONG
这里是新月武馆的右跨院，院中有一口井可以打水(fill)，
西面就是武官的练功场。
LONG
	);

	set("resource/water", 1);
	set("cannot_build_home", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wuguan2",
]));

	set("outdoors","fengtian");
	setup();
	replace_program(ROOM);
}
