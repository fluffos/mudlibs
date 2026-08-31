# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("sword");
    
set_short("%^BLUE%^I%^RESET%^mp%^BLUE%^e%^RESET%^r%^BLUE%^ia%^RESET%^l Br%^BLUE%^oa%^RESET%^dsw%^BLUE%^o%^RESET%^rd");
    set_long("An Imperial Broadsword from the Terra Empire, most likely stolen from someone a vampire feasted on.  It is quite light and well made. ");
    set_id(({"sword", "broadsword"}));
    set_wc(17);            
    set_type("blade");
    set_mass(5);   

}
int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

