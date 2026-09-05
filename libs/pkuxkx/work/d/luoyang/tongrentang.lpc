//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"同仁堂"NOR);
        set("long", @LONG
这是一家老字号的药店。未入此处，清新的药香已沁人心裨。店中有
各种名药，玲琅满目，不乏珍奇异种。有些有起死回生的功效。药店中的
摆设也十分考究，桌椅被勤快的伙计擦的干干净净。墙上挂满了别人送来
的谢匾。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "east" : __DIR__"nandajie2", 
               "west" : __DIR__"yanhuapu", 
        ]));
        set("objects", ([
                __DIR__"npc/yaopuhuoji" : 1,
//                __DIR__"npc/yaopuhuoji" : 4,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
