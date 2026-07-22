#include <ansi.h>;
inherit SKILL;
string  *msg = ({
BLU"$N单臂负后，凝目远眺，脚下虚浮，胸前门户洞开，全身姿势与武学中各
项大忌无不吻合。$n略一迟疑，浑身已为$N掌力所绕。"NOR,
BLU"$N一招[ 心惊肉跳 ]，小腹肌肉颤动，同时胸口向内收缩，倏地弹出迎向
$n的双拳。"NOR,
BLU"$N一式[ 杞人忧天 ]，抬头向天，对$n的招数浑若不见，呼的一掌向自
己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拢住$n全身。"NOR,
BLU"$N突然手足齐动，一式[ 无中生有 ]左掌右袖，双足头锤，连的胸背腰腹
尽皆有招式攻出，无一不足以伤人。"NOR,
BLU"$N一式[ 拖泥带水 ]，右手云袖飘动，宛若流水，左掌却重滞之极，便似
带着几千斤泥沙一般，暗藏五行杀机，直罩$n的$l。"NOR,
BLU"$N身影陡转，如鬼魅般忽前忽后，瞬左瞬右，一式[ 徘徊空谷 ]掌风已至
$n的$l。"NOR,
BLU"$N长叹一声，沧桑疲惫，身形凝重，却是一招[ 力不从心 ]，诱得$n全
力进击之际，反手直拍命门大穴。"NOR,
BLU"$N面目僵然，四肢挺直，无弯无折，便似[ 行尸走肉 ]般，刀臂剑腿，横
斩直刺$n的$l。"NOR,
BLU"$N一式[ 庸人自扰 ]，左手锤胸，一边晃首不止，身形却也在倏忽间绕敌
身后，右掌闪电般暴击$n的后心。"NOR,
BLU"$N突然头下脚上，倒过身子，口中嗬嗬而叫，手代足行，足似手攻，双足
狂踢未定，双手互又闪电般拍向$n的下盘。"NOR,
BLU"$N忽然狂笑不止，忽又颠哭阵阵，嬉笑哀啼，$n不由心神驿动，正迷沉恍
惚中$N已一腿攻向$n的$l。"NOR,
BLU"却见$N翻身坐倒，双手合十，默颂经文，旋及人似车轮般旋向空中，凭空
砸向$n,威力骇人，无法硬接。"NOR,
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}
mapping query_action(object me)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(4)+1)*100,
		"damage_type":random(2)?"搓伤":"淤伤",
		"dodge":200,
		"force":450
	]);
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然消魂掌必须空手。\n");
	if (me->query_skill_mapped("force") != "yunu-xinjing")
		return notify_fail("练黯然消魂掌必须有玉女心经配合。\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 100)
		return notify_fail("你的玉女心经火候不够，无法练黯然消魂掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练黯然消魂掌。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
