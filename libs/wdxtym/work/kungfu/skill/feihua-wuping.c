
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
string *dodge_msg = ({
    "$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n",
    "可是$n不紧不慢往右走了一步，躲过了$N这一招。\n",
        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
        "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，$N这一招扑了个空。\n",
        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，有惊无险地避开了$N这一招。\n",
        "$n看似无心地信手一拂，肩头微侧,堪堪避过了$N这一招。\n"
});
int valid_enable(string usage) { return (usage == "dodge") ; }
int valid_learn(object me) 
{ 
    if (me->query("family/family_name")!="浣花剑派")
   return notify_fail("你不加入浣花剑派，无法学习本门技能。\n");
if ((int)me->query_skill("guiyuan-dafa",1) < 150)
return notify_fail("你的归元大法火侯太浅。\n");
return 1;           
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	    if (me->query("family/family_name")!="浣花剑派")
   return notify_fail("你不加入浣花剑派，无法练习本门技能。\n");
        if( (int)me->query("qi") < 50 )
                return notify_fail("你的体力太差了，练不了飞花无凭。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feihua-wuping/" + action;
}
	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡bug有关
int ob_hit(object ob, object me, int damage)
{

        int j,ap,dp;
		ap = me->query_skill("feihua-wuping", 1) * me->query("int",1);
		dp = ob->query_skill("dodge", 1) * ob->query("dex",1);

	if (damage <10)  damage=10;      	
      if(random(ap) > dp/10
		&& me->query_skill("guiyuan-dafa",1) > 100
		&& me->query_skill("feihua-wuping", 1) > 200
		&& me->query_skill_mapped("force") == "guiyuan-dafa"
        && me->query("neili") > 1000
		&& random(5)==0	)
        { 	
			message_vision(HIG"$N发挥出「乱花丛中过，片叶不粘衣」的境界，轻松闪过$n的招式。\n"NOR, me, ob); 		
            j = -(damage+random(damage)); 
			me->add("neili", -100 );
			return j;        
        }  
		
}
