// taxue-wuhen
// yuer

inherit SKILL;

string *dodge_msg = ({
	"$n一招「忽如其来」，忽然间青影一闪了,$N的攻势如泥牛入海。$n却已站在原地。\n",
	"$n一个「鬼使神差」，身不弯，腰不动,人已形同鬼魅一样，退出三四丈外，避开了$N的
凌厉攻势。\n",
	"$n使出「静极思动」，忽然不可思议地一步跃开，避开了$N的攻势。\n"
});

int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练踏雪无痕。\n");
        me->receive_damage("qi", 30);
        return 1;
}


