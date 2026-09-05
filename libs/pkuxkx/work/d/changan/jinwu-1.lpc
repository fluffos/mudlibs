
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "左金吾卫府");
        set("long", @LONG
这是左金吾卫大将军府，负责整个皇城内外和长安县的治安巡逻，
左金吾卫大将军掌管着全国几十个折冲府的军队。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"chengtianstreet-7",
        ]));

        set("objects", ([
		      __DIR__"npc/jinwu-7": 1,
          __DIR__"npc/jinwu-6": 2,
        ]));
        
        set("locate_level",1);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}