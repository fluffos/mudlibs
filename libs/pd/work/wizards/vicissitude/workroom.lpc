
#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
   set_short("The Mists of Space and Time");
    set_long(
     "Beyond the event horizon of matter and linear "
     "perception of being, just after the end of "
     "temporal existence. It feels as though you "
     "are being ripped apart by the cosmic pressure. "
     "There is a curious %^CYAN%^mist%^RESET%^ "
     "lingering around your heels as you move "
     "through the infinite expanse of this otherwise "
     "empty void. Stars shine brightly through "
     "the ages and far into the distance. It is "
     "unnaturally cold here and the silence is "
     "deafening. "
    );
    set_items(([
     "mist" : "The peculiar viridian haze trails "
        "at your feet with the elegance of a harsh quasar. ",
     "stars" : "They glimmer with eternal wisdom.",
     "star" : "Each star is too brilliant to focus on just one",
    ]));
   set_smell("default", "The scent of sandal wood and cherry blossom hover in the air.");
   set_listen("default", "Your ears almost begin to bleed from the silence.");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    
}
