//王家大门
//whuan
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
                "south" : "/d/pker/shanlu1",
                "north" : __DIR__"wmenlang",
                ]));
          set("objects", ([
                   __DIR__"npc/guanjia" : 1,
           ]));
   setup();
}
