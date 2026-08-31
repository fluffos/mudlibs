# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("dagger");
    
set_short("%^BLUE%^Dusk Dagger%^RESET%^");
    set_long("In the beginning there was chaos.  From that chaos "
        "a dagger was forged by the divine spirits and hidden.");
    set_id(({"dagger", "dusk dagger"}));
    set_wc(16);            
    set_type("knife");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
