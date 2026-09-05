
// 侠客台
// for Xiake dao
// modified by aiai  98/10/27

#include <ansi.h>

inherit ROOM;
#include "shibi.h";
string look_shibi();

string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});



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
　　│           赵  客  缦  胡  缨             │
　　│                                          │
　　│                                          │
    └─────────────────────┚


LONG NOR
    );

    set("exits", ([
        "south"  : __DIR__"shimen",
        "west"   : __DIR__"shishi2",
        "east"   : __DIR__"shishi24",
        "north"   : __DIR__"shishi25",
    ]));

    set("objects",([
        __DIR__"npc/miaodi" : 1,
//                 "/d/shaolin/obj/qingshui-hulu" : 1,
//                 names[random(sizeof(names))]: 1,    
//                "/d/mingjiao/obj/gangdao" : 1,
    ]));
//     set("valid_startroom",1);
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
    me->set_temp("石壁1/看",1);
    return HIB"壁上绘的是个青年书生，左手执扇，右手飞掌，神态甚是优雅潇洒。\n"NOR;
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
   if ( ! me->query_temp("石壁1/看") )
        return 0;
   if(!arg || (sscanf(arg, "%s %d",shibi,times) < 1 ))
   {
		return notify_fail("指令格式：watch 石壁 [次数]\n");
   }
   if (shibi != "石壁")
   	return notify_fail("你要看什么？\n");

   return canwu(me,"strike","你看得片刻，渐有所悟。\n",times);
}


