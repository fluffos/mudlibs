# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("knife");
    
set_short("%^BOLD%^%^BLACK%^S%^RESET%^p%^BOLD%^%^BLACK%^y Knife%^RESET%^");
    set_long("This type knife is incredibly rare and light as paper.  Although not an incredibly powerful weapon, the spy knife is extremly stealthy. ");
    set_id(({"knife", "spy knife"}));
    set_wc(10);            
    set_type("knife");
    set_mass(1);   

}
int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

