#include <mjungle.h>
#include <std.h>
inherit MONSTER;
int newbody();

void create() {
  ::create();
  set_name("shallzaea");
  set_short("Shallzaea, Dark Queen of the Merkkirri");
  set_long("Shallzaea is the first queen of the Quixxiol who is not of royal blood.  Her power stems from a devilish pact made with the lord of demons Asmodeus.  Having few mortal equals, Shallazaea is by far more powerful than any Merkkirri alive.\n%^BOLD%^RED%^**Shallzaea is a very powerful adversary.**%^RESET%^");
  set("aggressive", 0);
  set_id(({"shallzaea", "queen", "merkkirri queen", "the merkkirri queen"}));
  set_class("clergy");
  set_subclass("kataan");
  set_level(65);
  set_alignment(-1000);
// set_stats("wisdom", 200);
  set_race("gnoll");
  set_body_type("gnoll");
  set_gender("female");
  set_emotes(10, ({"Shallzaea gazes coldly upon you.", "The Merkkirri Queen is surrounded by a slow moving %^MAGENTA%^violet%^RESET%^ flame."}),0);
set_stats("wisdom", query_stats("wisdom") * 125 / 100);
  set_spell_chance(50);
  set_spells(({"absorb", "darkmist", "shadowburst", "torment", "hellfire"}));
  set_lang_prof("merkish", 10);
  set_speech(50,"merkish",({"Asmodeus favors me.  Your death is unavoidable now...", "My power is infinite!", "Wretched creature!"}),1);
  set_die((: newbody() :));
  set_exp(0);
}

int newbody() {
  tell_room(environment(this_object()),
   "Shallzaea's skin shreds from her body revealing a demon within!", ({ }));
  new(MOB "queendemon")->move(environment(this_object()));
  this_object()->remove();
  return 0;
}

void catch_tell(string str) {
  string person;
  if (!sscanf(lower_case(str), "%s dies a horrible death.", person)) return;
  if (!find_player(person)) return;
  message("info", "%^BOLD%^%^MAGENTA%^Shallzaea shouts:%^RESET%^ The soul "
   "of "+capitalize(person)+" shall serve my lord well!",
   users());
}
