#include <ansi.h>
inherit ROOM;
#include "/d/family-private/hall.h";

void create()
{
	set("short", "石厅");
	set("long",  "这里是一处石头砌成的大厅，一台大石桌(desk)，东南西北分别通向四个房\n间。这里可以查询(query)整个闭关区域的状况，也可以转换(convert)门派贡献\n度到闭关加成时间。\n");
    set("exits", ([
                "up" : __DIR__"shimen",
                "north": __DIR__"dazuo",
                "south": __DIR__"lian",
                "east" : __DIR__"xiulian",
                "west" : __DIR__"lingwu",
        ]));
    set("item_desc", ([
        "desk" : "桌上放了很多新鲜果蔬已经几坛清水，你可以随意吃(eat)一点，喝(drink)一些。\n",
	]));
    set("family_private_area",1);
    set("no_task", 1);
    setup();
}

