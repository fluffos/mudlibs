
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "右银台门");
        set("long", @LONG
这是大明宫和西内苑之间的大门右银台门，东面就是
紫宸殿，东北面是麟德殿。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"zichendian",
                "west" : __DIR__"hanguangdian",
                "northeast" : __DIR__"lindedian"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
}