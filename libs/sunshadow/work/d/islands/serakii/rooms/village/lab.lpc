// enchantment lab Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("enchantment laboratory");
    set_property("light",2);
    set_short("%^C068%^en%^C081%^c%^C068%^h%^C087%^a%^C068%^nt%^C074%^m%^C068%^ent la%^C069%^b%^C087%^o%^C068%^r%^C075%^a%^C068%^t%^C087%^o%^C068%^ry%^CRST%^");
set_long("This room is dominated by an %^C040%^e%^C034%^n%^C040%^ormo%^C035%^u%^C040%^s "+
"hov%^C035%^e%^C040%^ring cryst%^C034%^a%^C040%^l%^CRST%^ "+
"surrounded by a series of %^C247%^inscribed concentric "+
"rings%^CRST%^ which spin lazily around it on different "+
"axes. A %^C044%^magical circle%^CRST%^ has been "+
"permanently carved and inlaid with %^C226%^gold%^CRST%^ "+
"into the %^C246%^solid stone floor%^CRST%^ surrounding "+
"the device, intended to contain and amplify %^C204%^energy%^CRST%^ "+
"more than restrict %^C094%^physical movement%^CRST%^; enchanters "+
"pass through, using smaller gems and lenses to amplify energies "+
"through the larger crystal to create objects of wonder. The "+
"remaining space in the room is taken with %^C094%^worktables%^CRST%^ "+
"littered with signs of projects in progress; %^C044%^crystals%^CRST%^, "+
"%^C247%^cogs%^CRST%^, %^C059%^stained parchments%^CRST%^ outlining "+
"rough designs. Lining the walls are %^C094%^cabinets%^CRST%^ that "+
"house some %^C059%^texts%^CRST%^ on topics pertaining to %^C045%^"+
"enchantment%^CRST%^ and related fields, a variety of basic "+
"%^C060%^clockworks%^CRST%^, %^C159%^jars%^CRST%^ of %^C011%^"+
"enchanting materials%^CRST%^, %^C142%^neat leather toolkits%^CRST%^, "+
"and an extensive display of %^C043%^uncut crystals%^CRST%^ to "+
"demonstrate what gems look like in their natural crystalline "+
"structure. The far end of the room supports a %^C247%^slab of "+
"slate%^CRST%^, covered in complicated %^C255%^designs%^CRST%^ "+
"and %^C255%^equations%^CRST%^.\n");


    set_items(([
    ({"device"}) : "A large %^C046%^crystal%^CRST%^ hovers mid-air, "+
    "its %^C046%^color%^CRST%^ and %^C042%^frequency%^CRST%^ of "+
    "resonance altered by its environment. A series of concentric "+
    "%^C248%^metallic bands%^CRST%^ encircle and revolve around "+
    "it, each at a different speed, direction, and angle. Each "+
    "%^C247%^ring%^CRST%^ consists of several sections of material "+
    "fused together, %^C244%^etched%^CRST%^ and %^C243%^carved%^CRST%^ "+
    "with %^C074%^arcane symbols%^CRST%^; one knowledgeable in "+
    "spellcraft would see that they represent the different planes. "+
    "The smallest ring is two halves joined, the transitive planes "+
    "of astral and ethereal; the next largest is four sections "+
    "representing the inner planes of the elements; the largest ring "+
    "represents the outer planes, upper and lower, the divine residences "+
    "of the Gods. Each section of these bands have a circular gap with "+
    "metal claws to enclose around a gem and adjustable %^C159%^lenses%^CRST%^, "+
    "allowing enchanters to tweak the %^C082%^energy alignment%^CRST%^ of the device.",
    ({"clockworks"}) : "Some %^C060%^clockworks%^CRST%^ are simple things, "+
    "a series of %^C060%^gears%^CRST%^ that move an arm; others are clusters "+
    "of %^C060%^gears%^CRST%^ with no discernable purpose. There are more "+
    "artistic pieces, such as a %^C220%^clockwork beetle%^CRST%^ that can be "+
    "made to fly around the room, or a %^C111%^music box%^CRST%^ that once "+
    "wound, turns a series of %^C094%^barrels%^CRST%^ that interact with "+
    "thin %^C248%^metallic arms%^CRST%^, %^C143%^strings%^CRST%^, and "+
    "hammers to play an orchestral song.",
    ({"circle"}) : "The %^C248%^solid stone%^CRST%^ floor has been carved "+
    "with circles, lines and symbols, and inlaid with %^C226%^gold%^CRST%^. "+
    "Passing over the %^C226%^circle%^CRST%^ towards the device, one gets the "+
    "sense of walking into a %^C231%^wall of force%^CRST%^; the %^C159%^air%^CRST%^ "+
    "feels %^C111%^thicker%^CRST%^, more %^C220%^charged%^CRST%^ inside of it. "+
    "It's not uncommon for students to hiss and complain of %^C226%^static "+
    "shocks%^CRST%^ here.",

    ]));


set_smell("default","%^C110%^You smell nothing here%^CRST%^");
set_listen("default","%^C042%^Crystals resonate and hum when in use, some "+
"thrumming rhythmically, others piercingly high-pitched.%^CRST%^");

   set_exits(([

          "north" : TOWN"herb_vendor",
          
   ]));

}


int is_lab(){ return 1;}
