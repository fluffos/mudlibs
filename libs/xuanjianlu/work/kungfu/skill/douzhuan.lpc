//Cracked by Roath
// douzhuan.c 斗转星移

#define DOU_ZHUAN "douzhuan"
#define DOU_FAKE_NAME "douzhuan/pretend_skill"
#define DOU_FAKE_TYPE "douzhuan/type"

inherit SKILL;

mapping *action = ({
  ([  "lvl" :   0,  "skill_name" : "碧草迎风" ]),
  ([  "lvl" :  25,  "skill_name" : "形影不离" ]),
  ([  "lvl" :  50,  "skill_name" : "云封雾绕" ]),
  ([  "lvl" :  75,  "skill_name" : "茫茫若梦" ]),
  ([  "lvl" : 100,  "skill_name" : "水中映月" ]),
  ([  "lvl" : 125,  "skill_name" : "镜里摘星" ]),
  ([  "lvl" : 150,  "skill_name" : "移花接木" ]),
  ([  "lvl" : 175,  "skill_name" : "天外冥冥" ]),
  ([  "lvl" : 200,  "skill_name" : "斗转星移" ]),
});

// If level >= 200, can 斗转星移 all weapons and unarmed
// If level >= 150, can 斗转星移 all short weapons and unarmed
// else,            can 斗转星移 all unarmed

int valid_enable(string usage) 
{
  object me;
  int result, skill;
  
  me = this_player();
  skill = me->query_skill(DOU_ZHUAN, 1);
  
  if ( skill >= 200)
    return usage == "strike" || usage == "parry" || usage == "sword" 
        || usage == "blade"  || usage == "hook"  || usage == "staff" 
        || usage == "club"   || usage == "stick" || usage == "pike" 
        || usage == "whip";

  if ( skill >= 150)
    return usage == "strike" || usage == "parry" || usage == "sword" 
        || usage == "blade"  || usage == "hook";

  return usage == "strike" || usage == "parry";  
}

int valid_learn(object me)
{
  if ((int)me->query("max_neili") < 100)
	return notify_fail("你的内力太弱，无法练斗转星移。\n");
  return 1;
}

string query_skill_name(int level)
{
  int i;
  for(i = sizeof(action)-1; i >= 0; i--)
    if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
  int i, level, oldLev;
  string fake_skill, fake_type;
  mapping fAct;
  int lev;
  
  fake_skill = me->query_temp(DOU_FAKE_NAME);
  fake_type = me->query_temp(DOU_FAKE_TYPE);
  
  if(fake_skill && ((!weapon && fake_type != "strike") ||
      (weapon && weapon->query("skill_type") != fake_type)) )
  {
    me->delete_temp(DOU_ZHUAN);
    fake_skill = 0;
  }
  
  
  if(!fake_skill) {
    if(weapon) return weapon->query("actions");
    else return me->query("default_actions");
  }
    
  level = (me->query_skill(DOU_ZHUAN, 1));

  if(!(oldLev = me->query_skill(fake_skill)) )
    me->set_skill(fake_skill, level);
  
  fAct = SKILL_D(fake_skill)->query_action(me, weapon);
  
  if( oldLev ) me->set_skill(fake_skill, oldLev);
  else me->delete_skill(fake_skill);
  
  if(fAct["force"]) fAct["force"] = fAct["force"]/2;
  if(fAct["dodge"]) fAct["dodge"] = fAct["dodge"]/2;
  if(fAct["parry"]) fAct["parry"] = fAct["parry"]/2;
  if(fAct["damage"]) fAct["damage"] = fAct["damage"]/2;
 
  return fAct;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
	return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 40)
	return notify_fail("你的内力不够练斗转星移。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

string perform_action_file(string action)
{
  return __DIR__ + DOU_ZHUAN + "/" + action;
}