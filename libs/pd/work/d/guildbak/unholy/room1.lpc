#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
::create();
    set_short("Guild of the Unholy");
set_long("%^RED%^The %^BOLD%^demo%^MAGENTA%^n's wr%^RESET%^%^RED%^ist is%^BOLD%^ cut" "s%^MAGENTA%^hor%^RED%^t as %^RESET%^%^RED%^this %^BOLD%^hall %^MAGENTA%^has yet" 
"%^RESET%^%^RED%^ to %^BOLD%^be %^MAGENTA%^ful%^RESET%^%^RED%^ly "
"%^BOLD%^d%^MAGENTA%^u%^RED%^g ou%^RESET%^%^RED%^t.%^RESET%^");
    set_items(([
        "wrist" : "The wrist of the demon is red and pinkish.",
        "hall" : "The hall has yet to be dug out.",
    ]));
   set_properties(([
     "light":2, "night light":2, "no attack":1, "no magic":1, 
     "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));

    set_exits(([
        "north" : ROOMS "unholy/hall",
                
    ]));    
}
