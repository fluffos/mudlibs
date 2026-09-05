
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "通训门");
        set("long", @LONG
这是东宫的西大门通训门，东面就是太极接见朝臣的大殿明德殿。
LONG    );
        
        set("exits", ([
           "northeast" : __DIR__"mingdedian",
           "northwest" : __DIR__"menxiasheng"
        ]));
        
        set("locate_level",2);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}