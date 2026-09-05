#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        if((int) me->query_skill("jiuyin-zhengong", 1) < 220)
             return notify_fail("你只能通过研读九阴真经来提高九阴真功。\n");

        if ((int)me->query_skill("jiuyin-zhengong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("jiuyin-zhengong", 1) >= 220 )
             return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

       if ((int)me->query_skill("jiuyin-zhengong", 1) + 10 > me->query_skill("daode-jing", 1)
          && me->query_skill("daode-jing", 1) < 120)
               return notify_fail("你的道德经不够，不能继续修习九阴真功。\n");

        return 1;
}

int practice_skill(object me)
{
       if((int)me->query_skill("jiuyin-zhengong", 1) >= 220 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("jiuyin-zhengong", (int)me->query_int());
                   me->add("neili", -50); 
                   me->add("potential", -1*(1+random(2)));
                   return 1;
           }
        else return notify_fail("你现在的修为不足以提高九阴真功了。\n");       }
        else return notify_fail("你现在的九阴真功修为只能研读(study)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return SKILL_D("jiuyin-zhengong/") + func;
}

void skill_improved(object me)
{
      if( me->query_skill("jiuyin-zhengong",1) > 0
        && !me->query("jiuyin/bonus")){
         tell_object(me, "你的九阴真功增加了你的内力修为！\n");
         me->set("jiuyin/bonus", 1);
         me->add("max_neili", 10); 
      }
      if( me->query_skill("jiuyin-zhengong",1) >= 100
       && me->query("jiuyin/bonus") < 2 ){
        tell_object(me, "你的九阴真功增加了你的内力修为！\n");
        me->add("jiuyin/bonus", 1);
        me->add("max_neili", 100);
      }
      if( me->query_skill("jiuyin-zhengong",1) >= 220
       && me->query("jiuyin/bonus") < 3 ) {
        tell_object(me, "你的九阴真功增加了你的内力修为！\n");
        me->add("jiuyin/bonus", 1);
        me->add("max_neili", 200); 
      }
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : HIC + me->name() + "双眼微闭，被一股九阴真气围绕著。" NOR,
                "start_my_msg" : "你盘腿坐下，双目微闭，双手掌心相向成虚握太极，天人合一，练气入虚。\n",
                "start_other_msg" : me->name() + "盘腿坐下，双目微闭，双手掌心相向成虚握太极。轻风吹过，" + me->name() + "身上的衣袍竟然不为所动。\n",
                "end_my_msg" : "你将内息又运了一个小周天，缓缓导入丹田，双臂一震，站了起来。\n",
                "end_other_msg" : me->name() + "的脸上陡然一暗，又立刻隐去。随即双臂一震，站了起来。\n"
        ]);
}

