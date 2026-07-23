#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"你要为谁使用疗毒术？\n"NOR);

       if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法使用！\n");
		
	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

	
	if((int)me->query_skill("magic-light",1)< 350)
	return notify_fail("你的光明魔法太差了！\n");

	if((int)target->query("qi") > (int)target->query("max_qi")-50)
	return notify_fail("目标现在不需要使用疗毒术！\n");

	msg = HIY "$N"HIY"口中轻轻吟唱起了咒文.$N"HIY"的身上布满一层萤光.\n"NOR;
        msg += HIY"$N"HIY"念到 光之神啊，给我力量，照亮我的灵魂吧！！\n"NOR;
	msg += HIY "$N伸开双臂，神圣的光明之火注入$n的体内。\n";
	msg += HIG "光明之火使$n全身毒素一扫而光!\。\n";
	me->add("neili",-500);
	me->start_busy(2);
	if((int)target->query("qi") < (int)target->query("max_qi")+(int)target->query("max_qi")/8)
        {
	msg += HIG "光明之火使$n身上的伤少了一点!\。\n";
        target->add("qi",target->query("eff_qi")/10);
        target->add("eff_qi",target->query("eff_qi")/10);
if (target->query("qi") > target->query("max_qi")+1800)
target->set("qi",target->query("max_qi")+1800);
if (target->query("eff_qi") > target->query("max_qi"))
target->set("eff_qi",target->query("max_qi"));
        }
	if((int)target->query("jing") < (int)target->query("max_jing")+(int)target->query("max_jing")/8)
        {
	msg += HIG "光明之火使$n的精神一振!\。\n";
        target->add("jing",target->query("eff_jing")/10);
        target->add("eff_jing",target->query("eff_jing")/10);
if (target->query("jing") > target->query("max_jing")+1800)
target->set("jing",target->query("max_jing")+1800);
if (target->query("eff_jing") > target->query("max_jing"))
target->set("eff_jing",target->query("max_jing"));
        }

		if (target->query_condition("scorpion_poison"))
        target->apply_condition("scorpion_poison", 0);
		if (target->query_condition("qx_snake_poison"))
	target->apply_condition("qx_snake_poison", 0);
		if (target->query_condition("ss_poison"))
        target->apply_condition("ss_poison", 0);
		if (target->query_condition("tmzhuihun_poison"))
	target->apply_condition("tmzhuihun_poison", 0);
		if (target->query_condition("tmpili_poison"))
        target->apply_condition("tmpili_poison", 0);
		if (target->query_condition("zm_poison"))
        target->apply_condition("zm_poison", 0);
		if (target->query_condition("drunk"))
			target->apply_condition("drunk",0);
		if (target->query_condition("flower_poison"))
			target->apply_condition("flower_poison",0);
		if (target->query_condition("ice_poison"))
			target->apply_condition("ice_poison",0);
		if (target->query_condition("iceshock"))
			target->apply_condition("iceshock",0);
		if (target->query_condition("rose_poison"))
			target->apply_condition("rose_poison",0);
		if (target->query_condition("sanxiao_poison"))
			target->apply_condition("sanxiao_poison",0);
		if (target->query_condition("scorpion_poison"))
			target->apply_condition("scorpion_poison",0);
		if (target->query_condition("slumber_drug"))
			target->apply_condition("slumber_drug",0);
		if (target->query_condition("snake_poison"))
			target->apply_condition("snake_poison",0);
		if (target->query_condition("ss_poison"))
			target->apply_condition("ss_poison",0);
		if (target->query_condition("xx_poison"))
			target->apply_condition("xx_poison",0);
		if (target->query_condition("zhua_poison"))
			target->apply_condition("zhua_poison",0);
        if (target->query_condition("snake_poison"))
        {          target->clear_condition("snake_poison");}
        if (target->query_condition("wugong_poison"))
        {          target->clear_condition("wugong_poison");}
        if (target->query_condition("zhizhu_poison"))
        {          target->clear_condition("zhizhu_poison");}
        if (target->query_condition("xiezi_poison"))
        {          target->clear_condition("xiezi_poison");}
        if (target->query_condition("chanchu_poison"))
        {          target->clear_condition("chanchu_poison");}
        if (target->query_condition("qishang_poison"))
        {          target->clear_condition("qishang_poison");}
        if (target->query_condition("jy-poison"))
        {          target->clear_condition("jy-poison");}
        if (target->query_condition("xx_poison"))
        {          target->clear_condition("xx_poison");}
        if (target->query_condition("cold_poison"))
        {          target->clear_condition("cold_poison");}
        if (target->query_condition("flower_poison"))
        {          target->clear_condition("flower_poison");}
        if (target->query_condition("chilian_poison"))
        {          target->clear_condition("chilian_poison");}
        if (target->query_condition("yufeng_poison"))
        {          target->clear_condition("yufeng_poison");}
        if (target->query_condition("anqi_poison"))
        {          target->clear_condition("anqi_poison");}
       if (target->query_condition("yf_poison"))
        {          target->clear_condition("yf_poison");}
       if (target->query_condition("nx_poison"))
        {          target->clear_condition("nx_poison");}
       if (target->query_condition("x2_poison"))
        {          target->clear_condition("x2_poison");}
       if (target->query_condition("sanpoison"))
        {          target->clear_condition("sanpoison");}
       if (target->query_condition("insect_poison"))
        {          target->clear_condition("insect_poison");}
		message_combatd(msg, me, target);
	return 1;
}
