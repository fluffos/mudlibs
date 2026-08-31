//
// Trivia quest-prize for Waterworld
//       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int extra_wear();
int extra_remove();

void create() {
    ::create();
          set_name("Gloves of bargaining");
          set_id(({"gloves of bargaining","gloves","bargaining"}));
         set_short("The gloves of the %^CYAN%^N%^ORANGE%^eg%^BLACK%^%^BOLD%^ot%^YELLOW%^ia%^GREEN%^tor%^MAGENTA%^");

        set_long("The gloves of the %^CYAN%^N%^ORANGE%^eg%^BLACK%^%^BOLD%^ot%^YELLOW%^ia%^GREEN%^tor%^MAGENTA%^"
               " seem to 'breath' on their own."
              " The gloves to beem forged from some form of animal hide....");
          set_type("gloves");
          set_ac(1);
          set_weight(30);
          set("read","Crafted by the master magi of Atlantis!!");
          set_wear( (: extra_wear :) );
          set_remove( (: extra_remove :) );
}

int extra_wear() {
        object TP=this_player();
        object TR=environment(TP);
        string cap_tp=TP->query_cap_name();
        string sex_tp=TP->query_possessive();
        string ME=query_short();

        if( (TP->query("gloves-of-bargaining")>=1) ) {
              message("info",
                        ME+" %^RESET%^seem to vibrate as you slip them onto you hands..\n\n"
                        ,TP);
              message("info",
                        ME+" %^RESET%^seem to vibrate as "+cap_tp+" slips them onto "+sex_tp+" hands..\n\n"
                        ,TR,TP);
           message("info",
                     "A fog of shrewdness settles in around you and solidifies!!"
                         ,TP);
           message("info",
                     "A fog of shrewdness settles in around "+cap_tp+"!!"
                         ,TR,TP);
           TP->add_skill_bonus("bargaining",20);
                   return 1;}
         else {
            message("info",
                        ME+" %^RESET%^shreak in terror and run for parts unknown..."
                         ,TP);
            message("info",
                        ME+" %^RESET%^shreak in terror and run for parts unknown as "+cap_tp+" tries to wear them..."
                         ,TR,TP);
                    remove();
                    return 0;}
}
int extra_remove() {
        object TP=this_player();
        object TR=environment(TP);
        string cap_tp=TP->query_cap_name();
        string ME=query_short();
        string sex_tp=TP->query_possessive();

         message("info",
                        ME+" %^RESET%^seem almost to cry as you take them off your hands."
                     ,TP);
         message("info",
                        ME+" %^RESET%^seem almost to cry as "+cap_tp+" takes them off "+sex_tp+" hands."
                     ,TR,TP);
           TP->add_skill_bonus("bargaining",-20);
          return 1;
}
int query_auto_load() {
       if( (this_player()->query_property("gloves-of-bargaining"))==1) return 1;
}
