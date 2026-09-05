// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/entry_migong.h",
void create()
{
	set("short", "土路");
	set("long", @LONG
道路渐渐变窄，只有一些商贩往返于此地，贩卖两地的必须物资。往北穿过
科尔沁草原即可到达一个名作“大翰耳朵”的草原部落。
LONG
	);

	set("exits", ([
	    "west" : __DIR__"huangyuan",
		//"east" : __DIR__"shanqian2",
		"southeast" : "d/saiwai/guandaon1",
		"northwest" : __DIR__"random_caoyuan1_s",
	]));
    set("entry_direction","northwest");
    set("migong","/d/menggu/caoyuan1");
    set("migong_posi","south");
	set("no_robber",1);
    set("look_refuse_msg","科尔沁草原上刮起了大风，你什么都看不清了。\n");
    set("enter_refuse_msg","科尔沁草原上刮起了大风，这会儿进去太危险了。\n");
    set("objects", ([
        	__DIR__"npc/leader" : 1,
			__DIR__"npc/intro" : 1,
	    ]));
    set("outdoors", "menggu_e");
	setup();
}

void init()
{
    add_action("do_look","look");
}


