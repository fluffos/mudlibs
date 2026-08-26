// Chernobog & Titania (3/10/22)
// The Wailing Isle - Kraken Stomach

#include <std.h>
#include "../defs.h"

inherit ROOM;

object controller;
int counter, digesting;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 0);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("a kraken's stomach");
    set_short("%^RESET%^%^CRST%^%^C065%^inside a %^C108%^k%^C107%^r%^C106%^ake%^C107%^n'%^C108%^s %^RESET%^%^C065%^stomach%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C065%^The %^C065%^fleshy walls %^C065%^around you pulse and contract, gleaming wetly in the darkness. Pools of %^C118%^c%^C112%^or%^C106%^r%^C118%^o%^C112%^si%^C106%^v%^C118%^e %^C112%^ac%^C106%^i%^C118%^d%^C112%^s %^RESET%^%^C065%^bubble and spurt as the kraken's stomach attempts to digest anything that falls within. The %^C252%^o%^C255%^d%^C252%^d %^C255%^bo%^C252%^n%^C255%^e %^C065%^and %^C058%^sc%^C100%^ra%^C058%^p of %^C245%^m%^C247%^e%^C249%^t%^C247%^a%^C245%^l %^RESET%^%^C065%^hints at the indiscriminate diet of the leviathan.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C151%^It isn't pleasant, with a strong acidic aroma stinging your nostrils.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C143%^You're surrounded by the wet squelching sounds of digestion.%^CRST%^");
    set_items(([
        ]));
    set_exits(([
        ]));
    digesting = 0;
}

void init(){
    ::init();
    call_out("digest_fun", 3, this_player());
    if(!digesting) counter = 1;
    digesting = 1;
}

void digest_fun(object victim){
    switch(counter){
        case 1 :
            message("environment", "%^RESET%^%^CRST%^%^C118%^Strange gurgles seem to emanate from deeper within the cavernous organ. Dirty water sloshes along your feet, splashing about as the ground quivers.%^CRST%^\n", victim);
            break;
        case 2 :
            message("environment", "%^RESET%^%^CRST%^%^C112%^The fleshy walls seem to tighten, pulling in on themselves...%^CRST%^\n", victim);
            break;
        case 3 :
            message("environment", "%^RESET%^%^CRST%^%^C106%^...and the acidic fluids seem to drain away, pooling at the far end of the stomach.%^CRST%^\n", victim);
            break;
        case 4 :
            message("environment", "%^RESET%^%^CRST%^%^C064%^A tense moment of anticipation seems to fill the stifling, humid air.%^CRST%^\n", victim);
            break;
        default :
            message("info", "Something went wrong, please contact Chernobog.", victim);
    }
    
    if(counter > 3){
        call_out("vomit_fun", 6, victim);
        digesting = 0;
        return;
    }
    else call_out("digest_fun", 3, victim);
    
    counter ++;
    return;
}

void vomit_fun(object victim){
    object kraken_room;
    int i;
    kraken_room = environment(controller);
    
    message("environment", "%^RESET%^%^CRST%^%^C102%^Everything seems to shiver violently, quivering and tightening... and then flooding as the kraken %^C143%^v%^C137%^o%^C131%^mi%^C143%^t%^C137%^s%^RESET%^%^C102%^! You are expelled up and out and land heavily on the %^C058%^deck %^C102%^of the %^C058%^ship%^RESET%^%^C102%^, coated in bile and saliva.%^CRST%^", this_object());
    message("environment", "%^RESET%^%^CRST%^%^C102%^The kraken seems to pause for a moment, turning a faintly %^C107%^greener color%^C102%^... and then %^C143%^v%^C137%^o%^C131%^mi%^C143%^t%^C137%^s%^RESET%^%^C102%^, expelling "+victim->query_cap_name()+"%^RESET%^%^CRST%^%^C102%^ onto the deck in a wash of bile and saliva.%^CRST%^", kraken_room, victim);
    victim->move(kraken_room);
    victim->force_me("look");
    return;
}

void set_controller(object target){
    if(!objectp(target)) return;
    
    controller = target;
    return;
}

void empty_stomach(){
    object kraken_room, *everything;
    int i;
    everything = all_living(this_object());
    kraken_room = environment(controller);
    
    message("environment", "%^RESET%^%^CRST%^%^C102%^Everything seems to shiver violently, quivering and tightening... and then flooding as the kraken %^C143%^v%^C137%^o%^C131%^mi%^C143%^t%^C137%^s%^RESET%^%^C102%^! You are expelled up and out and land heavily on the %^C058%^deck %^C102%^of the %^C058%^ship%^RESET%^%^C102%^, coated in bile and saliva.%^CRST%^", this_object());
    
    for(i = 0; i < sizeof(everything); i++){
        if(userp(everything[i])){
            
            message("environment", "%^RESET%^%^CRST%^%^C102%^The kraken seems to pause for a moment, turning a faintly %^C107%^greener color%^C102%^... and then %^C143%^v%^C137%^o%^C131%^mi%^C143%^t%^C137%^s%^RESET%^%^C102%^, expelling "+everything[i]->query_cap_name()+"%^RESET%^%^CRST%^%^C102%^ onto the deck in a wash of bile and saliva.%^CRST%^", kraken_room, everything[i]);
            everything[i]->move(kraken_room);
            everything[i]->force_me("look");
        }
        continue;
    }
    
    return;
}

