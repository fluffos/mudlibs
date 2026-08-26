//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create(){
    ::create();
    loads = 5;
    set_id(({ "tsarven", "tobacco", "tsarven tobacco" }));
    set_name("tsarven");
    set_short("%^RESET%^%^CRST%^%^C196%^Ts%^C124%^ar%^C196%^v%^C124%^e%^C196%^n %^C058%^tobacco%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C124%^%^A satisfying, spicy and aromatic blend of Black Cavendish, Golden & Red Undrin, mixed with luxury brocken flake. The aromatic recipe of %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^C124%^and %^C136%^rum %^RESET%^%^C124%^make this blend smooth and very pleasant.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
    set_value(400);
    
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^CRST%^%^C101%^You enjoy the rich taste of the %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^RESET%^%^C101%^and %^C136%^rum %^RESET%^%^C101%^infused Tsarven tobacco.%^CRST%^" }));
    set_your_messages(({ "%^RESET%^%^CRST%^%^C101%^You smell the odor of %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^RESET%^%^C101%^and %^C136%^rum %^RESET%^%^C101%^infused Tsarven tobacco.%^CRST%^" }));
}

int use_load(){
    ::use_load();
    set_long("%^RESET%^%^CRST%^%^C124%^%^A satisfying, spicy and aromatic blend of Black Cavendish, Golden & Red Undrin, mixed with luxury brocken flake. The aromatic recipe of %^C255%^v%^C229%^ani%^C255%^l%^C229%^l%^C255%^a %^C124%^and %^C136%^rum %^RESET%^%^C124%^make this blend smooth and very pleasant.\n%^RESET%^%^CRST%^%^C058%^There are " + loads + " loads left in the pouch.%^CRST%^");
}

