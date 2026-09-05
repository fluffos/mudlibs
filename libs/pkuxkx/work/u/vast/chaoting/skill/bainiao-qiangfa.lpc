// 【百鸟朝凰枪法】

/*
百鸟朝凰枪法    dodge  10    parry  -10    damage  25
枪为百兵之王，百鸟朝凰枪威力尤猛，所以此枪善于突破
敌手的严密防守。缺点是不够轻灵，敌手要逃还是很
容易的。
*/

inherit SKILL;

mapping *action = ({
        ([      "action":
"$N使一招「飞燕啄泥」，手中$w连续刺向$n面门和哽嗓",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "刺伤",
		"skill_name" : "飞燕啄泥",
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招「雏燕穿林」刺向$n的$l",
                "damage":               60,
                "dodge":                15,
                "parry":                -10,
		"skill_name" : "雏燕穿林",
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一个跨步，使一招「黄莺落架」，手中$w势若落莺刺向$n的$l",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
		"skill_name" : "黄莺落架",
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一按枪把，啪！地一声抖出五朵枪花，一招[孔雀开屏]，上下左右，虚虚实实刺向$n全身要害",
                "damage":               55,
                "dodge":                -10,
                "parry":                -5,
		"skill_name" : "孔雀开屏",
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N一个斜跨，使个「平沙落雁」，手中$w带出一道寒气，由上而下疾刺$n$l",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
		"skill_name" : "平沙落雁",
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招「玄鸟划沙」快若闪电，毒辣无比",
                "damage":               80,
                "dodge":                5,
                "parry":                -25,
		"skill_name" : "玄鸟划沙",
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使个「大雁南飞」，身形斜飞，从侧面突出一枪，径刺$n$l",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
		"skill_name" : "大雁南飞",
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招「鸟雀齐鸣」向$n的$l横扫而去",
                "damage":               70,
                "dodge":                15,
                "parry":                -10,
		"skill_name" : "鸟雀齐鸣",
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N忽地一个转身，反手使出一招「凤凰梳羽」，$w一挺刺向$n$l",
                "damage":               100,
                "dodge":                10,
                "parry":                -20,
		"skill_name" : "凤凰梳羽",
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("neili") < 100 )
                return
notify_fail("你的内力不够，没有办法练百鸟朝凰枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");

        return 1;
}
int effective_level() { return 15;}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

        if( (int)me->query("qi") < 30
        ||    (int)me->query("neili") < 5  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        write("你按着所学练了一遍百鸟朝凰枪法。\n");
        return 1;
}
/*
string perform_action_file(string action)
{
        return __DIR__"/bainiao-spear/" + action;
}
*/