// D:\xkx\d\liuxiu-shanzhuang\shulin.c树林
// labaz  2012/10/20.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "树林");
    set("long", @LONG
你到了一片鸟鸣清啾的树林。林子里树木丛生，绿荫如茂，阳光却
还是从树枝树叶的空隙间射下，纵在白昼，地上也如繁星点点。
一阵风吹来，枝杈里藏着的鸟儿一下子全冒出来，欢叫着争相飞上
了天空。你向林子深处望去，有些麋鹿和兔子穿梭其间，好不欢快！
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
        "east" : __DIR__"weiminggu",
         ])
     );

	set("objects", ([
		__DIR__"npc/animal" : 2,
	]));

    setup();
}

void init()
{
	object me;
	me=this_player();
	
	if (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷"))
	{
		me->set_temp("newbie/shulin",1);
	}
	add_action("show_quest", "quest");
}

