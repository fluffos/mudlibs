// by mayue

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是五毒教存放武器的地方，四面靠墙全是兵器架，上面插满了
各种兵器。  
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"bingqi",
//		"south" : __DIR__"beiyuan",
		"west" : __DIR__"beiyuan",
//		"north" : __DIR__"chufang",
	]));
        set("objects", ([
                  __DIR__"obj/ganggou": 2,
                  __DIR__"obj/woodjian": 2,
//                __DIR__"obj/tiezhui": 2,
	]));
    

	setup();
	replace_program(ROOM);
}

