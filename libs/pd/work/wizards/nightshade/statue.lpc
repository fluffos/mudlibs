#include <std.h>
inherit OBJECT;
void create() {
 ::create();
   set_id(({ "fountain" }));
   set_name("fountain");
   set_long("The workmanship of the fountain is magnificent, in fact "
            "the finest you've seen in your life! Atop the fountain "
            "is a statue is of a mighty dragon, symbolizing Tirun's "
            "strength in battle. Water runs from the dragon's mouth "
            "into a pool at the dragons feet. A gold plaque has been "
            "mounted at the base of the fountain.");
   set_short("a fountain");
   set_weight(1);
   set("value", 0);
   set_prevent_get( "The fountain will not budge." );
}
int readPlaque(string what) {
   if (!what || what != "plaque") return 0;
   tell_room(environment(this_player()), this_player()->query_cap_name()+
        " reads over the plaque on the fountain.", ({ this_player()}));
   write("%^BOLD%^%^CYAN%^The gold plaque reads: %^RESET%^");
   write("%^YELLOW%^Reality has begun to wind itself and life has "
         "begun to spill forth upon this world. The gods "
         "whom sit on high would like to give thanks to thine, "
         "whom has helped in creating this, our world.");
   write("%^YELLOW%^Several names have been inscribed beneath the inscription:%^RESET%^");
   write("%^YELLOW%^Great thanks goes out to all whom hast helped, but especially to:\n");
write(@ENDTEXT
Seeker                 Inferno             Stormbringer 
Detach                 Wiz                 Nightshade
Asmodeus               Slinker             Leviathas
Suluial                Whit
ENDTEXT);
   return 1;
}
int goDrink(string str) {
   if (str != "fount" && str != "fountain" && str != "from fount" && str != "from fountain") {
      notify_fail("Drink from what?\n");
      return 0;
   }
   if (this_player()->query_disable())
   {
    write("You cannot drink that fast.");
    return 1;
   }
 this_player()->set_disable();
 this_player()->heal(10);
 write("%^BOLD%^%^BLUE%^The water refreshes you.%^RESET%^");
 return 1;
}
int DragonGaze(string str) {
    if(str != "into eyes")
      return 0;
    write("As you gaze into the dragons eyes, you find yourself in a whole new place...");
    call_out("first", 3, this_player());
    this_player()->set_paralyzed(17, "You do not know where you are!");
    return 1;
}
void first(object tp) {
    message("info","%^CYAN%^A voice says: %^RESET%^There was a time, long ago..  when dragons did not exist.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^There was no death, and everything was at peace.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^But when the races of earth became corrupted, the gods struck them with with their mortality.\n", tp);
    call_out("second", 6, tp);
}
void second(object tp) {
    message("info","%^CYAN%^A voice says: %^RESET%^Unfortunately...  with death came the dragons.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^Sick children, near death, would dissapear, only to return home as a dragon.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^Soon, all dragons became corrupted because of their power, except for one.\n", tp);
    call_out("third", 8, tp);
}
void third(object tp) {
    message("info","%^CYAN%^A voice says: %^RESET%^This dragon, Valor, hunted the corrupted dragons, saving scores of mortals.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^Soon enough, the others plotted against him and killed him.", tp);
    message("info","%^CYAN%^A voice says: %^RESET%^But by this time a balance had been reached, and dragons hid away, becoming mere legend.\n", tp);
    message("info","You find yourself standing back in front of the dragon, gawking.", tp);
}
void init() {
 ::init();
   add_action("readPlaque", "read");
   add_action("goDrink", "drink");
   add_action("DragonGaze", "gaze");
}
