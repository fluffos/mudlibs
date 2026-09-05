
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "延嘉殿");
        set("long", @LONG
这是皇后的居所延嘉殿，南面是皇帝寝宫甘露殿，北面是太后寝宫。
LONG    );
        
        set("exits", ([
           "north" : __DIR__"chengxiangdian",
           "south" : __DIR__"ganludian"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}