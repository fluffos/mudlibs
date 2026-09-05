inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())

     reset() {
       set_name("Elite Platemail");
       set_alias("battle armor");
       set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Battle Armor"+NORM);
       set_long(
         "This Armor is very well crafted the golden glow reflects\n"+
         "the surounding light.  The Armor seems to glow with solar\n"+
         "power.\n");
       set_ac(4);
       set_light(1);
       set_type("armor");
       set_weight(4);
       set_value(3000);
       }

     do_special(owner)    {
       if(!random(6)){
         tell_room(environment(USER),
         BOLD+YEL+CAP(USER->query_name())+"'s armor "+HIY+"GLOWS"+NORM+" with power."+NORM+".\n");
           owner->add_hit_point(random(7));
             return 0;}
             return 0;}

     short(){
       string heh;
         heh = ""+RED+"["+BOLD+YEL+"";
           if(environment()){
           if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Battle Armor"+NORM+" ";
           else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Battle Armor"+NORM;
       }

       else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Battle Armor"+NORM;
       /*if(broke) heh += " [BROKEN]";
         if(wielded) heh += " (wielded)";*/
         if(worn) heh += " (worn)";
       return heh;
       }
      
     
