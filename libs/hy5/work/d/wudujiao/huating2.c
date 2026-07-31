// by mayue

inherit ROOM;

void create()
{
	set("short", "栖凤亭");
	set("long", @LONG
这里是一个花园中的小亭子，雕梁画栋，古色古香。亭子当中立着几个木人。
LONG
	);
//       set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huating",
//		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan2",
		"north" : __DIR__"huating1",
	]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren":4,
	]));
    

	setup();
	replace_program(ROOM);
}

