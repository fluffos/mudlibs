// by mayue

inherit ROOM;

void create()
{
        set("short", "瀑布");
	set("long", @LONG
 -------   施工中，                              闲人免进！
LONG
	);
        set("outdoors", "wudujiao");
   set("building",1);
	set("exits", ([
//              "east" : __DIR__"sl8",
//              "northwest" : __DIR__"sl4",
//              "west" : __DIR__"sl6",
//              "northeast" : __DIR__"sl5",
                "south" : __DIR__"sl3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

