#include <std.h>
#include <tirun.h>

void eject(object tp) {
     object ob, *all;
     int i;
     message("info", "%^RESET%^CYAN%^An Archangel says: %^RESET%^Your death, approaches.", tp, );
     message("info", "%^BOLD%^WHITE%^White flame spills from the Archangel's body, engulfing his opponents!", tp, );
     message("info", "%^BOLD%^WHITE%^Holy%^RESET%^ORANGE%^fire %^BOLD%^WHITE%^e%^RESET%^ORANGE%^n%^BOLD%^WHITE%^g%^RESET%^ORANGE%^u%^BOLD%^WHITE%^l%^RESET%^ORANGE%^f%^BOLD%^WHITE%^s %^RESET%^ORANGE%^you%^BOLD%^WHITE%^!", tp, );
     message("info", "hp: -"+(random(400)+101)+"    sp: "+tp->query_sp()+"    mp: "+tp->query_mp()+"", tp, );
     message("info", read_file("/news/ghost"), tp, );
     message("info", "You die.\nYou feel the sensations of nothingness as you rise above your corpse.\nYou arrive at a destination in a reality not like your own.", tp, );
     tp->move(ROOMS"square");
     tp->set_paralyzed(20, "");
     message("info", "\n%^RESET%^CYAN%^A shadow says: %^RESET%^"+capitalize(tp->query_name())+" was caught trespassing.", environment(tp), tp);

     all = users();
     i = sizeof(all);
     while(i--) {
       ob = all[i];
       if(ob->query_guild() == "illuminati" && !wizardp(ob))
         message("info", "\n%^YELLOW%^"+capitalize(tp->query_name())+" just got caught entering our guild hall!%^RESET%^", ob, );
       }
}
