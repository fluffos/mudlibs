#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", "小厅");
	set("long", "这里是大厅旁的一个小厅，布置得相当素雅，靠墙的位置有茶几锦
椅供人小歇。一位庄内的教头正坐在椅上品茗。\n"NOR);
	set("exits", ([
		"west" : __DIR__"dating",
	]));
    set("objects", ([
	    __DIR__"npc/jiaotou" : 1,
        ]));
	setup();
}



