#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([      "action" : "$n陡然扭身闪开，如意条游鱼般得躲过了$N的攻势。\n",
        "dodge"  : 120
]),
([      "action" : "$n身子一拔数丈，接着向後一个转折，$N招数便权数落空。\n",
        "dodge"  : 130
]),
([      "action" : "$n突然身子如鬼魅般向後滑行，倏忽已在五丈开外。\n",
        "dodge"  : 140
]),
([      "action" : "$N即将击中$n，不知道怎么$n突然消失，出现在$N後方！\n",
        "dodge"  : 150
])
});

mapping query_action(object me)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage){return usage == "dodge";}

int valid_learn(object me)
{
	if (!me->query("jiuyin/full") && !me->query("jiuyin/xia") && !me->query("jiuyin/gumu"))
		return notify_fail("你现在不能学习九阴身法。\n");
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
        if( (int)me->query_skill("jiuyin-shenfa", 1 ) < 150 )
                return notify_fail("你现在不能练习九阴身法。\n");
        if( (int)me->query("jing") < 50 )
                return notify_fail("你的精力太差，不能练习九阴身法。\n");
        if( (int)me->query("qi") < 60 )
                return notify_fail("你的内力太差了，不能练九阴身法。\n");

        me->receive_damage("jing", 35);
        me->receive_damage("qi", 30);
        return 1;
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int skill, neili, neili1;
        int j = 0;
        skill = me->query_skill("jiuyin-shenfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

        if(skill > random(ob->query_skill("dodge", 1)) 
         && random(me->query("combat_exp")) > ob->query("combat_exp")/3
         && me->query_skill_mapped("dodge") == "jiuyin-shenfa"
         && neili > 500 && skill > 80
         && me->query_temp("jiuyin/fast")){
                msg =random(2)? HIR + action[random(sizeof(action))]["action"]+NOR :
                                HIC + action[random(sizeof(action))]["action"]+NOR ; 
                message_vision(HIY"$N在刻不容缓的一瞬间躲过了$n的攻击！\n"NOR,me,ob);
                        msg += "结果$N的力道被躲开了！\n", 
                        j = -(damage+skill*2);
                message_vision(msg, ob, me);
                return j;
          } 
          return j;   
}
string perform_action_file(string action)
{
        return __DIR__"jiuyin-shenfa/" + action;
}
