//  Created by Whit
//  Soran

#include <std.h>
#include <soran.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("gardener");
    set_short("a tall gardener is here, pruning the trees");
    set_long("The gardener stands tall with his cutting "
      "shears in hand ready to tear up some people.  The "
      "face of the person looks old and weather-worn.");
    set_race("human");
    set_body_type("human");
    set_level(40);
    new(WEP"shears")->move(this_object());
    force_me("wield shears");
}


