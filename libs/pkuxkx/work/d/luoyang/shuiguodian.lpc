//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"唐记水果"NOR);
        set("long", @LONG
这间水果店地方不大，但却有着丰富的水果品种：如香蕉，苹果，橘
子，生梨，西瓜，荔枝等等，尤其是那荔枝，古语有诗云：“日啖荔枝三
百颗，不辞长做岭南人”。可见无论是当地居民还是来往游客都很喜欢光
顾这里。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
//               "east" : __DIR__"houyuan",  
               "east" : __DIR__"beidajie2",            
        ]));
        set("objects", ([
        __DIR__"npc/tanglaoban":1,
        ]));

//        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

