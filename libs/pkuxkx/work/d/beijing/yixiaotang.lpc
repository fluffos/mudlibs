// /d/beijing/yixiaotang
// Room:一笑堂
// vast 2003.2
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"一笑堂"NOR);
        set("long",
CYN"这是京城老字号药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百
个小抽屉里散发出来的。一位大夫坐在八仙桌旁，据说他就是著名的神医喜
来乐，皇宫的御医也比不上他。一名胖胖小伙计站在柜台后招呼着顾客。柜
台上贴着一张广告(guanggao)。\n"NOR
        );
        set("item_desc", ([
			   "guanggao" : "本店出售药品，并诊治伤病人。\n",
        ]));

        set("objects", ([
			 __DIR__"npc/xilaile" : 1,
			 __DIR__"npc/hcthuoji" : 1,
        ]));

        set("exits", ([
		       "east" : __DIR__"fuchengdajie_s",
        ]));

        setup();
        replace_program(ROOM);
}
