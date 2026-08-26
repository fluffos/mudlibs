// Chernobog & Titania (2/7/22)
// The Wailing Isle - Voodoo Herbalist Shop

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("The Voodoo Herbalist");
    set_short("%^RESET%^%^CRST%^%^C102%^The Voodoo Herbalist%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C102%^The %^C243%^faded %^C095%^red walls%^C102%^ of this squat building close in around you. Bundles of %^C058%^d%^C064%^r%^C070%^y%^C076%^i%^C077%^n%^C071%^g %^C065%^h%^C059%^e%^C058%^r%^C064%^b%^C070%^s%^RESET%^%^C102%^ hang from the ceiling, easily mistaken for %^C058%^da%^C064%^ng%^C070%^li%^C064%^ng %^C058%^m%^C064%^o%^C070%^s%^C064%^s%^RESET%^%^C102%^ with their overbearing earthy aroma. A %^C101%^broad board%^C102%^ has been set over a pair of %^C101%^squat drawers%^C102%^ to serve as a counter, groaning beneath the weight of a multitude of %^C251%^gla%^C247%^s%^C251%^s%^RESET%^%^C102%^ and %^C053%^ce%^C054%^ra%^C055%^mi%^C056%^c j%^C055%^ar%^C054%^s%^RESET%^%^C102%^ scattered across the surface. Several sets of %^C101%^shelves%^C102%^ line the walls around the shop and behind the counter, crooked and warped from the constant moisture in here, and from the weight of countless %^C194%^s%^C195%^mal%^C194%^l v%^C195%^ial%^C194%^s%^RESET%^%^C102%^ and containers for the varieties of %^C110%^o%^C109%^d%^C108%^d %^C107%^in%^C108%^gr%^C109%^ed%^C108%^ie%^C107%^nt%^C108%^s%^RESET%^%^C102%^. Strange %^C141%^kn%^C140%^ick%^C141%^kna%^C140%^ck%^C141%^s%^RESET%^%^C102%^ and %^C141%^o%^C140%^dd%^C141%^it%^C140%^ie%^C141%^s%^RESET%^%^C102%^ have been tucked here and there among the wares. The %^C059%^shopkeep%^C102%^ stands in a haze of %^C250%^s%^C247%^m%^C244%^o%^C247%^k%^C250%^e%^RESET%^%^C102%^ as %^C116%^in%^C117%^cen%^C116%^se%^RESET%^%^C102%^ lazily wafts from several %^C194%^b%^C194%^r%^C193%^a%^C192%^z%^C191%^i%^C190%^e%^C184%^r%^C178%^s%^RESET%^%^C102%^ that hang from %^C247%^delicate chains%^C102%^.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C116%^An %^C110%^o%^C104%^d%^C103%^d %^C109%^i%^C110%^n%^C104%^c%^C103%^e%^C109%^n%^C110%^s%^C104%^e%^RESET%^%^C116%^ wafts through the air with a %^C110%^st%^C109%^ra%^C110%^ng%^C109%^el%^C110%^y c%^C109%^al%^C110%^mi%^C109%^ng %^C110%^sc%^C109%^e%^C110%^nt%^C116%^.%^CRST%^");
    set_listen("default","%^CRST%^%^RESET%^%^C098%^The %^C092%^bo%^C091%^is%^C090%^te%^C091%^ro%^C092%^us %^C090%^so%^C091%^un%^C092%^ds%^RESET%^%^C098%^ of the streets spill into the shop.%^CRST%^");
    set_items(([
        ({"herbs", "ceiling"}) : "%^RESET%^%^CRST%^%^C070%^The herbs seem to be recently pulled from the ground and bound in twists of %^C058%^crude twine%^C070%^, their %^C066%^ar%^C065%^om%^C071%^at%^C077%^ic %^C066%^s%^C065%^c%^C071%^e%^C077%^n%^C066%^t%^C065%^s%^RESET%^%^C070%^ still rather pungent as they dry overhead. %^C066%^Wind chimes%^C070%^, collections of %^C247%^bones%^C070%^, woven circles of %^C100%^be%^C101%^ad%^C102%^ed %^C101%^we%^C100%^bb%^C101%^ing%^RESET%^%^C070%^, and other odd creations loom down over you, %^C082%^chiming%^C070%^ and %^C082%^clattering%^C070%^ in the occasional errant breeze.%^CRST%^",
        ({"jars", "containers", "shelves", "vials"}) : "%^RESET%^%^CRST%^%^C080%^While many jars seem to be home to a vast collection of %^C076%^herbs%^C080%^, there really is no limit to what you will find filling these strange jars, chests and boxes. Kietta is known for her %^C086%^uncanny ability%^C080%^ to know exactly where everything is, down to its precise measurements.%^CRST%^",
        ({"oddities", "knickknacks"}) : "%^RESET%^%^CRST%^%^C108%^From hideous masks, to lifelike dolls, various figurines in all sizes.. taxidermied spiders, living spiders, rings, coins, curious paintings, bones, fur, hair, plants, some more alive than others, amulets, sticks and stones... %^C109%^to name a few%^C108%^.%^CRST%^",
        "counter" : "%^RESET%^%^CRST%^%^C101%^A items essential to running the shop are kept here, such as a scale and a mortar and pestle. Jars, sachets, carved wooden boxes, and a myriad of other containers are all %^C102%^crammed together%^C101%^, covering the entire surface of the counter.%^CRST%^",
        "walls" : "%^RESET%^%^CRST%^%^C102%^The cracked and peeling %^C160%^red paint%^C102%^ that once brought life and color to these walls is now faded into a dirty shade of %^C132%^pink%^C102%^. More %^C250%^oddities%^C102%^ cover the walls, wherever they manage to find an empty space to fill.%^CRST%^",
        "braziers" : "%^RESET%^%^CRST%^%^C152%^Several small %^C149%^metal braziers%^C152%^ send their %^C253%^wisps%^C152%^ of %^C253%^incense%^C152%^ into the shop. Some are %^C094%^brass%^C152%^, some %^C255%^silver%^C152%^, one even appears to be %^C142%^gold%^C152%^, and no two seem to be burning the same herbs. Their efforts combine into a %^C195%^la%^C194%^ng%^C230%^ui%^C231%^d c%^C195%^lo%^C194%^ud%^RESET%^%^C152%^ of smoke that rolls about the room.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"market4",
        ]));
}

void reset(){
    if(!present("herbalist")) new(MON"kietta")->move(this_object());
}

