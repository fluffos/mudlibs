//【冷月凝香舞】 moondance.c
// cglaem...12/07/96.
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
     "$n低头细数裙褶，情思困困，步法回旋之际似乎娇柔无力，却将$N攻势一一化于无形。\n",
     "只见$n一个转身，忽然回眸一笑。$N一楞之下，哪里还有人在。\n",
     "可是$n婉尔一笑，不退反进，身形径向$N飘来。$N只觉一股甜香入鼻，这一招竟无着力之处。\n",
     "$n身法轻灵，腰肢几拧，居然幻出斑驳月影。$N眼一花，哪里分得出是人，是影。\n",
     "$n裙裾飘飘，白衣姗姗，已然从$N头顶飞过，这般女神端丽之姿，仙子缥缈之形，$N不由得看呆了！\n",
     "$n脚步轻盈，风姿嫣然，身子便如在水面上飘浮一般掠过，不等$N劲风袭到，已悄然隐去。\n",
     "$n纤腰微颤，带飞如虹，轻轻将$N的劲力拨在一旁，尽数化解。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("冷月凝香舞只有女性才能练。\n");
	if( (int)me->query("spi") < 10 )
		return notify_fail("你的灵性不够，没有办法练冷月凝香舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query_skill("moondance",1) >= 200 && (string)me->query("family/family_name") != "月宫")
		return notify_fail("你不是月宫弟子，冷月凝香舞很难再进展了。\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练冷月凝香舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("moon") + "/moondance/" + func;
}

mixed hit_ob(object me,object target)
{
	string str;
	int damage;
	if( !me || !target || !living(me)
	 || me->is_busy()
	 || me->is_hunluan()
	 || me->is_blind()
	 || me->is_no_move() 
	 || !me->is_fighting(target) )
		return 0;
	if( me->query("family/family_name")!="月宫" 
	 && me->query("chushi/chushi_moon")!="yes" )
		return 0;
	if( !me->is_killing(target->query("id")) )
		return 0;
	if( me->query_skill("moondance",2)<400 )
		return 0;
	if( target->is_busy() )
		return 0;
	if( random(me->query_per())<target->query("per") )
		return 0;
	damage = me->query_skill("moondance",1)/10-40;
	if( damage<1 )
		damage = 1;
	if( damage>3 )
		damage = 3;
	damage = 1+random(damage);
	target->start_busy(damage);
	return HIC"$n"HIC"朝$N"HIC"嫣然一笑，$N"HIC"顿时心中一动，说不出的滋味涌上心头，动作不由一滞。"NOR"\n\n";
}							 