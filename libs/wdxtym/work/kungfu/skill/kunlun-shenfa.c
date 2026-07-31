// kunlun-shenfa.c (kunlun) 昆仑身法
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「雁落平沙」，变招奇速，右足向前踢出，身子已然腾起，轻轻巧巧地落在一旁。\n",
	"dodge"  : 15
]),
([	"action" : "$n一式「玉龙飞起」，纵身高跃，半空中一折一转，已飘身在数丈之外。\n",
	"dodge"  : 25
]),
([	"action" : "$n一式「夏日消融」，两足足跟不动，足尖左磨，身子随之右转，卸开了$N这一招。\n",
	"dodge"  : 35
]),
([	"action" : "$n一式「枯松倒挂」，只见$n身子后仰，双掌往地下一撑，身子借势倒射而出，$N便已打$n不着。\n",
	"dodge"  : 45
]),
([	"action" : "$n一式「晴雪飞滩」，纵高伏低，东奔西闪，身形飘忽不定，$N手无足措，只得回招自守。\n",
	"dodge"  : 55
]),
([	"action" : "$n一式「冰丝带雨」，突然反手一招，竟然是两败俱伤的打法，趁$N手忙脚乱安全脱身。\n",
	"dodge"  : 65
]),
([	"action" : "$n一式「寒江钓雪」，不招不架，只微微一侧身，$N犹如暴风骤雨般的进攻便即落空。\n",
	"dodge"  : 75
]),
([	"action" : "$n一式「鱼龙潜跃」，陡然间身形拔起，直冲云霄，直如鹰隼，几个盘旋，飘飘荡荡落在数丈之外。\n",
	"dodge"  : 85
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("kunlun-shenfa");

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
	return usage == "dodge" ;
}

int valid_learn(object me)
{

    if (me->query("family/family_name")!="昆仑派")
   return notify_fail("你不是昆仑弟子，无法学习本门技能。\n");	
    if ((int)me->query_skill("xuantian-wuji", 1) < 20)		
        return notify_fail("你的玄天无极气功火候不够，无法学习本门技能。\n");

	return 1;
}

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
    if (me->query("family/family_name")!="昆仑派")
   return notify_fail("你不是昆仑弟子，无法练习本门技能。\n");	

	if( (int)me->query("jing") < 40 )
		return notify_fail("你的精力太差了，不能练昆仑身法。\n");
	me->receive_damage("jing", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kunlun-shenfa/" + action;
}
	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{

        int j,ap,dp,neili,neili1;
		ap = me->query_skill("kunlun-shenfa", 1) * me->query("con",1);
		dp = ob->query_skill("dodge", 1) * ob->query("str",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
	if (damage <10)  damage=10;      	
      if(random(ap) > dp/10
		&& me->query_skill("xuantian-wuji",1) > 100
		&& me->query_skill("kunlun-shenfa", 1) > 200
		&& me->query_skill_mapped("force") == "xuantian-wuji"
        && me->query("neili") > 1000
		&& random(5)==0	)
        { 	
        message_vision(HIB"$N身形突然拔高，一下子就蹦到昆仑山中，周身云雾缭绕。\n"NOR, me, ob); 		
		if (!ob->is_busy()) ob->start_busy(random(2));
		me->add("neili", -100 );
		   if(neili >= random(neili1)+damage)
		   {
              message_vision( HIC"$n发现$N笼罩在云雾之中，身形难以看清，只好胡乱攻出几招！\n"NOR, me, ob);
              j = -(damage*2+random(damage*2)); 
            }
			else
			{
				j = -(damage+random(damage)); 
			}
           return j;
        }          
}
