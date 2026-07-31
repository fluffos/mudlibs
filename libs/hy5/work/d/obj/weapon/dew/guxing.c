    //一意孤行
    //by dewbaby@sk

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
       set_name(HIW"一意孤行"NOR, ({"yiyi sword","yiyi","sword"}));
       set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
       else {
          set("unit","柄");
          set("value","1200");
          set("material","silver");
          set("long",HIW"这是镇远大仙的护身宝剑，已随他飘荡多年。它散发出隐隐白光，甚是神秘！\n"NOR);
          set("wield_msg",HIW"$N默念心诀，只见$n"HIW"从天而降，落入$N手中!\n"NOR);
          set("unwield_msg",HIW"$N默念心诀，$n"HIW"顿时消失得无影无踪!\n"NOR);
          set("no_sell","你大脑有问题吧? 这东西你也敢卖? \n");
          set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
  }
     init_sword(830);
     setup();
  }
/*
      mixed hit_ob(object me, object victim)   
{
               int damage_bonus = 0;   

             if( (string)me->query("family/family_name") == "五庄观"   
                             && me->query_skill("sanqing-jian",1) > 1)   
                     damage_bonus = me->query_skill("sanqing-jian",1);   
                     damage_bonus = (damage_bonus+random(damage_bonus))/2;   

                       victim->receive_wound("qi",damage_bonus);   
                     return HIR"一意孤行上隐现出一丝丝血红! \n" NOR;   
   }
*/
