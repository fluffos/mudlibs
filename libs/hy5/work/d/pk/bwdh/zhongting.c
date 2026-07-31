//zhongting 中厅

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"中厅"NOR);
        set("long", @LONG
这是一个小巧而精致的楼房，楼下布置的象个小客厅兼书房。房中间是
一个小红木八仙桌，旁边摆了四把椅子，靠窗是一张书桌，上面摆满了笔墨
砚台，书桌角上放了几本书。书桌旁边是一书架，架上摆满了各式各样的书。
站在书桌前向窗外望去，你可以看到窗外的芭蕉和池塘的一角。
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([        
        "west" : __DIR__"caodi3",
        "east" : __DIR__"caodi4",
        "north" : __DIR__"zoulang2",
        "south" : __DIR__"quqiao4",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
     
        setup();
}

