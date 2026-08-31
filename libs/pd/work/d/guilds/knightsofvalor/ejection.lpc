#include <std.h>
#include <tirun.h>
void eject(object tp) {
     object ob, *all;
     int i;
     message("info", "A knight walks up to you and speaks... '%^BOLD%^Your presence is not accepted here.  Please speak with Yun, our leader.'", tp, );
     tp->move(ROOMS"square");
     message("info", "\nA shadow says: "+capitalize(tp->query_name())+" was caught trespassing.", environment(tp), tp);

     all = users();
     i = sizeof(all);
     while(i--) {
       ob = all[i];
       if(ob->query_guild() == "knightsofvalor" && !wizardp(ob))
         message("info", "\n"+capitalize(tp->query_name())+" just got caught entering our guild hall!", ob, );
       }
}
