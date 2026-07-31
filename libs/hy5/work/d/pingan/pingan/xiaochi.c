//canchang
  

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
这里卖最烈也是最劣的白酒。一杆已经被风扯裂的酒旗上画着一个用红圈起来的
“酒”字。几根竹竿撑着一块业已变黑的白帆布，白布下放着几张破旧的木桌和方凳，
木桌上零零散散得放着几双木筷和几个崩了口的小碟儿。不过这里的生意还不错.
LONG
	);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"west" : __DIR__"nan1",
		"east" : __DIR__"xiaochi2",
	]));
        set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

