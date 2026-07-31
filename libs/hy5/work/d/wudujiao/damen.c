// by mayue

inherit ROOM;

void create()
{
	set("short", "五毒教大门");
	set("long", @LONG
这里是一座隐没于山林中的大宅院，高高的围墙，朱红的大门，
好象是一座有钱人家的避暑别院。 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"lianwu",
//		"south" : __DIR__"wdsl5",
		"west" : __DIR__"wdsl7",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
	]));
    

	setup();
        "/clone/board/wudujiao_b"->foo();
}

