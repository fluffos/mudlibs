// xiaowu2.c 蜂屋
// Java Oct.10 1998
#include <ansi.h>
inherit ROOM;
int do_zhujia();
#include "/quest/givegift.c"
void create()
{
        set("short", "蜂屋");
        set("long", @LONG
这里是小龙女喂养训练玉蜂的蜂屋，屋角上挂着很多个六角形的
蜂巢，还未进门，就闻得到一阵蜂蜜的甜香。你似乎可以做玉蜂浆
(zuofengjiang)
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaoting",
                "east" : __DIR__"xiaowu3",
        ]));

        set("objects", ([
                __DIR__"obj/fengjiang" : 3,
                __DIR__"obj/fengmi" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_zhujia","zuofengjiang"); 
}

int do_zhujia()
{
        object ob,me,ob1;
        int b1,b2,exp;
        me=this_player();
        
        if (!(ob = present(me->query("id")+" yufeng", this_player())) )
                return notify_fail("你身上没有采蜜玉蜂，如何做玉蜂浆？\n");

        if( me->query("family/family_name") != "古墓派")
           return notify_fail("你不是古墓派的人啊!\n");

        if (!me->query_temp("gmjob"))
           return notify_fail("你还是先去和小龙女打个招呼吧。\n");
                 
        if ( (int)me->query("jing")<30)
                return notify_fail("你的精力不足，无法做玉蜂浆。\n");


if (me->query("combat_exp") >1000000)
{
        if ( me->query_temp("gumukill") )
        {
                return notify_fail("不是告诉你林中有黑衣女子吗？
                去查一查她在干什么吧！\n");
        }
}
        if( me->is_busy() )
                return notify_fail("你现在很忙！不能做玉蜂浆！\n");

        if ( (int)me->query("qi")<30)
                return notify_fail("你的体力不足，无法做玉蜂浆。\n");

  message_vision("$N从采蜜玉蜂身上,慢慢的做出玉蜂浆。\n",me);
me->start_busy(1);
      me->add("jing",-(10+random(10)));
      me->add_temp("gmzyf",1);
  if ( (int)me->query_temp("gmzyf")>(random(13)+8))
 {
        if (!(ob = present(me->query("id")+" yufeng", this_player())) )
                return notify_fail("你身上没有采蜜玉蜂，如何做玉蜂浆？\n");
  message_vision(CYN"$N做了良久，终于将做出了一瓶玉蜂浆。\n"NOR,me);
b1=random(30)+60;
b2=random(50)+40;
me->add("jing",-(me->query("jing")/12));
exp=b1;
exp=exp/2+8;
addnl(me,"exp",exp);
me->delete_temp("gmzyf");
me->delete_temp("gmjob");
destruct(ob);
}
      return 1;
} 
