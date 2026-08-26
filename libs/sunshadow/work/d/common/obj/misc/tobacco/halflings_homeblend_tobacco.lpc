//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create(){
    ::create();
    loads = 5;
    set_id(({ "halfling's homeblend tobacco", "tobacco", "halfling's homeblend", "halflings homeblend tobacco", "halflings homeblend" }));
    set_name("halfling's homeblend tobacco");
    set_short("%^RESET%^%^CRST%^%^C036%^H%^C040%^a%^C046%^lfli%^C040%^n%^C036%^g%^C040%^'%^C036%^s H%^C040%^o%^C046%^meble%^C040%^n%^C036%^d %^RESET%^%^C058%^tobacco%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C036%^A mixture of broad and very ripe Halfling Burley and a double fermented Black Cavendish. A wonderful natural sweetness with a touch of %^C040%^a%^C046%^ppl%^C040%^e f%^C046%^lavo%^C040%^r%^RESET%^%^C036%^.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
    set_value(350);
    
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the naturally sweet tobacco with a touch of apple flavor.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the aroma of naturally sweet tobacco infused with a touch of apple.%^RESET%^" }));
}

int use_load(){
    ::use_load();
    set_long("%^RESET%^%^CRST%^%^C036%^A mixture of broad and very ripe Halfling Burley and a double fermented Black Cavendish. A wonderful natural sweetness with a touch of %^C040%^a%^C046%^ppl%^C040%^e f%^C046%^lavo%^C040%^r%^RESET%^%^C036%^.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
}

