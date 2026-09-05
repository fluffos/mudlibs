
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "敬时楼");
        set("long", @LONG
这是尚书省的正门敬时楼，敬时楼为长安八景之一的“晨钟暮鼓”，
里面就是尚书省和六部官员办公的场所。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"chengtianstreet-8",
                "east" : __DIR__"shangshusheng"
        ]));

        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
          __DIR__"npc/jinwu-1": 2,
        ]));
        
        set("locate_level",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}