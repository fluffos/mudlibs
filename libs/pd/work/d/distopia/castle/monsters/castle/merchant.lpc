#include <std.h>
inherit MONSTER;
void create() {
::create();
    set_name("merchant");
    set_short("A cowardly merchant");
    set_long("The merchant is currently cowering behind his wagon, trying to avoid any fighting as his guards defend him.");
    set_id(({"human", "merchant", "monster"}));
    add_money("gold", 200);
    set_level(20);
    set_race("human");
    set_body_type("human");
    set_gender("male");
    
    
    set_emotes(20,     // He will emote this line once every 10 heart beats
	({"The merchant screams at the battle",
	  "The merchant cowers by his wagon",
	  "The merchant looks at you and screams for help"
	}),
	1);
}
void bash(object ob) {
  
  this_object()->force_me("kill brigand");
  this_object()->force_me("kill brigand 2");
    this_object()->force_me("kill bandit");
      this_object()->force_me("kill bandit 2");
}
void init() {
   object *all;
   int i;
   ::init();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
        call_out("bash", 3, all[i]);
   return;
   }
}		
