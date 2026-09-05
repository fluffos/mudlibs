//xiantian-quan.c
//written by freecv
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIR"$N忽然龙行虎步义气风发，$n一时沉醉其中撞向$N手中$w"NOR,
	"force":  20,
        "dodge":  10,
        "damage": 500,
        "damage_type": "挫伤"
]),
([      "action": HIB"$N剑眉一竖，轻抛手中$w"+HIB"，滔天英气逼向$n的$l"NOR,
        "force":  40,
        "dodge":  20,
        "damage": 800,
        "damage_type": "挫伤"
]),
([      "action": HIM"$N低头望望手中的$w"+HIM"，又看看$n的$l，低叹一声：你，不是我的对手!"NOR,
        "force":  40,
        "dodge": 30,
        "damage": 1200,
        "damage_type": "挫伤"
]),
([      "action": HIC"$N对天轻吟：和风~~日朗，碧水~~天青，顾影~~自怜，$n岂能如我英姿~~勃发，潇洒~~多金！$n听后，只觉一股血气冲向$l"NOR,
	"force":  60,
        "dodge": 20,
        "damage": 2000,
        "damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "sword"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if (me->query("id") != "freecv")
            return notify_fail("你没有freecv帅，学习先天拳法小心走火入魔\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
  object target_ob;
  int mint,vint,mper,vper,mkar,vkar;
 int ap,dp;
  int ml,vl;

  
  target_ob = me->select_opponent();
  if (target_ob){
  mint = me->query_int();
  vint = target_ob->query_int();
  mper = me->query("per");
  mkar = me->query("kar");
  vkar = target_ob->query("kar");
  vper = target_ob->query("per");
  ml = (me->query("int")+mper+mkar+me->query("dex")+me->query("str")+me->query("con"))%10;
  vl = (target_ob->query("int")+vper+vkar+target_ob->query("dex")+target_ob->query("str")+target_ob->query("con"))%10;
  if ( ml > vl )
    ml = ml - vl;
  else
    ml = vl - ml;
  if ( ml < 1 ) ml = 1;

  ap = random(mint+mper*5+mkar*10);
  dp = random(vint+vper*5+vkar*10);
  if ( ap > dp )
  {
  me->add("qi",100);
  me->add("neili",100);
  target_ob->add("neili",-100);
  target_ob->add("qi",-me->query_skill("xiantian-quan",1)*ml);
  target_ob->start_busy(4);
// return action[3];
  }
  else if ( ap > dp / 2 )
  {
  me->add("qi",50);
  me->add("neili",50);
  target_ob->add("neili",-50);
  target_ob->add("qi",-me->query_skill("xiantian-quan",1)*(int)(ml/2));
// return action[2];
  }
}
          return action[random(sizeof(action))];

}
int practice_skill(object me)
{
        if (me->query("id") != "freecv")
            return notify_fail("freecv大人的功夫也是你学得的?别痴心妄想了\n");
        me->receive_damage("qi", -40);
        return 1;
}

string perform_action_file(string action)
{
        return "/u/freecv/obj/pfm/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
