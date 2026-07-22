#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob,weapon,*team;
	int i, t,damage;
	int ap,dp;
	string msg;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("force") < 500 )
		return notify_fail("你的内力不够。\n");
	if(me->query("family/family_name")!="盘丝洞")
		return notify_fail("这是盘丝绝学。\n");
        if((int)me->query_skill("yinsuo-jinling", 1) < 100
         || me->query_skill_mapped("whip") != "yinsuo-jinling" )
                return notify_fail("你的银索金铃级别还不够，使用这一招会有困难！\n");
	if(me->query_skill("force",1)<100)
		return notify_fail("你的内功不够精深。\n");
	weapon = me->query_temp("weapon");
	if( !weapon )
//	 || weapon->query("id")!="yinsuo jinling" )
		return notify_fail("你手里没铃儿。\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
         	return notify_fail("你要对谁施展铃声？\n");
	
	team = me->query_team();         		
        msg = HIC"\n$N"HIC"双手摇动，银索金铃上顿时珠链相击，发出一连串的铃声，层层叠叠，隐约可见一股股气旋在四周不停的翻腾震荡！\n"NOR;
	message_vision(msg,me);
	me->add("force", -300);
	ap = COMBAT_D->skill_power(me,"yinsuo-jinling",SKILL_USAGE_ATTACK);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) 
	{
		if( !me || !living(me) )
			break;
		if( !living(ob[i]) || ob[i]==me )
			continue;
		if( ob[i]->is_fighting(me) )
		{
			if( !ob[i]->killing(me->query("id")) )
				ob[i]->kill_ob(me);
			dp = COMBAT_D->skill_power(ob[i],"dodge",SKILL_USAGE_DEFENSE);			
			dp+= COMBAT_D->skill_power(ob[i],"force",SKILL_USAGE_DEFENSE);
			dp/= 3;
			if( (random(ap+dp)>=dp || COMBAT_D->check_level(me,ob[i])==1)
			 && COMBAT_D->check_level(me,ob[i])!=-1 )
			{
				message_combatd(HIR"$n"HIR"只觉听得心烦意乱，整个人好似控制不住，乱舞起来，结果累得腰酸背痛。\n"NOR,me,ob[i]);
				damage = COMBAT_D->valid_damage(me,ob[i],"yinsuo-jinling",TYPE_COMBAT);
				ob[i]->receive_damage("kee", damage,me,TYPE_PERFORM);
				COMBAT_D->report_status(ob[i]); 
				t = damage/10+1;
				if( t>5 )  t = 5;
				if( t<2 )  t = 2;
				if( !ob[i]->is_hunluan() )
					ob[i]->start_hunluan(t,HIR"\n你情不自禁的随着"+me->name()+HIR"的铃声舞动。\n"NOR);
			}
		}
		else if( ob[i]==me )
			continue;
		else if( team && arrayp(team) )
		{
			if( member_array(ob[i],team)!=-1 )
			{
				damage = COMBAT_D->vlaid_damage(me,ob[i],"yinsuo-jinling",TYPE_COMBAT)+1;
				damage = damage/3+random(damage/3)+1;
				message_combatd(HIG"$n"HIG"只觉听得心旷神怡，无比舒坦。\n"NOR,me,ob[i]);
				ob[i]->receive_curing("kee",damage);
				ob[i]->receive_curing("sen",damage);
				ob[i]->receive_heal("kee",damage/3);
				ob[i]->receive_heal("sen",damage/3);
			}
		}	
	}
	me->start_busy(3);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：天外飞音
        外功所属：银索金玲
        外功效果：对周围所有敌人进行铃声诱惑，使其陷入混乱
                  如有队员在场，则恢复、治疗队友的气血和精神 
                  自身busy 3 秒
        外功条件：
                  盘丝洞弟子
        	  人物等级10级
                  内力500点，消耗300点
                  银索金铃100级并激发
                  基本内功100级
STR;
        me->start_more(str);
        return 1;
}