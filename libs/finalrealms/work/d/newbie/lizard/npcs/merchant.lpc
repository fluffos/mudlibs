/*allonon 95-8-22*/
#include "path.h"
inherit "/obj/monster";

void setup() 
  {
      set_name("wealthy merchant");
      add_alias("merchant");
      add_alias("wealthy merchant");
      set_main_plural("wealthy merchants");
      set_race("half lizard-man");
      set_level(7);
      set_gender(0);
      set_random_stats(12, 18);
      set_dex(18);
      set_al(random(10));
	adjust_money(10, "silver");
      set_short("Merchant");
set_long("This is obviously a powerfull half-lizard-man since "
"he appears to be quite wealthy. Looking him over you see that "
"his purse is bulging with coins and that his bags seem to be "
"filled with goods from outside of the swamp.\n");
  new(ARMOR+"cloak")->move(this_object());
 new(WEAPON+"dagger")->move(this_object());
 this_object()->init_equip();
  }
