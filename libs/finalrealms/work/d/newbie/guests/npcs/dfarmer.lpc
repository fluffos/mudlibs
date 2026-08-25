// borrowed from Mist with his permission.

inherit "/obj/monster";
#include "path.h"
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
   set_name("farmer");
   set_short("Farmer");
   set_long("As you look at the farmer he shies away.  The farmer "
           "doesn't appear to enjoy company much.  After failing in "
           "his attempt to become a Grimbrand Cleric he decided to "
           "stick to the thing he knew best.\n"
           "\n");
   set_gender(1);
   set_race("duergar");
   set_guild("fighter");
   set_random_stats(1, 6);
   adjust_dex(9);
   adjust_int(4);
   adjust_wis(4);
   adjust_str(16);
   adjust_cha(9);
   set_level(12);
   set_al(random(10));
   set_wimpy(0);
   add_move_zone("farm");
   load_chat(50, ({
        1, "'Look out for the Mushrooms, your stepping on them!!",
	1, ":tends his field."
   }));
   load_a_chat(100, ({
        1, ":howls with pain.",
        1, ":tries to hurt you.",
        1, ":tries to kill you"
   }));
   adjust_money(random(3), "gold");
   set_move_after(10,20);
   clone_object(WEAPONS+"dhoe")->move(this_object());
   command("equip");
}
 
