// 神龙帝王拳   
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": HIW"$N长袖突然翻起攻向$n的$l，如流云，如泻水，招式自然巧妙，浑如天成，\n"
"口中却郎声吟道："HIC"“自传芳酒翻红袖，似有微词动绛唇。”"NOR,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
        "damage_type": "瘀伤"
]),
([      "action": HIC"$N衣衫突然鼓动而起，宛如有千百条青蛇，在衣衫中窜动，显然体内真气满蓄，\n"
"纵不动手，也可伤敌，$N口中又自朗吟道："HIM"“雾气暗通青桂苑，日华摇动黄金袍。”"NOR,
        "dodge": 15,
        "parry": 20,
        "force": 18,
        "damage": 160,
        "damage_type": "瘀伤"
]),
([      "action": HIM"$N左手下垂，五指连续点击$n的$l，身形突转，右手已自颊边翻起又挥向$n的$l，\n"
"身形流动自如口中吟道："HIB"“垂手乱翻雕玉佩，背人多整绿去鬟。”"NOR,
	"dodge": 10,
	"parry": 15,
	"force": 12,
        "damage": 160,
	"damage_type": "瘀伤"
]),
([      "action": HIB"$N右手一斜，双臂曲收，招式一变，攻中带守，$N口中吟道：\n"
HIY"“纤腰怕束金蝉断，寒鬓斜簪玉燕光。”"NOR,
        "dodge": 15,
	"parry": 11,
	"force": 16,
        "damage": 160,
	"damage_type": "瘀伤"
]),
([      "action": HIY"$N身形已回飞三次，手掌突又斜挥而起劈向$n的$l，道：\n"
HIG"“黄鹂久住浑相识，青鸟西飞意未回。”"NOR,
	"dodge": 21,
	"parry": 21,
	"force": 20,
        "damage": 160,
	"damage_type": "瘀伤"
]),
([      "action": HIG"$N微微一笑，左掌突然化作一片掌影，护住了全身七十二处大穴口中念道：\n"
HIW"“帘前春色应须惜，楼上花枝笑独眠。”右掌掌影中一指点向$n的$l。"NOR,
	"dodge": 15,
	"parry": 12,
	"force": 25,
	"damage_type": "瘀伤"
]),

([      "action" : "$n抓住$N的后颈，一把提起。"+(order[random(13)])+"「子胥举鼎」"NOR"， $N左手反转，在$n左腋底搔了一把，\n"
                   "$n身子软了下来，$N左手拿住$n腋下，右手慢慢回转，抓住$n领口，缓缓\n"
                   "举起$n的身子，过了自己头顶，向外摔出"NOR,
        "force" : 50,
        "dodge" : 5,
        "parry" : 10,
        "damage": 160,
        "lvl" : 0,
        "skill_name" : "子胥举鼎",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N俯伏地上，$n右足踏住$N的后腰，"+(order[random(13)])+"「鲁达拔柳」"NOR"，$N双腿一缩,似欲跪拜,\n"
                   "右臂却慢慢横掠而出，突然间一个筋斗，向$n的胯下钻去，只一作势\n"
                   "左手已抓住$n右脚足踝，右手向$n+(order[random(13)])+"「够魅,
        "force" : 60,
        "dodge" : 20,
        "parry" : 20,
        "damage": 190,
        "lvl" : 10,
        "skill_name" : "鲁达拔柳",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双臂反在背后，突然双手十指弯起，各成半球之形，身子向后一撞\n"
                   "十指便抓向$n的胸部，$n向后一缩，$N突然一个倒翻筋斗，身子跃起\n"
                   "双腿一分，跨在$n肩头，"+(order[random(13)])+"「狄青降龙」"NOR"，同时双手按指压住$n太阳穴,食指按眉,中指按眼",
        "force" : 100,
        "dodge" : 30,
        "parry" : 30,
        "damage": 210,
        "lvl" : 20,
        "skill_name" : "狄青降龙",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身子微曲，纤腰轻扭,左足反踢,"+(order[random(13)])+"「贵妃回眸」"NOR",向$n小腹踢去,$n后缩相避,\n"
                   "$N顺势反过身来，左手搂住$n头颈，右手握剑对准$n后心，一剑刺去",
        "force" : 70,
        "dodge" : 5,
        "parry" : 10,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "贵妃回眸",
        "damage_type" : "刺伤"
]),
([      "action" : "$N翻身卧倒,$n伸出右足踏住$N的后腰，"+(order[random(13)])+"「小怜横陈」"NOR",$N的脑袋向着她自己的胸口钻落,\n"
                   "顺势在地下一个筋斗，在$n的胯下钻过，右手握剑刺入$n的后心",
        "force" : 80,
        "dodge" : 20,
        "parry" : 20,
        "damage": 220,
        "lvl" : 10,
        "skill_name" : "小怜横陈",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右足向前轻踢,顺势一勾，"+(order[random(13)])+"「飞燕回翔」"NOR",腿上的剑疾向$n的咽喉刺去",
        "force" : 120,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "lvl" : 20,
        "skill_name" : "飞燕回翔",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="xuanming-zhang" || combo == "dulong-shenzhua"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练神龙帝王拳必须空手。\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的内力太弱了，无法练习神龙帝王拳。\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 180)
		return notify_fail("你的神龙心法火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 180)
		return notify_fail("你的神龙腿法火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("dulong-shenzhua", 1) < 180)
		return notify_fail("你的毒龙神爪功火候不够，无法神龙帝王拳.\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 180)
		return notify_fail("你的化骨绵掌火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 180)
		return notify_fail("你的蛇岛奇功火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 180)
		return notify_fail("你的神龙八式火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("xuanming-zhang", 1) < 180)
		return notify_fail("你的玄冥神掌火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("yixingbu", 1) < 180)
		return notify_fail("你的意形步法火候不够，无法学神龙帝王拳.\n");

	if ((int)me->query_skill("qingshe-sword", 1) < 80)
		return notify_fail("你的青蛇剑法火候不够，无法学神龙帝王拳.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return
notify_fail("神龙帝王拳只能用学的。\n");
}

int effective_level() { return 20;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 30;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       int lvl,nlevel;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);
nlevel= (int) me->query_skill("diwangquan",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N高声狂叫：战无不胜，攻无不克，无坚不摧，无敌不破！$n头一晕,鲜血喷出!\n";
}

        if (random(7)==0  && me->query("neili") >= 100)
        {
if (victim->query("qi") > 500)
victim->add("qi",-((random(nlevel)) / 2+1));
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "忽然感到一股莫名的恶心，阴寒的冷气攻心，全身瘫软，嘴皮乌紫。\n" NOR;
        }
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() || random(10)==0) {
                victim->receive_wound("qi", (random(nlevel)) / 2+20 );
                switch(random(3)) {
                        case 0: return HIR"你听到"+(order[random(13)])+"「喀啦」"HIR"，一声轻响，竟似是骨碎的声音！\n"NOR;
                        case 1: return RED"$N劲力一吐，$n的$l发出"+(order[random(13)])+"「喀」"RED"，地一声爆响！\n"NOR;
                        case 2: return HIY"只听见$n的$l"+(order[random(13)])+"「喀」"HIY"，地一声 ...\n"NOR;
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"diwangquan/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("diwangquan", 1)  % 10 == 0 ) {
                tell_object(me,
                        HIW "\n你突然觉得一股正气冲上心头，只觉得世间有太多的不平事....\n\n"
 NOR);
                me->add("score", 1);
        } else
                me->add("score", 1);
}

string *parry_msg = ({
	"$n深吸一口气，就象粘在$N的$w上一样。\n",
        "$n身子微微一侧，已躲开$N的攻势。\n",
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
});

string *unarmed_parry_msg = ({
        "$n身子微微一侧，已躲开$N的攻势。\n",
	"$n双拳错落，护住全身要害。\n",
        "$n双手急抓$N的手腕，$N手中的兵器几乎脱手而出。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

