// Chernobog (6/8/21)
// Cigar Case/Humidor

#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create(){
    ::create();
    set_id(({"cigar case","cigar box","humidor","case","box"}));
    set_name("cigar box");
    set_short("%^CRST%^%^RESET%^%^C130%^a small %^C136%^wo%^C142%^o%^C143%^d%^C136%^en%^C130%^ case%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C103%^Fashioned from %^C102%^t%^C101%^hi%^C102%^n wo%^C101%^od%^C102%^en la%^C101%^ye%^C102%^rs%^RESET%^%^C103%^, this small case opens on a cloth hinge in order to store a selection of %^C100%^cigars%^C103%^. The wood is %^C243%^d%^C102%^a%^C243%^rk eb%^C101%^o%^C102%^n%^C243%^y%^RESET%^%^C103%^ accompanied by %^C229%^g%^C227%^o%^C229%^ld s%^C227%^c%^C228%^r%^C229%^ollw%^C227%^o%^C228%^r%^C229%^k%^RESET%^%^C103%^ along the edges, typical of %^C110%^Tonovi%^C103%^ decor. The underside of the lid is ringed by %^C104%^so%^C105%^ft%^C111%^ly %^C117%^gl%^C116%^ow%^C104%^in%^C105%^g s%^C111%^cr%^C117%^ip%^C116%^t%^RESET%^%^C103%^, a passive enchantment to keep its contents humid and fresh.%^CRST%^");
    set_weight(2);
    set_value(5000);
    set_cointype("gold");
    set_max_internal_encumbrance(10);
    set_property("repairtype",({ "woodwork" }));
}

int item_allowed(object item){
    if(!item->is_cigar()){
        write("This box is only meant for cigars.");
        return 0;
    }
    if(sizeof(all_inventory(TO)) > 10){
        write("The box is already full.");
        return 0;
    }
    return 1;
}

