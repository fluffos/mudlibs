// Room: /d/tangmen/guajiantang.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "挂剑堂");
	set("long", @LONG
	这里是挂剑堂。唐门是武林世家，当然有很多喜好收集兵器的人。剑是兵器
之王，经过历代的收集，已经有不少神兵利器陈列在挂剑堂中。
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang11",
		"west" : __DIR__"duanmuting",
		"east" : __DIR__"changlang17",
		"up" : __DIR__"jiaolou6",
	]));
       set("objects", ([
		__DIR__"npc/dizi" : 4,
			]));

	setup();
	replace_program(ROOM);
}

