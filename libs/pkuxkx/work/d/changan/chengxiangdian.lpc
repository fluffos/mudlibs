
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "承香殿");
        set("long", @LONG
承香殿是太后的居所，北面就是玄武门和禁宫护卫羽林军的卫府，
南面是皇帝读书和日常居住之所甘露殿。
LONG    );
        
        set("exits", ([
                "north" : __DIR__"northgate",
                "south" : __DIR__"yanjiadian"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}