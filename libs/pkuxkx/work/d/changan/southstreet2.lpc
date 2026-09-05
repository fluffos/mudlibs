
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "朱雀大街");
        set("long", @LONG
这是繁华的朱雀大街，两边都是高官富商的宅邸，隐隐听闻四周
寺院道观里面的诵唱声音。北面是皇城的南门朱雀门，南面通向
明德门，东面可以看见著名的小雁塔。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"southstreet",
                "north" : __DIR__"zhuque",
                "east" : __DIR__"jianfosi"
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


