#include <ansi.h>

inherit ROOM;
inherit F_SAVE;
#include "/d/luoyang/record.h"

void create()
{
        set("short", HIG"排行榜"NOR);
        set("long", @LONG
这里竖着一面巨大的排行榜(bang)，旁边还挂了一块牌子(pai)。
LONG
        );
        set("item_desc", ([
		"bang" : (:look_bang:),
        "pai" :(:look_pai:),
	    ]));
        set("exits", ([
              
               "west" : __DIR__"bang",            
               
        ]));
        /*set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));*/
        set("record_time",10800);
        set("max_record_item",10);
        set("no_reset",1);
        set("no_clean_up", 1);
        set("no_task",1);
        set("no_fight",1);
        set("outdoors", "luoyang");
        setup();
        
}

