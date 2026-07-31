    //xueqin.c
    //by dewbaby

#include <weapon.h>
#include <ansi.h>
       inherit SWORD; 

       void create() 
       { 
          set_name(HIW"雪琴三笑"NOR,({"xue qin","xueqin"})); 
           set_weight(4000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","柄"); 
                      set("value",4000); 
                      set("no_drop","1");
                      set("no_sell","1"); 
                      set("material","silver"); 
                      set("long",HIW"据说这是大雪山神的神器，它通体若雪般洁白，散发着冷冷光芒。"NOR); 
                     set("wield_msg",HIW"$N淡淡一笑，$n"HIW"已经被$N握在手中，四周顿时冰雪纷飞。\n"NOR); 
                      set("unwield_msg",HIW"$N双眼微闭，眨眼间已将$n"HIW"插回腰间。\n"NOR); 
                      set("no_drop","还是不要丢吧，小心大雪山神要了你的小命！\n"); 

                set("weapon_prop/courage", 20); 
                    } 
          init_sword(830); 
           setup(); 
      } 
/*
    mixed hit_ob(object me, object victim)  
    {
       int damage_bonus = 0;  

       if( (string)me->query("family/family_name") == "大雪山"  
                           && me->query_skill("bainiao-jian",1) > 1)  
       damage_bonus = me->query_skill("bainiao-jian",1);  
       damage_bonus = (damage_bonus+random(damage_bonus))/2;  

       victim->receive_wound("qi",damage_bonus);  
       return HIW"雪琴三笑顿时散发出阵阵寒雪之光! \n" NOR;  
    }
*/
