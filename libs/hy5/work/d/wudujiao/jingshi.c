// by mayue


inherit ROOM;

void create()
{
	set("short", "静室");
	set("long", @LONG
这是一个昏暗的房间，除了几张床之外什么都没有。室内光线昏暗，你
不由的打了一个哈欠。
LONG
	);
//      set("outdoors", "wudujiao");
        set("sleep_room", 1);
        set("no_fight", 1);
//      set("valid_startroom", 1);

	set("exits", ([
//		"east" : __DIR__"huayuan1",
//		"south" : __DIR__"jingshi",
//		"west" : __DIR__"lianwu",
		"north" : __DIR__"dating",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
               "/d/wudujiao/npc/obj/skirt.c":1,
	]));
    

	setup();
	replace_program(ROOM);
}

