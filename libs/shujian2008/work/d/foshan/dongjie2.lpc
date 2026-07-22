// Room: dongjie2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "佛山东街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。南边是打铁铺，叮叮
当当的声音老远就能听到。
LONG
	);
        set("outdoors","佛山");
	set("exits", ([
            "south" : __DIR__"ironsmith",
            "east" : __DIR__"dongjie3",
            "west" : __DIR__"dongjie",
            "north" : __DIR__"shaobing",
]));

        set("objects", ([
            __DIR__"npc/jiading" : 2,
]));

	set("no_clean_up", 0);
	set("coor/x",20);
  set("coor/y",-530);
   set("coor/z",0);
   setup();

}
