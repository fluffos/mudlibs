
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"丹凤门广场"NOR);
        set("long", @LONG
这是宽广的丹凤门广场，广场正北是高大雄伟的含元殿，这里是
国家重大庆典举办场所，东北和西北角是东西朝堂，为每月朔望两日
大朝之时百官觐见休息场所，整个广场东西宽五百步，南北宽四百步，
是整个京城最大的广场之一。
LONG        );
        
        set("exits", ([
                "northup" : __DIR__"hanyuandian",
                "south" : __DIR__"danfengmen",
                "northeast" : __DIR__"chaotang-1",
                "northwest" : __DIR__"chaotang-2"
        ]));
        
        set("locate_level",3);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}