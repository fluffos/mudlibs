// 心剑齐发

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    int damage , zhao;
    string msg;
    object weapon;
    int extra;
    int i;
    
string  *pfattack_msg = ({
                       HIG"「倒剑式」$N突然将所有剑式倒转为施，但见$n顿时被逼得手忙脚乱，自己向$N的长剑撞将上来。\n"NOR,
                       HIR"「逆剑式」$N将长剑交到左手，剑招变的左右颠倒，$n一时没有弄懂被刺个正着。\n"NOR,
                       HIC"「落剑式」$N腾身而起，成头下脚上势，从空中攻向$n，$n防备不及结果被$N的刺中。\n"NOR,
                       HIY"「摇剑式」只见$N的长剑有如灵蛇一般左右迂回着，$n不知剑要攻向自己的什么位置，站在原地发呆，结果被刺中。\n"NOR,
                       HIW"「荡剑式」$N的剑招突然变得犹如风中柳絮，飘忽不定，$n只觉眼前一花，胸口已被刺中。\n"NOR,
                       HIB"「浪剑式」犹如大海狂涛，又四面向$n压去，$n只觉置身于$N的剑招的狂风暴雨之中，不知不觉已经被刺中。\n"NOR,
                       YEL"「挫剑式」$n与$N互相一搓身，只见$N将长剑轻轻一带，$n的小腹已中了$N的一剑。\n"NOR,
                       HIG"「离剑式」只见$N将手中长剑随手抛向空中，长剑剑光暴长，急若流星飞向$n，$n躲避不及被长剑刺中。\n"NOR,
                       HIW"$N手中长剑虚空一点，"+HIR"「剑气式」"+HIW"应手而出，三丈之内剑气纵横连绵不绝袭向$n，$n急忙腾空而起但已经太晚，剑气已经贯胸而过。\n"NOR
                       });

string *pfparry_msg = ({
                      HIG"$p看破了$P的企图，挺剑而上，一圈一点破解了$P的这招。\n"NOR,
                      HIB"$p腾身而起，$P的剑招险险从脚下擦过。\n"NOR,
                      HIY"$P突然从左方攻去一剑，早以被$p料到，身体轻轻向右飘出丈余，化解了这招。\n"NOR,
                      });

    if (!target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「心剑齐发」？\n"NOR);

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("lonely-sword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("huashan-sword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("zixia-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zixia-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        msg = HBWHT "$N贯通华山武学，使出了华山的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);      
if (random(3)==0) target->start_busy(3);
damage = (int)me->query_skill("lonely-sword", 1);
	extra = me->query_skill("lonely-sword",1) / 20;
	extra += me->query_skill("zixia-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
      msg = HIW "$N剑气冲霄，使出「"HIG"独孤九剑"HIW"」绝技，身法陡然加快，猛地连出9招！\n"NOR;
        message_vision(msg, me, target);
//        me->add("neili", -500);
        msg = HIC"第一剑！「"HIG"独孤九剑"HIY"飞星式"HIC"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW"第二剑！「"HIG"独孤九剑"HIC"落沙式"HIW"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY"第三剑！「"HIG"独孤九剑"HIW"奔流式"HIY"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIR"第四剑！「"HIG"独孤九剑"BBLU+HIW"行空式"NOR+HIR"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = BLU"第五剑！"HIB"「"HIG"独孤九剑"HIR"横扫式"BLU"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG"第六剑！「"HIG"独孤九剑"RED"直刺式"HIG"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = CYN"第七剑！「"HIG"独孤九剑"HIY"绝情式"NOR+CYN"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW+BLK"\n第八剑！「"HIG"独孤九剑"HIB"斜劈式"HIW+BLK"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = MAG"第九剑！"HIR"「"HIG"独孤九剑"HIY"之"U+HIG"九"HIW"天"HIY"御"HIW+BLK"剑"HIR"术"NOR+HIR"」"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        target->receive_wound("qi", random(damage));
           msg = HIW"\n结果$n被$N攻了个措手不及。\n"NOR;
           message_vision(msg, me, target);
        me->start_busy(4);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

    msg = HIW "$N以气御剑手中长剑剑芒跃动，剑光暴长，剑尖颤动使出独孤九剑的，独门绝技\n"NOR;
    msg += HIR"「九式合一」"+HIW+"剑光左右飘忽，上下不定，直向$n卷去！\n\n"NOR;

for (zhao=0;zhao<9;zhao++)
{ 

    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
    {
        me->start_busy(4);
  if( !target->is_busy() )
{
        target->start_busy(random(2)+1);
}
        damage = (int)me->query_skill("lonely-sword", 1) + (int)me->query_skill("sword", 1);
        damage = 200 + damage + random(damage);
        target->receive_damage("qi", damage/3);
        target->receive_wound("qi", damage/4);
      msg += pfattack_msg[random(sizeof(pfattack_msg))];
//        me->add("neili", -damage/5);
    } else
    {
    me->start_busy(4);
 
      msg += pfparry_msg[random(sizeof(pfparry_msg))];
   }
}
    message_combatd(msg, me, target);
    return 1;
}
