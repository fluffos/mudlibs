// guangchang.c
// by yuer
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "广场");
	set("long","这里是明教总舵的广场，整个广场由大块的青石铺成，极为平坦。
但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。上方一块大匾，
龙飞凤舞地书着 \n\n"+ YEL "          光     明     顶" NOR + "\n\n");

	set("exits", ([
		"southdown" : __DIR__"damen",
                "west" : __DIR__"dayuan",
                "north" : __DIR__"zoulang",
	     
	]));
      set("objects",([
		CLASS_D("mingjiao") + "/yangxiao" : 1,
                __DIR__"npc/fan" : 1,
            ]));

        set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}



