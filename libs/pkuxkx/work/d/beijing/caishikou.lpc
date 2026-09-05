// Room: /d/beijing/caishikou.c
#include <ansi.h>
inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", HIC"菜市口"NOR);
	set("long",
CYN"这里是朝廷处斩犯人示众的场所。路中央有一个断头台 (tai)，应该就是行
刑用的。不远处天桥的热闹还能隐约听到，与这里肃杀的气氛构成了鲜明的对比。\n"NOR
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);

	set("item_desc", ([
	"tai" : "一个血迹斑斑的木台子。\n",
]));
	set("outdoors", "beijing");
	set("cost", 2);
    set("objects", ([
        "/d/beijing/npc/captain_guangan2" : 1,
        ]));
	setup();
}


void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie2",
          "south" : __DIR__"youandajie",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie2",
	  "west"  : __DIR__"guanganmen",
	  "south" : __DIR__"youandajie",
	]));
    }
}

string GATE_OUT_DIR1 = "west";
string GATE_OUT_DIR2 = "";
#include "gate.h"
