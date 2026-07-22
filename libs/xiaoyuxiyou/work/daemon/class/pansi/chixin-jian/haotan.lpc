//yudian 2000-11-14
// haotan.c  痴情八叹  
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
	int damage;
	object weapon;

	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="盘丝洞")
		return notify_fail("“痴情八叹”只有盘丝洞门人才可以用！\n");
	if (me->query_skill_mapped("force")!="jiuyin-xinjing")
		return notify_fail("只有用九阴心经做功底。\n");
	if (me->query_skill("chixin-jian",1)<300)
		return notify_fail("你的痴心情长剑法还得再练练。\n");
	if((int)me->query("force") < 500 )
		return notify_fail("你的内力还不到火候。\n");
	if((int)me->query("kee") < 150 )
		return notify_fail("你的体力已经不够了！\n");
	if((int)me->query("sen") < 150 )
		return notify_fail("你连自己都控制不住自己的感情！\n");
	if( time()<me->query_temp("psd_haotan")+6 )
		return notify_fail("你太多情善感了。\n");
				
	weapon = me->query_temp("weapon");
	if( !weapon 
    	 || ( weapon->query("skill_type") != "sword" 
    	   && weapon->query("use_apply_skill") != "sword" ) )
                return notify_fail("你手里没剑，如何弹刃而歌？\n");

	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("没人愿意听你诉苦。\n");
	
	damage = me->query_skill("literate",1)+me->query_skill("chixin-jian",1)+me->query_skill("jiuyin-xinjing",1);
	damage/= 4;
	me->receive_damage("sen",100,me);
	me->receive_damage("kee",100,me);
	me->add("force", -200);
	msg = HIC "\n$N"HIC"凝住$w"HIC"，稳而不发，剑势不减，剑意不绝！\n" NOR;
	msg+= HIM"$N"HIM"居然就地盘膝而坐，以剑作琴，对着$n"HIM"纵声浩叹，“此恨绵绵无绝期”，似是叹息，又似哀怨，跟着琴声颤抖，如是更漏欲绝，明烛将熄。前三叹未绝，又和琴浩叹：“黯然消魂未尽时！”，如此痴情八叹，琴声斗转，犹如夜幕般弥散开来。\n"NOR;
	succ_msg = HIW "$n"HIW"为琴声感染，无限思绪纷至沓来，恍然不在人世！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"头部",damage);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		msg = HIW "$n"HIW"冲着$P鄙意的冷笑道：别婆婆妈妈的，这种事情还好意思说？！$N"HIW"顿时羞愧难当。\n"NOR;
	    	message_combatd(msg, me, target);
	} 
	else 
	{
		target->receive_damage("sen",damage,me,TYPE_PERFORM);
		COMBAT_D->report_sen_status(target); 
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：痴情八叹
        外功所属：痴心情长剑
        外功效果：打击对方的气血与精神
                  冷却时间6秒
        外功条件：
                  盘丝洞弟子
        	  人物等级30级
                  内力500点，消耗200点
                  气血150点，消耗100点
                  精神150点，消耗100点
                  痴心情长剑300级并激发
                  激发九阴心经
STR;
        me->start_more(str);
        return 1;
}