// by mayue

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这里是一间客房，靠墙布着一溜通铺，行人累可以在这里随
意休息。窗边摆着一个破破烂烂的木桌，一个游方道人正坐在桌
边喝茶。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"xiaodian",
//		"south" : __DIR__"milin1",
//		"west" : __DIR__"neijin",
//		"north" : __DIR__"road3",
	]));
        set("objects", ([
                __DIR__"npc/daoshi": 1,
	]));
   

	setup();
	replace_program(ROOM);
}

