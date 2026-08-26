#include <std.h>
#include "../serakii.h"

inherit VAULT;

string seas;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_name("outside a grand tavern");
    set_short("%^C137%^o%^C094%^u%^C137%^tsi%^C094%^d%^C137%^e a gra%^C094%^n%^C137%^d t%^C094%^a%^C137%^vern%^CRST%^");
	
    seas = season(time());
        set_long("%^C248%^Before you stands a %^C244%^grand stone%^C248%^ and %^C058%^wooden structure%^C248%^ that has obviously stood the test of time well. Its walls are formed from %^C245%^massive stone blocks%^C248%^ with a %^C254%^pure white plaster%^C248%^ in the cracks between then. At regular intervals small %^C094%^windows %^C248%^are framed in %^C094%^dark oak%^C248%^. The roof is made from layered %^C197%^clay roof tiles%^C248%^ painted %^C254%^white%^C248%^. %^C064%^Hearty vines%^C248%^ climb the walls and grow up the chimney and is spotted with small red flowers. The ground is %^C094%^dirt %^C248%^and %^C064%^grass %^C248%^and as you walk around you realize there must be some %^C174%^enchantment %^C248%^around the %^C100%^inn %^C248%^as no matter what season beyond it, it is always a mild %^C037%^Springstime %^C248%^around its %^C252%^walls%^C248%^. To the north you see an imposing %^C254%^white stone keep%^C248%^.%^CRST%^\n");

   set_items(([
      ({"ground","grass"}) : "%^C101%^The ground around the inn is a collection of %^C094%^dirt %^C101%^and %^C034%^healthy grass%^C101%^.\n%^CRST%^",
      ({"walls","wall"}) : "%^C248%^large %^C244%^stone blocks%^C248%^ form the walls of the inn, each the size of a %^C058%^barrel%^C248%^. There is a %^C255%^pure white plaster%^C248%^ between the %^C243%^cracks%^C248%^. Even in the roughest storm or battle these walls would hold up as well as a fortress.\n%^CRST%^",
      ({"vines","flowers"}) : "%^C022%^Hearty vines grow up the stone and across the %^C058%^wooden windows%^C022%^. The ivy is dotted with small%^CRST%^ %^C196%^de%^C088%^e%^C196%^p r%^C088%^e%^C196%^d flow%^C124%^e%^C196%^rs%^CRST%^ %^C022%^and is quite beautiful.\n%^CRST%^",
    ]));


set_smell("default","%^C136%^You smell %^C125%^cooking %^C136%^and %^C094%^wood fire%^C136%^ from inside the tavern%^CRST%^");
set_listen("default","%^C164%^You hear the %^C129%^merriment %^C164%^from inside the %^C058%^tavern%^CRST%^");


}
