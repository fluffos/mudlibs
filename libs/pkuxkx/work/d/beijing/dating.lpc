// Room: /d/beijing/dating.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"大厅"NOR);
        set("long",
CYN"厅中的陈设也不甚豪华，周围散放着几张椅子，门后不显眼处放有一
人来高的镀金自鸣钟，，算是室内最气派的奢侈品，大厅当中摆着一张檀
木长桌，一大群人围着这张桌子喝七吆八的赌得正在兴头上，旁边有告示(sign)一块。\n"NOR
        );

        set("no_fight",1);
        set("no_steal",1);
        set("exits", ([
                "east" : __DIR__"tingyuan",
                "north" : __DIR__"duchang1",
                "south" : __DIR__"duchang2",
                "west" : __DIR__"shaizi-room",
                "down": __DIR__"shusini-room",
        ]));
        set("item_desc", ([
                "sign": @TEXT

骰子的赌法：

ｂｅｔ　＜种类＞　＜银子数量＞

种类：　０，１，２，３到１８
０：　          赌小    （３－１０）    一赔一
１：            赌大    （１１－１８）  一赔一
２：　          赌围骰  （三粒骰子同点）一赔十二
３－１８        赌单点                  一赔六

例子：
ｂｅｔ　０　５０
赌五十两在小上

TEXT
        ]) );

        set("objects", ([
//                 "/adm/npc/weixiaobao": 1,
//新的韦小宝，附带神龙教的秘密
                 "/adm/npc/wei": 1,
        ]));
        set("max_user",10);
        setup();
}


void init()
{
        int i;
        object* inv;
	object me;
	me = this_player();
	if( me->query("gamble/amount")) {
		me->delete("gamble/amount");
	}
                for(i=0; i<sizeof(inv); i++) {
                    if (inv[i]->query("gamble/amount")) {
                        inv[i]->delete("gamble/amount");
                    }
                }
}
