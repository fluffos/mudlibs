// liao.c  一阳指的特殊招式－疗伤
// Made by ysg (1997.10.22)
//modified by Zine，合并天龙寺和全真的一阳指
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="other" ;
}

int perform(object me, object target)
{
	int level;
    string name1, name2;

	level = me->query_skill("yiyang-zhi", 1);

	if( !objectp(target) ) return notify_fail("你使用一阳指要给谁疗伤？\n");

	if( target == me ) return notify_fail("使用一阳指不能给自己疗伤。\n");

	if ( (!me->query("yiyang_zhi/quanzhen") && me->query("yiyang_zhi/tianlong")) || 
         (me->query("yiyang_zhi/quanzhen") && me->query("yiyang_zhi/tianlong") && (me->query("env/yiyang")=="tianlong"||!me->query("env/yiyang"))) )
	{
		if((int)me->query_skill("kurong-shengong", 1)<100 && (int)me->query_skill("beiming-shengong", 1)<100 )
        return notify_fail("你的天龙内功等级不够，还不到能够疗伤的境界。\n");
	}
	else 
	{ if( me->query_skill("xiantian-gong", 1) < 100 )
      return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");
  
    if( me->query_skill_mapped("force") != "xiantian-gong" )
      return notify_fail("使用疗伤必须激发先天功才能使出这个绝招。！\n");
  }
//		return notify_fail("一阳指疗伤乃天龙寺独门秘技。\n");
	//***tianlongsi***//
	if( !objectp(target) || !target->is_character() ) 
        return notify_fail("你要给谁疗伤？\n");

	if( target->is_fighting() || me->is_fighting() ||target->is_busy()) 
        return notify_fail("在战斗中疗伤，你想找死啊？\n");

	if( level < 40 ) return notify_fail("你的一阳指等级不够，还不到能够疗伤的境界。\n");

	if( (int)me->query("max_neili") < 350 
		|| (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够，不能用一阳指疗伤。\n");

    name1 = me->query("name")+NOR+HIY;
    name2 = target->query("name")+NOR+HIY;
	tell_room(environment(me),
	HIY"只见"+ name1+"深深的吸了一口气，脸色顿时变得紫红，伸出右手食指，运指如飞，\n"
	"沿着"+name2+"的任、都二脉一路点将下来，只见"
	+name2+"“哇”的吐出一口鲜血，脸色看起来好多了。\n"NOR,({me,target}));
	tell_object(me,HIY"你盘膝坐下，调匀了气息，使出一阳指的独门功夫，开始给"+ name2 +"疗伤。\n"NOR);
	tell_object(target,HIY"只见"+name1+"盘膝坐下，使出一阳指的独门功夫，开始给你疗伤。\n"NOR);

	me->add("neili", -200);
	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->receive_wound("jing", 80, "替人疗伤耗尽精血");
	me->receive_wound("qi", 80, "替人疗伤耗尽精血");
	me->start_busy(3);
	target->set("eff_qi", (int)target->query("max_qi"));
	target->set("eff_jing", (int)target->query("max_jing"));
	return 1;
}
