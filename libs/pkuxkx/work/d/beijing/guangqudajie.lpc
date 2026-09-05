// Room: /d/beijing/east/guangqudajie.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([
	  "north" : __DIR__"chongwendajie2",
	  "northwest" : __DIR__"tiantan/xiaohutong3",
	]));
    }else{
	set("exits", ([
	  "south" : __DIR__"zuoanmen",
	  "north" : __DIR__"chongwendajie2",
	  "northwest" : __DIR__"tiantan/xiaohutong3",
	  "east"  : __DIR__"guangqumen",
	]));
    }
}

void create()
{
	set("short", HIC"广渠门大街"NOR);
	set("long",
CYN"这是繁华热闹的广渠门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
	fix_exits_for_night(0);
	set("outdoors","beijing");
	set("cost", 2);
	set("exits", ([ /* sizeof() == 5 */
//  "northeast" : __DIR__"dongbianmen",
//  "west" : "/d/beijing/west/dongtianmen",
  "north" : __DIR__"chongwendajie2",
  "south" : __DIR__"zuoanmen",
  "east" : __DIR__"guangqumen",
  "northwest" : __DIR__"tiantan/xiaohutong3",
]));

	setup();
}
string GATE_OUT_DIR1 = "south";
string GATE_OUT_DIR2 = "east";
#include "gate.h"
