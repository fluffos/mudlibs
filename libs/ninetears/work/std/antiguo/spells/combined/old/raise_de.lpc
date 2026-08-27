/*** Raise Dead Spell ****/
/*** origional author unknown ***/
/*** modified for use on FR-MUD by Eerevann ***/

/*** Sphere Necromantic ***/
/*** Level 5 ***/

#define SP_NAME "Raise Dead"
#define GP_COST 10

mixed spell(string str, int skill, int cast);

/*** Help file here ***/
string help() {
   return
   "\n\n"
   "Spell Name: "+SP_NAME+"\n"
   "Sphere:  Necromantic\n"
   "Level:  5th\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
   "  This spell raises you from the dead.  It removes one of your lives, unlike "
   "resurrect, and turns you back from being a ghost.\n\n";
}
 
int cast_spell(string str) {
  int   skill;
  mixed ret;
 
  str = (string)this_player()->expand_nickname(str);
  ret = spell(str, skill, 1);
  if (stringp(ret)) {
    notify_fail(ret);
    return 0;
  }
  write("You begin to cast Raise Dead.\n");
  return 1;
}
 
mixed spell(string str, int skill, int cast) {     
  mixed ob;

  if (!str || str == "")
    return "You try to raise nothing and fail miserably.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Who is " + capitalize(str) + "?\n";
  if (!living(ob))
    return (string)ob->query_cap_name() + " refuses to be brought to life.\n";
  if (!ob->query_property("dead"))
    return (string)ob->query_cap_name() + " is not dead ... yet.\n";
  if (ob->query_property("noregen"))
    return "Death tells you: HOLD ON, I'M NOT FINISHED WITH THEM YET.\n";
  if (cast && (int)this_player()->adjust_gp(-GP_COST) < 0)
    return "You fail to draw enough power from your diety.\n";

  write("You call upon the gods to restore " + (string)ob->query_cap_name() +
    " from " + (string)ob->query_possessive() + " immaterial state.\n");

  tell_object(ob, (string)this_player()->query_cap_name() +
    " summons the gods to raise you from the dead.\n");

  say((string)this_player()->query_cap_name() + " summons the gods to raise " +
    (string)ob->query_cap_name() + " from the dead.\n", ob);

  ob->remove_ghost();

  return (random(500));
}
