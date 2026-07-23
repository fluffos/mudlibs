// 腐尸毒
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        
       object co,weapon;
        /* i, j;
        i = me->query_skill("xuantian-strike", 1);
        j = me->query_skill("strike")/2;*/

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「腐尸毒」只能在战斗中对对手使用。\n");
weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须空手才能使用这个绝技！\n");		

        if( (int)me->query_skill("xuantian-strike", 1) < 220 )
                return notify_fail("你的玄天冰蚕掌还不够娴熟，使不出「腐尸毒」绝技。\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("你的化功大法修为不够，不能使用「腐尸毒」。\n");
        if((int)me->query_skill("poison",1)<120)
           return notify_fail("你积毒不够无法使用腐尸毒。\n"); 
           co=present("corpse",me);       
        if (!co)
        return notify_fail("你身上没有尸体，如何使用腐尸毒!\n");

                                                                         

        if( (int)me->query("max_neili") < 1000) 
                return notify_fail("你内力太弱，使不出「腐尸毒」。\n");      

        if( (int)me->query("neili") < 300)
                return notify_fail("你现在真气太弱，使不出「腐尸毒」。\n");
       message_vision(BLU"\n$N一声阴笑，右手突出，挟起一具尸体掷出，一股死鱼烂肉的臭气弥漫四周，闻者欲呕！\n"NOR,me);
       call_out("destroying", 1, co);
//         if (!target->is_killing(me))
//me->kill_ob(target);
//       target->kill_ob(me);
       me->add("neili", -250);
       if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/5*3&&
            me->query_str() > (int)target->query_str()/3*2) 
      { 
       message_vision(HIB"\n$n见此怪异的招数，手足无措，躲闪无及，只见散发着恶臭的尸体，正击在自己身上。\n"NOR, me, target);
       target->set_temp("last_damage_from", "腐尸毒入脑");
       target->unconcious();
       return 1;  
        }
        else if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4&&
          me->query_str() > (int)target->query_str()/2) 
        {
          message_vision(HIB"\n$n 见事不好，连忙纵身直起，腐尸从身下掠过，没有打中。\n"NOR,me,target);
          tell_object(target,HIB"\n 你虽然及时避开了毒尸，但一股腥臭气入鼻，你已中了剧毒了。\n"NOR);
// no condition fs_poison, change to xx_poison (by xbd)
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
target->apply_condition("fire_poison",60);

          target->apply_condition("xx_poison", random(100) + 
           (me->query_skill("poison", 1)/10) +
           target->query_condition("xx_poison"));
         me->start_busy(5);
        target->start_busy(1);
        return 1;
      }
       message_vision(HIB"\n$n 胸有成竹，一声长啸，双掌连环劈出，把毒尸毒气荡向来路。\n"NOR,me,target);
       tell_object(me,HIB"\n 不好，毒尸反弹向你,你虽然躲开，但毒气也侵入你的身体。\n"NOR);
// no condition fs_poison, change to xx_poison (by xbd)
                 me->apply_condition("xx_poison", random(3) + 
           (me->query_skill("poison", 1)/10) +
           me->query_condition("xx_poison"));
       return 1;
 }          

void destroying(object obj)
{
        destruct(obj);
        return;
}
  
