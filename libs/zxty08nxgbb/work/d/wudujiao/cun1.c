// by mayue

inherit ROOM;

void create()
{
	set("short", "小村口");
	set("long", @LONG
这里是桃花江边的一个小村，村口有几个农家的小孩正在大树底下玩
耍。远远的升起缕缕炊烟，忙碌了一天的人们开始做饭了。 
LONG
	);
       set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"cun2",
//		"south" : __DIR__"wdsl5",
		"west" : __DIR__"jiang2",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                 __DIR__"npc/kid": 3,
//               "/d/npc/guojing": 1,
//               "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}

