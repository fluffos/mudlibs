       //长眠万年
       //by dewbaby@sk


#include <ansi.h> 
#include <weapon.h> 
inherit STAFF;

void create() 
{
          set_name(WHT"长眠万年"NOR,({"long staff","staff","long"})); 
           set_weight(20000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","条"); 
                      set("value",1200); 
                      set("material","gold"); 
                      set("long",WHT"一条看似笨重的禅杖，它周身闪耀着暗灰的光芒。\n"NOR); 
                 set("wield_msg",WHT"$N随手一挥，$n"WHT"刹那间出现在$N手中。\n"NOR); 
                      set("unwield_msg",WHT"$N双眼微闭，转眼间$n"WHT"已消失不见。\n"NOR); 
                      set("no_sell","你大脑有问题吧？这东西你都敢卖？\n");  
                      set("weapon_prop/courage",30);
                    } 
          init_staff(130); 
           setup(); 
      } 
/*
             mixed hit_ob(object me, object victim)  
     {
                   int damage_bonus = 0;
                   if( (string)me->query("family/family_name") =="南海普陀山"
                              && me->query_skill("lunhui-zhang",1) > 1)  
                   damage_bonus = me->query_skill("lunhui-zhang",1);  
                   damage_bonus = (damage_bonus+random(damage_bonus))/2;  

                   victim->receive_wound("qi",damage_bonus);  
                   return WHT"长眠万年突然间发出声声震耳之音!\n" NOR;
     }
*/
