#include <std.h>
inherit "/d/common/mons/bat";

void create() {
   ::create();
   set_name("penguin");
   set_id(({"penguin","monster","animal"}));
   set_short("A penguin");
   set_long("This is a black and white pinguin. "+
   " They like to hang around on the ice when "+
   "they are not swimming in the sea looking for fish to eat.");
   set_gender(random(2) ? "male" : "female");
   set_race("penguin");
}
void init(){
   ::init();
   if(TP->query_stats("charisma")< 18){
      write("%^CYAN%^The penguin gets spooked by you and jumps in the water.");
      tell_room(ETO,"%^CYAN%^The penguin gets spooked by "+TPQCN+
      " and jumps in the water.");
      TO->move("/d/shadowgate/void");
      TO->remove();
   }
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 25; }
string query_DC_type(){ return "survival"; }

