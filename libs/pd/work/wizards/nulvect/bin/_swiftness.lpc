
#include <std.h>
#include <dirs.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 "%^BOLD%^%^WHITE%^"

#define SWIFTNESS_CMD_ID "swiftness_stop_cmd"
#define COMMAND_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

void apply_bonuses(object, int*);
void use_sp(class Effect);
void end_swiftness(class Effect);
int do_stop(string);


int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("entertainment") >= 40*3 &&
      tp->query_skill("defense") >= 40*5)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <swiftness>\n\n"
    "The ability to move more quickly and gracefully. This taxes the user "
    "for as long as he uses it. One can <stop> it at any time as well.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You fly around swiftly.");

  if (tp->query_effect("swiftness"))
    FAIL("You are already moving swiftly!");

  if (tp->query_sp() < 100)
    FAIL("You are too tired.");

  return 1;
}

int cmd_swiftness(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;
  int *bonuses;
  int dex;
  class Effect swift;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  if (!(ob = new(COMMAND_OB)))
    FAIL("An error occurred, please contact a staff member.");

  ob->set_id( ({ SWIFTNESS_CMD_ID }) );
  ob->set_command("stop");
  ob->set_function(this_object(), "do_stop");
  ob->move(tp);

  dex = tp->query_base_stats("dexterity")/5;

  bonuses = ({
    tp->query_skill("defense")/5 + random(dex),
    tp->query_skill("double wielding")/5 + random(dex),
    tp->query_stats("dexterity")/6 + random(4),
  });

  swift = new(class Effect);
  swift->name = "swiftness";
  swift->desc = "You are moving more swiftly.";
  swift->caster = swift->target = tp;
  swift->castername = tp->query_name();
  swift->interval = 2;
  swift->endtime = time() + tp->query_skill("entertainment")*2/3 + random(15);
  swift->func = (: use_sp :);
  swift->endfunc = (: end_swiftness :);
  swift->endmessages = ({
    "Your movement slows back to normal.",
    tp->query_cap_name()+"'s movement slows back to normal.",
  });
  swift->misc = ({ ob, bonuses });

  apply_bonuses(tp, bonuses);

  tp->add_effect(swift);

  message("info",
    "You start to "+COL+"m"+COL2+"o"+COL+"v"+COL2+"e"+RES+" more "+
    COL+"s"+COL2+"w"+COL+"i"+COL2+"f"+COL+"t"+COL2+"l"+COL+"y"+RES+".",
    tp);
  message("info",
    tp->query_cap_name()+" starts to "+
    COL+"m"+COL2+"o"+COL+"v"+COL2+"e"+RES+" more "+
    COL+"s"+COL2+"w"+COL+"i"+COL2+"f"+COL+"t"+COL2+"l"+COL+"y"+RES+".",
    env, tp);

  return 1;
}

void apply_bonuses(object tp, int *bonuses) {
  if (!tp || sizeof(bonuses) != 3) return;

  tp->add_skill_bonus("defense", bonuses[0]);
  tp->add_skill_bonus("double wielding", bonuses[1]);
  tp->add_stat_bonus("dexterity", bonuses[2]);
}

void use_sp(class Effect swift) {
  object tp = swift->caster;
  if (!tp) return;
  if (tp->query_sp() < 70) {
    end_swiftness(swift);
    tp->remove_effect(swift);
  }
  else
    tp->add_sp(-(9+random(13)));
}

void end_swiftness(class Effect swift) {
  object tp = swift->target;
  object ob;
  if (!tp) return;
  ob = swift->misc[0];
  if (ob)
    ob->remove();
  apply_bonuses(tp, map(swift->misc[1], (: -1 * $1 :) ) );
}

int do_stop(string str) {
  object tp = this_player();
  class Effect swift;
  
  if (tp && str) {
    switch (str) {
      case "swiftness":
      case "moving swiftly":
        swift = tp->query_effect("swiftness");
        if (swift) {
          // remove_effect() doesn't run the endfunc
          end_swiftness(swift);
          tp->remove_effect(swift);
          return -1; // makes command ob remove itself
        }
    }
  }

  FAIL("Stop what?");
}

