// Room: /d/beijing/xizhidajie.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "north" : __DIR__"jewelrystore",
	  "south" : __DIR__"fuchengdajie_n",
           "east" : __DIR__"guloudajie_w2",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "northwest" : __DIR__"deshengmen",
	  "west" : __DIR__"xizhimen",
	  "north" : __DIR__"jewelrystore",
	  "south" : __DIR__"fuchengdajie_n",
	  "east" : __DIR__"guloudajie_w2",
	]));
    }
}

void create()
{
	set("short", HIC"西直门大街"NOR);
	set("long",
CYN"这是一条十分宽阔的大街。人来人往，相当热闹。有几个小贩
正在沿街叫卖着什麽，偶有几个行人会停下来驻足问价。南面是阜
成门大街，西面则是西直门。\n"NOR
	);
	fix_exits_for_night(0);

	set("outdoors", "beijing");


	setup();
}
string GATE_OUT_DIR1 = "west";
string GATE_OUT_DIR2 = "northwest";
#include "gate.h"
