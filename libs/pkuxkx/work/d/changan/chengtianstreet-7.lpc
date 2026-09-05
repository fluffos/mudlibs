
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"承天门大街"NOR);
        set("long", @LONG
这是皇城的主干道承天门大街，北面是太极宫南门承天门，
两边是金吾卫的衙门，南面是尚书省。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"jinwu-2",
                "south" : __DIR__"chengtianstreet-8",
                "east" : __DIR__"jinwu-1",
                "north" : __DIR__"chengtianstreet-4",
                
        ]));
        
        set("locate_level",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


