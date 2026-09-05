// Zine 2014/8/1
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"鸡笼山下"NOR);
        set("long", @LONG
这里是镇江府的城南的鸡笼山脚下，鸡笼山上据说出产很多不同矿石，但有
时官府会禁止平民进入。
LONG);
		set("old_long",query("long"));
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "north" : __DIR__"southgate",
])); 
		set("no_task",1);
		setup();
}
int valid_leave(object me,string dir)
{
	if (dir!="north"&&!userp(me)) return notify_fail("");
	return ::valid_leave(me,dir);
}