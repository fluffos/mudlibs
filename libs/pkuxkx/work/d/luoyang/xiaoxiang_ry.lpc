//xiaoxiang.c	小巷
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","小巷");
	set("long",@LONG 
你置身于一条窄窄的巷子之中。巷子尽头，好大一片绿竹丛，迎风摇曳，雅致天然。
你刚踏进巷子，便听得琴韵丁冬，有人正在抚琴，小巷中一片清凉宁静，和外面的
洛阳城宛然是两个世界。
LONG
	);
	set("exits", ([
		"south" : __DIR__"xiaoshe2",
		"north"	: __DIR__"yingyingju",
	]));
	set("objects", ([
                "/d/riyuejiao/npc/ahua" : 1,
        ]));

	set("outdoors", "city");
	setup();
}



int valid_leave(object me, string dir)
{
        if (dir == "north" && (present("a hua",environment(me))))
		return notify_fail("阿花拦住了你的去路，朝你「汪汪」叫了几声。\n");
        return ::valid_leave(me, dir);

}