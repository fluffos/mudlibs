
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "左银台门");
        set("long", @LONG
这是大明宫和东内苑之间的大门左银台门，西面就是
紫宸殿，西北面是皇帝寝宫蓬莱殿。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"zichendian",
                "east" : __DIR__"dongneiyuan",
                "northwest" : __DIR__"penglaidian"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
}