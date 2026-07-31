// Room: /d/tianshan/ctbu.c
// By Linux

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"赤天部"NOR);
	set("long", @LONG
眼前是一个可容纳数百人的大厅，是赤天部的所在地，大厅墙壁上画满了
浮雕，天顶上是一片云雾，一仙人卧于其中，面目沉静，姿态幽雅，似乎万物
与其无关痛痒，万事不动其心。地面以灰色岩石磨就，分毫无缝，浑然天成。
大厅四角点着数盏明灯，弥漫在大厅里的香气好象就是从灯里发出。
LONG);
	 set("exits", ([
                "southdown" : __DIR__"dadao2",
		"northdown" : __DIR__"dadao3",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    
	setup();
}
