// 倾城一笑 Yixiao.c
// Cracked by 凌惊雪 12-14-2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me )
{
	int t,extra;

	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	extra = me->query_skill("moondance",1);
	if( extra < 100) 
		return notify_fail("你的「冷月凝香舞」还不够纯熟！\n");
	if( extra<350 )
		t = 6;
	else if( extra<900 )
		t = 5;
	else	t = 4;		
	if( time()<me->query_temp("moon_yixiao")+t )
		return notify_fail("绝招用多就不灵了。\n");
	if( me->query("force")<800 )
		return notify_fail("你的内息不够。\n");
	return 1;	
}

int perform(object me, object target)
{
	string msg;
	int extra,extra2,extra3,ap,dp,tt;

	if( !valid_perform(me) )
		return 0;	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	|| target==me
	||	!me->is_fighting(target) )
		return notify_fail("「倾城一笑」只能对战斗中的对手使用。\n");
				
	extra = me->query_skill("moondance",1);
	extra3 = (int)me->query_per();

	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
		
	ap = COMBAT_D->skill_power(me,"moondance",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE);
	if((target->query("gender") != "女性") && (me->query("family/family_name") == "月宫"))
		dp-= dp/5;
	if( ap<1 ) ap=1;
	if( dp<1) dp= 1;
	ap+= extra3;	
	tt = (int)me->query_skill("moondance", 1) /50;
        if ( tt > 8 ) tt = 8;
        if ( tt < 2  ) tt = 2;		
	if(me->query("family/family_name") != "月宫"
	 && me->query("chushi/chushi_moon")!="yes" )
	{
		ap = ap-random(ap/3);
		tt = 2;
	}
	message_vision(HIC"$N"HIC"随风而舞，抬起头来朝$n"HIC"妩媚地一笑，如沉鱼落雁，倾国倾城！\n"NOR,me,target);
	me->add("force",-80);
	me->set_temp("moon_yixiao",time());
	if( random(ap+dp)>=dp/3*2 )
	{
		message_combatd(HIR"$n"HIR"神不守舍地看着$N"HIR"醉人的容颜，顿时不知所措！\n"NOR,me,target);
		target->start_busy(tt);
	}
        else 	
        {
		message_combatd(HIR"不料确被$N"HIR"看破，毫不为所动！$N"HIR"攻其不备，$n"HIR"反被打了个措手不及！\n"NOR,target,me);
		me->start_busy(1+random(2));
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：倾城一笑
        外功所属：冷月凝香舞
        外功效果：使对方busy 2-8 秒
        	  非月宫(出师)弟子使用命中降低，使对方busy 2 秒
                  使用后冷却4-6秒
                  失败则自身busy 1-2 秒
        外功条件：
        	  人物等级10级
                  内力800点，消耗80点
                  冷月凝香舞 100 级
                  
STR;
        me->start_more(str);
        return 1;
}