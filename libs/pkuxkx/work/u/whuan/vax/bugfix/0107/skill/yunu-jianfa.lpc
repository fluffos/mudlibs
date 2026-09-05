// yunu-jianfa 玉女剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「柳荫联句」，手中$w竖削三下，而后一剑掠出，划向$n的$1。",
        "damage" : 40,
        "dodge" : 10,
        "force": 100,
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N左手外拨，右手中$w微举，陡变为数朵剑花，齐刺$n的$1，正是一招「竹帘临池」。",
        "force" : 200,
        "dodge" : 20,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑走轻灵，手中$w微抖，招断意连，绵绵不绝地逼向$n的$1，却是一招「池边调鹤」。",
        "force" : 200,
        "dodge": 30,
        "damage" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一式「抚琴按萧」，左手微按，右手$w递出，但见青光激荡，剑花点点，四散而下，洒向$n.",
        "damage" : 80,
        "force" : 200,
        "dodge" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「清饮小酌」，剑尖上翻，竞是指向自己樱唇，宛似举杯自饮一般，而后$w一弯，弹向$n的前胸。",
       "force" : 200,
        "dodge" : 40,
        "damage" : 100,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一招「浪迹天涯」，趋身而进，手中$w挥出，飘逸无比地向$n的$1掠去.",
        "damage" : 120,
        "dodge" : 50,
        "force": 250,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w轻扬，飘身而进，姿态飘飘若仙，剑锋向$n的下盘连点数点，却是一招「小园艺菊」.",
        "damage" : 170,
        "dodge" : 50,
        "force": 400,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一招「彩笔画眉」，$w横剑斜削，然后微微两颤，合成一式「帘下梳妆」，刺向$n的$1.",
        "damage" : 160,
        "dodge" : 50,
        "force": 350,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手握住剑柄，举剑上挑，一式「举案齐眉」刺向$n的$1，剑意中温雅疑疑，风光旖旎。",
        "damage" : 140,
        "dodge" : 40,
        "force": 300,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N手中$w来回挥削，如鲜花招展风中，颤动地刺向$n,只晃得$n眼花缭乱，浑不知剑招从何处攻来，正是一招「花前月下」.",
        "damage" : 180,
        "dodge" : 40,
        "force": 450,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }
int valid_combine(string combo) { return combo=="changhen-bian"; }
int valid_learn(object me)
{
//	if(me->query("gender")!="女性"&&(int)me->query_skill("yunu-jianfa",1)>100)
//		return notify_fail("你不是女性，对「玉女剑法」柔和的剑气不能好好地掌握。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("你的玉女心经等级不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
//	if(me->query("gender")!="女性"&&(int)me->query_skill("yunu-jianfa",1)>100)
//		return notify_fail("你不是女性，对「玉女剑法」柔和的剑气不能好好地掌握。\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练玉女剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
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
        return __DIR__"yunu-jianfa/" + action;
}
