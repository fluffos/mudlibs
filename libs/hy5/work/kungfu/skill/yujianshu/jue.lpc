//by dewbaby@sk_sjsh
//九剑·情绝


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
                int damage,p;
        string msg,dodge_skill;
        weapon = me->query_temp("weapon");
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("请使用磐石神功!\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("你的磐石神功还不够。。。\n"); 


        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出「情绝」。\n");
        if ( (int)me->query("neili") < 900)
                return notify_fail("你的真气不够，无法施展出「情绝」。\n");
        if ((int)me->query("qi") < 900)
                return notify_fail("你的气血不够，无法施展出「情绝」。\n");


     
        lvl = me->query_skill("yujianshu", 1);
        if(lvl < 250)
                return notify_fail("你的这门武功还不够。。。\n"); 


     message_vision(WHT"$N神情轻蔑地看着$n。\n\n"NOR,me,target);
     message_vision(WHT"$N凝神定气，突然手中"+ weapon->name() +HIY"化为九道金色剑气朝$n射去！\n"NOR,me, target);
 
        me->add("neili", -(200 +random(100)) );
        me->add("qi", -50);
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2000);

        message_vision(HIY"$N身形如风，手中剑气影射不断！\n"NOR,me,target);
msg=WHT"$n"+WHT"被被迎面而来的剑气逼得连连后退，似乎颇为吃力。\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"一剑                  "+BLINK+HIC+"泪洒西厢月\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"二剑             "+BLINK+WHT+"迢迢银汉隔\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"三剑             "+BLINK+HIB+"囚来高塔倾\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"四剑             "+BLINK+HIW+"哭到长城裂\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"五剑             "+BLINK+BLU+"百宝影无寻\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"六剑             "+BLINK+HIR+"红楼梦难歇\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"七剑             "+BLINK+HIC+"不如抛此情\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"八剑             "+BLINK+HIM+"去做花间蝶\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"九剑             "+BLINK+WHT+"情绝情难了\n"NOR;
                  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
        
if ((int)me->query_skill("yujianshu",1)>=380)
{
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动幻作漫天飞雪卷向$n。\n"NOR,me,target);
 message_vision(HIC"\n$N同时使出风回雪舞剑的前三招，在半空中压向$n。\n"NOR,me,target);
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("yujianshu",1);  
            //damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*2);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
		


if ((int)me->query_skill("yujianshu",1)>=480)
{
 message_vision(HIC"\n$N身体斜斜向上飘出，也不回头，反手就刺出了两招。\n"NOR,me);	
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 200+(int)me->query_skill("yujianshu",1);  
            //damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*2);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
		
}

if ((int)me->query_skill("yujianshu",1)>=680)
{
 message_vision(HIC"\n$N斜斜一再个翻身，长剑幻作千百支冰箭，夹着一股寒风扑向$n。\n"NOR,me,target);
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 300+(int)me->query_skill("yujianshu",1);  
           // damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*3);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
	
}
}	

        me->start_busy(5);
        return 1;
}


