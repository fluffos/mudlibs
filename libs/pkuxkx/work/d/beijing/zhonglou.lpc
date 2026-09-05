// Room: /d/beijing/zhonglou.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "up" : __DIR__"zhonglou2",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "north" : __DIR__"andingmen",
	  "up" : __DIR__"zhonglou2",
	]));
    }
}

void create()
{
	set("short", HIC"钟楼"NOR);
	set("long",
CYN"北京城钟楼高九丈有余，完全砖石结构，建于元朝至元年
间。钟楼上的大铜钟一到定更天，就会打两番一百零八下钟声，
据说还有一个“铸钟娘娘”的凄凉传说。\n"NOR
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");

	setup();
}
string GATE_OUT_DIR1 = "north";
string GATE_OUT_DIR2 = "";
#include "gate.h"
