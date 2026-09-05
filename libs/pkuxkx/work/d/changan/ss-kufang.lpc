
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "户部库房");
        set("long", @LONG
这是尚书省户部衙门所属的库房，两边一排排库房存折着各种物资。
LONG        );
        
        set("exits", ([
                "southup" : __DIR__"ss-hubu",
                "west"    : __DIR__"ss-kufang2",
                "east"    : __DIR__"ss-kufang3",
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}