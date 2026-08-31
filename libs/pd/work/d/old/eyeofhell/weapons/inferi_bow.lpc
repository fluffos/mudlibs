#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    
void create() {
    ::create();                                                                        
    set_name("Inferi Bow");
    set("id", ({ "bow" }) );
    set("short", "%^BOLD%^%^BLACK%^I%^WHITE%^n%^BLACK%^feri B%^WHITE%^o%^BLACK%^w%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^Made by the inferi for the eye of hell, this bow is 
extreamly accurate.%^RESET%^" );
set_type("bow");
set_weight(20);
set_curr_value("gold", 175);
set_wc(10);
set_type("ranged");
set("skill level", 100);
 }
int query_auto_load() {
if (this_player()->query_level() >= 30)
return 1;
 }
