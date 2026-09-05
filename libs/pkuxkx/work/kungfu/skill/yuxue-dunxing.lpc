inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
WHT"$n一招「雁独行」，双臂平伸，借势一个空心筋斗向后倒翻出去。\n"NOR,
WHT"$n见状曲膝俯身以手撑地，使出一招「鱼潜」，双足一点，箭一般从$N腋下蹿了过去。\n"NOR,
WHT"$n平地带起一阵旋风，一招「狸翻」，跃起在空中几个横滚，$N的招数被化于无形。\n"NOR,
WHT"$n斜斜的倒退几步，突然探手在$N肩上一按，使出一招「鹰千里」，已经从$N头顶越过。\n"NOR,
WHT"$n使出一招「蛇游」，身体左摇右摆，飘忽不定，脚下毫无章法，$N的招数却差之毫厘，一一落空。\n"NOR,
WHT"$n纵声清啸，双掌在地下一拍，气流激动之下，一招「龙巡」冲天而起。\n"NOR,
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 50 )
                return notify_fail("你的体力太差了。\n");
        me->receive_damage("qi", 25);
        return 1;
}

