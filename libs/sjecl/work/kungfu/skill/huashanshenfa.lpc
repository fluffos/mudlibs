// huashan-shenfa.c 华山身法

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「巨鹏亮翅」，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。\n",
        "dodge"  : 10
]),
([      "action" : "$n一式「风送紫霞」，双臂前伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「燕徊朝阳」，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
        "dodge"  : 30
]),
([      "action" : "$n一式「却别苍松」，一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n",
        "dodge"  : 40
]),
([      "action" : "$n一式「旭日出生」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
        "dodge"  : 50
]),
([      "action" : "$n一式「金雁横空」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
        "dodge"  : 60
]),
([      "action" : "$n一式「晚星朗月」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
        "dodge"  : 70
]),
([      "action" : "$n一式「幻眼云湮」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。\n",
        "dodge"  : 80
])
});

mapping query_action(object me)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("huashan-shenfa");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(object me)
{
        mapping action;

        action = query_action(me);

        return action["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练华山身法。\n");
        me->receive_damage("jingli", 20+random(10));
        return 1;
}
