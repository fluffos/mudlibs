// chan.c 打狗棒法「缠」字诀

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff" )
                return notify_fail("你右手没拿棒,还想使棒法的绝招?别作梦了!\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if( (int)me->query_skill("dagou-bang", 1) < 40 )
                return notify_fail("你的打狗棒法不够娴熟，不会使用「缠」字诀。\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        msg = HIW "$N"HIW"棒头朝天口中似乎念一声"HIG"缠！"HIW"突然棒头下挥剪、拨、挑、连去处尽是$n"HIW"的下盘！\n$n"HIW"双脚连跳后退，大叫：不好！莫非今日要受制于人？\n";

        me->start_busy(1+random(2));
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 6+me->query("betrayer")*6, me, target) ) {
                msg += HIR"$p"HIR"连连后退中终于露出破绽，$P"HIR"得理不饶人，" + weapon->query("name") + HIR +"连续递出尽攻$p"HIR"所必救！\n$p"HIR"左支右绌苦苦支撑，陷入了完全被动的境地，根本无法还手！\n" NOR;
                F_KUNGFU->hit_busy( "body", (int)me->query_skill("dagou-bang")/10, target );
        } else {
                msg += HIG"$p"HIG"眼看" + weapon->query("name") + HIG"扫至，取其变招瞬间迅捷无伦地在棒头一抹，将$P"HIG"欲留的力量一泻无遗！\n"HIW"$P"HIW"叹了口气知道这“缠”字决已为人所破，只得收回了招式。\n" NOR;
        }
        me->add("neili", -100);
        message_vision(msg, me, target);

        return 1;
}

