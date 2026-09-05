
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "两仪殿");
        set("long", @LONG
皇帝时常用来和少数亲近大臣商谈国事，以及宴请大臣和使节的处所。
北面就是皇帝读书的地方甘露殿。
LONG        );
        
        set("exits", ([
                "northdown" : __DIR__"ganludian",
                "southdown" : __DIR__"liangyimen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}