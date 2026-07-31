// Room: /d/5lt/center.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "村广场");
	set  ("long",  @LONG
这里便是无厘头村的正中心，一个很宽阔的广场，东南西北四条碎
石路交汇于此。一些游手好闲的人在这里溜溜达达，经常有艺人在这里
表演。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

	set("exits",  ([  //sizeof()  ==  4
		"up" : "/d/pingan/pinganmen",
		"north" :  __DIR__"nroad1",
		"south" :  __DIR__"sroad1",
		"west"  :  __DIR__"wroad1",
		"east"  :  __DIR__"eroad1",
  "down"	: "/d/city/lajichang",
	]));
        set("objects", ([
		__DIR__"npc/hehehehe": 1,
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -150);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
