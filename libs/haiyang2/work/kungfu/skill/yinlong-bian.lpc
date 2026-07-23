#include <ansi.h>
inherit SKILL;
mapping *action = ({
([     "action": HIG"$N将$w抖动成圆，一式「圆转如意」，$w已将$n$l缠住"NOR,
       "dodge": 50,
       "damage": 100,
       "force":  300,
       "lvl" : 0,
       "skill_name" : "圆转如意",
       "damage_type":  "拉伤"
]),
([     "action": HIW"$N的$w在$n身旁连连进击，忽然一招「银龙回首」从$n$l处倒卷上来"NOR,
       "dodge": 50,
       "damage": 150,
       "force": 400,
       "lvl" : 60,
       "skill_name" : "银龙回首",
       "damage_type":  "拉伤"
]),
([     "action": HIM"$N运起九阴真气，$w陡然变成笔直，一式「银龙出洞」，向$n直刺过去"NOR,
       "dodge": 50,
       "damage": 180,
       "force": 450,
       "lvl" : 90,
       "skill_name" : "银龙出洞",
       "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;
	if (!me->query("jiuyin/full") && !me->query("jiuyin/xia") && !me->query("jiuyin/emei"))
                return notify_fail("你现在不能学习九阴银龙鞭。\n");
       if( (int)me->query("max_neili") < 1000 )
               return notify_fail("你的内力修为不足，没有办法练九阴银龙鞭。\n");
       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        level   = (int) me->query_skill("yinlong-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( (int)me->query_skill("yinlong-bian", 1 ) < 150 )
		return notify_fail("你现在不能练习九阴银龙鞭。\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力不够练九阴银龙鞭。\n");
	if ((int)me->query("neili") < 100 )
		return notify_fail("你的内力不够练九阴银龙鞭。\n");
	me->receive_damage("qi",20);
	me->add("neili",-20);
	return 1;
}

string perform_action_file(string action)
{
               return __DIR__"yinlong-bian/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
 object weapon, weapon1;    
  int  wp, wp1, wp2,we1,we2;  
  weapon=me->query_temp("weapon");
     weapon1=victim->query_temp("weapon");
     if(objectp(weapon) && objectp(weapon1)){
        wp = weapon->query("rigidity");
        wp1 = weapon1->query("sharpness");
        wp2 = weapon1->query("rigidity");
     if (random(me->query_skill("yinlong-bian",1)<100))
         return 0;
     if (random(10)>4) return 0;    
             if(wp > 10) wp = 10;
             if(wp1 > 10) wp1 = 10;
             if(wp2 > 10) wp2 = 10;
             if( wp > 0 && wp > wp1 && wp > wp2 &&
              random(me->query("str")) > victim->query("str")/2){
              message_vision(HIY "只听见「唰」地一声轻响，$N手中的"+weapon1->name()+WHT"已经被"+weapon->name()+WHT"卷为两截！\n"NOR, victim );
               weapon1->unequip();
               weapon1->move(environment(victim));
               weapon1->set("name", "断掉的" + weapon1->query("name"));
               weapon1->set("value", 49);
               weapon1->set("weapon_prop", 0);
               victim->reset_action();
                } 
              if (wp==0)  {
                we1=me->query_str()+(int)me->query("jiali")+(int)me->query_skill("parry")/3;         
                we2=victim->query_str()+(int)victim->query("jiali")+(int)victim->query_skill("parry")/3;
                if (random(we1)>random(we2))
              {
 message_vision(HIY "只见「呼呼」连响，$N手中的"+weapon1->name()+HIY"已经被"+weapon->name()+"卷中一个把持不定脱手飞出！\n"NOR, victim );
if (!victim->is_busy()) victim->start_busy(random(3));
               weapon1->move(environment(victim));
               }
              }      
              }
       return 0;
}
