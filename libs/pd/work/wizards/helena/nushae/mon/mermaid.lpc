#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_name("mermaid");
    set_id(({ "mermaid", "maid" }));
    set_short("a beautiful mermaid");
    set_long("Silky hair that flows with the current, deep pools of eyes, the beauty of the mermaid is hard not to stare at.");
    set_gender("female");
    set_level(20);
    set_race("merfolk");
    set_body_type("merperson");
    new(ARM "bikini")->move(this_object());
    this_object()->force_me("wear bikini");
}
