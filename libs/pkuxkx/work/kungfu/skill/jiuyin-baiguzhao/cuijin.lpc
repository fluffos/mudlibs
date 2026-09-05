// cuijin.c  九阴白骨爪「摧筋破骨」
#define message_combatd message_vision
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage;
    string msg;
    int coe1=(int)me->query("jiuyin_2");
    int coe2=random(2);
    int rate_level;
    
    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「摧筋破骨」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 180 )
        return notify_fail(WHT"你的九阴白骨爪不够娴熟，还使不出「摧筋破骨」。\n"NOR);

    if( (int)me->query_skill("force", 1) < 180 )
        return notify_fail(RED"你的内功心法火候不够，使用「摧筋破骨」会震伤自己的经脉。\n"NOR);

    if( (int)me->query("neili") < 800 )
        return notify_fail("你内力不够了。\n");

    msg = HIC "$N一声怪啸，绕着$n急转数圈，而后施展出「摧筋破骨」，双爪齐出，直插$n前胸。\n"NOR;
    
//由于hit_rate函数在极低命中率级别的时候表现不佳，当本身经验远比对方高的时候适当上调命中率级别，修正命中率影响
//对于铜雀台影响导致的九阴白骨爪效果级别适当上调以保持和原有效果一致
//命中率级别根据情况不同在F到D-浮动，铜雀台解密前在F级别，解密后在E/D-级别浮动    
    if ( !coe1 )
    	rate_level=17;
    else
    	rate_level=14-coe2*2;

    if ( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), rate_level, me, target) )
    {
      if (me->query("neili") > target->query("neili")*3/2)
      {
        me->start_busy(3);
        damage = target->query("max_qi");
        F_KUNGFU->hit_wound("qi", damage/2 + 1, damage/2 + 1, me, target);
        me->add("neili", -400);
        msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
      } 
      else 
      {
        me->start_busy(3);
        damage = target->query("max_qi");
        F_KUNGFU->hit_wound("qi", damage/20, damage/20, me, target);
        me->add("neili", -400);
        msg += HIY"$N只觉$n内力浑厚！双爪竟不能惯胸而入,只在$n胸前留下了一道血痕！！！\n"NOR;
      } 
    } 
    else
    {
      me->start_busy(3);
      me->add("neili", -300);
      msg += HIY"可是$p早有防备，不慌不忙,卸开了$P的双爪。\n"NOR;
    }
    message_combatd(msg, me, target);
    COMBAT_D->report_status(target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    return 1;
}
