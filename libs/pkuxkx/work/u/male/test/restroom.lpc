//竞技场休息室
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"竞技场休息室"NOR );
        set("long", HIY@LONG
    这就是竞技场后面的休息室，在这里你可以看到不停地有人
进进出出的将尸体从竞技场里抬出来，你隐隐约约得还可以听到
竞技场里搏击的声音，弱肉强食是这里永恒的旋律，多少人在这
里一夜成名，也有多少人在这里失去自己宝贵的生命。飞蛾扑火
有人认为是一种寻求光明的壮举，也有人认为是自不量力的惨淡
下场。在这里生与死、荣与辱也就在你的一念之间。
LONG NOR
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([ /* sizeof() == 1 */
          "down" : "/d/city/biwuchang",
        ]));
        set("no_clean_up", 0);
        setup();
}


void init()
{
        add_action("do_jifen","jifen");
        add_action("do_none","perform");
        add_action("do_none","yong");
        add_action("do_none","steal");
}
int do_none()
{
  return 1;
}
int do_jifen()
{
object me;
me=this_player();
if(!me->query_temp("jingji_exp"))
{
  write(HIB"你没有在竞技中获得任何奖励！\n"NOR);
return 1;
}
  write(HIB"你总共得到"+chinese_number(me->query_temp("jingji_exp"))+"点经验和"+chinese_number(me->query_temp("jingji_potential"))+"点潜能！\n"NOR);
  write(HIB"你下一场竞技将从第一场开始！\n"NOR);
me->add("combat_exp",me->query_temp("jingji_exp"));
me->add("potential",me->query_temp("jingji_potential"));
me->set_temp("jingji_exp",0);
me->set_temp("jingji_potential",0);
me->set_temp("xiangbo_level",0);
return 1;
}
