
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "西内苑");
        set("long", @LONG
这是皇帝的御花园西内苑，里面亭台楼榭，名花异草，奇石假山遍布，
不是看见几名宫女从小道经过。
LONG        );
        
        set("exits", ([
                "northup" : __DIR__"xineiyuan-2",
                "south" : __DIR__"northgate"
        ]));
        
        set("locate_level",3);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}