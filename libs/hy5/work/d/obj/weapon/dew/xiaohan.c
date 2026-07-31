    //晓寒三更
    //by dewbaby@sk


#include <weapon.h>
#include <ansi.h>
//  inherit UNIQUE;

inherit STAFF;
void create()
{
       set_name(WHT"晓寒三更"NOR,({"xiaohan stick","xiaohan","stick","bang"}));
       set_weight(20000);
    if( clonep() )
          set_default_object(__FILE__);
       else {
    set("long",WHT"一把象牙白的玉棒，一看就知相当不寻常。它闪闪发亮，素中鲜艳，晶莹透亮。\n"NOR);
       set("unit","根");
       set("value",12000);
       set("wield_msg",WHT"$N一个转身，左手一挥，只见$n"WHT"已被$N握在手中。\n"NOR);
       set("unwield_msg",WHT"$N默念心诀，晓寒三更化为一缕晨雾，从手中消失了。\n"NOR);
    set("do_put",1);

      set("weapon_prop/courage", 20); 
     }
       init_staff(130);
       setup();
}
/*
    mixed hit_ob(object me, object victim) 
{

         int damage_bonus = 0; 

          if( (string)me->query("family/family_name") == "方寸山三星洞" 
           && me->query_skill("qianjun-bang",1) > 1) 
      damage_bonus = me->query_skill("qianjun-bang",1); 
       damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("qi",damage_bonus); 
    return HIW"晓寒三更上散发出刺骨寒意! \n" NOR; 

}
*/
