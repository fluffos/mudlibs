// Room: shidetang.c
// Lklv Modify 2001.9.21

inherit ROOM;

void create()
{
	set("short", "世德堂");
	set("long", @LONG
你走进一座两开间的大厅，当中一块大匾，写着三个大字：“世德堂”。
厅上中堂条幅，云板花瓶，陈设的甚是考究，一派豪绅大宅的气派。
LONG
	);
	set("objects", ([
		__DIR__"npc/wennanyang": 1,
	]));

	set("exits", ([
                "north": __DIR__"damen",
		"south": __DIR__"tianjing",
		"west":__DIR__"wofang1",
		"east":__DIR__"wofang2",
	]) );

	set("incity",1);
	setup();
}
