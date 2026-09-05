
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "承天门横街");
        set("long", @LONG
这里是承天门前面的宽阔广场，整条横街宽三百步，据说每到
国家有重大庆典总是在这里举行，整条街道戒备森严，一般日子闲
杂人等禁止进入。
LONG    );
        
        set("exits", ([
                "east" : __DIR__"chengtianstreet-2",
                "west" : __DIR__"chengtianstreet-6",
                "north" : __DIR__"chengtianstreet-3",
                "south" : __DIR__"chengtianstreet-7",
        ]));
        
        set("locate_level",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}