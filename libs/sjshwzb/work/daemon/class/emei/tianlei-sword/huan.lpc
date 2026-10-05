#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
              object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("「"HIM"幻剑"NOR"」只能在战斗中使用！\n");

        if(!me->is_fighting())
                return notify_fail("「"HIM"幻剑"NOR"」只能对战斗中的对手使用。\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail(RED"你的内力修为不足，无法运足「幻剑」的内力。\n"NOR);


	if((int)me->query("force") < 500 )
                   return notify_fail(HIC"你现在内力不够，没能将「幻剑」使完！\n"NOR);

        if((int)me->query("sen") < 500 )
                return notify_fail(HIC"你的精神不足，没法子施用「幻剑」！\n"NOR);

        if((int)me->query_skill("tianlei-sword", 1) < 80)
                return notify_fail(HIM"你的天雷双剑不够娴熟，还使不出「幻剑」。\n"NOR);

        if((int)me->query_skill("emeiforce", 1) < 1)
                return notify_fail(HIW"你的峨嵋心法火候不够，「幻剑」不成招式。\n"NOR);

        if ((int)me->query_skill("jinding-zhang", 1) < 80 )
                return notify_fail(HIY"你的金顶绵掌火候不够，「灭剑」不成招式。\n"NOR);
	if(me->query_temp("last_pili")+5>time())
                return notify_fail("你内力使用过度，「"HIM"幻剑"NOR"」不成招式。\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	if (! present(target,environment(me))) return 1;
message_vision(HIM"\n$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐\n"NOR,me,target);
message_vision(HIM"渐逼近$n，$n看到漫天剑光，抽身后跃，只这一刹，漫天剑\n"NOR,me,target);
message_vision(HIM"影化为数剑直刺$n前胸，变幻莫测，突来三剑！\n"NOR,me,target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),10);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),10); 

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),10);



        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("last_pili",time());
        return 1;
}

