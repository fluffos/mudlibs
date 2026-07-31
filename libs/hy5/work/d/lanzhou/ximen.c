// Room: /wizhome/lanzhou/ximen.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
这是兰州城的西城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告
示(gaoshi)。许多来边疆做苦力的罪犯常常经过这里逃回中原，官兵们戒备森严，
动不动就截住行人进行盘问。一条笔直的青石大道向东西两边延伸。西边是郊外，
一直向西去就是举世闻名的敦煌，许多游客在找到向导后都座着骆驼由这里出去
游览敦煌。许多本地人赶着牲口从这里经过，到城里去卖掉自己种的瓜果，再买
回生活必需品。东边是城里。
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
                "west"  : "/d/xingxiu/xxroad1",
                "east"  : __DIR__"xidajie1",
		
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

