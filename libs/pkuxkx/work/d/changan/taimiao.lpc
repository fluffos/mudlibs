
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太庙");
        set("long", @LONG
这里是太庙，是每年重大节日或者有重大政治活动的时候，皇帝
祭祀祖先的地方，整个太庙巍峨高耸，庄严肃穆，太庙的西面是掌管
祭祀的太常寺，东面是碑林。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"beilin",
                "west" : __DIR__"taichangsi"
        ]));
        
        set("locate_level",1);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        set("outdoors", "changan");
        setup();   
}
