#include <std.h>

inherit MONSTER;

int do_die() {
#ifdef REALLY_DIE
    message("environment", "%^BOLD%^%^RED%^The archangels cheer!  The world "
      "is relieved at the death of the Overlord demon Desmos!", users());
    this_object()->remove();
#else
    this_object()->force_me("say You may have one this time but you "
      "will not win again.");
    say("Desmos vannishes into thin air.");
    this_object()->remove();
#endif
    return 1;
}

void create() {
    ::create();
    set_name("desmos");
    set_short("Desmos Overlord of the Demons");
    set_long("This is the overlord of all the demons.  A crazy "
      "dream one night has caused him to go crazy and search "
      "for the book of demons in the holy city of Lodos.");
    set_id(({"desmos"}));
    set_level(40);
    set_hp(10000);
    set_exp(0);
    set_gender("male");
    set_race("demon");
    set_body_type("demon");
    set_die((: do_die :));
}

