// Room: /d/yandang/shimeng.c

inherit ROOM;

void create()
{
	set("short", "石门");
	set("long", @LONG
沿着陡峭山路向下,可看到前方两岩东西隔溪相对如门,所以称为石
门,进入门内,如行甬道之中,门上有玉兔峰诸景.从头顶可依稀听到山猿
的哀鸣,声声不息.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"tianzhu",
  "north" : __DIR__"luoyan1",
]));

	setup();
	replace_program(ROOM);
}
