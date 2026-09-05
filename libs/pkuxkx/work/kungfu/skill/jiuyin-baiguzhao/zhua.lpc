// zhua.c  九阴白骨爪「亡魂一击」
// Modified by Venus Oct.1997

#include <ansi.h>
#include <char.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int extra;
    string msg;
    int coe1=(int)me->query("jiuyin_2");
    mapping attack_val = ([
        "base": ([ "no_weapon" : "claw" ]),//基本功夫类型
        "skill" : ([ "no_weapon" : "jiuyin-baiguzhao" ]),//高级技能名称
        ]);


    extra = me->query_skill("jiuyin-baiguzhao",1)*(4+coe1)/4;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「亡魂一击」只能对战斗中的对手使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SHEN) &&
         (int)me->query("shen", 1) > 0)
        return notify_fail("你是侠义道人士，怎麽能「亡魂一击」这种阴毒武功。\n");

    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 85 )
        return notify_fail("你的九阴白骨爪不够娴熟，还使不出「亡魂一击」。\n");

    if( (int)me->query_skill("force", 1) < 85 )
        return notify_fail("你的内功心法火候不够，使用「亡魂一击」会震伤自己的经脉。\n");

    me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);
    msg = HIR "$N突然将双掌变爪合于胸前，然后象风车般急转数圈，而后施展出「亡魂一击」，双爪向外一翻，随后绕着$n疾转数圈，又回到原地。\n"NOR;
    message_vision(msg, me, target);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
	me->start_busy(2);
    me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra*2);
    return 1;
}

