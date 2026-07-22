// Demon-steps.c 天魔步法
// Cracked by 凌惊雪 4-12-2003

inherit SKILL;

string *dodge_msg = ({
        "$n一招“魔幻虚影”，全身化出千百个身影躲闪开了$N这一招。\n",
        "$n气聚丹田，一招“重生魔寐”，身形急缩，躲开$N那致命一击。\n",
        "$n真气荡漾，清啸连连，一招“魔魇懵懵”，滑出丈外。\n",
        "$n双脚轻踏九曲，一招“魔光旖旎”，身形无比美妙地荡开数尺。\n",
        "$n使出如意人魔连环八步中的“魔影娉婷”，身形化实为虚地躲开了$N这一招。\n",
        "$n腾空一跃，双脚凌空虚踏，一招“魔冲霄汉”，躲开数尺。\n",
        "$n身形晃动，一招“魔心穹隆”，全身化作无数虚影掠出丈外。\n",
        "$n猛吸一口气，一招“奇魔异形”，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法练天魔步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练天魔步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

