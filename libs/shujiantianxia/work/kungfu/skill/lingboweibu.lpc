// lingboweibu.c 凌波微步

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$n足下一个踉跄，乘势向左斜出半步，恰符合了凌波微步中「忽焉纵体」的步子，闪了开来。\n" ,
	"dodge"  : 30
]),
([      "action" : "$n使出「流风回雪」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n",
	"dodge"  : 40
]),
([      "action" : "$N的招式明明可以把$n围住，不知怎的，$n一式「轻云蔽月」，又如鬼魅般的跨出了圈外\n",
	"dodge"  : 50
]),
([      "action" : "$n一式「以遨以嬉」，瞻之在前，忽焉在后，$N招式的落点和$n身子间总有厘毫之差。\n",
	"dodge"  : 60
]),
([      "action" : "$n身形闪处，突然转向，使出了「神光离合」，$N加紧攻势，竟无法碰到$n一片衣角。\n",
	"dodge"  : 70
]),
([      "action" : "$n大喝一声，使出「乍阴还阳」，左足向右踏出，不料踏实之时，身子已在西北角上。\n",
	"dodge"  : 80
]),
([      "action" : "$n一式「飘忽若神」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n",
	"dodge"  : 90
]),
([      "action" : "$n一式「体迅飞枭」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n",
	"dodge"  : 100
])
});

mapping query_action(object me)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("lingboweibu");

	if (level < 80 )
		zhaoshu--;

	if (level < 60 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "parry";
}

int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 100)
		return notify_fail("你的知识不够，无法领会凌波微步。\n");
 //   if ((int)me->query_skill("qimen-bagua", 1) < 40)
//		return notify_fail("你的奇门五行的知识不够，无法领会凌波微步。\n");
    if ((int)me->query("int") < 40)
		return notify_fail("你的悟性不够，无法领会凌波微步。\n");

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
       if( (int)me->query("max_neili") < 1200 )
		return notify_fail("你的内力修为太差，强练凌波微步只会走火入魔。\n");
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练凌波微步。\n");
if( (int)me->query("jing") < 20 )
		return notify_fail("你的体力太差了，不能练凌波微步。\n");
if( (int)me->query("qi") < 20 )
		return notify_fail("你的体力太差了，不能练凌波微步。\n");

	me->receive_damage("jing", 10);
       me->receive_damage("jingli", 25);
       me->receive_damage("qi", 15);
	me->improve_skill("force", (int)me->query("int")/2);

	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("lingboweibu", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

      if(me->query_temp("lingboweibu")){
           me->delete_temp("lingboweibu");
           return 1;
           }
      if(skill > random(ob->query_skill("dodge", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("dodge") == "lingboweibu"
         && neili > 400 && skill > 80)
        {
         me->add_temp("lingboweibu", 1);    
         msg = "$N不见有任何动作，只是身子一晃一转，蹴的一下转到$n的背后。";
	  tell_object(ob, HIR "你只觉眼前一花，不见了对手的身影！\n" NOR);
         if(neili >= neili1+random(neili1)+damage){
              msg += "$n一招打空，急忙收力，力道反打了回来。\n",
              ob->receive_damage("qi", damage);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += COMBAT_D->damage_msg(damage/2, "震伤");
              msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
              j = -(damage*3);
              ob->start_busy(1);
              }             
           else if(neili >= random(neili1)+damage){
              msg += "结果$n的力道被你躲开了！\n", 
              j = -(damage*2+skill*2);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += "结果$n的力道被躲过了一半！\n", 
              j = damage/2;               
              }
           else{
              msg += "结果$N只躲过了$n的一小半力道！\n", 
              j = damage/2+random(damage/2); 
              }           
           message_vision(msg, me, ob);
           return j;
           }          
}
