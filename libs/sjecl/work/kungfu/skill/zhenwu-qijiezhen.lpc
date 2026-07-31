// zhenwu-qijiezhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIW"\n$N漫声吟道：“太极阴阳少人修，吞吐开合问刚柔。”\n\n"NOR,
	HIW"\n$n只见眼前突的剑法大变，忽而轻灵如山，忽而灵动如羽，不禁心中一动，惧意暗生。\n\n"NOR,
	HIW"\n$N手中宝剑大开大阖，势道雄浑，有如泰山压顶之势攻向$n前胸要害。\n\n"NOR,
	HIW"\n$N疾趋疾退，剑尖上幻出点点寒星，每点星光都照在$n闪躲之处。\n\n"NOR,
	HIW"\n$N看似闲庭散步，实则脚踏七星，刚好占住了$n的步法移动之处。\n\n"NOR,
	HIW"\n$n只觉得全身上下都被剑气所缠绕，仿佛身坠云中，手中的兵刃竟施展不开。\n\n"NOR,
	HIW"\n$N等几人忽左忽右，穿来插去，几柄长剑织成一道光网，却不向对方递招。\n\n"NOR,
	HIW"\n几柄长剑使的犹如群山之大气磅礴，连绵不绝，又如浩浩大河，奔流不息。\n\n"NOR,
	HIW"\n$n一招攻向$N，只见$N竟然纹丝不动，突然左右两股剑风袭到，却是另外两只长剑\n"
		+"一先一后已然攻到。\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 7;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
	if( me->query_skill("yinyun-ziqi",1) < 120)
		return notify_fail("你的氤氲紫气级别不够，无法学习真武七截阵。\n");
	if( me->query_skill("taiji-jian",1) < 120)
		return notify_fail("你的太极剑法级别不够，无法领悟真武七截阵。\n");
    if( me->query_skill("taoism",1) < 120)
        return notify_fail("你的道学心法级别不够，无法领悟真武七截阵。\n");
	if( me->query_int() < 32 )
		return notify_fail("你的悟性，无法领悟真武七截阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("真武七截阵只能通过学习(learn)来提高。\n");
}
