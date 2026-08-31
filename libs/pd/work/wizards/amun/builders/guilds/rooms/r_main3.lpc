#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","%^BOLD%^%^WHITE%^The more away from the main area the path leads, the more charisma it seems to have. Towards the north a small %^CYAN%^c%^BLUE%^r%^CYAN%^e%^BLUE%^e%^CYAN%^k %^WHITE%^flows smoothly. Skipping along the sides of the %^CYAN%^c%^BLUE%^r%^CYAN%^e%^BLUE%^e%^CYAN%^k%^WHITE%^, the %^RESET%^%^GREEN%^d%^CYAN%^r%^GREEN%^a%^BOLD%^%^CYAN%^g%^GREEN%^o%^CYAN%^n%^GREEN%^f%^CYAN%^l%^RESET%^%^GREEN%^i%^CYAN%^e%^GREEN%^s %^BOLD%^%^WHITE%^roam around in search of their next meal. The breeze that flows through the area kicks up some %^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^.%^RESET%^");
    set_items(([ "path" : "%^BOLD%^%^WHITE%^The path begins to look more cheerful as it moves away from the center of the town.%^RESET%^", "creek" : "%^BOLD%^%^CYAN%^The creek flows smoothly and offers %^BLUE%^melodic sounds %^CYAN%^for those who pass by it.%^RESET%^", "dragonflies" : "%^BOLD%^%^CYAN%^The %^RESET%^%^GREEN%^d%^CYAN%^r%^GREEN%^a%^BOLD%^%^CYAN%^g%^GREEN%^o%^CYAN%^n%^GREEN%^f%^CYAN%^l%^RESET%^%^GREEN%^i%^CYAN%^e%^GREEN%^s %^BOLD%^%^GREEN%^buzz %^CYAN%^around %^GREEN%^the %^CYAN%^edge %^GREEN%^of %^CYAN%^the %^GREEN%^%^water %^CYAN%^in %^GREEN%^search %^CYAN%^of %^GREEN%^food.%^RESET%^", "gravel" : "%^BOLD%^%^BLACK%^The g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^e%^RESET%^l%^BOLD%^%^BLACK%^ is kicked up by the wind.%^RESET%^" ]));
    set_exits( ([ "west" : GROOM "r_main2", "east" : GROOM "r_main4" ]) );
}
