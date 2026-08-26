// Chernobog (3/9/22)
// Bottle of Rum

#include <std.h>

inherit OBJECT;

int drinks;

void create(){
    ::create();
    set_name("bottle of rum");
    set_id(({"bottle", "rum", "bottle of rum", "rum bottle"}));
    set_short("%^RESET%^%^CRST%^%^C144%^bottle of %^C130%^rum%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C144%^This is a spiced rum, %^C130%^dark brown %^RESET%^%^C144%^in hue with a sweet, syrupy fragrance and a hint of %^C250%^v%^C255%^ani%^C250%^l%^C255%^l%^C250%^a%^RESET%^%^C144%^. The bottle has accrued a thin layer of dust from storage. It was originally sealed by a cap of %^C196%^c%^C124%^ri%^C196%^ms%^C124%^o%^C196%^n %^C124%^wax%^RESET%^%^C144%^, but all that remains are cracked remnants around the mouth and neck of the bottle, enticing you to take a %^C143%^drink%^RESET%^%^C144%^.%^CRST%^" 
    );
    set_weight(6);
    set_value(500);
    drinks = 6;
}

void init(){
    ::init();
    add_action("drink_fun","drink");
}

int drink_fun(string str){
    object room, drinker, bottle;
    room = environment(this_player());
    drinker = this_player();
    bottle = this_object();
    
    if(!str) return 0;
    if(str == "from the bottle" || str == "from the bottle of rum" || str == "rum"){
        if(drinks < 1){
            tell_object(drinker, "%^RESET%^%^CRST%^%^C243%^The rum bottle is %^C059%^empty%^C243%^.%^CRST%^\n");
            return 1;
        }

        if(drinks > 1){
            tell_object(drinker,"%^RESET%^%^CRST%^%^C144%^You take a long swig from the bottle, the %^C130%^dark brown liquid %^RESET%^%^C144%^radiating %^C124%^warmth %^C144%^along your throat.%^CRST%^");
            tell_room(room,"%^RESET%^%^CRST%^%^C144%^"+drinker->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ takes a long swig from the bottle.%^CRST%^", drinker);
            drinker->add_intox(125);
            drinks -= 1;
            return 1;
        }
        if(drinks == 1) {
            tell_object(drinker,"%^RESET%^%^CRST%^%^C144%^You drain the last bit of rum from the bottle, the %^C130%^dark brown liquid %^RESET%^%^C144%^radiating warmth along your throat.%^CRST%^");
            tell_room(room,"%^RESET%^%^CRST%^%^C144%^"+drinker->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ drains the last bit from the bottle.%^CRST%^", drinker);
            drinker->add_intox(125);
            drinks -= 1;
            bottle->set_id(({"empty bottle", "bottle", "empty bottle of rum", "empty rum bottle"}));
            bottle->set_short("%^RESET%^%^CRST%^%^C144%^an empty bottle%^CRST%^");
            bottle->set_long("%^RESET%^%^CRST%^%^C144%^This is an empty bottle. There are some fragments of %^C196%^c%^C124%^ri%^C196%^ms%^C124%^o%^C196%^n %^C124%^wax %^RESET%^%^C144%^around the mouth and along the neck.%^CRST%^");
            bottle->set_weight(1);
            return 1;
        }
    }
    tell_object(drinker, "You could try to drink from the bottle.");
    return 0;
}

