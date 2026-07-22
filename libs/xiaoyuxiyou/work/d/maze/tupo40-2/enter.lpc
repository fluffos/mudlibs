#include <ansi.h>
inherit ROOM; 

void create() 
{ 
        set("short", "遗迹入口"); 
        set("long", @LONG 
到处郁郁葱葱，无数长藤与并不算粗大的树木纠缠成浓浓的一团。就那么乱七八糟的生长着。
LONG); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_fight",1);    
        set("exits", ([
                "east" : __DIR__"maze/entry", 
                "down": "/d/moon/tree2",
        ])); 
        setup();
} 