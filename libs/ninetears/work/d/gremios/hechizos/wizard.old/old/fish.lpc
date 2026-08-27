#define MIN_LVL 1

mixed fish(string str,int skill, int cast);

int cast_fish(string str) {
  int skill;
  mixed ret;

  skill = (int)this_player()->query_skill_bonus("magic.spells.offensive.target");
  if (skill < MIN_LVL) {
    notify_fail("You are not skillfull enough.\n");
    return 0;
  }
  ret = fish(str, skill, 1);
  if (stringp(ret)) {
    notify_fail(ret);
    return 0;
  }
  write("You cast your Magic Missile.\n");
  return 1;
}

mixed fish(string str, int skill, int cast) {
  mixed ob;
/* now skill bonus... will range from about 1-250 or so...
 * make max damage 25 hp... ok skill/10.
 * no problems.
 * remember it will be random(dam) anyway ...
 * garanteeded of doing SOME damage.. ;)
 */
  if ((int)this_player()->query_spell_effect("attack")) 
/* used to add spells in the attack procedure. */
    return "You are already casting a spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;
  this_player()->add_spell_effect(1, "attack", "Magic Missile", this_object(),
                                "heart_beat_fish", ({ skill/10, ob, cast }));
  return 1;
}

int heart_beat_fish(object attacker, mixed *params) {
  if (params[2]) /* were we cast? */
     previous_object()->adjust_sp(-10);
  if (params[1])
    attacker = params[1];
  if (!attacker) {
    write("Your spell failed... there is no one to attack.\n");
    return 0;
  }
  say(previous_object()->query_cap_name()+" magic fishs "+
      attacker->query_name()+"\n", attacker);
  tell_object(attacker, previous_object()->query_cap_name()+
              " magic fishs you.\n");
  tell_object(previous_object(), "You magic fish "+attacker->query_name()+
                                 ".\n");
  attacker->attack_by(previous_object());
/* exp... */
  return (int)attacker->hit_player(params[0], "magic" );
}
int query_xp_cost()
{
  return 100;
}
string query_full_name()
{
  return "Magic FISH";
}
