#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle14");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^Main Hallway\n%^RESET%^"
"%^CYAN%^Adorned with gilded tables, chairs, and other scattered "
"%^CYAN%^artworks, this hallway was built in excess to impress. "
"%^CYAN%^Antechambers to the Royal Court can be seen to the east and "
"%^CYAN%^west. A slight chill passes by every now and then..");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["southeast" : ROOMS"castle33", 
              "southwest" : ROOMS"castle34",
              "west" : ROOMS"castle24",
              "east" : ROOMS"castle23",
              "south" : ROOMS"castle9"]) );



}

void reset() {
    ::reset();
     if (children(MOBS"sneakychild")==({})||
         sizeof(children(MOBS"sneakychild"))<1)
            new(MOBS"sneakychild")->move(this_object());
        
}
