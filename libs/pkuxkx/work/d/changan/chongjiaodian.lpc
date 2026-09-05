
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "崇教殿");
        set("long", @LONG
这是太子寝宫崇教殿，北面是太子妃寝宫丽正殿，西北面是太子读书
所在崇文馆。
LONG    );
        
        set("exits", ([
           "north" : __DIR__"lizhengdian",
           "south" : __DIR__"mingdedian",
           "northwest" : __DIR__"chongwenguan"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}