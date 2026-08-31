# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("dark sword");
    
set_short("%^BOLD%^%^BLACK%^Da%^RESET%^%^BOLD%^rk %^RESET%^S%^BOLD%^wo%^BLACK%^rd%^RESET%^");
    set_long("A pitch black sword. ");
    set_id(({"sword", "dark sword"}));
    set_wc(18);            
    set_type("blade");   

}
int query_auto_load() { if (this_player()->query_level() >=30) return 1; }
