//jiashan.c 假山

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIW"假山"NOR);
        set("long", @LONG
一座雕刻玲珑的假山，石缝中流出清凉的泉水，山的背面有一个小洞，里
面似乎隐藏着什么，由于附近终年潮湿，你小心翼翼的走在打滑的鹅卵石上。
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "west" : __DIR__"quqiao1",
        "east" : __DIR__"quqiao3",
        "north" : __DIR__"quqiao4",
        "south" : __DIR__"quqiao2",

        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "试剑山庄");

        setup();
}

