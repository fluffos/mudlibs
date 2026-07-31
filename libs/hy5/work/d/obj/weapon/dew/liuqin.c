//六亲不认
//by dewbaby@sk

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SPEAR;
#include <ansi.h>
void create()
{
       set_name(HIB"六亲不认"NOR, ({"liuqin qiang","liuqin","qiang"}));
       set_weight(20000);
if( clonep() )
              set_default_object(__FILE__); 
        else { 
      set("long",HIB"白发老人随身携带它多年，他总是想也许该把它传给一个忠实的徒弟。可惜...\n"NOR);
              set("unit", "根"); 
                set("value", 12000);
            set("wield_msg",HIB "$N轻轻一笑，神情傲然地将$n"HIB"握在手中。\n"NOR); 
              set("unwield_msg",HIB "眨眼间，$n"HIB"已经在$N的手中悄然消失了!\n"NOR); 
           set("no_sell","你大脑有问题吧？这东西你都敢卖？\n");  
              set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");  

              set("weapon_prop/courage", 20); 
}
            init_spear(130); 
              setup(); 
}
/*
mixed hit_ob(object me, object victim) 
{
    int damage_bonus = 0; 

       if( (string)me->query("family/family_name") == "将军府" 
                     && me->query_skill("bawang-qiang",1) > 1) 
    damage_bonus = me->query_skill("bawang-qiang",1); 
     damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("qi",damage_bonus);
     return HIB"六亲不认抖然一震，散发出阵阵幽明之气!\n" NOR; 

}
*/
