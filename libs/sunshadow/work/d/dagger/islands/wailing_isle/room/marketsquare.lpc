// Chernobog & Titania (2/14/22)
// The Wailing Isle - Market Square

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("The Market Square");
    set_short("%^RESET%^%^CRST%^%^C109%^The Market Square%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C109%^A %^C244%^circular fountain%^RESET%^%^C109%^ sits in the center of the square, its edges %^C247%^crumbling%^RESET%^%^C109%^ and the basin in complete %^C247%^disrepair%^RESET%^%^C109%^. Three %^C152%^im%^C146%^pr%^C145%^es%^C146%^si%^C152%^ve m%^C146%^a%^C145%^rb%^C146%^l%^C152%^e t%^C146%^en%^C145%^tac%^C146%^le%^C152%^s%^RESET%^%^C109%^ twist upward from its center, an unfortunate %^C101%^galleon%^RESET%^%^C109%^ being %^C123%^crushed%^RESET%^%^C109%^ in their overbearing grasp while several other %^C152%^t%^C146%^en%^C145%^tac%^C146%^le%^C152%^s%^RESET%^%^C109%^ roam low, creeping over the lip of the basin. The market area spreads out here with %^C245%^s%^C243%^ton%^C245%^e t%^C243%^ile%^C245%^s%^RESET%^%^C109%^ forming a %^C059%^w%^C243%^o%^C245%^r%^C247%^n %^C059%^s%^C243%^p%^C245%^i%^C247%^r%^C059%^a%^C243%^l%^C245%^i%^C247%^n%^C059%^g %^C243%^p%^C245%^a%^C247%^t%^C059%^t%^C243%^e%^C245%^r%^C247%^n%^RESET%^%^C109%^ beneath your feet. Noise spills out from the %^RESET%^%^C194%^s%^C193%^q%^C194%^uat y%^RESET%^%^C193%^e%^C194%^ll%^C193%^o%^C194%^w b%^C193%^u%^C194%^il%^C193%^di%^C194%^ng%^RESET%^%^C109%^ to the west, colliding with the %^C123%^chaos%^C109%^ of the marketplace. Looking eastward provides a %^C043%^p%^C037%^ic%^C043%^tur%^C037%^es%^C043%^qu%^C037%^e vi%^C043%^e%^C037%^w%^RESET%^%^C109%^ of the %^C043%^b%^C037%^a%^C043%^y%^RESET%^%^C109%^ and the %^C101%^majestic ships%^C109%^ floating on the %^C021%^d%^C027%^e%^C033%^e%^C039%^p %^C045%^b%^C051%^l%^C087%^u%^C081%^e %^C075%^w%^C069%^a%^C063%^t%^C057%^e%^C056%^r%^C062%^s%^RESET%^%^C109%^, while the %^C123%^market%^C109%^ continues to the north and south. A %^C250%^young girl%^C109%^ has set up a %^C245%^fish stand%^RESET%^%^C109%^ here, her sharp voice cutting through the din.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^C066%^The scent of %^C072%^fish%^C066%^ and %^C072%^food%^C066%^ fills the air.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C061%^Lo%^C055%^u%^C061%^d h%^C055%^ag%^C061%^gl%^C055%^in%^C061%^g and l%^C055%^i%^C061%^ve%^C055%^l%^C061%^y c%^C055%^on%^C061%^ver%^C055%^s%^C061%^ati%^C055%^on%^C061%^s%^RESET%^%^C061%^ rise over a backdrop of d%^C055%^i%^C061%^sta%^C055%^n%^C061%^t mu%^C055%^s%^C061%^ic.%^CRST%^");
    set_items(([
        ({"fountain", "basin", "statue", "tentacles", "galleon"}) : "%^RESET%^%^CRST%^%^C253%^This fountain is huge and was probably quite impressive back in its prime. Now it is c%^C247%^r%^C253%^ac%^C247%^ke%^C253%^d%^RESET%^%^C253%^, cr%^C247%^u%^C253%^mbl%^C247%^in%^RESET%^%^C253%^g, and covered in %^C255%^g%^C102%^u%^C255%^ll po%^C106%^o%^C255%^p%^RESET%^%^C253%^ and other suspicious substances. Stagnant, %^C243%^black water%^C253%^ and odd pieces of %^C058%^trash%^C253%^ lurk in the basin, offering up a rank smell. Suckered %^C145%^t%^C152%^e%^C159%^n%^C152%^t%^C145%^a%^C152%^c%^C159%^l%^C152%^e%^C145%^s%^RESET%^%^C253%^ rise from the depths of the %^C244%^b%^C059%^r%^C058%^a%^C244%^cki%^C059%^s%^C243%^h wa%^C058%^t%^C059%^e%^C243%^r%^C253%^, careening upwards to a height of at least fifteen feet. They juggle a %^C102%^galleon%^C253%^ in their suckered grasp, the unfortunate ship crushing beneath their weight. Some of the ship's masts hang askew, more so from time and neglect rather than design. A few odd %^C145%^t%^C152%^e%^C159%^n%^C152%^t%^C145%^a%^C152%^c%^C159%^l%^C152%^e%^C145%^s%^RESET%^%^C253%^ trace their way through the basin before curling up and over the edge.%^CRST%^",
        ({"ground", "tiles"}) : "%^RESET%^%^CRST%^%^C243%^The road is paved in %^C059%^huge gray slabs%^C243%^ of %^C059%^stone%^C243%^, with %^C059%^smaller black tiles%^C243%^ used to create the %^C059%^sp%^C243%^ir%^C246%^al%^C249%^ing %^C059%^mo%^C243%^sa%^C246%^ic%^RESET%^%^C243%^. Many of the stones are crushed or missing, and one must tread carefully lest they trip.%^CRST%^",
        ({"yellow building", "bar"}) : "%^RESET%^%^CRST%^%^C194%^From the sounds spilling out into the street, not to mention the %^C106%^pungent scent%^C194%^ of %^C247%^cheap liquor%^C194%^ and %^C247%^beer%^C194%^, the squat building is a bar. A %^C101%^sign%^C194%^ hangs over the door, but it seems that someone has ripped out a large chunk of it, removing any traces of a namesake for this rambunctious establishment. The few windows it has are imprisoned behind %^C059%^wrought iron bars%^C194%^, and what was once likely a part of the architecture now stands as a symbol of the %^C138%^ramshackle nature%^C194%^ of the building. There are a few scratches near the doorway.%^CRST%^",
        "sea" : "%^RESET%^%^CRST%^%^C044%^Light ripples over the surface of the %^C038%^azure water%^C044%^ like diamonds, %^C051%^luring%^C044%^ you into its bountiful depths. The %^C250%^breeze%^C044%^ is constant, bringing with it the scents of the sea, and it whispers the %^C051%^promises%^C044%^ of adventures abound and treasures not yet plundered. The vastness of the sea is humbling to some... and something to be conquered by others.%^CRST%^",
        "ships" : "%^RESET%^%^CRST%^%^C102%^The ships float %^C090%^majestically%^C102%^ on the bay, awaiting their next %^C172%^adventure%^C102%^. They feature %^C250%^great sails%^C102%^, meant for the deep seas. Absent from their masts are the colors of any of the city states of the realm, and a few even sport %^C059%^black flags%^C102%^ with malicious icons.%^CRST%^",
        ({"plant life", "mosses"}) : "%^RESET%^%^CRST%^%^C070%^Nature has started to reclaim parts of the isle as it falls further into %^C064%^disrepair%^C070%^.%^CRST%^",
        "visitors" : "%^RESET%^%^CRST%^%^C100%^Never was a dirtier lot found! Pirates, thieves, drunks and other unsavory types flood the streets, looking for a %^C142%^good time%^C100%^ or the chance to make some %^C142%^coin%^C100%^. Many of these fearless folks are drawn to the sea with nothing left to lose, and will take what they can get out of life.%^CRST%^",
        ]));
    set_exits(([
        "northeast" : ROOMS"market3",
        "south" : ROOMS"market2",
        "west" : ROOMS"tavern",
        "southeast" : ROOMS"beach2",
        "northwest" : ROOMS"residential3",
        "alley" : ROOMS"alley",
        ]));
    set_invis_exits(({ "alley" }));
    set_pre_exit_functions(({"northwest"}),({"going_up"}));
    set_pre_exit_functions(({"southeast"}),({"going_down"}));
}

void reset(){
    if(!present("fishmonger")) new(MON"tilly")->move(this_object());
    if(!present("seafood cart")) new(OBJ"fish_cart")->move(this_object());
}

void init(){
    ::init();
    add_action("look_fun", "look");
}

int look_fun(string str){
    object player;
    player = this_player();
    
    if(!str) return 0;
    if(str != "scratches") return 0;
    
    tell_object(player, "%^RESET%^%^CRST%^%^C194%^There are quite a few odd scratches in the stucco, that almost seem intentional.%^CRST%^");
    if(player->is_class("thief") || player->is_class("bard")) tell_object(player, "%^RESET%^%^CRST%^%^C196%^You can pick out a couple words in the cant, \"fence\" and \"alley\".");
    return 1;
}

int going_up(){
    object player;
    player = this_player();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C094%^You follow the steep %^C100%^s%^C101%^e%^C102%^r%^C103%^p%^C102%^e%^C101%^n%^C100%^t%^C101%^i%^C102%^n%^C103%^e %^C102%^c%^C101%^u%^C101%^r%^C100%^v%^C101%^e %^RESET%^%^C094%^of the road up to the %^C138%^residences%^C094%^.%^CRST%^\n");
    return 1;
}

int going_down(){
    object player;
    player = this_player();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C094%^You follow the steep %^C100%^s%^C101%^e%^C102%^r%^C103%^p%^C102%^e%^C101%^n%^C100%^t%^C101%^i%^C102%^n%^C103%^e %^C102%^c%^C101%^u%^C101%^r%^C100%^v%^C101%^e %^RESET%^%^C094%^of the road down to the %^C186%^beach%^C094%^.%^CRST%^\n");
    return 1;
}

