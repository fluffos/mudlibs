// xianyun-shenfa 纤云身法
// written by dingdang
inherit SKILL;
string *dodge_msg = ({
	"却见$n展开轻功，向旁急退，避过了这一招。\n",
	"$n运起绝顶轻功，漫天飞舞，忽急忽慢，躲了开去。\n",
	"却见$n伏低身子向后一串，$N这一招扑了个空。\n",
        "$n双足点地，倏地一下从$N头顶掠过，如风拂玉树，雪裹琼苞，冷浸溶溶月。\n",
        });
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");}
int valid_learn(object me) {return 1;}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{       
               if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练纤云身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
