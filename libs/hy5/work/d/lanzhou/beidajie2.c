// Room: /lanzhou/beidajie2.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
	你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人
都往南边走去，那里有一个热闹的广场。西边是一个小吃馆，阵阵香味飘来，让
你直流口水！
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"west" : __DIR__"xiaochidian",
		"south" : __DIR__"beidajie1",
		"north" : "/d/lanzhouchen/road2",
	]));
	setup();
	replace_program(ROOM);
}

