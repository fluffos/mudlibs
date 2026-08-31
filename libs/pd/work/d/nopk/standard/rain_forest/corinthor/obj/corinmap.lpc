#include <std.h>
#include <aziraphale.h>
inherit OBJECT;

void create() {
   ::create();
     set_id(({"map", "mapxzor"}));
     set_name("map");
     set_long("This is a map of the 'Ring of Life', the eight trees surrounding Orn'Atar that make up the elven village of Corinthor. You could %^CYAN%^<read map>%^RESET%^ if you wish.");
     set_short("Map of Corinthor");
     set_weight(0);
     set_value(0);
}

void init() {
   ::init();
        add_action("readin", "read");
        }

int readin(string str) {
        if(str != "map") return 0;
        write( @EndText

 %^RESET%^RED%^                 To Palace
 %^GREEN%^                     |
             [ ]-[ ] [ ] [ ]-[ ]
            /       \ | /       \
         [ ]         [ ]         [ ]
          |    %^BOLD%^BLUE%^Sun    %^RESET%^GREEN%^|  %^BOLD%^BLUE%^Summer   %^RESET%^GREEN%^|
     [ ]-[ ]         [ ]         [ ]-[ ]
    /       \       / | \       /       \
 [ ]         [ ]-[ ] [ ] [ ]-[ ]         [ ]
  |  %^BOLD%^BLUE%^Spring   %^RESET%^GREEN%^|       |       |   %^BOLD%^BLUE%^Stars   %^RESET%^GREEN%^|
 [ ]         [ ]     [ ]     [ ]         [ ]
    \       /         |         \       /
     [ ]-[ ]-[ ]-[ ]-[%^YELLOW%^X%^RESET%^GREEN%^]-[ ]-[ ]-[ ]-[ ]
    /       \         |         /       \
 [ ]         [ ]     [ ]     [ ]         [ ]
  |   %^BOLD%^BLUE%^Earth   %^RESET%^GREEN%^|       |       |  %^BOLD%^BLUE%^Autumn   %^RESET%^GREEN%^|
 [ ]         [ ]-[ ] [ ] [ ]-[ ]         [ ]
    \       /       \ | /       \       /
     [ ]-[ ]         [ ]         [ ]-[ ]
          |  %^BOLD%^BLUE%^Winter   %^RESET%^GREEN%^|   %^BOLD%^BLUE%^Moons   %^RESET%^GREEN%^|
         [ ]         [ ]         [ ]
            \       / | \       /
             [ ]-[ ] [ ] [ ]-[ ]
                      |
 %^RED%^                 To Forest%^RESET%^

EndText );
return 1;
}
