#include <npc.h>
#include <city_name.h>


#include "../DEFS.h"

void
create_monster()
{
    string tmp;
    tmp = (string) (NAMEGEN_C)->random_orc_name();
    set_name(tmp);
    set_id(({ "caretaker" }));
    set_race("human");
    set_short(capitalize(tmp) + " the Caretaker");
    set_long(capitalize(tmp)+" "
      +"is the new caretaker of the " CITY_NAME " Sanatorium.");
    set_level(26);
    set_hp(400 + random(100));
    set_money(random(150) + 50);
    set_alignment(random(2) ? AL_NICE : AL_NASTY);
    set_gender(G_MALE);
    set_wc(30,1);
    set_ac(30,1); // was 20 - Germ
    set_ep(600000);
    add_block( "south","all",0,0,
      ":%<me.name>% stops you. \"Only our patients may go there.\"",
      ":%<me.name>% stops %<him.name>%.",0,0);
}
