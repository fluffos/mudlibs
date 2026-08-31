// /std/cmd/act.c
// Acts are commands that _do_ something as opposed to just general manip
// or information commands. It still inherits the command object, but it
// also has a "few" extra things.
//
// Created:     2024/02/20: Gesslar
// Last Change: 2024/02/20: Gesslar
//
// 2024/02/20: Gesslar - Created

inherit STD_CMD;

inherit EXT_CHECKS;

/** @typedef {STD_ITEM | STD_BODY} AnyTarget */
/** @typedef {STD_BODY} LivingTarget */

// Functions
int condition_check(object tp, string arg);
mixed use(object _tp, string _arg) {}
int cost_check(object tp, string arg);
void apply_cost(object tp, string arg);
object local_target(object tp, string arg, function f);
int cooldown_check(object tp, string arg);
void apply_cooldown(object tp, string arg);

// Variables
protected nomask nosave string ability_type;
protected nomask nosave int aggressive;

// Targetting
protected nomask nosave int target_current;

// Conditions
protected nomask nosave float hp_cost, sp_cost, mp_cost;
protected nomask nosave mapping cooldowns;

void mudlib_setup() {
  ability_type = "action";
}

mixed main(object tp, string arg) {
  int check_result;

  // Do pre checks
  check_result = condition_check(tp, arg);
  if(check_result == 0) return 0 ; // Failure/unavailable/etc
  if(check_result == 2) return 1 ; // Failure, but message already sent

  // Now use
  return use(tp, arg);
}

/**
 * Checks the conditions for using the ability, including
 * whether the player is already acting, cooldown readiness,
 * and resource cost availability.
 *
 * @param {STD_BODY} tp - The player to check conditions for
 * @param {string} arg - The argument passed to the ability
 * @returns {int} 1 if conditions are met, 2 if not met but
 *                message was sent, 0 if unknown
 */
int condition_check(object tp, string arg) {
  if(tp->is_acting()) {
    tell(tp, "You are already doing something.\n");
    return 2;
  }

  // Cooldown checks
  if(!cooldown_check(tp, arg))
    return 2;

  // Cost checks
  if(!cost_check(tp, arg))
    return 2;

  return 1;
}

/**
 * Returns the type of ability.
 *
 * @returns {string} The ability type identifier
 */
string query_ability_type() {
  return ability_type;
}

/**
 * Finds a local target for the ability. If no argument is
 * provided and target_current is set, falls back to the
 * player's highest threat target. For aggressive abilities,
 * also validates that combat is permitted.
 *
 * @param {STD_BODY} tp - The player using the ability
 * @param {string} arg - The target identifier string
 * @param {function} [f] - Optional filter function for target validation
 * @returns {AnyTarget | 0} The target if found, 0 if not
 * @errors If tp is not a valid object
 */
varargs object local_target(object tp, string arg, function f) {
  object t;
  object source;
  mixed result;

  if(!objectp(tp))
    error("Bad argument 1 to local_target().\n");

  if(falsy(arg)) {
    if(target_current) {
      if(t = tp->highest_threat())
        return t;
      else {
        tell(tp, "You need to specify a target.\n");
        return 0;
      }
    } else {
      tell(tp, "You need to specify a target.\n");
      return 0;
    }
  }

  source = environment(tp);

  if(!t = find_target(tp, arg, source, f)) {
    tell(tp, "You don't see "+add_article(arg)+" here.\n");
    return 0;
  }

  if(aggressive == 1) {
    if(stringp(result = tp->prevent_combat(t))) {
      tell(tp, append(result, "\n"));
      return 0;
    }
  }

  return t;
}

varargs object carried_target(object tp, string arg, function f) {
  object t;
  object source;

  if(!objectp(tp))
    error("Bad argument 1 to carried_target().\n");

  if(!stringp(arg) || falsy(arg)) {
    tell(tp, "You need to specify a target.\n");
    return 0;
  }

  source = tp;

  if(!t = find_target(tp, arg, source, f)) {
    tell(tp, "You don't see "+add_article(arg)+" here.\n");
    return 0;
  }

  return t;
}

varargs object carried_or_local_target(object tp, string arg, function f) {
  object t;
  object source;

  if(!objectp(tp))
    error("Bad argument 1 to carried_target().\n");

  if(!stringp(arg) || falsy(arg)) {
    tell(tp, "You need to specify a target.\n");
    return 0;
  }

  if(starts_with(arg, "my ")) {
    arg = chop(arg, "my ", 1);

    object ob = find_target(tp, arg, tp, f);

    if(ob)
      return ob;

    tell(tp, "You don't have "+add_article(arg)+".\n");

    return 0;
  } else if(ends_with(arg, " here")) {
    arg = chop(arg, " here", -1);

    object ob = find_target(tp, arg, environment(tp), f);

    if(ob)
      return ob;

    tell(tp, "You don't see "+add_article(arg)+" here.\n");

    return 0;
  }

  source = tp;
  if(t = find_target(tp, arg, source, f))
    return t;

  source = environment(tp);
  if(t = find_target(tp, arg, source, f))
    return t;

  tell(tp, "You don't see "+add_article(arg)+" here.\n");
}

/**
 * Checks whether the player has sufficient HP, SP, and MP to cover the
 * ability's resource costs.
 *
 * @param {STD_BODY} tp - The player to check resources for
 * @returns {int} 1 if the player can afford the cost, 0 if not
 */
int cost_check(object tp) {
  if(hp_cost && tp->query_hp() < hp_cost) {
    tell(tp, "You are too weak to do that.\n");
    return 0;
  }

  if(sp_cost && tp->query_sp() < sp_cost) {
    tell(tp, "You are too drained to do that.\n");
    return 0;
  }

  if(mp_cost && tp->query_mp() < mp_cost) {
    tell(tp, "You are too tired to do that.\n");
    return 0;
  }

  return 1;
}

/**
 * Applies the ability's resource costs by deducting HP, SP,
 * and MP from the player.
 *
 * @param {STD_BODY} tp - The player to deduct costs from
 */
void apply_cost(object tp) {
  hp_cost && tp->adjust_hp(-hp_cost);
  sp_cost && tp->adjust_sp(-sp_cost);
  mp_cost && tp->adjust_mp(-mp_cost);
}

/**
 * Finds the matching cooldown key for the given argument by checking against
 * the cooldown mapping's test patterns.
 *
 * @private
 * @param {string} arg - The argument to match against
 *                       cooldown patterns
 * @returns {string | undefined} The cooldown key if found, 0 if no match
 */
private string find_cooldown_key(string arg) {
  string key, test;
  string *cles;

  if(!mapp(cooldowns))
    return undefined;

  cles = keys(cooldowns);

  if(sizeof(cles) == 1) {
    key = cles[0];
    test = cooldowns[key][0];

    if(test == "" || arg == test || pcre_match(arg, test))
      return key;

    return null;
  }

  foreach(key in cles) {
    test = cooldowns[key][0];

    if(test == "")
      continue;

    if(arg == test || pcre_match(arg, test))
      return key;
  }

  return null;
}

/**
 * Checks whether the ability's cooldown has expired for the
 * given player.
 *
 * @param {STD_BODY} tp - The player to check cooldowns for
 * @param {string} arg - The argument passed to the ability
 * @returns {int} 1 if the cooldown is ready or no cooldown applies, 0 if
 *                still on cooldown
 */
int cooldown_check(object tp, string arg) {
  string key = find_cooldown_key(arg);

  if(!key)
    return 1;

  if(tp->query_cooldown_remaining(key) > 0) {
    tell(tp, "You must wait before you can use that again.\n");
    return 0;
  }

  return 1;
}

/**
 * Applies the cooldown for the ability to the player based
 * on the matched cooldown key and its configured duration.
 *
 * @param {STD_BODY} tp - The player to apply the cooldown to
 * @param {string} arg - The argument passed to the ability
 */
void apply_cooldown(object tp, string arg) {
  string key;

  key = find_cooldown_key(arg);
  if(!key)
    return;

  tp->add_cooldown(key, cooldowns[key][1]);
}
