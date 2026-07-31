// hamabu.c 蛤蟆步

inherit SKILL;

string *dodge_msg = ({
       "只见$n双腿一弯一登，一下蹦起老高，躲过了$N的攻击。\n",
       "$n身子突然一矮，象只蛤蟆一样蹲了下来。$N的招式全部打在空处。\n",
      "$n双腿一并，噔~噔~噔向后连跳三下，远远地躲了开去。\n",
       "$n冲到$N面前，咬牙咧嘴，一付要拼命的样子，吓得$N连忙退开几步。\n",
       "$n低吼一声，双掌向前一推，趁势往后飘了开去。\n",
       "$n向地上连拍几掌，激起满天的灰尘，自己趁势躲过了$N这一招。\n"
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的体力太差了，不能练蛤蟆步。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
