// Room: /wizhome/lanzhou/nanmen.c
// Date: xws 98/10/14

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是兰州城的南城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“南门”两个大字，城墙上贴着几张通缉告
示(gaoshi)。许多来边疆做苦力的罪犯常常经过这里逃回中原，官兵们戒备森严，
动不动就截住行人进行盘问。一条笔直的青石大道向南北两边延伸。南边是郊外，
一些西域来的商人都从这里出城，向南到达成都。许多本地人也赶着牲口从这里
经过，到城里去卖掉自己种的瓜果，再买回生活必需品。北边是城里。
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : "/d/xibei/tuntian3",
		"south" : __DIR__"caroad1",
                "north" : __DIR__"nandajie2",
		
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 2,
                "/d/city/npc/bing" : 4,
        ]));
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         黑潮判官\n          无  心\n";
}

