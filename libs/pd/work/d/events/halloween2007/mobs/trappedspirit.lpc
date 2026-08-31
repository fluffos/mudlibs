
#include <std.h>
#include <h2k7.h>

inherit MONSTER;

object finisher;
int count = 1;

void create() {
  ::create();
  set_name("spirit");
  set_id( ({ "spirit", "spirit of alan",
    "spirit of alan hosseldorf", "alan", "alan hosseldorf", }) );
  set_short("the spirit of Alan Hosseldorf");
  set_long("This spirit looks mostly human, but with a pumpkin "
    "in place of a head. The pumpkin has a face carved into it.");
  set_properties( ([ "passive": 1, "no corpse": 1, "no bump": 1 ]) );
  set_undead(1);
  set_gender("male");
  set_race("ghost");
  set_body_type("human");
  set_level(55);
  set_class("fighter");
  set_subclass("paladin");
  set_alignment(800);
  set_spells( ({ "cure me", "dispell", "headbutt", "rush", "smite" }) );
  set_spell_chance(65);
  set_heart_beat(2);
  set_chats(15, ({
    "The spirit says: It caught me off guard...",
    "The spirit sighs.",
    "The spirit says: Please, I need to protect my family.",
  }) );
}

void finish_quest(object tp) {
  if (!tp || finisher) return;

  set_chats(0, ({ }) );
  set_long("This spirit looks completely human. He smiles gently "
      "and stands with an air of quiet dignity.");

  load_object(H2K7D)->stop_reminder();
  
  finisher = tp;
}

void heart_beat() {
  ::heart_beat();

  if (!this_object() || !finisher) return;

  switch (count) {

  case 1:
    command("say You released me!");
  break;

  case 2:
    command("say I was trying to speak with my family "
            "when that shade attacked me.");
  break;

  case 3:
    command("say Now I can go watch over them in our house "
            "on Parthos road.");
  break;

  case 4:
    command("say I could never thank you enough, "+
      finisher->query_cap_name()+". I am in your debt.");
    command("bow "+finisher->query_name());
  break;

  default:
  case 5:
    message("info", "%^BOLD%^%^WHITE%^The spirit fades "
      "slowly from sight.%^RESET%^", environment(this_object()) );
    message("info", "%^BOLD%^%^WHITE%^"+finisher->query_cap_name()+
      " has released the spirit of Alan Hosseldorf "
      "from the pumpkin!%^RESET%^",
      users() );
    finisher->set_manual_quest("The Trapped Halloween Spirit", 10);
    finisher->add_exp(250000);
    finisher->add_money("platinum", 80);
    this_object()->remove();
  break;

  }

  count++;
}
