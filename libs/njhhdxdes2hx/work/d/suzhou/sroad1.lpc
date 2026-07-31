//ROOM: d/suzhou/sroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"南大街"NOR);
	set("long", @LONG
	    你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人
都往北边走去，那里是热闹的市中心。东边是一家生意兴隆的客栈，来自各地的人们
进进出出，据说也是情人们的幽会地点。西边是一家红娘庄。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"mroom",
		"north" : __DIR__"shizx",
		"south" : __DIR__"sroad2",
		"east" : __DIR__"kezhan",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 2,  
]));
	
	setup();
}





