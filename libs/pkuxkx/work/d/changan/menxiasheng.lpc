
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "门下内省");
        set("long", @LONG
这是门下省在内廷办公的场所，以备随时接受皇帝咨询和签署政令。
LONG    );
        
        set("exits", ([
           "west" : __DIR__"taijimen",
           "southeast" : __DIR__"tongxunmen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}