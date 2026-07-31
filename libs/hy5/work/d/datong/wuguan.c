// Room: /open/dt/wuguan.c

inherit ROOM;

void create()
{
	set("short", "武馆");
	set("long", @LONG
大同地处边关，因此民风强健，大同人不论男女没有不会武
功的。这家武馆平时不光教少年人习武练功，许多武林健者也经
常到这里切磋比试，所以非常的热闹。武馆的主人是一个笑咪咪
的胖子，从没有人看到过他跟人动手过招，但大家都认为他是一
个深藏不露的武林高手。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu4",
]));

	setup();
	replace_program(ROOM);
}
