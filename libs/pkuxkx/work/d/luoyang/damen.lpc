//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", RED"王家大门"NOR);
        set("long", 
        "这里是金刀无敌王元霸的家。王元霸富甲一方，在洛阳可否如雷贯耳。
从门口看过去，但见房舍高大，朱红漆的大门，门上两个大铜环，擦得晶光雪亮。
八名壮汉垂手在大门外侍候。
门头上高悬一块黑匾："+RED"\n\n\n\t\t金  刀  王  府"NOR+"\n\n \n"
        );
        set("outdoors", "luoyang");
        set("exits", ([
                "south" : __DIR__"xidajie2",
                "north" : __DIR__"menlang",
                ]));
          set("objects", ([
                   __DIR__"npc/guanjia" : 1,
           ]));
   setup();
}

int valid_leave(object me, string dir)
{
    object ob = present("guan jia", environment(me));  
        if ( objectp(ob) && living(ob) && dir == "north")
                return notify_fail("管家挡住了你：我们家老爷不在家。\n");
        return ::valid_leave(me, dir);
}

