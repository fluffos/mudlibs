// Room: /d/tianshui/skou.c

inherit ROOM;

void create()
{
	set("short", "天水镇南口");
	set("long", @LONG
这里就是天水镇的南口了，从这里一直向北走就可以到达边
关大营，由于通往军事重地，这里的检查非常严格，几个全副武
装的士兵这在盘查过往的行人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad2",
  "south" : __DIR__"yidao5",
]));
	set("objects",([
	__DIR__"npc/tiaofu" : 1,
	]));

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
