// Xiake quanjiao
// by guilin||male
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIB"$N一声长笑:'赵客缦胡缨，吴钩霜雪明。银鞍照白马，疯沓如流星。'双手有如流星赶月一般,直逼$n面门!"NOR,
        "dodge": 50,
        "parry": 10,
        "force": 300,
        "damage_type": "瘀伤"
]),
([      "action": HIG"$N气沉丹田,吟到:'十步杀一人，千里不留行。事了拂衣去，深藏身与名。'同时双腿向前连环踢出数腿!"NOR,
        "dodge": 50,
        "parry": 0,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": HIY"$N冷笑一声:'闲过信陵饮，脱剑膝前横。将炙啖朱亥，持觞劝侯嬴。'双手由拳化掌,往外急翻,以内力逼人!"NOR,
	"dodge": 10,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIR"$N长啸一声:'三杯吐然诺，五岳倒为轻。眼花耳热后，意气素霓生。'身形飘忽不定,双腿向前连扫两脚!"NOR,
        "dodge": 15,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIM"$N低声默念:'救赵挥金锤，邯郸先震惊。千秋二壮士，［火亘］赫大梁城。'身体一跃而起,又突然下移,霎那间,已连出三掌!"NOR,
	"dodge": 10,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIW"突然间$N悲由心起,吟出一句:'纵死侠骨香，不惭世上英。谁能书阁下，白首太玄经？',身体动也不动,只是将掌风舞得密不透风!"NOR,
	"dodge": 10,
	"parry": 20,
	"force": 350,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="xiake-strike"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiake-quanjiao/" + action;
}

string *parry_msg = ({
        "$n掌风一变,只听见「锵」一声，$N被$p格开了。\n",
        "$n身子一侧，用手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p侥幸格开了。\n",
        "结果被$p侥幸挡开了。\n",
});

int practice_skill(object me)
{
        return notify_fail("侠客拳脚只能用学(learn)的来增加熟练度。\n");
}


string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "少阳";
}