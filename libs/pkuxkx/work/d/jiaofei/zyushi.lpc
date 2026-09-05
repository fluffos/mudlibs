// Room: /shenlongjiao/shanquan.c
// kiden 06/08/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"澡堂子"NOR);
        set("long", @LONG
这里是五指山的澡堂子，里面的搓澡服务由于采用了特殊精油，颇有
提神醒脑之效，所以土匪们经常光顾。
顺着楼梯上去是女浴池，右边便是男浴池。门口放着一个牌子(paizi)。
LONG
        );
	set("outdoors", "shenlongdao");
	set("resource/water", 1);
	set("objects", ([
		"/d/jiaofei/npc/zaotang-laoban" : 1,
	]));
        set("exits", ([
                "south" : __DIR__"zjiedao2",
				"east"  : __DIR__"zyushim",
			    "up"    : __DIR__"zyushiw",
        ]));
		set("item_desc", ([
		"paizi" : HIR"精油搓澡，50g一次"NOR+"\n",
		]));
        setup();
}

void init()
{
}
int valid_leave(object me, string dir)
{
	if(dir == "up" && me->query("gender") != "女性")
		return notify_fail(HIY"上边是女浴池！你要耍流氓么？\n"NOR);
	return ::valid_leave(me, dir);
}