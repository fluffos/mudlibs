// Foyer Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit VAULT;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("comfortable foyer");
    set_property("light",2);
set_short("%^C094%^co%^C059%^m%^C094%^forta%^C059%^b%^C094%^le foy%^C059%^e%^C094%^r%^CRST%^");
    set_long("The main hall and entrance to the %^C111%^Institute "+
    "for Trades%^CRST%^ is %^C060%^unassuming%^CRST%^ and "+
    "%^C060%^plain%^CRST%^, little more than a functional "+
    "thoroughfare. The floor is a %^C248%^simple "+
    "flagstone%^CRST%^, the walls %^C223%^plastered%^CRST%^ "+
    "and %^C231%^whitewashed%^CRST%^, with %^C095%^thick wooden "+
    "beams%^CRST%^ bracing the arched ceiling above. It's open "+
    "to a circular hall curving %^C044%^southwest%^CRST%^ and %^C044%^southeast%^CRST%^ to the other wings, while a %^C248%^grand arch%^CRST%^ directly to the %^C045%^"+
    "south%^CRST%^ looks out over the %^C028%^atrium%^CRST%^. "+
    "Smaller %^C248%^arches%^CRST%^ to the %^C045%^east%^CRST%^ "+
    "and %^C045%^west%^CRST%^ lead a few steps down into the "+
    "%^C094%^wood vendor%^CRST%^ and to the %^C094%^woodshop%^CRST%^, "+
    "%^RESET%^respectively. A large set of %^C095%^heavy double doors %^CRST%^"+
    "lead out, flanked by %^C220%^leaded glass windows%^CRST%^ "+
    "offering a view of the square beyond. A %^C242%^simple "+
    "chandelier%^CRST%^ overhead offers some light, while a stack "+
    "of %^C094%^wooden panels %^CRST%^covered in a %^C223%^cloth%^CRST%^ "+
    "leans in a corner, out of the way.\n");

    set_items(([
    ({"panels"}) : "%^C060%^It's clear that there is some intention "+
    "to gussy up the foyer at some point in the future. Lifting the "+
    "cloth protecting them, one can see a set of eight ornately "+
    "carved panels, figures framed by gothic arches. Each one "+
    "represents a different craft, holding a tool of their trade "+
    "and an item they might craft.%^CRST%^",
    ({"chandelier"}) : "%^C247%^A %^C241%^thin iron ring%^C247%^ "+
    "pierced with %^C252%^diamonds%^C247%^ and crosses hung by "+
    "chain that travels through a ring in one of the %^C094%^"+
    "beams%^C247%^, then down to a %^C243%^hook%^C247%^ embedded "+
    "into a wall. It supports several %^C223%^glass cones%^C247%^ f"+
    "illed with %^C220%^oil%^C247%^ and a wick; the %^C110%^glass%^C247%^ "+
    "helps refract more of the light below.%^CRST%^",
    ({"floor","flagstone"}) : "%^C243%^The floor here is simple flagstone%^CRST%^",
    ]));


set_smell("default","%^C094%^This area is filled with the satisfying scent of cut wood.%^CRST%^");
set_listen("default","%^C158%^Muted sounds of apprentices' conversation drift through the room.%^CRST%^");


   set_exits(([

         "out" : TOWN"institute",
          "east" : TOWN"wood_vendor",
          "west" : TOWN"wood_shop",
          "south" : TOWN"garden",
          "southeast" : TOWN"fabric_vendor",
          "southwest" : TOWN"herb_vendor",
          
   ]));

    set_door("wooden door",TOWN"institute","out",0);
    set_door_description("wooden door","Thick wooden planks "+
    "are bound by solid bands of black iron. Both the hinges "+
    "and the handles are decorative, vines spiraling away and "+
    "ending in oak leaves, though its somewhat crudely worked. "+
    "Its said these are amongst the very first projects produced "+
    "by students here, and though there may be finer made fittings "+
    "they remain in honour of new beginnings..");
    set_string("wooden door", "open", "You push against the heavy door and
it opens slowly.");
    set_string("wooden door", "close", "You close the heavy wooden door
slowly.");

}

    void reset()
{
        ::reset();
        if(!present("guard"))
        {
           new(MOBS"serith_guard")->move(TO);
        }
}
