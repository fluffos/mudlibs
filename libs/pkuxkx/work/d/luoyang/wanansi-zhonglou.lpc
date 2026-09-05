//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"钟楼"NOR);
        set("long", @LONG
一口大钟，占据了几乎整个楼层。据说是按照城东白马寺的大钟仿制的，
每日晨昏，钟鼓齐鸣，声传数十里，遥遥与白马寺的钟鼓声呼应。
LONG
			);

        set("exits", ([     
               "east" : __DIR__"wanansi-tianwangdian",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}