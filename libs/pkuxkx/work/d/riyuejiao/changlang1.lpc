//changlang1.c	长廊
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG 
这里是一道长廊，数百名武士排列两旁，手中各挺进一把明晃晃的长刀，
交叉平举。你只能从阵下弓腰低头而过，数百柄长刀中只要有一柄突然砍落，
便不免身首异处，令人心惊胆战。
LONG
	);
	set("exits", ([
		"north"	: __DIR__"changlang2",
		"out"	: __DIR__"chengde",
	]));
	set("objects", ([
                __DIR__"npc/shizhe": 4,
        ]));

	set("outdoors", "riyuejiao");
	setup();
}

