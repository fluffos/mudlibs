#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^This is a beautiful area of repose where weary adventurers come to be renewed, body and spirit. Amidst this ethereal dreamscape lies a %^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^CYAN%^ walkway, as well as magical %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^lls%^CYAN%^ which complete the tranquil effect. The %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^lls%^CYAN%^ spill into a cloudy %^BLUE%^p%^CYAN%^o%^BLUE%^ol%^CYAN%^ that appears shallow yet bottomless all at once. A soothing breeze filters through the area.%^RESET%^");
    set_items( ([ "dreamscape": "%^BOLD%^%^GREEN%^The trees and %^MAGENTA%^fl%^RED%^ow%^RESET%^%^MAGENTA%^er%^BOLD%^%^BLUE%^s %^GREEN%^encompass the area, making it beautiful.%^RESET%^", "Walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^", "waterfalls" : "%^BOLD%^%^BLUE%^The w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^lls are %^CYAN%^crystal clear%^BLUE%^ and inviting. A mist of w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^r is sprayed over all who enter the area.%^RESET%^ " ]) );
    set_exits( ([ "south" : SKYROOM "m9" ]) );
    new(SKYOBJ "monk_statue")->move(this_object());
}
void reset() {
    ::reset();
    if (!present("monk", this_object()))
	new(SKYMOB "wise_old_monk")->move(this_object());
}
