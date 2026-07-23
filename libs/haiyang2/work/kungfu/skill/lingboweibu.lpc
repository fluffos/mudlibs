// lingboweibu.c 凌波微步
#include <ansi.h>

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

string *dodge_msg = ({
        HIR"$n足下一个踉跄，乘势向左斜出半步，恰符合了凌波微步中「忽焉纵体」的步子，闪了开来。\n"NOR ,
        HIC"$n使出「流风回雪」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n"NOR,
        HIB"$N的招式明明可以把$n围住，不知怎的，$n一式「轻云蔽月」，又如鬼魅般的跨出了圈外\n"NOR,
        HIW"$n一式「以遨以嬉」，瞻之在前，忽焉在后，$N招式的落点和$n身子间总有厘毫之差。\n"NOR,
        HIY"$n身形闪处，突然转向，使出了「神光离合」，$N加紧攻势，竟无法碰到$n一片衣角。\n"NOR,
        HIC"$n大喝一声，使出「乍阴还阳」，左足向右踏出，不料踏实之时，身子已在西北角上。\n"NOR,
        HIG"$n一式「飘忽若神」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n"NOR,
        HIG"$n一式「体迅飞枭」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n"NOR,
        RED"但是$n身形飘忽，轻轻一纵，早已避开。\n"NOR,
        YEL"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n"NOR,
        GRN"可是$n侧身一让，$N这一招扑了个空。\n"NOR,
        HIG"却见$n足不点地，往旁窜开数尺，躲了开去。\n"NOR,
        HIW"$n身形微晃，有惊无险地避开了$N这一招。\n"NOR
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move") || (usage == "parry"); 
}

int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 100)
		return notify_fail("你的知识不够，无法领会凌波微步。\n");
        if( me->query("family/family_name") != "逍遥派")
{
    if ((int)me->query("int") < 30)
		return notify_fail("你的悟性不够，无法领会凌波微步。\n");
}
	   return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
if( (int)me->query("jing") < 60 )
		return notify_fail("你的体力太差了，不能练凌波微步。\n");
if( (int)me->query("qi") < 60 )
		return notify_fail("你的体力太差了，不能练凌波微步。\n");

	me->receive_damage("jing", 40);
       me->receive_damage("qi", 40);
if( (int)me->query("qi") < 40 )
return notify_fail("你的体力太差了，不能练凌波微步。\n");
        me->receive_damage("qi", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"lingboweibu/" + action;
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

if (damage <10)
{
damage=10;      
}

if (me->query_skill("beiming-shengong",1) <100)
{
           me->delete_temp("lingboweibu");
           return 1;
}
      if(me->query_temp("lingboweibu")){
           me->delete_temp("lingboweibu");
           return 1;
           }
      if(skill > random(ob->query_skill("dodge", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("dodge") == "lingboweibu"
         && neili > 400 && skill > 150)
        {
         me->add_temp("lingboweibu", 1);    
         msg = HIG"$N不见有任何动作，只是身子一晃一转，蹴的一下转到$n的背后。\n"NOR;
	  tell_object(ob, HIR "你只觉眼前一花，不见了对手的身影！\n" NOR);
         if(neili >= neili1+random(neili1)+damage){
              msg += HIR"$n一招打空，急忙收力，力道反打了回来。\n"NOR,
//              if (damage < 10) damage=10;
              ob->receive_damage("qi", damage);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "震伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*3);
              ob->start_busy(1);
              }             
           else if(neili >= random(neili1)+damage){
              msg += HIG"\n结果$n的力道被你躲开了！\n"NOR, 
              j = -(damage*2+skill*2);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += HIC"\n结果$n的力道被躲过了一半！\n"NOR, 
              j = damage/2;               
              }
           else{
              msg += HIB"\n结果$N只躲过了$n的一小半力道！\n"NOR, 
              j = damage/2+random(damage/2); 
              }           
           message_vision(msg, me, ob);
           return j;
           }          
}
