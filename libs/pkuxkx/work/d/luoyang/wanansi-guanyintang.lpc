//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"观音堂"NOR);
        set("long", @LONG
这里供奉着大慈大悲观世音菩萨。菩萨的金身为玉石打造，只见他相貌端庄，
眉目慈祥，手持净瓶杨柳，脚踏七彩莲座，仿佛正以无量智慧神通、大慈大悲，
普救人间疾苦。几个百姓正在这里祷告。
LONG
			);

        set("exits", ([     
			"east" : __DIR__"wanansi-daxiongbaodian",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}