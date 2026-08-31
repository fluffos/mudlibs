#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle33");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^The Waiting Room.\n%^RESET%^"
"%^CYAN%^This room was set aside for the Lords and Ladies while they "
"%^CYAN%^await an audience with the King. Plush accommodations have "
"%^CYAN%^been made to see that the Lords and Ladies are confortable "
"%^CYAN%^while they wait. Servants bustle in and out tending to the "
"%^CYAN%^needs of their Masters and Mistresses. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["southwest" : ROOMS"castle9", 
              "northwest" : ROOMS"castle14"]) );

        set_items( ([
        "bench" : "A %^BOLD%^%^ORANGE%^gi%^RESET%^%^WHITE%^ld%^BOLD%^%^ORANGE%^ed%^RESET%^ bench that would make any bottom comfortable.",
        "chair" : "%^BOLD%^%^BLACK%^Made from black oak, this chair looks like it would break the back of anyone who sat in it.",
        "chairs" : "%^BOLD%^%^BLACK%^Many black oak chairs are scattered around this room.",
        "benches" : "A few long %^BOLD%^%^ORANGE%^gi%^RESET%^%^WHITE%^ld%^BOLD%^%^ORANGE%^ed%^RESET%^ benches have been gathered around this room."]) );



}


