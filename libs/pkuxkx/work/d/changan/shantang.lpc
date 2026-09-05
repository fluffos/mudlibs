
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", CYN"善堂"NOR);
        set("long", @LONG
这里是长安一户富户开的善堂，经常施粥给流落的饥民，在西北这一带颇有
善名，施粥的日子有很多人排队领粥。
LONG
        );
        
        set("exits", ([
                "south" : __DIR__"weststreet-2",
                
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        
        setup();
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}


