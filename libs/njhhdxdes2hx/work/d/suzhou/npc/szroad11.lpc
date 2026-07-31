// ROOM: szroad11.c
//by dwolf
//97.11.8
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大道");
	set("long",  @LONG
	  这是一条青石大道，直通南北，两旁春意盎然，开着一些不知名的小花，
天空不时有几只小鸟飞过，于是草丛中惊起一只野兔，飞快地跑了。北边不远就是
杭州，南边不远是苏州。  
	);
	set("exits", ([
		"west" : __DIR__"ngate", 
		"north" : __DIR__"szroad12",
]));                            
	set("objects", ([
		__DIR__"npc/ren" : 1,
]));
	setup();
	replace_program(ROOM);
}
