//Gave new desc and made it more IG - Cythera 4/05
//Modified from new inherit. Nienne, 02/08.
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create(){
    ::create();
    loads = 5;
    set_id(({ "luxury of tharis tobacco", "tobacco", "luxury of tharis" }));
    set_name("luxury of tharis tobacco");
    set_short("%^RESET%^%^CRST%^%^C243%^L%^C244%^u%^C245%^x%^C246%^u%^C247%^r%^C248%^y %^C243%^of %^C243%^T%^C244%^h%^C245%^a%^C246%^r%^C247%^i%^C248%^s %^C058%^tobacco%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C243%^Incredibly popular and very rare.  Mild, golden Cordazethes, that possess a naturally high sweetness, are mixed with a very mild Black Cavendish. A fresh flavor with essences of exotic fruits and a touch of %^C125%^bo%^C126%^u%^C125%^rb%^C126%^o%^C125%^n %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^RESET%^%^C243%^is added to make this a very mild blend.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
    set_value(2000);
    
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^CRST%^%^C101%^You enjoy the rich taste of the %^C125%^bo%^C126%^u%^C125%^rb%^C126%^o%^C125%^n%^RESET%^%^C101%^-infused tobacco.%^CRST%^" }));
    set_your_messages(({ "%^RESET%^%^CRST%^%^C101%^You smell the sweet aroma of the %^C125%^bo%^C126%^u%^C125%^rb%^C126%^o%^C125%^n%^RESET%^%^C101%^-infused tobacco.%^CRST%^" }));
}

int use_load(){
    ::use_load();
    set_long("%^RESET%^%^CRST%^%^C243%^Incredibly popular and very rare.  Mild, golden Cordazethes, that possess a naturally high sweetness, are mixed with a very mild Black Cavendish. A fresh flavor with essences of exotic fruits and a touch of %^C125%^bo%^C126%^u%^C125%^rb%^C126%^o%^C125%^n %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^RESET%^%^C243%^is added to make this a very mild blend.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
}

