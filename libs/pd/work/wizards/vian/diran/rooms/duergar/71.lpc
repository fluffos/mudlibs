#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The Psion training hall of Duergar is a large and tidy room, filled with bookcases and cabinets full of books, vials, various potions and liquids, and gemstones.  There is a large open space as well, for practicing spellwork.  Many Psions study here in the day.");
set_exits(([
"out" : ROOMS"duergar/72",

]));
    set_items( ([
"bookcases":"The bookcases are carved from a black stone.",
"cabinets":"The cabinets are so full that they don't fully close.",
"vials":"The vials contain liquids unknown, but it would be wise to stay away.",
"books":"There are many old and tattered books on dark magic here.",
"potions":"The potions look moderately safe, but it would probably be wise to avoid them.",
"gemstones":"Gemstones used in spellcasting are stored here.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("dpsion"))
          new(MOB "dpsion")->move(this_object());
          new(MOB "dpsion")->move(this_object());
          new(MOB "dpsion")->move(this_object());
          new(MOB "dpsion")->move(this_object());
}
}