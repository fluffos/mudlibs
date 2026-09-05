// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
#include "dating.h"
string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，官府
的告示(gaoshi)因此不太显目。官兵们被近处的欢声笑语所吸引，似乎不是很认
真在执勤。
LONG);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
    set("gate","南");
	set("exits", ([
		//"south" : "/d/wudang/wdroad1",  //扬州按实际地理位置放在长江北
		"north" : __DIR__"nandajie3",
        "southup" : __DIR__"guandaos1",
	]));
    
        set("objects", ([
                __DIR__"npc/wujiang1"+random(2) : 1,
                __DIR__"npc/bing" : 2,
        ]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

void init()
{
    add_action("do_dating","dating");
    add_action("do_answer","answer");
}