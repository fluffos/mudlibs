
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "通明门");
        set("long", @LONG
这是掖庭宫的东大门通明门，西面就是宫女的居所掖庭宫，东面是中书内省。
LONG    );
        
        set("exits", ([
           "west" : __DIR__"yetinggong",
           "northeast" : __DIR__"zhongshusheng"
        ]));
        
        set("locate_level",2);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}