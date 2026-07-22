// Skill: Emei-ShenFa.c 峨眉身法
// Date : AHA 97/06/22

inherit SKILL;

string *dodge_msg = ({
  "只见$n一招「旱地拔葱」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
  "$n一招「倦鸟归林」，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
  "$n使出「金鹏展翅」，向一旁飘然纵出，轻轻着地。\n"
  "但是$n一招「旭日东升」，身形飘忽，轻轻一纵，早已避开。\n",
  "$n一招「影随人移」，身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
  "可是$n使出「变幻无常」，侧身一让，$N这一招扑了个空。\n",
  "却见$n足不点地，一招「归去来兮」，往旁窜开数尺，躲了开去。\n",
  "$n一招「似左忽右」，身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) 
  { return usage == "dodge"; }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 30 )
      return notify_fail("你的体力太差了，不能练峨眉身法。\n");
   me->receive_damage("qi", 20);
   return 1;
}
