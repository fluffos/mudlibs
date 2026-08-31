# include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("Dunce cap");
    
    set_short("Dunce Cap");
    set_long("A large cone shaped hat with the word %^BOLD%^%^RED%^DUNCE%^RESET%^ written on it.");
    set_id(({"cap", "hat", "dunce"}));
    set_ac(0);            
    set_mass(1);
    set_type("body armor");  
    set_limbs(({ "head", 
}));
}
void init() {
    ::init();
add_action("go_stairs", "give");
add_action("go_stairs", "remove");
add_action("go_stairs", "put");
add_action("go_stairs", "bury");
add_action("go_stairs", "hide");
add_action("go_stairs", "drop");

   add_action("slap_on_the_wrist", "wear");
}

int go_stairs() {
  if(this_player()->is_player()) return 1;
  return 0; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (!this_player()->is_player()) return 1;
   write("You are now a dunce. You must look like such a dork wearing this cap.");
    say(this_player()->query_cap_name() + " has been dubbed, Dork of the Year, with the stupidity award thrown at him from above.", this_player());
   return 0;
}
int query_auto_load() { if (this_player()->query_level() < 100) return 1; }
