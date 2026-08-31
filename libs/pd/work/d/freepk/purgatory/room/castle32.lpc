#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle32");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^A Sitting Room\n%^RESET%^"
"%^CYAN%^A fairly small room compared to the rest of the castle, this "
"%^CYAN%^room is set aside for people to get away from the hustle and "
"%^CYAN%^have a nice little chat. Plush benches and chairs lay where "
"%^CYAN%^the last person left them.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["southeast" : ROOMS"castle2", 
              "west" : ROOMS"castle10"]) );

    set_items( ([
        "bench" : "A plush looking bench that would make any bottom comfortable.",
        "chair" : "Made from black oak, this chair looks like it would break the back of anyone who sat in it.",
        "chairs" : "Many black oak chairs are scattered around this room.",
        "benches" : "A few long plushly finished benches have been gathered around this room."]) );


}
