// Chernobog (2/14/22)
// The Wailing Isle - Path Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("a dirt path along the bay");
    set_short("%^RESET%^%^CRST%^%^C100%^a %^C101%^dirt path%^C100%^ along the bay%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C101%^The %^C100%^dirt trail%^C101%^ here is narrow and littered with %^C102%^r%^C243%^o%^C059%^c%^C243%^k%^C102%^s%^RESET%^%^C101%^ that seem determined to trip you up and send you %^C137%^fl%^C144%^a%^C145%^i%^C137%^li%^C144%^n%^C145%^g %^C137%^gr%^C144%^a%^C145%^c%^C137%^el%^C144%^e%^C145%^s%^C137%^sly%^C101%^ over a %^C245%^steep%^C101%^ drop-off to land unceremoniously on the %^C244%^r%^C059%^o%^C244%^ck%^C243%^y s%^C244%^h%^C243%^o%^C059%^r%^C243%^e%^RESET%^%^C101%^ below. The path itself is %^C100%^packed earth%^C101%^, worn down over time from travelers moving between the docks and the cliffside village. Similarly perilous are the %^C034%^ov%^C041%^er%^C048%^gr%^C085%^ow%^C084%^n f%^C047%^or%^C040%^es%^C046%^t %^C083%^fr%^C078%^on%^C077%^ds%^RESET%^%^C101%^ that encroach along the other side, forcing you to maneuver yourself carefully as you ease your way along. But at least the view isn't bad.%^CRST%^\n");
    set_smell("default","%^CRST%^%^RESET%^%^C079%^Th%^C080%^e s%^C081%^ce%^C080%^nt%^C079%^s o%^C078%^f t%^C077%^he %^C078%^se%^C079%^a m%^C080%^ix %^C081%^pl%^C080%^ea%^C079%^sa%^C080%^nt%^C081%^ly %^C079%^wi%^C078%^th %^C077%^th%^C078%^os%^C079%^e o%^C080%^f t%^C081%^he %^C080%^ne%^C079%^ar%^C080%^by %^C081%^fo%^C079%^re%^C078%^st%^RESET%^%^C079%^.%^CRST%^");
    set_listen("default","%^C105%^Wa%^C104%^ve%^C103%^s c%^C102%^ra%^C103%^sh %^C104%^ag%^C105%^ai%^C104%^ns%^C103%^t t%^C102%^he %^C103%^ja%^C104%^gg%^C105%^ed %^C104%^ro%^C103%^ck%^C102%^s %^C103%^be%^C104%^lo%^C105%^w.%^RESET%^%^CRST%^");
    set_items(([
        ({"forest", "frond"}) : "%^CRST%^%^RESET%^%^C082%^The %^C083%^th%^C077%^ic%^C083%^k f%^C047%^ol%^C083%^ia%^C077%^ge%^RESET%^%^C082%^ is so dense as to be impassable. The forest, with its %^C102%^wi%^C108%^ld %^C107%^an%^C101%^im%^C102%^al%^C108%^s%^RESET%^%^C082%^ and %^C048%^vibrant %^C160%^f%^C088%^r%^C094%^u%^C100%^i%^C172%^t %^C166%^b%^C160%^e%^C088%^a%^C094%^r%^C100%^i%^C172%^n%^C166%^g %^C048%^trees%^C082%^ and %^C048%^shrubs%^C082%^, is a source of food for the island folk, but only the most skilled of navigators find their way easily along the precarious paths. %^C085%^Sw%^C049%^ee%^C048%^t s%^C084%^ce%^C085%^nt%^C086%^s%^RESET%^%^C082%^ carried from within the forest's depths %^C147%^invigorate%^C082%^ you, while your eyes catch glimpses of %^C129%^b%^C128%^r%^C127%^i%^C126%^g%^C125%^h%^C124%^t%^C196%^l%^C197%^y %^C198%^h%^C199%^u%^C200%^e%^C201%^d %^C207%^b%^C206%^l%^C205%^o%^C204%^s%^C203%^s%^C202%^o%^C130%^m%^C131%^s%^RESET%^%^C082%^ among the %^C048%^lush foliage%^C082%^.%^CRST%^",
        ({"drop off", "rocky shore"}) : "%^CRST%^%^RESET%^%^C059%^It's about a twenty foot drop over the precipice to the %^C061%^ro%^C060%^ck%^C059%^y s%^C060%^ha%^C061%^ll%^C060%^ow%^C059%^s%^RESET%^%^C059%^ below. %^C066%^Waves%^C059%^ crash hungrily against the %^C243%^s%^C245%^har%^C243%^p b%^C243%^ou%^C243%^ld%^C244%^er%^C243%^s%^RESET%^%^C059%^ along the abrupt shore.%^CRST%^",
        "rocks" : "%^CRST%^%^RESET%^%^C252%^White rocks litter your path, similar to those that make up the cliffs dominating the island. Half buried in the %^C101%^dirt%^C252%^, they likely draw out plenty of %^C245%^muttered curses%^C252%^ as travelers trip or stumble on them.%^CRST%^",
        "view" : "%^CRST%^%^RESET%^%^C038%^The vast sea spreads out before you to the east beyond the bay, light twinkling along its surface like %^C255%^d%^C253%^i%^C250%^a%^C255%^mo%^C250%^n%^C253%^d%^C255%^s%^RESET%^%^C038%^. In the other direction, a %^C020%^waterfall%^C038%^ plunges down from the %^C255%^majestic white cliffs%^C038%^, broken into several streams by outcroppings, the %^C250%^mist%^C038%^ refracted into a myriad of %^C160%^t%^C166%^i%^C184%^n%^C118%^y %^C051%^ra%^C153%^in%^C135%^bo%^C063%^ws%^RESET%^%^C038%^. The view is truly %^C189%^awe inspiring%^C038%^.%^CRST%^",
        "sea" : "%^RESET%^%^CRST%^%^C044%^Light ripples over the surface of the %^C038%^azure water%^C044%^ like diamonds, %^C051%^luring%^C044%^ you into its bountiful depths. The %^C250%^breeze%^C044%^ is constant, bringing with it the scents of the sea, and it whispers the %^C051%^promises%^C044%^ of adventures abound and treasures not yet plundered. The vastness of the sea is humbling to some... and something to be conquered by others.%^CRST%^",
        ]));
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_path")->move(this_object());
}

