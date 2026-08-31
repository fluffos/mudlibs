# include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Tanned leather cloak");
    
    set_short("Tanned leather cloak");
    set_long("The leather in this cloak looks strangely familiar...."
             "It finally hits you!! This cloak is made from the skins"
             " of small children!!! Most would think it a bad idea to search out"
             " the maker of such a cloak.. ");
    set_id(({"cloak"}));
    set_ac(4);            
    set_mass(35);
    set_curr_value("gold", 150);
    set_type("child cloak");  
    set_wear("All around you, children scream in horror!") ;
    set_remove("Snickering can be heard as you remove the cloak");
    set_limbs(({ "torso", "right arm", "left arm" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

