
#include <std.h>
#include <daemons.h>

#define CHOKE_PROP "choke_abil_who"
#define CHOKE_OB_ID "choke_struggle_ob"

inherit OBJECT;

object victim, choker;

void setup(object c, object v);
int do_struggle(string str);
void remove_me();

void setup(object c, object v) {
  choker = c;
  victim = v;
}

void create() {
  ::create();
  set_id( ({ CHOKE_OB_ID }) );
  set_mass(0);
}

int drop() { return 1; }
int give() { return 1; }

void init() {
  ::init();
  if (victim && this_player() == victim)
    add_action("do_struggle", "", 1);
}

int do_struggle(string str) {
  object tp = this_player();
  string verb = query_verb();
  object env, cmd;
  string file;
  int cost;

  if (!(victim && choker) || tp != victim) return 0;

  env = environment(victim);

  if (member_array(verb, env->query_exits()) == -1) {

    file = CMD_D->find_cmd(verb, tp->query_search_path());

    if (strlen(file))
      if (!(cmd = load_object(file)))
        return 0;

    if (!cmd->abil() && !cmd->spell())
      return 0;
  }

  cost = 20+random(25);
  if (victim->query_sp() < cost) {
    message("combat", "You try to struggle, but you're too tired.", victim);
    return 1;
  }

  victim->add_sp(-cost);
  choker->add_sp(-cost);

  message("combat", "You struggle against your assailant!", victim);
  message("combat", victim->query_cap_name()+" struggles frantically!",
    env, victim);

  if (random(victim->query_stats("strength")) + victim->query_stats("dexterity") >
      random(choker->query_stats("strength")) + choker->query_stats("dexterity")) {

        message("combat", "With a great heave, you manage to break free!", victim);
        message("combat", "With a great heave, "+victim->query_cap_name()+" manages "
                          "to break free!", env, victim);
        ({victim, choker})->set_paralyzed(0, "You take a moment to recover.");
        choker->set(CHOKE_PROP, ({ }) );
        call_out("remove_me", 0);

  }

  return 1;
}

void remove_me() { remove(); }
