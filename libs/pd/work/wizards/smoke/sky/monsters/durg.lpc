#include <std.h>
#include <cp.h>
inherit MONSTER;

void check_quest(string *what);

void create() {
  ::create();
  set_name("Durg Rockboot");
  set_id(({ "portal keeper", "keeper", "durg rockboot", "durg" }));
  set_short("Durg Rockboot the portal keeper");
  set_long("Durg is always here, making sure the portal never "
   "vanishes. He often nods off, exhausted from the "
   "never ending task of not doing anything. He has "
   "a weary look across his face.");
  set_race("dwarf");
  set_class("fighter");
  set_subclass("berserker");
  set_money("gold", 100);
  set_body_type("dwarf");
  set("aggressive", 50);
  set_gender("male");
  set_level(95);
  set_spell_chance(70);
  set_spells(({"pummel", "rush"}));
  set_emotes(10, ({"Durg Rockboot begins to nod off.",
    "Durg Rockboot mutters random curses at the portal.",
    "%^CYAN%^Durg Rockboot grunts:%^RESET%^ I need to start charging for this thing.."}), 0);
}
void catch_tell(string str) {
  object ob;
  string a, b;

  if(this_player() == (ob = this_object())) return;
  if(sscanf(str, "%squest%s", a, b) == 2) {
    this_object()->force_me("say I dunno about no quest, but ye "
     "could do me a favor if ye want.");
    return;
  }
  if(sscanf(str, "%sfavor%s", a, b) == 2) {
    this_object()->force_me("say My wife forgot my lunch. Yeah imagine that, huh? "
     "If ye go get it for me I'd be pretty grateful.");
    return;
  }
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    call_out("check_quest", 2, ({ lower_case(a), lower_case(b) }) );
  }
}

void check_quest( string *what ) {
  object tp, ob;
  string who, that;

  who = what[0];
  that = what[1];
  tp = present(who, environment(this_object()));
  ob = present("lunchbox");
  if(!tp) return;
  if(!ob) {
    tell_object(tp, "Durg Rockboot rubs his belly.");
    return;
  }
  if(!ob->id("lunchbox_qo")) {
    tell_object(ob, "%^BOLD%^%^CYAN%^Durg Rockboot says:%^RESET%^ This "
     "ain't my lunch!");
    force_me("give "+that+" to "+who);
    return;
  }
  tell_room(environment(this_object()), "Durg Rockboot's stomach growls.",
   this_object());
  tell_object(tp, "%^CYAN%^Durg Rockboot says:%^RESET%^ Ahh... "
   "she didn't want to give it up did she? Harharhar ye "
   "did me two favors at once.. my many thanks my friend.");
  if(!tp->set_mini_quest("lunchbox", 100, "You killed Durg Rockboot's wife "
    "and brought him his lunchbox.\n"))
    tp->add_exp(1000000+random(250000));
}
