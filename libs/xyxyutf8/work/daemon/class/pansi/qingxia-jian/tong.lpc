// tong.c 姐妹同心
// by jingxue 1.11.2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
  	int damage,extra; 
  	
  	if( me->query_level()<15 )
  		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "盘丝洞")
		return notify_fail(HIM"「姐妹同心」"+NOR"是盘丝洞迷法！\n");
	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不够！\n");
	if( time()-(int)me->query_temp("tong_end") <5 )
		return notify_fail("绝招用多就不灵了！\n");
	if((int)me->query_skill("qingxia-jian", 1) < 150
	 && me->query_skill_mapped("sword") != "qingxia-jian" )
		return notify_fail("你的青霞剑法级别还不够，使用这一招会有困难！\n");
	if((int)me->query_skill("yinsuo-jinling", 1) < 150
	 && me->query_skill_mapped("whip") != "yinsuo-jinling" )
		return notify_fail("你的银索金玲级别还不够，使用这一招会有困难！\n");

  	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「姐妹同心」？\n");
	
	message_vision(HIG"\n$N"HIG"仰天长叹：千种恨万般冤仇，弹指间，一笑过。\n"NOR,me,target);
    	damage = me->query_skill("jiuyin-xinjing",1);
    	me->add_temp("apply/combat_damage",damage);    
    	me->add("force", -300);
    	me->set_temp("tong_end",time());
    	
    	msg = "半空中出现青霞仙子叹到：千里血如荼，同仇敌忾心。$N突然使出青霞剑法闪电般刺向$n！\n";
    	weapon=me->query_temp("weapon");
    	weapon->set("use_apply_skill","sword");
    	me->reset_action();
    	extra = me->query_skill("qingxia-jian",1)/10;
    	me->add_temp("apply/attack", extra);	
    	me->set_temp("pfm_color",HIC);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
    	me->set_temp("pfm_color",0);
    	me->add_temp("apply/attack", -extra);
    	weapon->delete("use_apply_skill");
    	me->reset_action();
    	
    	msg = "\n半空中出现紫霞仙子叹到：双钩银丝劲，姊妹共相亲。$N蓦的变招，手中$w变得柔弱无比，如银索金铃一般网向$n！\n"NOR;
    	weapon=me->query_temp("weapon");
    	weapon->set("use_apply_skill","whip");
    	me->reset_action();
    	extra = me->query_skill("yinsuo-jinling",1)/10;
    	me->add_temp("apply/attack", extra);	
    	me->set_temp("pfm_color",HIM);
    	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
    	me->set_temp("pfm_color",0);
    	me->add_temp("apply/attack", -extra);
    	weapon->delete("use_apply_skill");
    	me->reset_action();
    	
    	me->add_temp("apply/combat_damage",-damage);    
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：姐妹同心
        外功所属：青霞剑法
        外功效果：瞬间提升自身的物理伤害，以青霞剑法和银索金玲
                  分别攻击对方一次。
                  冷却时间5秒
        外功条件：
                  盘丝洞弟子
        	  人物等级15级
                  内力500点，消耗300点
                  青霞剑法150级并激发
                  银索金玲150级并激发
STR;
        me->start_more(str);
        return 1;
}	