// Room: /wizhome/lanzhou/beimen.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是兰州城的北城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“北门”两个大字，城墙上贴着几张通缉告
示(gaoshi)。许多罪犯常常经过这里逃到西域，官兵们戒备森严，动不动就截住
行人进行盘问。一条笔直的青石大道向南北两边延伸。北边是郊外，许多西域来
的商人都从这里进城。许多本地人也赶着牲口从这里经过，到城里去卖掉自己种
的瓜果，再买回生活必需品。南边是城里。
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : "/d/lanzhouchen/yizhan",
		"north" : __DIR__"nroad1",
 "northwest" : "/d/lanzhouchen/road4",
"south" : "/d/lanzhouchen/road3",		
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

