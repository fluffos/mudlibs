
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "翰林院");
        set("long", @LONG
这里是皇帝近臣聚会的场所翰林院，皇帝常过来和近臣吟诗
作画，有时召见翰林起草机密诏制。
LONG        );
        
        set("exits", ([
                "southeast" : __DIR__"lindedian"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}