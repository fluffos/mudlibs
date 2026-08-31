#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Golden Silk Robes");
    set("id", ({ "robe", "robes" }) );
    set("short", "%^BOLD%^%^YELLOW%^G%^WHITE%^o%^YELLOW%^lden S%^WHITE%^i%^YELLOW%^lk R%^WHITE%^o%^YELLOW%^bes");
    set("long", "%^BOLD%^%^WHITE%^These %^YELLOW%^robes %^WHITE%^are as light as a feather and as hard as 
%^RESET%^%^BLUE%^dr%^BOLD%^%^WHITE%^a%^RESET%^%^BLUE%^g%^BOLD%^%^WHITE%^o%^RESET%^ %^BLUE%^n  sc%^BOLD%^%^WHITE%^a%^RESET%^%^BLUE%^l%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^." );
set_type("robes");
set_ac(1);
set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
set_weight(25);
set_curr_value("gold", 200); 
 }
int query_auto_load() {
if (this_player()->query_level() >= 25)
return 1;
 }
