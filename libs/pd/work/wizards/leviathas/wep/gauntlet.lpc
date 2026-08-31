# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("gauntlets");
    
set_short("%^BLUE%^G%^BOLD%^%^GREEN%^a%^RESET%^%^BLUE%^u%^BOLD%^%^RED%^n%^RESET%^%^BLUE%^t%^BOLD%^%^GREEN%^l%^RESET%^%^BLUE%^e%^BOLD%^%^RED%^t%^RESET%^");
    set_long("A pair of dark blue metal gauntlets studded with many emeralds and rubies. ");
    set_id(({"gauntlets"}));
    set_wc(20);            
    set_type ("melee");   

}

int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
