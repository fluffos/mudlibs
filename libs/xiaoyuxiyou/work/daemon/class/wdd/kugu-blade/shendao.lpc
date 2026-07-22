// shendao.c stey 血刀「祭血神刀」
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;
    	string msg,succ_msg;
    	object weapon;

	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("kugu-blade", 1) < 300 )
        	return notify_fail(WHT"你枯骨刀刀法不够娴熟，使不出「枯骨祭血神刀」。\n"NOR);
	if((int)me->query("force") < 500 )
		return notify_fail("你现在内力不够，没能将「枯骨祭血神刀」使完！\n"NOR);
	weapon = me->query_temp("weapon");
        if( !weapon 
	 || (weapon->query("skill_type")!="blade"
	  && weapon->query("use_apply_skill")!="blade") )	
		return notify_fail("你手里头木有刀。\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
     		return notify_fail("你要对谁施展这一招？\n");
     				 		
	msg = RED"$N"RED"右手持$w"RED"向左肩一勒，一阵"NOR HIR"血珠"NOR RED"溅满刀面，紧接着右臂抡出，一片血光裹住刀影向$n"RED"当头劈落！\n"NOR;
	succ_msg = HIR"$n"HIR"疾忙侧身避让，但血刀疾闪，只觉眼前一阵血红，刀刃劈面而下，鲜血飞溅，惨声大嚎！\n"NOR;
	me->add("force",-250);
	me->receive_wound("kee",50);
	
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,me->query_skill("blade")+800);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
		message_combatd(HIC"可是$n"HIC"侧身避让，不荒不忙，躲过了$P的血刀。\n"NOR,me,target);
	else
	{
		target->receive_wound("kee", damage,me,TYPE_PERFORM);
		COMBAT_D->report_status(target,1);
	}
        me->start_busy(2);
	return 1;
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
              外功名称：枯骨祭血神刀
              外功所属：枯骨刀法 
              外功效果：给予对方带至少800点固定伤害的物理伤害，打击其气血后限
                        自身busy 2 秒
                        会消耗自身气血后限50点
              外功条件：
			人物等级30级
			内力500点，消耗250点
			枯骨刀法300级 
LONG;
me->start_more(str);
return 1;
}