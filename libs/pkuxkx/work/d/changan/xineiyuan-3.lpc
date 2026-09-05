
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "西内苑");
        set("long", @LONG
这是皇帝的御花园西内苑，里面亭台楼榭，名花异草，奇石假山遍布，
不是看见几名宫女从小道经过，东边就是东大内大明宫，北面是皇宫内踢
马球的场所含光殿。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"xineiyuan-2",
                "north" : __DIR__"hanguangdian"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
}