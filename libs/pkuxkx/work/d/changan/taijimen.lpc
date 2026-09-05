
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太极门");
        set("long", @LONG
这是太极宫正殿太极殿的正门，两边是中书和门下两省内廷办公场所，
前面就是巍峨的太极殿。
LONG        );
        
        set("exits", ([
                "northup" : __DIR__"taijidian",
                "south" : __DIR__"chengtianmen",
                "west" : __DIR__"zhongshusheng",
                "east" : __DIR__"menxiasheng"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        set("outdoors", "changan");
        setup();   
}