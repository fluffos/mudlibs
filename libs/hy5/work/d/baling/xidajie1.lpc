// baling/xidajie1
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，
行人稀少，静悄悄地很是冷清。东边是一个热闹的广场。南边是燕王府。
那里闲人免进。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"guangchang",
                "north" : __DIR__"yanju",
		"west" : __DIR__"ximen",
		
	]));

	setup();
	replace_program(ROOM);
}

