// a dungeonware.net production
// coded for Primal Darkness by Stormbringer
// recoded by Nulvect
#include <std.h>

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_skill("magic defense") >= 25 && tp->query_level() >= 10 &&
   member_array(tp->query_subclass(),({"sorceror","necromancer","pyromancer"})) != -1)
    return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
   "Syntax: <buffer [living]>\n\n"
   "Creates a powerful spell of protection.",
   this_player());
}

int can_cast(object tp, object ob) {
  if (!tp) return 0;

  if (!ob)
    FAIL("Cast buffer on whom?\n");

  if (environment(tp) != environment(ob))
    FAIL("That is not here.\n");

  if (!living(ob))
    FAIL("That is not alive.\n");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (ob->query("buffer_spell_wait"))
    FAIL((tp==ob?"You are":capitalize(ob->query_subjective())+" is")+" already buffered.\n");

  return 1;
}

int cmd_buffer(string str) {
  object tp=this_player();
  object ob, env;
  int defense, def;
  int cost, amount, time;

  if (!spell()) return 0;

  env = environment(tp);

  if (str == "me" || str == "myself") ob = tp;
  else if (str) ob=present(str,env);

  if (!can_cast(tp,ob)) return 0;

  defense = tp->query_skill("magic defense");
  cost = defense*2/3 + random(defense/3);

  if(this_player()->query_mp() < cost)
    FAIL("Too low on magic power.\n");

  message("magic", "You look "+(tp==ob?"over yourself":"at "+ob->query_cap_name())+
   " and call on your powers of protection.", tp);
  message("magic", tp->query_cap_name()+" looks "+
   (tp==ob?"over "+tp->query_objective()+"self":"at "+ob->query_cap_name())+
   " and calls on "+tp->query_possessive()+" powers of protection.", env, tp);

  if (defense < 50) def = 1;
  else if (defense < 100) def = 2;
  else if (defense < 150) def = 3;
  else if (defense < 200) def = 4;
  else if (defense < 250) def = 5;
  else if (defense < 300) def = 6;
  else if (defense < 350) def = 7;
  else if (defense < 400) def = 8;
  else if (defense >= 400) def = 9;

  amount = def+random(def)+1;
  time = (def*35)+random(def);

  ob->add_skill_bonus("defense",25,time);
  ob->add_magic_protection( ({ 0, amount , time }));

  ob->set("buffer_spell_wait",1);
  call_out("buffer_off", time, ob);

  tp->set_magic_round(1);
  tp->add_skill_points("magic defense", random(defense/40));
  if (ob != tp)
    tp->add_alignment(random(defense/40));
  tp->add_mp(-cost);
  return 1;
}

void buffer_off(object ob) {
  if (!ob) return;
  message("magic","%^YELLOW%^Your buffer wears off.%^RESET%^\n",ob);
  ob->set("buffer_spell_wait",0);
}
