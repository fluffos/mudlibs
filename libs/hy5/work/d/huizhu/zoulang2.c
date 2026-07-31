// Room: /d/huijiang/zoulang2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long",@LONG
你走在一条长长的走廊上，四周没有一个人，你的脚步声传得很远，
两旁池塘里的残荷上停了几只呱呱乱叫的青蛙，阵阵轻风吹来，令人欲
醉。南边似乎有一扇门。
LONG );
	set("outdoors", "huijiang");	
	set("exits", ([
		"south"     : __DIR__"xiuxishi",
		"west"     : __DIR__"yixiangting",
		"northup"  : __DIR__"zongduo",
		"eastdown" : __DIR__"zoulang1" ,
	]));
	
        set("objects", ([
                __DIR__"npc/dizi" : 4,
        ]));
	
	set("no_clean_up", 0);
	set("coor/x", -50070);
	set("coor/y", 9140);
	set("coor/z", 10);
	set("door_name","门");
	set("door_dir","south");
	set("restroom",__DIR__"xiuxishi");

	setup();
}
