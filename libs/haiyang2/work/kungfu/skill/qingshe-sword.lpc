// fonxansword.c

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
        ([      "action":               
"$N使一招"+(order[random(13)])+"「青蛇狂舞」"NOR"，手中$w带着霍霍剑光，宛如一条灵蛇般刺向$n的$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出青蛇剑法中的"+(order[random(13)])+"「蛇影万道」"NOR"，剑光如梭般地斩向$n的$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招"+(order[random(13)])+"「杯弓蛇影」"NOR"，身形陡然凌空飞出数尺，手中的$w徒然斩向$n的$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式"+(order[random(13)])+"「灵蛇电闪」"NOR"对准$n的$l猛的刺出数剑",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招"+(order[random(13)])+"「雪地飞蛇」"NOR"对准$n的$l斜斜刺出一剑",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，猛然变换招事，一招"+(order[random(13)])+"「青蛇化龙」"NOR"刺向$n的$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               

"$N手中$w向外一分，使一招"+(order[random(13)])+"「蛇困忧城」"NOR"反手对准$n$l一剑刺去",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招"+(order[random(13)])+"「蛇影密布」"NOR"画出一道光弧刺向$n的$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
([  "action":"$N使一式「"+BLK+"潮泛银海"+NOR+"」，手中$w疾挽，漫天寒光，隐夹风雷之声，闪电般狂涌向$n的$l",
    "force" : 120,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : BLK "潮泛银海" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N错步上前，使出「"+RED+"银雨飞花"+NOR+"」，手中$w登时剑芒暴射，宛如漫天瑞雪飞洒向$n的$l",
    "force" : 140,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : RED "银雨飞花" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w一抖，一招「"+GRN+"花影滨飞"+NOR+"」，$w犹如狂风扫落叶般急攻向$n的$l",
    "force" : 160,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : GRN "花影滨飞" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w锵啷啷长吟一声，一式「"+BLU+"神龙寻食"+NOR+"」，$w头上脚下洒攻而下，攻势之疾，无以伦比向$n的$l",
    "force" : 180,
    "lvl" : 47,
    "skill_name" : BLU "神龙寻食" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+MAG+"西风倒卷"+NOR+"」，手中$w将剑自下拖上，端的无比毒辣使$n难断虚实，无可躲避",
    "force" : 220,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : MAG "西风倒卷" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w,一式「"+BLU+"天罗地网"+NOR+"」，仿佛一面无形的黑网向$n的$l斜斜击出",
    "force" : 260,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : BLU "天罗地网" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+HIR+"日月失色"+NOR+"」，$w银光万道，如江河倒泻，剑芒绵绵无尽向$n的胸口递去",
    "force" : 380,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : HIR "日月失色" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+YEL+"金针渡劫"+NOR+"」，$w形神合一，把全部真气贯注剑身之上，快如天光乍闪向$n刺去",
    "force" : 380,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : HIY "金针渡劫" NOR,
    "damage_type":  "刺伤"
])
});

int valid_learn(object me)
{
        object ob;


//        if( (string)me->query_skill_mapped("force")!= "wudu-force")
 //               return notify_fail("青蛇剑法必须配合五毒心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱了，无法练习\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 80)
		return notify_fail("你的神龙心法火候不够。\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 80)
		return notify_fail("你的神龙腿法火候不够。\n");

	if ((int)me->query_skill("dulong-shenzhua", 1) < 80)
		return notify_fail("你的毒龙神爪功火候不够。\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 80)
		return notify_fail("你的化骨绵掌火候不够。\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 80)
		return notify_fail("你的蛇岛奇功火候不够。\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 80)
		return notify_fail("你的神龙八式火候不够。\n");

	if ((int)me->query_skill("xuanming-zhang", 1) < 80)
		return notify_fail("你的玄冥神掌火候不够。\n");

	if ((int)me->query_skill("yixingbu", 1) < 80)
		return notify_fail("你的意形步法火候不够。\n");



        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 300
        ||      (int)me->query("neili") < 300 )
                return 
notify_fail("你的内力或气不够，没有办法练习青蛇剑法。\n");
        me->receive_damage("qi", 80);
        me->add("neili", -30);
        write("你按著所学练了一遍青蛇剑法。\n");
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
       int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
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

        if (random(7)==0 && me->query("neili") >= 100)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "忽然感到一股莫名的恶心，阴寒的冷气攻心，全身瘫软，嘴皮乌紫。\n" NOR;
        }
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() || random(10)==0) {
                victim->receive_wound("qi", (damage_bonus - 60) / 2+20 );
                switch(random(2)) {
                        case 0: return HIR"$N使出一招「灵蛇游八方」，剑气化做漫天蛇影！刺中了$n的$l。\n"NOR;
                        case 1: return RED"$N使出一招「青蛇翻身咬」，剑气化作一条长虹！刺中了$n的$l。\n"NOR;
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"qingshe-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({

        "$n使出一招「青蛇翻身咬」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「盘身」诀，将$N的$w封于丈外。\n",
        "$n使出一招「灵蛇游八方」，手中的$v化做漫天蛇影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「青蛇抢珠」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「蛇焰冲天」，整个人消失在一团剑光之中。\n",
        "$n使出一招「蛇舞九天」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，宛如七条毒蛇，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}
