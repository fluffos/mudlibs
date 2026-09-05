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
    set("long", HIM @LONG

    这是一间石室，东面是块打磨光滑的大"石壁"，石壁旁点
燃着八根大火把，照耀明亮。壁上刻得有图有字。三个劲装老
者展开正在冥思苦想。

　　┌─────────────────────┐
　　│                                          │
　  │　                                        │
　　│            银  鞍  照  白  马            │
　　│                                          │
　　│                                          │
    └─────────────────────┚


LONG NOR
    );

    set("exits", ([
        "east"  : __DIR__"shishi2",
        "west"   : __DIR__"shishi4",
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
    me->set_temp("石壁3/看",1);
    return HIB"壁上所刻的似乎是一套基本戟法。\n"NOR;
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

   if ( ! me->query_temp("石壁3/看") )
        return 0;
   if(!arg || (sscanf(arg, "%s %d",shibi,times) < 1 ))
   {
		return notify_fail("指令格式：watch 石壁 [次数]\n");
   }
   if (shibi != "石壁")
   	return notify_fail("你要看什么？\n");
   return canwu(me,"halberd","你看得片刻，渐有所悟。\n",times);
}
