#include <std.h>
#include <guild.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("recite", "recite");
}
string magic_colour();
string magic_colour() {
    if(!random(4)) return "%^BOLD%^%^MAGENTA%^A%^RESET%^%^MAGENTA%^"
	"r%^BOLD%^c%^RESET%^%^MAGENTA%^a%^BOLD%^n%^RESET%^%^MAGENTA%^"
	"e %^BOLD%^S%^RESET%^%^MAGENTA%^c%^BOLD%^r%^RESET%^%^MAGENTA%^"
	"o%^BOLD%^l%^RESET%^%^MAGENTA%^l%^RESET%^";
    else if(!random(3)) return "%^BOLD%^%^BLUE%^A%^RESET%^%^BLUE%^r"
	"%^BOLD%^c%^RESET%^%^BLUE%^a%^BOLD%^n%^RESET%^%^BLUE%^e "
	"%^BOLD%^S%^RESET%^%^BLUE%^c%^BOLD%^r%^RESET%^%^BLUE%^o%^BOLD%^"
	"l%^RESET%^%^BLUE%^l%^RESET%^";
    else if(!random(2)) return "%^BOLD%^%^RED%^A%^RESET%^%^RED%^r"
	"%^BOLD%^c%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^e %^BOLD%^%^RED%^"
	"S%^RESET%^%^RED%^c%^BOLD%^r%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^%^"
	"RED%^l%^RESET%^";
    else if (!random(1)) return "%^BOLD%^GREEN%^A%^RESET%^%^GREEN%^"
	"r%^BOLD%^c%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^e "
	"%^BOLD%^S%^RESET%^%^GREEN%^c%^BOLD%^r%^RESET%^%^GREEN%^o%^BOLD%^"
	"l%^RESET%^%^GREEN%^l%^RESET%^";
}
int scroll;
void create() {
    ::create();
    scroll = 0;
    set_name("arcane scroll");
    set_id( ({ "scroll", "arcane scroll", "an arcane scroll" }) );
    set_short(""+magic_colour()+"%^RESET%^");
    set_long("This scroll holds the arcane magics from centuries past.  To "
      "release its power, just <recite scroll>.");
    set_mass(2);
    set_curr_value("gold", 1200);
    set_destroy();
}

//  BALANCE- made it random time

int recite(string str) {
    int de, i;
    object *stuff;

    if(!str) return notify_fail("What?\n");
    if(str != "scroll") return notify_fail("What?\n");
    if(this_player()->query_guild() != "forsaken") return notify_fail("What?\n");
    if(scroll) {
	write("The power of the arcane scroll is already inside of you.\n");
	return 1;
    }
    stuff = all_inventory(this_player());
    i = sizeof(stuff);
    while(i--) {
	if(stuff[i]->query_scroll()) {
	    write("The power of the arcane scroll is already inside of you.\n");
	    return 1;
	}
    }
    write("You recite the "+magic_colour()+" into your "
      "body and an aura of protection surrounds you.\n");
    de=1800 + random(1800);
    this_player()->add_magic_protection(({0, 9, de}));
    if(random(3)) this_player()->disable();
    this_object()->set_short("");
    this_object()->set_id(({ "hidden_object" }));
    scroll = 1;
    call_out("scroll_dead", de, this_player());
    return 1;
}

int scroll_dead() {
    scroll = 0;
    write("%^BOLD%^The aura around you fades into the darkness.\n");
    this_object()->remove();
    return 1;
}

int query_scroll() {return scroll;}
