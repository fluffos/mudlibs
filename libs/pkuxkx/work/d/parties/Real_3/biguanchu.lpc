#include <ansi.h>
inherit F_SAVE;
inherit ROOM;
#include "/d/parties/public/hall.h";

void create()
{
    set("number",2);
    set("short", "大厅");
	set("long",  "这里是一座大厅，东侧坐着几个人，西侧放置着一张八仙桌(desk)和几把椅\n子，东南西北分别通向四个房间。这里可以查询(query) 整个宅子的状况，老学\n生也可以贡献(gongxian)黄金增加这里的发展程度。\n");
    set("exits", ([
                "north": __DIR__"dazuo",
                "southwest": __DIR__"lian",
                "southeast" : __DIR__"du",
                "west" : __DIR__"sleep",
                "east" : __DIR__"court",
        ]));
    set("item_desc", ([
        "desk" : "桌上放了很多新鲜果蔬已经几坛清水，你可以随意吃(eat)一点，喝(drink)一些。\n",
	]));
    set("no_reset",1);
    set("no_clean_up", 1);
    set("no_task", 1);
    setup();
    get_exit(query("number"));
}

