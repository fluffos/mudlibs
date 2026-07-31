// longfeng-xiang.c 龙凤双翔

inherit SKILL;

string *msg = ({
"$n突然拔地而起，在空中一叠一转，飞到$N身后，实和武当绝技「梯云纵」有同工异曲之妙。\n",
"$n脚下连登，一招「升龙式」接连跃起三此，远远飘了开去。\n",
"$n做了个「凤点头」的姿势，却又双袖挥动，轻轻向后滑出。\n",
"$n一个「凤凰双飞」，身形随着$N的攻势轻轻飘起，从容躲过这一招。\n",
"$n使出一招「玉凤穿云」，脚尖一点，身子拔高丈余，结果$N扑了个空。\n",
"$n身形一摇，幻出无数个人影，一招「百鸟朝凤」躲过了$N的攻势。\n",
"$n一招「飞凤天翔」纵身跃起，在空中一转，倏忽已落至$N身后。\n",
"$n左一摇，右一晃，一招「云凤雾凰」已轻松闪过$N的攻击。\n",
"却见$n的身形顺着$N的招式幻化不定，跟着「凤凰展翅」一转便到了$N的身后\n",
"$n脚下猛力一登，「天龙飞升」拔起丈高，逼开了$N的招式。\n",
"$n双掌连拍，一式「龙飞九天」跃起三丈高，远远飘了开去。\n",
"$n身子连续翻滚，一式「神龙降世」，跳出了$N的攻击范围。\n",
"$n一招「海底游龙」，身子一弯，贴着地面平平滑开。\n"
});

int valid_enable(string usage) 
{ 
  return usage == "dodge" || usage == "parry"; 
}

int valid_learn(object me) { return 1; }
mapping query_action(object me)
{
        return ([
            "action":msg[random(sizeof(msg))],
            "dodge":10+(random(me->query_dex())),
        ]);
}
string query_dodge_msg(object me)
{
  return msg[random(sizeof(msg))];
}
string query_parry_msg(object weapon)
{
  return msg[random(sizeof(msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的体力太差了，不能练习龙凤双翔。\n");
        me->receive_damage("jingli", 35);
        return 1;
}