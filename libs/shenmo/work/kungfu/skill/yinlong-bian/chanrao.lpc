#include <ansi.h>

inherit F_SSERVER;

int check_fight(object me, object target, object weapon, int skill);
void remove_effect(object me, object target, object weapon, int skill);

int perform(object me, object target)
{
        string msg;
	int skill = me->query_skill("yinlong-bian", 1);
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("缠绕诀只能对战斗中的对手使用。\n");

        if(me->query_skill("yinlong-bian",1) < 100)
                return notify_fail("你的九阴银龙鞭还不够娴熟，不会使用缠绕诀。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return notify_fail("你现在无法使用缠绕诀。\n");

        if( me->query("neili") < 1500 )
                return notify_fail("你的内力不够。\n");

        if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

	msg = HIG "$N使出缠绕诀，鞭子一挥向$n的双腿卷去！\n";

        me->start_busy(random(2)+1);
        if((random(me->query("combat_exp")) > target->query("combat_exp")/3) 
          )
        {
		msg += HIY "结果$p被$P一卷，两条腿被结结实实的捆起来，在地上无法爬起。\n" NOR;
                target->start_busy(2);
		target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry", -skill/3);
		target->add_temp("apply/armor", -skill/3);
		me->set_temp("jiuyin/chan", 1);
	        me->start_perform(1, "缠绕诀");
		remove_call_out("check_fight");
	        call_out("check_fight", 1, me, target, weapon, skill);
		remove_call_out("remove_effect");
	        call_out("remove_effect", skill/20, me, target, weapon, skill);
        } 
        else {
                msg += HIW "可是$p看破了$P的缠绕诀，身子一跃便躲开了。\n" NOR;
	        me->start_perform(8, "缠绕诀");
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        me->add("neili", -1000);
        return 1;
}

int check_fight(object me, object target, object weapon, int skill)
{
        string msg;
        object wep;
	int neili, jiali;

        if (!me) return 1;
        if (!me->query_temp("jiuyin/chan")) return 1;

        if(!living(me) || !target){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "whip"){
           remove_effect(me, target, weapon, skill);
           return 1;
           } 
        if(environment(me) != environment(target)){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           
        if(wep != weapon){
           remove_effect(me, target, weapon, skill);
           return 1;
	   }
       if (userp(me) && me->query_skill_mapped("whip") != "yinlong-bian"){
           remove_effect(me, target, weapon, skill);
           return 1;
           }   
       if( me->query("neili") <= me->query_skill("yinlong-bian", 1)/2 ){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           

       target->start_busy(2);
       me->start_perform(3, "缠绕诀");
       if (!random(3) && me->query_skill("jiuyin-zhengong", 1) > 150) {
	   message_vision(HIB"$N趁着$n手忙脚乱之际，猛然攻出一招。\n"NOR, me, target);
	   me->add_temp("apply/attack", skill);
	   me->add_temp("apply/damage", skill*2);
	   neili = me->query("neili");
	   jiali = me->query("jiali");
	   me->set("jiali", me->query_skill("jiuyin-zhengong", 1));
	   weapon->unequip(); 
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	   weapon->wield();
	   me->set("jiali", jiali);
	   me->set("neili", neili-100);
	   me->add_temp("apply/attack", -skill);
	   me->add_temp("apply/damage", -skill*2);
       }
       call_out("check_fight", 1, me, target, weapon, skill);
       return 1;
}       

void remove_effect(object me, object target, object weapon, int skill)
{
	if (!me->query_temp("jiuyin/chan")) return;
        me->delete_temp("jiuyin/chan");
	if (!target) return;
	message_vision(HIW"$n双腿略一用劲，挣脱了"+weapon->name()+"的束缚，从地上爬了起来。\n"NOR, me, target);
	target->add_temp("apply/dodge", skill/3);
	target->add_temp("apply/parry", skill/3);
	target->add_temp("apply/armor", skill/3);
}
