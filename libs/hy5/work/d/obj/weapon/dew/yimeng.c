    //一梦浮生
    //by dewbaby@sk


#include <weapon.h>
//  inherit UNIQUE;

#include <ansi.h>
inherit SPEAR;

void create()
{
       set_name(HIW"一梦浮生"NOR,({"fusheng spear","fusheng","spear"}));
       set_weight(20000);
     if( clonep() )
     set_default_object(__FILE__);
    else{
       set("unit","杆");
       set("value",12000);
       set("material","silver");
       set("long",HIW"这是黄飞虎的随身神枪，已跟随他多年。\n"NOR);
       set("wield_msg",HIW"一阵狂风卷过，$n"HIW"已被$N牢牢握在手中!\n"NOR);
        set("unwield_msg",HIW"不知道什么时候，$n"HIW"已悄然消失了。$N似笑非笑地看着四周。\n"NOR);
       set("no_sell","你大脑有问题吧? 这东西你也敢卖? \n");
       set("no_drop","去垃圾堆丢吧, 乱扔会污染环境! \n");
  }
    init_spear(130);
    setup();
  }
/*
    mixed hit_ob(object me, object victim)    
  {
    int damage_bonus = 0;    

     if( (string)me->query("family/family_name") == "火云洞"    
             && me->query_skill("wuyue-spear",1) > 1) 
       damage_bonus = me->query_skill("wuyue-spear",1);    
     damage_bonus = (damage_bonus+random(damage_bonus))/2;    

       victim->receive_wound("qi",damage_bonus);    
       return HIG"一梦浮生在狂风中发出震耳之音! \n" NOR;    

}
*/
