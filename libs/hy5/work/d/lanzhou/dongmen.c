// Room: /wizhome/lanzhou/dongmen.c
// Date: xws 98/10/13

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这是兰州城的东城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“东门”两个大字，城墙上贴着几张通缉告
示(gaoshi)。许多来边疆做苦力的罪犯常常经过这里逃回中原，官兵们戒备森严，
动不动就截住行人进行盘问。一条笔直的青石大道向东西两边延伸。东边是郊外，
许多西域来的商人都从这里出城，向东到达中原。许多本地人也赶着牲口从这里
经过，到城里去卖掉自己种的瓜果，再买回生活必需品。西边是城里。
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"west"  : __DIR__"dongdajie1",
		"north"  : __DIR__"majiu",	
		
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

