// snowstep.c 梅雪飘香步

inherit SKILL;
#include <ansi.h>

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
	"$n一式"+(order[random(13)])+"「冰消雪融」"NOR"，一下滑到丈外开去，把$N攻势化於无形。\n",
	"$n使出"+(order[random(13)])+"「金狮狂舞」"NOR"，一个筋斗从$N头上一翻而过，$N打$n不着。\n",
	"$n脚步虚踩，忽左而右，使出"+(order[random(13)])+"「雪入黄河」"NOR"从$N的腋下穿到$P身後。\n",
	"$n微笑中後退两步，身子一顿，一式"+(order[random(13)])+"「飞雪藏形」"NOR"躲过$N这一击。\n",
	"$n掉转身子，轻轻一跃，一式"+(order[random(13)])+"「狮子摇头」"NOR"轻描淡写地化开$N这一招。\n",
	"$n身子向上一纵，使出一式"+(order[random(13)])+"「踏雪无痕」"NOR"跃起数尺，飘然落到一旁。\n",
    "但是$n轻笑一声,回身高拨而起,一式"+(order[random(13)])+"「红梅飘雪」"NOR",轻轻闪过了这招。\n",
    "$n随意转身,一招"+(order[random(13)])+"「檀板金樽」"NOR",如舞乐般飘身而上,避过了这招。\n",
    "只见$n身形一旋,拨身而起,使出"+(order[random(13)])+"「梅月黄昏」"NOR",整个人都失去了踪影,令$N扑了个空。\n",
    "却见$n伸手往地上遥遥一拍,一式"+(order[random(13)])+"「梅飘九宵」"NOR",如柳絮般轻轻飘起,躲过了这招。\n",
    "$n长笑一声,一式"+(order[random(13)])+"「寒梅傲雪」"NOR",长身而起,一时四面八方都是$n的影子,虚虚实实,不知哪个才是真的。\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge");
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30 )
   return notify_fail("你的体力太差了，不能练梅雪飘香步......\n");
    me->receive_damage("qi", 10);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"snowstep/" + action;
}
