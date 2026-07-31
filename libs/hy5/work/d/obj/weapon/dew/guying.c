    //落漠孤影
    //by dewbaby@sk

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
       set_name(WHT"落漠孤影"NOR,({"guying sword","guying","sword"}));
        set_weight(20000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
            set("unit","柄");
            set("value",1200);
            set("material","silver");
            set("long",WHT"一柄散发着丝丝杀气的天界宝剑。此乃三界山的震山之宝。\n"NOR);
            set("wield_msg",WHT"$N右手一挥，只见一个灰影“嗖”的一声从天边坠入$N手中。\n"NOR);
            set("unwield_msg",WHT"$N微闭双眼，昂首傲然地注视着四周。$n"WHT"却早已化为一团缥缈轻烟消失不见!\n"NOR);
            set("no_sell","你大脑有问题吧? 这东西你也敢卖? \n"NOR);
            set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"NOR);
            set("weapon_prop/courage",20);
     }
       init_sword(830);
       setup();
   }
/*
mixed hit_ob(object me, object victim)  
{
         int damage_bonus = 0;  

        if( (string)me->query("family/family_name") == "三界山"  
                       && me->query_skill("huxiaojian",1) > 1)  
                damage_bonus = me->query_skill("huxiaojian",1);  
                damage_bonus = (damage_bonus+random(damage_bonus))/2;  

                 victim->receive_wound("qi",damage_bonus);  
                return HIB"落漠孤影形如鬼魅，在风中嗖嗖作响! \n" NOR;  
        }
*/
