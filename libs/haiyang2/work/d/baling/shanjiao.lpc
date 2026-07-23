// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "山脚");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。东面有一做山挡在前面，大驿道
顺山而修，蜿蜒的向北而去，一条小道顺山势进入山上的密林中。
LONG
	);

	set("exits", ([
		"west" : __DIR__"edao2",
                "northwest" : __DIR__"edao3",
                "eastup" : __DIR__"shanru",
                "south" : __DIR__"edao10",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


