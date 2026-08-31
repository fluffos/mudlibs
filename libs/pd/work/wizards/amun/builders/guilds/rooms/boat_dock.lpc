#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
    ::create();
    set_short("Docks");
    set_long("%^BOLD%^%^CYAN%^Many boats move up and down because of the waves. The supports of the pier are covered with seaweed. A traveler can get on his boat right here if he has one. If your boat isn't docked at this pier you can <recall boat>. Once it's docked here you can <board (name)>.%^RESET%^");
    set_listen("default", "The breeze blows on you lightly.");
    set_smell("default", "The strong smell of sea water fills the air.");
    set_exits( ([ "west" : GROOM "docks" ]) );
    set_letter("E");
}
