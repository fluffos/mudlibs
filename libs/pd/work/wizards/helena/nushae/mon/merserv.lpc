#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_short("a merservant");
    set_id( ({ "merservant", "servant" }) );
    set_name("Servant");
    set_level(15);
    set_long("One of the many servants who have pledged their life to the King.");
    set_body_type("merperson");
    set_race("merfolk");
    set_gender("female");
    new(ARM "dhat")->move(this_object());
    this_object()->force_me("wear hat");
}
