// by mayue

inherit ROOM;

void create()
{
	set("short", "竹舍");
	set("long", @LONG
这是一间竹子搭成的房子，虽然简陋但却被主人收拾的干干净
净。一个羽扇纶巾，相貌清雅的文士正坐在案边闲看三国，听见
脚步声不由抬起头来。
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
//		"south" : __DIR__"zhushe",
//		"west" : __DIR__"wumiao",
		"north" : __DIR__"caoping",
	]));
        set("objects", ([
                __DIR__"npc/zhuge": 1,
	]));

	setup();
	replace_program(ROOM);
}

