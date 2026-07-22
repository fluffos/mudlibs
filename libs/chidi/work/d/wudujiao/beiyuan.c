// by mayue


inherit ROOM;

void create()
{
	set("short", "北院");
	set("long", @LONG
这里是北院，院子里静悄悄的。北面有一个厨房，远远飘来一
股饭香，想是该开饭了。  
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"bingqi",
		"south" : __DIR__"lianwu",
//		"west" : __DIR__"damen",
		"north" : __DIR__"chufang",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}

