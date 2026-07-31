//heijian-jindao 连环三刀
//by fqyy
/*
    这一刀当头直砍，招数似乎颇为呆滞，杨过只须稍一侧身，便可轻易避过，然而谷主黑
剑所划剑圈却笼罩住了他前后左右，令他绝无闪避躲让之处。杨过只得举起半截钢杖，一招
“只手擎天”，硬接了他这招。但听得当的一声巨响，刀杖相交，只爆得火花四溅，杨过双
臂只感一阵酸麻。公孙谷主第二刀连着又上，招法与第一刀一模一样。杨过武学所涉既广，
临敌时又是机灵异常，但竟无法破解他这笨拙钝重的一招，除了同法硬架之外，更无善策。
刀杖二度相交，杨过双臂酸麻更甚，心想只要再给他这般砍上几刀，我手臂上的筋络也要给
震坏了。思念未定，谷主第三刀又砍了过来。再接数刀，杨过手中的半截钢杖已给金刀砍起
累累缺口，右手虎口上也震出血来。
    公孙谷主见他危急之中仍是脸带微笑，左手一刀砍过，右手黑剑□地往他小腹上刺去。
杨过此时已给他逼在厅角，眼见剑尖刺到，忙伸手平掌一挡，剑尖刺中他掌心，剑刃弯成弧
形，弹了回来。原来小龙女的掌套甚是坚密，黑剑虽利，却也伤它不得。
*/

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void next1(object me, object target, int i);
void next2(object me, object target, int i);
int perform(object me,object target)
{
	int i;
	string msg;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("连环三击只能对战斗中的对手使用。\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用连环三击！\n");

        if( me->query("jing") <= 500 )
                return notify_fail("你的精力不够使用连环三击！\n");
        if( me->query_skill("heijian-jindao",1) < 60 )
                return notify_fail("你黑剑金刀未到炉火纯青之境！\n");

        if (!weapon)
                return notify_fail("你手中无剑怎能使用连环三击？！\n");
        if (!me->query_temp("heijian-jindao/luanren",1)||!me->query_temp("heijian-jindao/nizhuan",1))
                return notify_fail("你不使用“阴阳倒乱刃法”怎么能用连环三击封住敌人行动！\n");

        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("你必须先将黑剑金刀相互配合。\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("你只有一种兵器就想连环三击？\n");

	msg = HIM"$N这一刀当头直砍，招数似乎颇为呆滞，$n只须稍一侧身，便可轻易避过，\n"+
		"然而$N所划剑圈却笼罩住了他前后左右，令$n绝无闪避躲让之处。\n"NOR;
	me->start_perform(5,"「连环三击」");
	if((random(me->query_skill("heijian-jindao",1)) + me->query_int()) >
	(target->query_skill("dodge",1)/3 + target->query_int())) {
		msg = msg + HIR "$n只得一招“只手擎天”，硬接了$N这招。\n" NOR;
		target->add_busy(random(i*5) + 2);
	}
	else {
		msg = msg + HIW "可是$n看破了$N的企图，飞快的向后退去。\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	next1(me, target, i);
	return 1;
}

void next1(object me, object target, int i)
{
	string msg;
	int damage;
	object weapon;

	if (!me) return ;
	weapon = me->query_temp("weapon");
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}

	msg = HIG"\n$N第二刀连着又上，招法与第一刀一模一样。\n"+
		"$n武学所涉既广，临敌时又是机灵异常，但竟无法破解他这笨拙钝重的一招，除了同法硬架之外，更无善策。\n"NOR;

	if((random(me->query("max_neili")) + me->query_skill("force",1)) >
	    (target->query("max_neili") + target->query_skill("force",1))/3 ||(target->is_busy()&&random(2))){
		msg = msg + HIR"$N$n二度相拼，$n双臂酸麻更甚，只要再给$N这般砍上几刀，$n手臂上的筋络也要给震伤。\n"NOR;
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("blade",1);
		damage += random(damage);
		if (!target->is_busy()) target->start_busy(damage/500);
		target->add("neili",-(500+random(150)));
		damage=damage+500;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg += damage_msg(damage, "震伤");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "手臂");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
me->start_busy(2);
		me->add("jing",-100);
	} else {
		msg  =  msg + CYN"$n内力深厚硬生生接下了这一招。\n"NOR;
		message_vision(msg, me, target);
		me->start_busy(1+random(2));
		target->start_busy(1+random(2));
	}

	next2(me, target, i);

}

void next2(object me, object target, int i)
{
	string msg;
	int damage;
	object weapon;

	if( !me ) return ;

	weapon = me->query_temp("weapon");
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}

	msg = HIC "\n$n思念未定，$N第三刀又砍了过来。左手一刀砍过，右手剑法突地往$n小腹上刺去。\n"NOR;

	if((random(me->query("combat_exp")) + me->query_str()) >
	    (target->query("combat_exp") + target->query_str())/3 ||(target->is_busy()&&random(2))){
		msg = msg + HIW "$n此时已给$N逼在厅角，眼见剑尖刺到，忙伸手平掌一挡，剑尖刺中$n掌心！\n"NOR;
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("sword",1);
		damage += random(damage);
		if (!target->is_busy()) target->start_busy(damage/500);
		target->add_temp("apply/attack", -100);
		target->add_temp("apply/dodge", -100);
		target->add_temp("apply/parry", -100);
		damage=damage+500;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg += damage_msg(damage, "刺伤");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "手心");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
		me->add("jing",-50);
		call_out("back", 5 + random(me->query("jiali") / 20), target);
	} else {
		msg = msg + HIW "$n此时已给他逼在厅角，眼见剑尖刺到，忙伸手平掌一挡，剑尖刺中他掌心，\n$n内力深厚使得剑刃弯成弧形，弹了回来。\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
		target->start_busy(1+random(2));
	}
}

void back(object target)
{
	if (!target) return;
	target->add_temp("apply/attack", 100);
	target->add_temp("apply/dodge", 100);
	target->add_temp("apply/parry", 100);
}
