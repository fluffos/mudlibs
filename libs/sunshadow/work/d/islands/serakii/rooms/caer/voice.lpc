
#include <std.h>
#include "../../serakii.h"

inherit CVAULT;

void pick_critters();


void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("massive meeting room");
    set_short("massive meeting room");
    set_long("Massive in scale, this circular room could easily hold hundreds of "+
        "people. At the very centre of the room is a %^C060%^raised dais%^CRST%^ "+
        "with a %^C094%^podium%^CRST%^. %^C094%^Benches%^CRST%^ are laid out in "+
        "concentric circles around the %^C094%^podium%^CRST%^ facing it. The high "+
        "vaulted ceiling is hung with silk %^C045%^cloth banners%^CRST%^ of varied "+
        "shades of %^C041%^green%^CRST%^ and %^C069%^blue%^CRST%^ that sway softly. "+
        "This is the room of the %^C190%^Voice%^CRST%^, the ruling council of "+
        "%^C045%^Serakii%^CRST%^. On each %^C094%^bench%^CRST%^ there is a "+
        "cut %^C231%^white rose%^CRST%^ that is fresh enough that it must have "+
        "been placed today. There is a sad serenity here. \n");
    set_items(([
      ({"ceiling","banners"}) : "The high vaulted ceiling here is filled with %^C045%^silk cloth%^CRST%^ that hangs at different lengths of %^C111%^blue%^CRST%^ and %^C042%^green%^CRST%^. There is a source of %^C229%^light%^CRST%^ amongst them that lights the room but the %^C045%^silk cloths%^CRST%^ diffuse it nicely.\n",
      ({"benches"}) : "%^C094%^Benches%^CRST%^ are laid out in concentric circles around the %^C247%^dias%^CRST%^. Obviously they are meant for large gatherings to listen to whoever is at the podium at the time.\n",
      ({"dias","podium"}) : "The %^C094%^dias%^CRST%^ and %^C247%^podium%^CRST%^ are higher than anything else in the room, allowing for the speaker to be seen and heard by the entire room.\n",
      ({"roses","white roses"}) : "On each %^C094%^bench%^CRST%^ is a fresh cut %^C255%^white rose%^CRST%^. Some sort of memorial perhps?\n",

    ]));

    set_smell("default","You smell fresh cut flowers.");
    set_listen("default","%^C060%^The room is silent.%^CRST%^");
    
    set_exits(([

       "southwest" : CAER"4",



    ]));

    set_door("white door",CAER"4","southwest",0);
    set_door_description("white door","Formed from solid wood painted white.");

}
