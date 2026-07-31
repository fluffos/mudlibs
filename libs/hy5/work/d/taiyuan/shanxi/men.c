#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "庄门"); 
        set("long", @long
庄门就庄门，就等於荷花就是荷花，而不是桃花或者兰花。越是宏伟
的庄园，庄门就越是简单。黑木铜环，汉玉狮子，金漆牌匾。唯一不同的
是，门内用於照明的，既非火折，亦非松油，而是大如龙眼的明珠。明珠
就随随便便地放在那里，彷如砖瓦。

long); 
       // set("type","waterbody");
        set("exits",([
                
                "south":__DIR__"shulin",
                "north":__DIR__"yuan1",
        ]) );
        set("objects",([
                __DIR__"npc/xiaofan":1,
        ]) ); 

       set("indoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-380);
        set("coor/z",100);
        setup();
} 