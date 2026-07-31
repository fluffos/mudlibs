    //xiao.c
    //dewbaby@sk


#include <ansi.h> 
#include <weapon.h> 
inherit F_UNIQUE; 
inherit SWORD; 

void create() 
{
          set_name(HIM"一笑倾情"NOR,({"qing sword","sword","qing"})); 
           set_weight(20000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","柄"); 
                      set("value",12000); 
                      set("material","silver"); 
                      set("long",HIM"这是蜀山剑仙心爱的宝剑，它周身散发着耀眼的光芒。\n"NOR); 
                 set("wield_msg",HIM"$N婉然一笑，$n"HIM"已经被$N握在手中。一片月光瞬间包围了$N。\n"NOR); 
                      set("unwield_msg",HIM"$N双眼微闭，眨眼间已将$n"HIM"插回腰间。\n"NOR); 
                      set("no_sell","你大脑有问题吧？这东西你都敢卖？\n");  
                      set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");  

                 set("weapon_prop/courage", 20); 
}
          init_sword(130); 
           setup(); 
}
/*
    mixed hit_ob(object me, object victim)  
    {
       int damage_bonus = 0;

       if( (string)me->query("family/family_name") == "蜀山派"
                            && me->query_skill("yujianshu",1) > 1) 
       damage_bonus = me->query_skill("yujianshu",1);
       damage_bonus = (damage_bonus+random(damage_bonus))/2;

       victim->receive_wound("qi",damage_bonus);
       return HIM"一笑倾情抖然一震，光芒四射! \n"NOR;
    }
*/
