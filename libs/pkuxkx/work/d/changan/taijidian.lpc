
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太极殿");
        set("long", @LONG
这是巍峨高耸的太极殿，为朔望两日皇帝会见群臣，视朝听政的场所，
每逢国家大典也在这里举行。北面就是皇帝寝宫和嫔妃居住的宫殿。
LONG        );
        
        set("exits", ([
                "southdown" : __DIR__"taijimen",
                "northdown" : __DIR__"liangyimen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}