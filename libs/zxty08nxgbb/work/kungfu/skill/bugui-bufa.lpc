// bugui-bufa.c 不归步法

inherit SKILL;

mapping *action = ({
([      "action" : "$N足下轻轻回舞，乘势向左斜出半步，恰符合了不归步法中「忽焉归去」的要旨，闪了开来。\n",
    "dodge"  : 10
]),
([      "action" : "$N使出「流连忘返」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中
躲过了$N的攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n的招式明明可以把$N围住，不知怎的，$N一式「轻云蔽月」，又如
鬼魅般的跨出了圈外。\n",
        "dodge"  : 30
]),
([      "action" : "$N一式「乘风归去」，瞻之在前，忽焉在后，$n招式的落点和$N身子
间总有厘毫之差。\n",
        "dodge"  : 40
]),
([      "action" : "$N身形闪处，突然转向，使出了「来去如梦」，$n加紧攻势，竟无法碰到
$N一片衣角。\n",
        "dodge"  : 50
]),
([      "action" : "$N大喝一声，使出「我心依旧」，左足向右踏出，不料踏实之时，身子已在
西北角上。\n",
        "dodge"  : 60
]),
([      "action" : "$N一式「归去来兮」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，
已欺到$n的身后。\n",
        "dodge"  : 70
]),
([      "action" : "$N一式「去若不归」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想
不到的所在。\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("bugui-bufa");
        return action[random(zhaoshu)];
}

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 50 )
                return notify_fail("你的体力太差了，不能练不归步法。\n");
        me->receive_damage("qi", 35);
        return 1;
}

