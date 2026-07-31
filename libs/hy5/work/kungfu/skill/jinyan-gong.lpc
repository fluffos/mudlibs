// jinyan-gong.c 金雁功
// By Lgg,1998.10

inherit SKILL;

string *dodge_msg = ({
        "$n足尖在地面一点，身形拔地而起，躲开了这一招。\n",
        "却不料$n身形一转，突然转到了$N的身后。\n",
        "$n随着$N攻来的招式飘了起来，就如一片微风中的柳絮一般。\n",
        "$n身形左一晃、右一闪，不知怎么的，从攻击的间隙中钻了出来。\n",
        "$n足不点地地围绕$N连绕三个大圈，把$N这一招避了开去。\n",
        "$n连旋数个大圈，跟着又是一个大圈，身形高高地拔了起来。\n",
	"$n一招「天玑离枢」，身子掣忽一转，$N只觉的眼前一花，失去了目标。\n",
	"只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。\n",
	"$n使出「倒转天权」，身体急转，化为一道白光，虚幻不定的出现在$N的周围。\n",
	"$n左足一点，一招「逐影天枢」腾空而起，避了开去。\n",
	"可是$n使一招「风动玉衡」，身子轻轻向上纵起，飘了开去。\n",
	"$n身影微动，已经藉一招「开阳薄雾」轻轻闪过。\n",
	"但是$n一招「瑶光音迟」使出，早已绕到$N身後！\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 35 )
                return notify_fail("你的体力太差了，不能练习金雁功。\n");
        me->receive_damage("qi", 25);
        return 1;
}
