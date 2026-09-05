// Xiake strike
// by aiai 6/28/99
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIB"$N心头一热，不禁吟到：'赵客缦胡缨，吴钩霜雪明。银鞍照白马，疯沓如流星。'\n双掌径直朝$n的双掌对去！"NOR,
        "dodge": 50,
        "parry": 10,
        "force": 300,
        "damage_type": "瘀伤"
]),
([      "action": HIG"$N在打斗之间竟然闭住双眼！喝道：'十步杀一人，千里不留行。事了拂衣去，深藏身与名。'\n但双掌却已在$n难以想象的角度向其丹田拍去！"NOR,
        "dodge": 50,
        "parry": 0,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": HIY"$N突然一声长叹：'闲过信陵饮，脱剑膝前横。将炙啖朱亥，持觞劝侯嬴。'\n竟然以掌代剑，使出一招侠客剑法!"NOR,
	"dodge": 10,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIR"$N淡淡一笑，淡然道：'三杯吐然诺，五岳倒为轻。眼花耳热后，意气素霓生。'\n双掌却以掌背对人，看也不看，向$n甩去！"NOR,
        "dodge": 15,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIM"突然间$N豪气干云，长啸一声:'救赵挥金锤，邯郸先震惊。千秋二壮士，［火亘］赫大梁城。'\n掌风急变，以掌代刀居然使出一招侠客刀法！"NOR,
	"dodge": 10,
	"parry": 10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([      "action": HIW"$N突然一阵悲凉，隐约之间双眼暗淡无光，低声叹道：'纵死侠骨香，不惭世上英。谁能书阁下，白首太玄经？'\n掌风轻轻回收，却是暗藏杀机！"NOR,
	"dodge": 10,
	"parry": 20,
	"force": 350,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="xiake-quanjiao"; }

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
	return __DIR__"xiake-strike/" + action;
}

string *parry_msg = ({
        "$n掌风一变,只听见「锵」一声，$N被$p格开了。\n",
        "$n身子一侧，用手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

int practice_skill(object me)
{
	return notify_fail("侠客掌法只能用学(learn)的来增加熟练度。\n");
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