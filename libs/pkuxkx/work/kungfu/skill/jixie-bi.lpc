// 机械臂-机关人的攻击技能

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	"action" : CYN+"$N"+CYN+"挥动机械臂，铁拳带着呼呼风声锤向$n"+CYN+"的$l"+NOR,
	"force" : 400, 
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
    "damage_type" : "瘀伤"
]),
([	"action" : CYN+"$N"+CYN+"伸臂直戳，锐利如刀锋的指尖刺向$n"+CYN+"的$l"+NOR,
	"force" : 450,
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
    "damage_type" : "刺伤"
]),
([	"action" : CYN+"$N"+CYN+"张开双掌，一对蒲扇般的大铁掌大开大阖，直拍向$n"+CYN+"的$l"+NOR,
	"force" : 480,
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
        "damage_type" : "瘀伤"
]),
([	"action" : CYN+"$N"+CYN+"抬起右腿，一记灵活的侧踢弹腿，铁锤般的大脚踢向$n"+CYN+"的$l"+NOR,
	"force" : 520,
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
        "damage_type" : "瘀伤"
]),
([	"action" : CYN+"$N"+CYN+"突然大张双臂，以一个熊抱之势向$n"+CYN+"扑了过来，双拳齐出砸向$n"+CYN+"的$l"+NOR,
	"force" : 550,
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
	"damage_type" : "瘀伤"
]),
([	"action" : CYN+"$N"+CYN+"两条机械手臂舞得飞快，如同风车般向着$n"+CYN+"劈头盖脸地卷了过来"+NOR,
	"force" : 600,
    "dodge" : -50,
	"parry" : 100,
	"skill_name" : "机械臂",
    "damage_type" : "瘀伤"
]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


string query_skill_name(int level)
{
	return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return notify_fail("机关人的攻击手段无法通过练习来提高。\n");
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手臂架开。\n",
        "但是$n身子一侧，用手臂格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"jixie-bi/" + action;
}