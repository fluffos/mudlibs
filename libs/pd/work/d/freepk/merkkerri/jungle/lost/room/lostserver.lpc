#include <std.h>
#include <lost.h>

inherit VIRTUALSERVER;

void create() {
   ::create();
     set_how_long(4);

     set_day_sentances(({
       "%^GREEN%^%^BOLD%^The field stretches off in all directions.%^RESET%^",
       "%^GREEN%^%^BOLD%^The grass of the field is rather long, making it difficult to travel through.%^RESET%^",
       "%^GREEN%^%^BOLD%^A large boulder sits here in the field, breaking up the landscape.%^RESET%^",
       "%^GREEN%^%^BOLD%^A small tree stands off in the distance, blowing in the wind.%^RESET%^",
       "%^GREEN%^%^BOLD%^The sun beats down on the field, reflecting off of all the grass.%^RESET%^",
       "%^GREEN%^%^BOLD%^Pollen floats through the air, dancing on the wind.%^RESET%^",
       "%^GREEN%^%^BOLD%^A soft breeze rustles the grass, making the field look alive.%^RESET%^",
       "%^GREEN%^%^BOLD%^Some large beast can be seen far off in the distance, perhaps it is just an illusion.%^RESET%^",
       "%^GREEN%^%^BOLD%^The grass is pressed down here, it looks to be a footprint from some large beast.%^RESET%^",
                }));

     set_night_sentances(({
        "%^GREEN%^The darkness makes it difficult to tell how far the field stretches.%^RESET%^",
        "%^GREEN%^A soft breeze blows through here, making the grass of the field rustle.%^RESET%^",
        "%^GREEN%^Strange shadows can be seen moving in the distance, it is impossible to tell what they are though.%^RESET%^",
        "%^GREEN%^A large boulder stands here, creating more darkness.%^RESET%^",
        "%^GREEN%^The grass is tall and thick, making it very difficult to travel further.%^RESET%^",
        "%^GREEN%^The field is very quiet at night, only the sounds of the wind blowing fills the air.%^RESET%^",
                }));

     set_item_list(([
        "grass"               : "Tall thick grass that fills the field.",
        "boulder"               :   "A large grey boulder that stands far above the grass.",
        "tree"                  :   "A small tree with almost no leaves on it.",
                ]));

     set_smell("The smell of pollen fills the air.");
     set_listen("Grass rustles in the breeze.");

  set_reset_list( ({
        VMOBS"allosaurus",
        VMOBS"ankylosaurus",
        VMOBS"brontosaurus",
  }) );

     set_properties(([ "light"          : 1,
                       "plain"          : 1,
                       "night light"    : 0
                   ]));
  set_short("Lost Field");
}
