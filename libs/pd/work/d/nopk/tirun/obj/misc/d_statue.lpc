#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_id(({ "statue" }));
   set_name("statue");
   set_long("The workmanship of the statue is magnificent, in fact the "
            "finest you've seen in your life! The statue is of "
            "a mighty dragon, symbolizing Tirun's strength in "
            "battle. The dragon's head is pulled back, ready to "
            "attack. It's eyes seem to gaze deep into the depths "
            "of your soul. A silver plaque has been affixed to the "
            "base of the plaque.");
   set_short("A statue of a dragon");
   set_weight(1);
   set("value", 0);
set_prevent_get( "The statue is too heavy." );

}



int readPlaque(string what) {
   if (!what || what != "plaque") return 0;
   tell_room(environment(this_player()), this_player()->query_cap_name()+
        " reads over the silver plaque on the statue.", ({ this_player()}));
   write("%^BOLD%^%^CYAN%^The polished silver plaque reads: %^RESET%^");
   write("Reality hast begun to wind itself and life hast "
         "begunst to spill forth upon this world. The gods "
         "whom sit on high would like to give thanks to thine, "
         "whom hast helped in creating this, our world.");
   write("%^CYAN%^Several names have been inscribed beneath the inscription:%^RESET%^");
   write("%^YELLOW%^Great thanks goes out to all whom hast helped, but especially to:%^RESET%^\n");
write(@ENDTEXT
Seeker                          Inferno
Detach                          Stormbringer
Asmodeus                        Marduk
Slinker                         Morgoth
Swifty                          Manex
Suluial
ENDTEXT);
   return 1;
}

void init() {
 ::init();
   add_action("readPlaque", "read");
}
