//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create(){
    ::create();
    loads = 5;
    set("id", ({ "dwarf's pride tobacco", "tobacco", "dwarf's pride", "dwarfs pride tobacco", "dwarfs pride" }));
    set_name("dwarf's pride tobacco");
    set_short("%^RESET%^%^CRST%^%^C032%^D%^C026%^wa%^C020%^rf's %^C032%^P%^C026%^ri%^C020%^de %^RESET%^%^C058%^tobacco%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C026%^A mild blend of %^C202%^orange %^C026%^and %^C136%^mahogany %^C026%^dwarven tobaccos with aromatic Halfling Burley and Fired Stoutfolk leaf, lightly flavoured with %^C214%^w%^C220%^h%^C226%^isk%^C220%^e%^C214%^y%^RESET%^%^C026%^.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
    set_value(250);
    
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^CRST%^%^C101%^You enjoy the rich taste of the %^C214%^w%^C220%^h%^C226%^isk%^C220%^e%^C214%^y%^C101%^-infused dwarven tobacco.%^CRST%^" }));
    set_your_messages(({ "%^RESET%^%^CRST%^%^C101%^You smell the aroma of %^C214%^w%^C220%^h%^C226%^isk%^C220%^e%^C214%^y%^C101%^-infused dwarven tobacco.%^CRST%^" }));
}

int use_load(){
    ::use_load();
    set_long("%^RESET%^%^CRST%^%^C026%^A mild blend of %^C202%^orange %^C026%^and %^C136%^mahogany %^C026%^dwarven tobaccos with aromatic Halfling Burley and Fired Stoutfolk leaf, lightly flavoured with %^C214%^w%^C220%^h%^C226%^isk%^C220%^e%^C214%^y%^RESET%^%^C026%^.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
}

