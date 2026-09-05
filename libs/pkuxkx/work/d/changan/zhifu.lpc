
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", MAG"京兆府"NOR);
        set("long", @LONG
这是位于长安万年县的京兆府，管理着整个京畿地区二十三
个县的大小事务，大凡涉及到通行、通商、民间纠纷、治安等等
事宜都可以到京兆府咨询。
LONG    );
        
        set("exits", ([
          "north" : __DIR__"weststreet-1",
          "west" : __DIR__"zhifu-2",
        ]));

        set("objects", ([
		      __DIR__"npc/yayi" : 2,
          "/clone/npc/zhifu":1,
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


