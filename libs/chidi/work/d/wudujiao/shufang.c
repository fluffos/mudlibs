// by mayue


inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是教主平时看书的地方，房间不大，只靠窗摆着一张书案，案边
放了几本书，看来是教主经常翻看的。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huayuan1",
//		"south" : __DIR__"jingshi",
//		"west" : __DIR__"lianwu",
		"south" : __DIR__"dating",
	]));
        set("objects", ([
                 __DIR__"obj/book1": 1,
                 __DIR__"obj/book2": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

