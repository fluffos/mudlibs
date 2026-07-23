
// ruanhong-zhusuo.c 软红蛛索
// by Vin 2000
//modify by windy
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N端坐不动，一式「天蛛盘丝」，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤扫向$n",
        "dodge" : -20,
        "parry" : -10,
        "damage": 30,
    "damage_type": "刺伤"
]),
([      "action": "$N一式「蛛丝马迹」，$w抖得笔直，“呲呲”破空声中向$n疾刺而去",
        "dodge" : -20,
        "parry" : -20,
        "damage": 50,
              "damage_type": "刺伤"
]),
([      "action": "$N内劲到处，将$w抖动转成两个圆圈，一式「灵蛛夺食」，从半空中往$n缠下",
        "dodge" : -30,
        "parry" : -20,
        "damage": 90,
               "damage_type": "刺伤"
]),
([      "action": "$N劲走螺旋，一式「蛛网织天」，$w在$n眼前连变数种招式，忽然从$l处倒卷上来",
        "dodge" : -10,
        "parry" : -40,
        "damage": 100,"damage_type": "刺伤"
]),
([      "action": "$N一声高喝，使出「龙蛛捉蟒」，$w急速转动，鞭影纵横，似真似幻，绞向$n",
        "dodge" : 0,
        "parry" : -40,
        "damage": 80,"damage_type": "刺伤"
]),
([      "action": "$N含胸拔背，一式「金蛛银索」，力道灵动威猛，劲力从四面八方向$n挤压出去",
        "dodge" : -10,
        "parry" : -20,
        "damage": 60, "damage_type": "刺伤"
]),
([      "action":"$N力贯鞭梢，一招「天虹密布」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "dodge" : -20,
        "parry" : -50,
        "damage": 80,
        "damage_type": "刺伤"
]),
([      "action":"$N力贯鞭梢，一招「天地蚕食」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "dodge" : -50,
        "parry" : -50,
        "damage": 110,"damage_type": "刺伤"
]),
});

int valid_learn(object me)
{
   object ob;
 if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练软红蛛索。\n");
if( (string)me->query_skill_mapped("force")!= "wudu-xinfa" && me->query("shilian")< 1)
     return notify_fail("软红蛛索必须配合五毒心经才能练。\n");
if ( me->query("family/family_name")!="黄花观五毒门"  && me->query_skill("ruanhong-zhusuo",1)<350 && !me->samsara_check

("ruanhong-zhusuo"))  
        return notify_fail("非妖魔之身不可习也。\n");  
if (me->query("class")!="yao" && !me->samsara_check("ruanhong-zhusuo"))
        return notify_fail("非妖魔之身不可习也。\n");  
   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("你必须先找一把鞭子才能练鞭法。\n");
   return 1;
}
int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("rhzs_perform");
 if( ! me->query_temp("rhzs_perform"))
      {
     if(me->query("skill_ruanhong-zhusuo")==0) return action[random(5)];
     if(random(2))return action[random(5)];
     m_actions=me->query("skill_ruanhong-zhusuo");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
  {
 return action[5];
  }
   return action[random(sizeof(action))];
}
int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习软红蛛索。\n");
  me->receive_damage("kee", 30);
   me->add("force", -3);
   write("你按着所学练了一遍软红蛛索。\n");
   return 1;
}
string perform_action_file(string func)
{
return CLASS_D("wudu") + "/ruanhong-zhusuo/" + func;
}


