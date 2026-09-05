//城墙 /d/jinyang/citywall
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "内城墙");
        set("long", @LONG
这是长安城皇城的城墙，四周守卫森严。
LONG     );
        set("exits", ([
                "west" : __DIR__"innerwall9",
                "north" : __DIR__"innerwall5"
        ]));
        
        set("locate_level",4);
        
        set("outdoors", "changan");
        set("changan", 4); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}