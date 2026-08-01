// create by athoi@sj 2004.xx.xx
// modify by athoi@sj 2005.01.23 更改飞跃公式

#define BASIC 		2
#define ADVANCED	3
#define SUPER		4
#define QUEST		5
#define SKILL_LEVEL 	200

string skill_name() {
  string skill, *name;

  skill = base_name(this_object());
  name = explode(skill, "/");
  return name[2];
}

mapping get_action(object me, object weapon, int power, string color) {
  int skill, force, dodge, parry;
  string action_msg;

  skill = me->query_skill(skill_name(), 1);
  force = me->query_skill(me->query_force_skill(), 1);
  parry = me->query_skill(me->query_parry_skill(), 1);
  dodge = me->query_skill(me->query_dodge_skill(), 1);
  power += LEVEL;
  if (power < 1)
    power = 1;
  //if (wizardp(me))
  //	tell_object(me, sprintf("%s = %d\n", skill_name(), power));
  if (arrayp(attack_action))
    action_msg = attack_action[random(sizeof(attack_action))];
  else if (arrayp(dodge_action))
    action_msg = dodge_action[random(sizeof(dodge_action))];
  else
    action_msg = "";
  if (skill >= 450 && arrayp(feiyue_action))
    action_msg = feiyue_action[random(sizeof(feiyue_action))];

  if (skill >= 450 || (skill >= 350 && me->query_temp("is_perform")))
    action_msg = color + replace_string(action_msg, "$w", "$w" + color) + NOR;

  return ([
    "action": action_msg,
    //"force" : force * power * (force >= FORCE_LEVEL ? 1 : 0) / 30,
    //"dodge": dodge * power * (dodge >= DODGE_LEVEL ? 1 : 0) / 30,
    //"parry": parry * power * (parry >= PARRY_LEVEL ? 1 : 0) / 30,
    //"attack": skill * power * (skill >= ATTACK_LEVEL ? 1 : 0) / 30,
    //"damage": skill * power * (skill >= DAMAGE_LEVEL ? 1 : 0) / 30,
    //"power": skill * power / 3,
    "damage_type": DAMAGE_TYPE,
  ]);
}

int practice_skill(object me, int cost) {
#ifdef IS_FORCE
  if (me->query_skill(skill_name(), 1) >= 200) {
    if (me->query("potential") > 5 && me->query("neili") > cost * LEVEL) {
      me->improve_skill(skill_name(), me->query_int("postnatal"));
      me->receive_damage("neili", cost * LEVEL);
      me->add("potential", -force_improve(me));
      return 1;
    } else
      return notify_fail("你现在的修为不足以提高" + to_chinese(skill_name()) + "了。\n");
  } else
    return notify_fail("你现在的" + to_chinese(skill_name()) + "修为只能用学(learn)的来增加熟练度。\n");
#endif
  if (me->query("jingli") < cost * LEVEL)
    return notify_fail("你的体力不够练" + to_chinese(skill_name()) + "。\n");
  if (me->query("neili") < cost * LEVEL)
    return notify_fail("你的内力不够练" + to_chinese(skill_name()) + "。\n");
  me->receive_damage("jingli", cost * LEVEL);
  if (LEARN_TYPE != "dodge")
    me->receive_damage("neili", cost * LEVEL);
  return 1;
}

int valid_learn(object me, object weapon) {
  int lvl = me->query_skill(skill_name(), 1);
#ifdef NPC_SKILL
  return notify_fail("NPC武功，不对玩家开放\n");
#endif
  if (me->query("max_neili") < lvl * lvl * LEVEL * LEVEL / (100 * ((LEVEL - 1) ? (LEVEL - 1) : 1)))
    return notify_fail("你的内力不够。\n");
  switch (LEARN_TYPE) {
    case "unarmed":
    case "claw":
    case "cuff":
    case "finger":
    case "strike":
    case "hand":
    case "leg":
      if (weapon || me->query_temp("secondary_weapon"))
        return notify_fail("学" + to_chinese(skill_name()) + "必须空手。\n");
      break;
    case "sword":
    case "blade":
    case "dagger":
    case "brush":
    case "spear":
    case "hook":
    case "stick":
    case "staff":
    case "club":
    case "throwing":
    case "whip":
    case "axe":
    case "hammer":
      if (!objectp(weapon) || weapon->query("skill_type") != LEARN_TYPE)
        return notify_fail("你使用的武器不对。\n");
      break;
    default:
      break;
  }
  if (!me->query_skill(force, 1))
    return notify_fail("学习" + to_chinese(skill_name()) + "需要有" + to_chinese(force) + "的支持。\n");
  if (me->query_skill(force, 1) < (me->query_skill(skill_name(), 1) - (5 - LEVEL) * 10)
    && me->query_skill(skill_name(), 1) < SKILL_LEVEL)
    return notify_fail("你的" + to_chinese(force) + "火候太浅。\n");
  return learn_check(me, weapon);
}

string perform_action_file(string perform) {
  return __DIR__ + skill_name() + "/" + perform;
}

string exert_function_file(string exert) {
  return __DIR__ + skill_name() + "/" + exert;
}
