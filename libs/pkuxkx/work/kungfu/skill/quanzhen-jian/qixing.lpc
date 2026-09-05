// qixing. 七星绝命剑

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int next_attack(object me, object target, int damage, int turn);

int perform(object me, object target)
{
    string msg;
    object weapon = me->query_temp("weapon");
    int damage, pflv, turn, max;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) ||  !target->is_character() ||  !me->is_fighting(target) )
        return notify_fail("「七星绝命剑」只能对战斗中的对手使用。\n");

    if( me->query_skill("quanzhen-jian", 1) < 150 )
        return notify_fail("你的全真剑法不够熟练，使不出七星绝命剑。\n");

//    if ( !objectp(weapon) || weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "quanzhen-jian")
    if ( !objectp(weapon) || weapon->query("skill_type") != "sword" )
        return notify_fail("你没有装备剑类武器，无法使用七星绝命剑。\n");

    if ( me->query("neili") < 200)
        return notify_fail("你的内力不够，无法使用七星绝命剑。\n");
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "全真派")
		pflv = 0;

    msg = MAG "\n$N"MAG"一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n"MAG"。\n"
		+ HIC"就在$n"HIC"慌乱之间，剑幕中飞出一朵寒星，如流星般射向$n"HIC"！\n";

    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target ) ) 
    {
        damage = 4*(int)me->query_skill("quanzhen-jian", 1);
        damage = damage / 2 + random(damage / 2);
        if (damage > target->query("neili") / 10) damage -= target->query("neili") / 15;
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        if( damage < 500 ) msg += HIY"$n"HIY"躲闪不及，被剑光掠过，飞溅出一丛血花。\n"NOR;
        else if( damage < 2000 ) msg += RED"$n"RED"躲闪不及，被刺个正着，鲜血激射而出！\n"NOR;
        else msg += HIR"$n"HIR"躲闪不及，“啊”的狂叫一声，身上一道血箭狂喷而出！\n"NOR;
		message_vision(msg, me, target);
		if (pflv>0)
		{
			turn = 1;
			max = pflv;
			if (pflv>=5) max = 6;
			while (turn<=max)
			{
				if (next_attack(me, target, damage, turn)<=0) break;
				turn ++;
			}
		}
		COMBAT_D->report_status(target);
   } 
    else 
    {
        msg += HIW"$n"HIW"情急之中向后激飞，随即趴下，堪堪躲过了这致命一击。\n" NOR;
		message_vision(msg, me, target);
    }

    me->add("neili", -180);
    me->start_busy(2);

    return 1;
}

int next_attack(object me, object target, int damage, int turn)
{
	string *position = ({ "天枢","天璇","天玑","天权","玉衡","开阳","瑶光", });
	string *color = ({ CYN, HIB, HIG, HIC, HIY, HIM });
	string msg;
	if (turn < 1 || turn > 6) return 0;
	if (me->query("neili")<150) 
	{
		tell_object(me, HIY"你待乘胜追击，却无奈内力不济，只得悻悻然作罢。\n"NOR);
		return 0;
	}
	if (turn == 1)
		msg = color[turn-1] + "$N" + color[turn-1] + "一击命中，脚踩北斗七星，自" + HIW "「"+ position[turn-1]+ "位」"+ color[turn-1] 
			+"转" HIW "「"+ position[turn]+"位」" + color[turn-1] + "，再度刺出一剑！\n";
	else
		msg = color[turn-1] + "$N" + color[turn-1] + "毫无停滞地自" + HIW "「"+ position[turn-1]+ "位」"+ color[turn-1] 
			+"转" HIW "「"+ position[turn]+"位」" + color[turn-1] + "，剑光一闪，快速刺出第"+chinese_number(turn+1)+"剑！\n";
	me->add("neili", -100);
	if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target ) ) 
	{
		F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        if( damage < 500 ) msg += RED"$n"RED"躲闪不及，被剑光掠过，飞溅出一丛血花。\n"NOR;
        else if( damage < 2000 ) msg += RED"$n"RED"躲闪不及，被刺个正着，鲜血激射而出！\n"NOR;
        else msg += HIR"$n"HIR"躲闪不及，“啊”的狂叫一声，身上一道血箭狂喷而出！\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		return 1;
	} 
	else 
	{
		msg += HIW"$n"HIW"情急之中向后激飞，随即趴下，堪堪躲过了这致命一击。\n" NOR;
		message_vision(msg, me, target);
	}
	return 0;
}