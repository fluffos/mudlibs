# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("sword");
    
set_short("%^BOLD%^The%^RESET%^ %^RED%^F%^BOLD%^la%^YELLOW%^mi%^RED%^n%^RESET%^%^RED%^g%^RESET%^ %^BOLD%^Sword of Heaven%^RESET%^");
    set_long("This sword was made to burn ppl that piss Inferno off. ");
    set_id(({"sword", "flaming sword"}));
    set_wc(20);            
    set_type("blade");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
