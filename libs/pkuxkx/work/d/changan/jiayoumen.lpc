
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "嘉猷门");
        set("long", @LONG
嘉猷门是掖庭宫和太极宫之间的门户，西面就是宫女居所掖庭宫，
东面是太极宫的内廷嫔妃居所淑景殿。
LONG    );
        
        set("exits", ([
           "east" : __DIR__"shujingdian",
           "southwest" : __DIR__"yetinggong",
           "west" : __DIR__"taicang"
        ]));
        
        set("locate_level",2);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}