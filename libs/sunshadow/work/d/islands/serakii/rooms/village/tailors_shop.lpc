// tailoring workshop Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("tailoring workshop");
    set_property("light",2);
    set_short(" %^C136%^ta%^C143%^i%^C136%^lo"+
    "ri%^C143%^n%^C136%^g wo%^C143%^r%^C136%^ksh%^C143%^o%^C136%^p%^CRST%^");
set_long("To call this a mere %^C143%^tailoring%^CRST%^ workshop is a "+
"misnomer, as students are engaged in a multitude of %^C184%^fibre%^CRST%^ "+
"arts. %^C095%^Standing looms%^CRST%^ are warped with %^C130%^brocades%^CRST%^ "+
"and %^C028%^tapestries%^CRST%^; %^C094%^comfortable chairs%^CRST%^ sit near "+
"%^C159%^windows%^CRST%^ with %^C254%^lace pillows%^CRST%^; %^C109%^cushions%^CRST%^ "+
"are scattered in one part of the room surrounding a %^C094%^large frame%^CRST%^ "+
"where students apply %^C203%^silk%^CRST%^ and %^C226%^metallic%^CRST%^ embroidery; "+
"%^C142%^vats%^CRST%^ heated by %^C205%^magic%^CRST%^ sit side by side in one "+
"corner, %^C046%^bright dyes%^CRST%^ ready for thread, fabric, or garments. There "+
"are enormous %^C094%^cutting tables%^CRST%^, covered in a %^C251%^paper%^CRST%^ "+
"students have sketched designs and noted measurements on, with various "+
"%^C243%^tools%^CRST%^ scattered overtop. %^C038%^Garments%^CRST%^ in "+
"mid-progress are draped over %^C137%^dress forms%^CRST%^ next to the "+
"%^C094%^desks%^CRST%^, though some have %^C094%^racks%^CRST%^ of shoes "+
"and lasts, while another has a headform supporting a fabulous hat. The "+
"room is bright with natural %^C227%^light%^CRST%^ from "+
"%^C111%^large windows%^CRST%^, so tailors can focus on fine detail work.\n");

    set_items(([

    ({"vats"}) : "The %^C094%^vats%^CRST%^ themselves %^C244%^steam%^CRST%^ "+
    "as they are gently agitated by students dying %^C044%^fabrics%^CRST%^ "+
    "and %^C142%^yarns%^CRST%^. One bubbles as if alive, itself a "+
    "%^C227%^yellowish%^CRST%^ %^C036%^green%^CRST%^ colour despite "+
    "anything emerging turning immediately from %^C040%^green%^CRST%^ "+
    "to %^C093%^indigo%^CRST%^ upon contact with the air. On the walls "+
    "above are %^C150%^colour guides%^CRST%^ of what one can expect; "+
    "%^C063%^Alkenet%^CRST%^ with %^C247%^iron%^CRST%^ produces mauve, "+
    "%^C169%^Alkenet%^CRST%^ with alum produces %^C055%^violet%^CRST%^. "+
    "The same dye on different fabrics produces a %^C111%^pale color%^CRST%^ "+
    "on linen, a %^C062%^dark color%^CRST%^ on wool, a %^C093%^vibrant%^CRST%^ "+
    "color on silk. There are shelves holding massive jars of dye stuffs, from "+
    "%^C140%^flowers%^CRST%^ to %^C220%^beetles%^CRST%^ to %^C094%^wood chips%^CRST%^, "+
    "and %^C059%^mordant jars%^CRST%^ of %^C244%^iron filings%^CRST%^, "+
    "%^C255%^alum powder%^CRST%^, %^C214%^copper%^CRST%^, and what appears to "+
    "be %^C227%^stale urine%^CRST%^.",
    ({"loom"}) : "These %^C094%^standing looms%^CRST%^ produce %^C043%^fabric%^CRST%^ "+
    "four foot wide, though some are doubled over to create eight foot wide fabric. "+
    "The beginners looms are warped to produce plainweave and twills in "+
    "%^C058%^wool%^CRST%^ and %^C142%^linen%^CRST%^, but more advanced "+
    "brocades and damasks with gleaming threads of %^C043%^silk%^CRST%^ "+
    "and %^C226%^gold%^CRST%^ added as supplementary weft are warped up as "+
    "well. One %^C094%^loom%^CRST%^ has a %^C028%^thick tapestry%^CRST%^ being worked on.",
    ({"tables","cutting tables"}) : "The %^C095%^broad cutting tables%^CRST%^ "+
    "are wide enough to support %^C074%^bolts%^CRST%^ of fabric as students lay "+
    "out their patterns. Edges are marked with measurements, though coil of "+
    "%^C142%^knotted string%^CRST%^ get used more often. Each table has thick "+
    "bundles of %^C040%^fabric%^CRST%^ swatches bound and hung on %^C243%^hooks%^CRST%^ "+
    "to the side, tailors chalk, cutting sheers, fabric weights, and a deadly "+
    "looking %^C159%^jar%^CRST%^ of %^C248%^pins%^CRST%^. Sewing kits include "+
    "%^C094%^hollow wooden bobbins%^CRST%^ wound with %^C042%^thread%^CRST%^ "+
    "that house %^C220%^brass%^CRST%^ needles inside, small nubs of "+
    "^C220%^beeswax%^CRST%^, bown %^C245%^awls%^CRST%^, and %^C246%^ring thimbles%^CRST%^.",


    ]));


set_smell("default","%^C222%^The corner with the vats has a slight whiff "+
"of ammonia clinging to it.%^CRST%^");
set_listen("default","%^C242%^Apprentices chatter as they work, occasionally "+
"swearing when they realize a mistake too late.%^CRST%^");

   set_exits(([

         "south" : TOWN"fabric_vendor",
          
   ]));

}


