// Room: /d/xiangyang/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "朱雀门外门");
	set("long", 
"这里是襄阳城的南城门的内城门，只见城门上方是三个大
字。"HIR"

                      朱雀门外门
\n"NOR
"近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵
们正在盘查要离襄阳城的人。两边是上城头的石阶，向北进入
城区。\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  :"quest/menpaijob/gaibang/guanka",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	setup();
	replace_program(ROOM);
}

