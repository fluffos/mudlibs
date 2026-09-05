//tanzhi.c
//write by lysh
#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{       int taohua,force;
        object ob;
        string msg;
       
	me->this_player();  
          if (me->is_busy())
                return notify_fail("你正忙着呢!\n");
	   if( !target ) target = offensive_target(me); 
   if(me->query_skill("tanzhi-shentong",1)<80||me->query_skill("luoying-zhang",1)<80)
        return notify_fail("你的桃花岛功夫的功力不够、\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「弹指神通』能对战斗中的对手使用。\n");  
                 if (me->query("neili")<100) return notify_fail("你的内力不够,无法使用「弹指神通』。\n");
                 me->add("neili",-75);
                taohua=me->query_skill("taohua-force",1);
                force = target->query_skill("force",1); 
                	        if(!objectp(ob=target->query_temp("weapon")) )
      {if(random(taohua*2)>force)
                   //空手成功了
                   {target->start_busy(2);
                    message_vision(CYN "$N使出「弹指神通」,向$n弹去,$n浑身一麻n" NOR,me,target);            
                   
                    return 1;
                    }  
                    else
                    //空手失败了
                    {message_vision(CYN "$N使出「弹指神通」,向$n弹去,$n轻轻一闪,躲开$N的攻势!\n" NOR,me,target);            
                    me->start_busy(1);
		    return 1;
	             } 
                    }
if(random(taohua)>force/2)
                  //对兵器成功了
		    {  ob = target->query_temp("weapon");
                      ob->unequip();
		      ob->move(environment(target));
                    message_vision(CYN "$N使出「弹指神通」,向$n的" NOR  +ob->name() + CYN "弹去! \n" NOR, me,target);
                    message_vision(CYN "$N只觉得手中" NOR + ob->name() + CYN "把持不定，脱手飞出！\n" NOR,target);
                    me->start_busy(1);
		    return 1;
                     }
                   else
	            {message_vision(CYN "$N使出「弹指神通」,向$n弹去,$n轻轻一闪,躲开$N的攻势!\n" NOR,me,target);            
                    me->start_busy(1);
		    return 1;
	            } 
       
}

