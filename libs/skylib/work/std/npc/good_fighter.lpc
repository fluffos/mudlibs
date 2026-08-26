/**
 * Inherit file used to make npc's use specials.
 * Currently no method to stop npc's using all specials, besides
 * over-riding this file, undef'ing specials, and defining them
 * to the commands you want to use.
 * Shiannar, 22/07/01.
 */

#define SPECIAL_COMMANDS ({ "pound", "slash", "feint" })
#define SPECIALS ([ \
                    "blunt" : ({"pound at $T$ with $W$"}), \
                    "pierce":({}),   \
                    "slash":({"slash at $T$ with $W$"}),   \
                    "all":({"feint at $T$ with $W$"}),   \
                    ])
#define SPECIAL_CHANCE 20

void add_actions();
void do_special();

void add_actions() {
  TO->add_combat_action(SPECIAL_CHANCE, "special_attack", (:do_special:));
  foreach(string comm in SPECIAL_COMMANDS) {
    TO->add_known_command(comm);
  }
  TO->set_combat_attitude("offensive");
}

void do_special() {
  object who;
  object weapon;
  string skill;
  string command;
  who = TO->query_attacker_list()[random(sizeof(TO->query_attacker_list()))];
  if(environment(who) != environment(TO)) {
    return; // Iirc this should never happen. But I prefer robust code
  }         // that doesn't break in 3 months when the mudlib gets tweaked.
  weapon = TO->query_holding()[random(sizeof(TO->query_holding()))];
  if(random(4)) {
    skill = weapon->query_skill();
  }
  else {
    skill = "all";
  }
  TO->concentrate(file_name(who));
  command = SPECIALS[skill][random(sizeof(SPECIALS[skill]))];
  command = replace(command, ({ "$T$", file_name(who), "$W$", file_name(weapon)}));
  TO->do_command(command);
}

void create() {
  call_out((:add_actions:), 0);
}