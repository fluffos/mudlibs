// 侠客台
// for Xiake dao
// modified by aiai  98/10/27

#include <ansi.h>

inherit ROOM;
#include "shibi.h";
string look_shibi();
void create()
{
    set("short",HIC"俠客岛石室"NOR);
    set("long", HIY @LONG

    这是一间石室，东面是块打磨光滑的大"石壁"，石壁旁点
燃着八根大火把，照耀明亮。壁上刻得有图有字。石室中已有
十多人，有的注目凝思，有的打坐练功，有的闭着双目喃喃自
语，更有三四人在大声争辩。

　　┌─────────────────────┐
　　│                                          │
　  │　                                        │
　　│           白  首  太  玄  经             │
　　│                                          │
　　│                                          │
    └─────────────────────┚


LONG NOR
    );

    set("exits", ([
        "west"   : __DIR__"shishi1",
        "east"   : __DIR__"shishi23",
    ]));

    set("objects",([

    ]));
    set("no_sleep",1);
    set("item_desc", ([ /* sizeof() == 2 */

        "石壁" :        (: look_shibi : ),

]));
    setup();
}

string look_shibi()
{
    object me;
    me = this_player();
    me->set_temp("石壁24/看",1);
    return HIB"壁上绘的是个白须老者，手中拿着一本医书。\n"NOR;
}

void init()
{
        add_action("do_watch","watch");
}

int do_watch(string arg)
{

   object me;
   string shibi;
   int times;

   me = this_player();

   if ( ! me->query_temp("石壁24/看") )
        return 0;
   if(!arg || (sscanf(arg, "%s %d",shibi,times) < 1 ))
   {
		return notify_fail("指令格式：watch 石壁 [次数]\n");
   }
   if (shibi != "石壁")
   	return notify_fail("你要看什么？\n");
   return canwu(me,"medical-skill","你对着石壁研究了一会,似乎有些心得。\n",times);
}
