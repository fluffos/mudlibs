#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_short("a merknight of Luti's");
    set_id( ({ "knight", "luti's night", "merknight" }) );
    set_name("luti's merknight");
    set_level(30);
    set_long("Tall, straight, stonger than any dangerous shark and more loyal than any other knights in the service of the royal family, the knights specially hired and trained by Princess Luti mean business.");
    set_body_type("merperson");
    set_race("merfolk");
    set_gender("male");
    new(WEAP "naxe")->move(this_object());
    this_object()->force_me("wield axe");
    new(ARM "ibracers")->move(this_object());
    this_object()->force_me("wear bracers");
}

int stop_me() {
  write("Princess Luti's knight holds you back as he stares stonily at you.");
    return 1;
}

void init() {
  ::init();
    add_action("stop_me", "up");
}
