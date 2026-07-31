// Room: /d/tangmen/ouxiang.c
// BY hem

inherit ROOM;

void create()
{
	set("short", "藕香小榭");
	set("long", @LONG
	这是藕香湖中一间雅致的小榭，四面皆有雕花小窗，窗上挂有暗花丝帘。中
间有一琴台，台上有焦尾古琴，青铜小鼎中正焚着檀香。一抹憔悴的身影，纤纤玉指
拨弄着琴弦。原来你刚才听到的忧郁琴音，正是从这儿传出的。
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"qulang3",
		"east" : __DIR__"qulang4",
		"northeast" : __DIR__"qulang2",
		"southeast" : __DIR__"qulang5",
		
	]));
	set("objects", ([
		__DIR__"npc/tang_fang" : 1,
                __DIR__"npc/yahuan" : 1,
	]));


	setup();
	replace_program(ROOM);
}

