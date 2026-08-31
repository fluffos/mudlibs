# include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^GREEN%^S%^RESET%^%^GREEN%^l%^BOLD%^GREEN%^u%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^-%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^s%^RESET%^");
    
    set_short("%^BOLD%^GREEN%^S%^RESET%^%^GREEN%^l%^BOLD%^GREEN%^u%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^-%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^s%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^A strange looking peice of armour, the outside writhing with live %^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^ that are attached together by fine filament. It looks like they can be worn on the legs!");
    set_id(({"slugs", "leggings", "slug"}));
    set_ac(8);            
    set_mass(25);
    set_type("body armor");  
    set_wear("%^BOLD%^RED%^You feel the sharp bite of many %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^s%^RED%^ as they adhere to your carapace.") ;
    set_remove("%^RED%^The %^BOLD%^GREEN%^s%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^s%^RESET%^%^RED%^ rip through flesh and chitin as you tear them loose.");
    set_limbs(({ "left foreleg", "right foreleg", "left rear leg", "right rear leg", 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
