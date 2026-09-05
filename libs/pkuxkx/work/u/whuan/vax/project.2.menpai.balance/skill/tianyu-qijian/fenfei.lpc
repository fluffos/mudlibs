//天羽纷飞
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int sword,force,dodge,ini_damage_apply,times,damage;
   int sword_level;
        int delays;
        delays = time();
        
        sword = (int)me->query_skill("tianyu-qijian", 1);
        force = (int)me->query_skill("bahuang-gong", 1);
        dodge = (int)me->query_skill("yueying-wubu", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIR"天羽纷飞要对战斗中的对手使用！\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIR"天羽纷飞只能在战斗中使用！\n"NOR);
          if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("skill_type") != "sword")
          if (!objectp(weapon = me->query_temp("secondary_weapon"))
          || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("你没拿剑,还想使剑法的绝招?别作梦了!\n");
        
        sword_level=(int)(sword/50);
        if( sword < 180)
                return notify_fail(HIR"你的天羽奇剑级别还不够，使用这一招会有困难！\n"NOR);

        if(me->query("family/family_name") != "灵鹫宫")
                return notify_fail(HIR"天羽纷飞是灵鹫宫不传之密，你现在不是灵鹫宫弟子，不能使用这一招！\n"NOR);
        
        if( force < 180)
                return notify_fail(HIR"你的八荒六合唯我独尊功修为不够，使用这一招会有困难！\n"NOR);
        
        if( dodge < 180)
                return notify_fail("你的月影舞步级别还不够，使用这一招会有困难！\n");
 	if (me->query("neili")<300||me->query("max_neili")<300)
                return notify_fail("你的内力不够，无法施展「天羽纷飞」。");       

      // 暂时做一下修改，延迟好像太长了一些，chui
       if( (delays - me->query_temp("fenfei_end")) < 10 )
                return notify_fail("绝招用多就不灵了！\n");
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动，一招天羽纷飞，层层剑光卷向$n。\n"NOR,me,target);
        
	damage=1;
        //前三剑
        message_vision(HIC"\n$N同时使出两招天羽奇剑，在半空中压向$n。\n"NOR,me,target);
        
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",50);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        //if (damage < 1) {me->add_temp("apply/damage",50);}
        //        else    {me->set_temp("apply/damage",ini_damage_apply);}
        //damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //再三剑
          if( sword >= 240 && force >= 240 && dodge >= 240 )
            {
            	message_vision(HIC"\n$N一咬银牙，反手又刺出两招！\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                //if (damage < 1) {me->add_temp("apply/damage",100);}
                //    else    {me->set_temp("apply/damage",ini_damage_apply);}
                //damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              }
      
           //最后三剑
            if( sword >= 300 && force >= 300 && dodge >= 300 )
               {
               	    message_vision(HIC"\n$N一个翻身跃起半空，似乎全身化作一把长剑，滚滚两招刺向$n\n"NOR,me,target);
               	    
                 if (damage < 1) {me->add_temp("apply/damage",150);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                //if (damage < 1) {me->add_temp("apply/damage",150);}
                //    else    {me->set_temp("apply/damage",ini_damage_apply);}
                //damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                if (damage < 1) {me->add_temp("apply/damage",200);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
	               }
	                
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                      //  if( userp(target) ) target->fight_ob(me);
                     //   else target->kill_ob(me);
                }
        }

        me->set_temp("fenfei_end",time());
	me->set("neili",(me->query("neili")-300));
        return 1;
}

