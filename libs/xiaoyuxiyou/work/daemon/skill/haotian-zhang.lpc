// haotian-zhang 昊天掌
// By Lgg,1998.10

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「春江潮水」，双手划了个半圈，按向$n的$l",
        "force" : 80,
        "dodge" : 10,
        "skill_name" : "春江潮水",
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「海上明月」，左手轻轻一挥，劈向$n的$l",
        "force" : 120,
        "dodge" : -8,
        "skill_name" : "海上明月",
        "damage_type" : "内伤"
]),
([      "action" : "$N右手掌心向外，由右向左，使一招「滟滟随波」，向$n的$l打去",
        "force" : 140,
        "dodge" : -10,
        "skill_name" : "滟滟随波",
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「江流宛转」，分击$n的胸口和$l",
        "force" : 100,
        "dodge" : -5,
        "skill_name" : "江流宛转",
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「月照花林」，左右掌同时击出，在空中突然左右掌方向互
变",
        "force" : 150,
        "dodge" : 20,
        "skill_name" : "月照花林",
        "damage_type" : "内伤"
]),
([      "action" : "$N左手不住晃动，右掌一招「空中流霜」，向$n的$l打去",
        "force" : 100,
        "dodge" : -20,
        "skill_name" : "空中流霜",
        "damage_type" : "内伤"
]),
([      "action" : "$N左手变掌为啄，右掌立掌如刀，一招「汀上白沙」，劈向$n的$l",
        "force" : 120,
        "dodge" : -38,
        "skill_name" : "汀上白沙",
        "damage_type" : "内伤"
]),
([      "action" : "$N左脚退后半步，右掌使一招「江天一色」，横挥向$n",
        "force" : 140,
        "dodge" : -10,
        "skill_name" : "江天一色",
        "damage_type" : "内伤"
]),
([      "action" : "$N一招「皎皎孤月」，左掌先发而后至，右掌后发而先至",
        "force" : 60,
        "dodge" : -20,
        "skill_name" : "皎皎孤月",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招「长江流水」，仪态潇洒",
        "force" : 80,
        "dodge" : -10,
        "skill_name" : "长江流水",
        "damage_type" : "内伤"
]),
([      "action" : "$N左手虚按，右手划道弧线使一招「白云悠悠」，向$n的$l插去",
        "force" : 100,
        "dodge" : -10,
        "skill_name" : "白云悠悠",
        "damage_type" : "内伤"
]),
([      "action" : "$N双手变掌做拳，向前向后划弧，一招「青枫浦上」击向$n的$l",
        "force" : 120,
        "dodge" : -28,
        "skill_name" : "青枫浦上",
        "damage_type" : "内伤"
]),
([      "action" : "$N左手虚划，右手变掌为钩一记「楼月蜚回」击向$n的$l",
        "force" : 140,
        "dodge" : 0,
        "skill_name" : "楼月蜚回",
        "damage_type" : "内伤"
]),
([      "action" : "$N施出「玉户帘中」，右掌向外挥出，左掌同时攻向$n",
        "force" : 160,
        "dodge" : -5,
        "skill_name" : "玉户帘中",
        "damage_type" : "内伤"
]),
([      "action" : "$N由臂带手，在面前缓缓划过，使一招「鸿雁长飞」，挥向$n的$l",
        "force" : 80,
        "dodge" : 22,
        "skill_name" : "鸿雁长飞",
        "damage_type" : "内伤"
]),
([      "action" : "$N负身就地，右掌使一招「鱼龙潜跃」，自下而上向$n的$l击去",
        "force" : 100,
        "dodge" : -20,
        "skill_name" : "鱼龙潜跃",
        "damage_type" : "内伤"
]),
([      "action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招「月华流照」",
        "force" : 120,
        "dodge" : 18,
        "skill_name" : "月华流照",
        "damage_type" : "内伤"
]),
([      "action" : "$N右掌不住向外扫出，是一式「闲潭落花」，左掌旋转着向$n攻去",
        "force" : 100,
        "dodge" : 16,
        "skill_name" : "闲潭落花",
        "damage_type" : "内伤"
]),
([      "action" : "$N右手经腹前经左肋向前撇出，使一招「江水流春」，向$n的$l锤去
",
        "force" : 120,
        "dodge" : -14,
        "skill_name" : "江水流春",
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「斜月沉沉」，左掌连划三个大圈，右掌从圈中穿出击向$n
",
        "force" : 150,
        "dodge" : -12,
        "skill_name" : "斜月沉沉",
        "damage_type" : "内伤"
]),
([      "action" : "$N左手向上划弧拦出，右手使一招「碣石潇湘」，手掌不住晃动，不离$n头顶方寸之间",
        "force" : 200,
        "dodge" : -30,
        "skill_name" : "碣石潇湘",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练昊天掌必须空手。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练昊天掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("emei") + "/haotian-zhang/" + func;
}
