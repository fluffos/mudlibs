#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_short("an old merservant");
    set_id( ({ "merservant", "servant", "old merservant" }) );
    set_name("Servant");
    set_level(20);
    set_long("One of the many servants who have pledged their life to the King. This one seems to have not bathed in a while, and is very lost...");
    set_body_type("merperson");
    set_race("merfolk");
    set_gender("male");
    new(ARM"dhat")->move(this_object());
    this_object()->force_me("wear hat");
    set_lang_prof("selunian", 10);
    set_speech(10, "selunian", ({"I've been down here a long time...",
                             "Am I still in trouble with Princess Luti? Am I forgiven?",
                             "Do I get to go back yet?"}), 0);
}
