// pmshenfa.c 飘渺身法
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
        "只见$n身随意转，一扭身已飘到$N背后，躲过了这一招。\n",
        "$n运起天魔身法，身影有如疾电流窜，令$N的攻势全数落空。\n",
        "$N只感眼前一花，$n已幻化成无数化身四散飞射。\n"
        "$n身影突如陀螺急转，形成猛烈的气劲漩涡，坚密如墙，$N根本无从入手。\n",
        "$n一招“魔幻虚影”，全身化出千百个身影躲闪开了$N这一招。\n",
        "$n气聚丹田，一招“重生魔寐”，身形急缩，躲开$N那致命一击。\n",
        "$n真气荡漾，清啸连连，一招“魔魇懵懵”，滑出丈外。\n",
        "$n双脚轻踏九曲，一招“魔光旖旎”，身形无比美妙地荡开数尺。\n",
        "$n使出如意人魔连环八步中的“魔影娉婷”，身形化实为虚地躲开了$N这一招。\n",
        "$n腾空一跃，双脚凌空虚踏，一招“魔冲霄汉”，躲开数尺。\n",
        "$n身形晃动，一招“魔心穹隆”，全身化作无数虚影掠出丈外。\n",
        "$n猛吸一口气，一招“奇魔异形”，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练飘渺身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pmshenfa/" + action;
}