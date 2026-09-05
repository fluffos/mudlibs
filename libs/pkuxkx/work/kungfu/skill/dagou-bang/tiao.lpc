//tiao.c 打狗棒法挑字决 by advent 060729
// Modified by iszt@pkuxkx, 2007-03-24

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2, wea;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「挑字诀」只能对战斗中的对手使用。\n");

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
            !me->query("dagou-bang/tiao"))
                return notify_fail("你还没有学会「挑字决」。\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff" )
                return notify_fail("你右手没拿棒,还想使棒法的绝招?别作梦了!\n");

/*        if( !(weapon = me->query_temp("weapon"))
          || weapon->query("skill_type") != "staff"
          || me->query_skill_mapped("staff") != "dagou-bang" ) 
                return notify_fail("你不用打狗棒法，无法使用挑字诀。\n"); */
 
        if ( !objectp(weapon = target->query_temp("weapon")) && !objectp(weapon2 = target->query_temp("secondary_weapon")) )
                return notify_fail("对方没有使用任何兵器，你无法使用「挑字诀」。\n");

        if( (int)me->query_skill("dagou-bang",1) <150)
                return notify_fail("你的打狗棒法还没学到家，无法挑人兵器！\n");


        msg = CYN "$N"CYN"突然棒法一变，招招直指$n"CYN"双目。$n"CYN"大惊之下，急让举起手中兵器掩住面门。\n$N"CYN"使起“挑”字诀，搭住$n"CYN"的兵器向上甩出，试图挑走$n"CYN"的兵器。\n";
        message_vision(msg, me,target);
        me->start_busy(2); 
//命中率C+，判师一次下降4个命中率级别
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 7+me->query("betrayer")*4, me, target) )
        {
                msg = HIY"$n"HIY"措手不及之下已然中招，手腕一麻，手中兵刃急飞上天！\n" NOR;
                if (objectp(weapon))  
                {
                	weapon->unequip();  
                	weapon->move(environment(target));
                }
                else
                {
                	weapon2->unequip();
                	weapon2->move(environment(target));
                }

                if (random(4)>0) 
                {
                        msg += CYN"$n"CYN"慌乱之下大惊失措，怔怔的不知如何是好！\n";          
                        message_vision(msg, me,target);
                        if (!target->is_busy()) target->start_busy(3);
                }
                else{
                        msg += CYN"$n"CYN"虽失兵器，却并不慌乱，双拳挥动掩住面门，身形急退，退出了$N"CYN"的攻击范围！\n";  
                        message_vision(msg, me,target);
                }
        }
        else
        {
                msg = NOR"可是$n的看破了$N的企图，手中兵刃一沉，$N并没有碰到。\n"NOR; message_vision(msg, me,target);
        }
        me->add("neili",-100);
        return 1;
}

void remove_broken_weapon(object ob)
{
        if(ob && environment(ob)) {
                tell_object(environment(ob),"一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
                destruct(ob);
        }
}

