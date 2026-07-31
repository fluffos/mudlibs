
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"岩盘的裂目"NOR);
	set("long", HIY @LONG
    你现在在一个黑暗潮湿的洞穴里，不过奇怪的是虽然这里弥漫著很重
的湿气，墙壁上却是一点青苔也没有。处於这个阴森森的洞穴里，你不由
得打了个机伶伶的冷战 .... 你觉得还是赶快离开这个鬼地方比较好。
LONG NOR);
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong3"+(random(6)+4),
                "east" : __DIR__"dong4"+(random(3)+3),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(3)+3),
                "east" : __DIR__"dong3"+(random(6)+4),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong4"+(random(3)+1),
                "west" : __DIR__"dong4"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev2" : 3,
              __DIR__"npc/lev5" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

