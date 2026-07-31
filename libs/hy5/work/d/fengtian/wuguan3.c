// Room: /d/fengtian/wuguan3.c

inherit ROOM;

void create()
{
	set("short", "左跨院");
	set("long", @LONG
这里是新月武馆的左跨院，是武馆的教头平时休息的地方，
东面就是武官的练功场。
LONG
	);

	set("cannot_build_home", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wuguan2",
]));

	set("objects",([
	__DIR__"npc/jiaotou" : 3,
]));

	set("outdoors","fengtian");
	setup();
	replace_program(ROOM);
}
