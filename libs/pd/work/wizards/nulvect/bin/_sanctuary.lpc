
#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^GREEN%^"

#define AFFECT_OB DIR_BACKBONE_OBJECTS+"/affect_ob"

inherit DAEMON;

void sanctuary_off(mixed *args);
void sanctuary_on(mixed *args);

int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("magic defense") >= 40*3 &&
      tp->query_skill("faith") >= 40*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <sanctuary>\n\n"
    "A prayer to sanctify a room for a period of time, "
    "preventing violence and theft.",
    this_player() );
}

int can_cast(object tp) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Alas, your restless soul is too pained for that.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if ((env->query_property("no attack") && env->query_property("no steal") &&
      env->query_property("no bump")) || env->query_property("sanctuary"))
        FAIL("This room has already been sanctified.");

  if (tp->query_mp() < 300)
    FAIL("Not enough magic.");

  return 1;
}

int cmd_sanctuary(string str) {
  object tp = this_player();
  object env = environment(tp);
  int cost, time;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  time = tp->query_stats("wisdom")*3;
  time += tp->query_skill("faith")/5;
  time += tp->query_skill("magic defense");

  cost = 250 + time/10;
  cost += random(30);

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.");
  
  tp->add_mp(-cost);
  tp->set_magic_round(2);

  message("magic", COL+"You pray to sanctify this place."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" says a prayer."+RES, env, tp);

  call_out("sanctuary_on", 2, ({ env, time }) );

  return 1;
}

void sanctuary_on(mixed *args) {
  object env = args[0];
  int time = args[1];
  object ob;

  if (!env) return;

  message("magic", COL+"A bright light "+COL2+"sweeps "+
    COL+"through the area!\n\n"
    "The light "+COL2+"li"+COL+"nger"+COL2+"s"+COL+" "
    "on the "+COL2+"e"+COL+"dg"+COL2+"e"+COL+" of "
    "your "+COL2+"v"+COL+"isi"+COL2+"on"+COL+"."+RES, env);

  ob = new(AFFECT_OB);
  ob->set_affectmsg(" \n"+COL+"A soft light lingers at the edges of the room."+RES);
  ob->move(env);

  foreach (object liv in all_inventory(env))
    if (liv->is_living())
      liv->cease_all_attacks();

  DELAY_D->add_delay(time()+time, this_object(), "sanctuary_off",
    ({ env, ob, env->query_property("no attack"),
       env->query_property("no steal"), 
       env->query_property("no bump"), }), 1);

  env->remove_property("no attack");
  env->set_property("no attack", 1);
  env->remove_property("no steal");
  env->set_property("no steal", 1);
  env->remove_property("no bump");
  env->set_property("no bump", 1);

  env->set_property("sanctuary", 1);
}

void sanctuary_off(object env, object ob, int att, int steal, int bump) {

  if (ob) ob->remove();
  if (!env) return;

  message("magic", COL+"The soft light dims and fades away."+RES, env);

  env->remove_property("no attack");
  env->set_property("no attack", att);
  env->remove_property("no steal");
  env->set_property("no steal", steal);
  env->remove_property("no bump");
  env->set_property("no bump", bump);

  env->remove_property("sanctuary");
}

