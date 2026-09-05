
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "蓬莱殿");
        set("long", @LONG
这是皇帝寝宫蓬莱殿，两边是嫔妃们的寝宫，西南面是内朝紫宸殿，
东南面是东内苑，西北面是美丽的太液池畔。
LONG        );
        
        set("exits", ([
                "southwest" : __DIR__"zichendian",
                "southeast" : __DIR__"yintaimen-1",
                "northwest" : __DIR__"taiye-1"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}