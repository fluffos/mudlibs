
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"承天门大街"NOR);
        set("long", @LONG
这是皇城的主干道承天门大街，北面是太极宫南门承天门，
东面是太常寺，西面是斗鸡场，不时传来一阵喧嚣声。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"taichangsi",
                "south" : __DIR__"zhuquemen",
                "west" : __DIR__"doujichang",
                "north" : __DIR__"chengtianstreet-8",
        ]));
        
        set("locate_level",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


