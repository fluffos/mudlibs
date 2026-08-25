// HM Warshout
// By Hanse @ Nightmare 11/25/94
// Paralyzes for strength/5 seconds... costs about 100+rnd(20) stamina
// hits all foes
// Strength vs wisdom save

#include <std.h>

inherit DAEMON;

#define SAVE_FORMULA random((int)this_player()->query_stats("strength")) > random((int)list[i]->query_stats("wisdom"))
#define PARA_FORMULA random((int)(this_player()->query_stats("strength"))/5)+1
#define PARA_MESSAGE "You are still recovering from the powerful shout.\n"
#define CASTING_COST 100 + random(20)

int cmd_warshout(string str) {
   int cost, i;
   object *list;

   if(this_player()->query_ghost()) {
      message("talk","You howl like an idiot", this_player());
      message("talk","You hear a wimpy howl.",
environment(this_player()), ({ this_player() }));
      return 1;
   }
   if(!(int)this_player()->query_class("fighter")) return 0;
   if(this_player()->query_level() < 20) return 0;
   cost = CASTING_COST;
   if(cost > this_player()->query_sp()) 
      return notify_fail("Your voice is a little hoarse right now.\n");
   this_player()->set_sp( (int)this_player()->query_sp() - cost);
   list = all_inventory(environment(this_player()));
   list = filter_array(list, "is_alive", this_object());
   for(i=0;i<sizeof(list);i++)
        if(!list[i]->query_paralyzed())
         if(SAVE_FORMULA)
            list[i]->set_paralyzed(PARA_FORMULA, PARA_MESSAGE);
   message("warshout","You bellow forth a huge warshout!", this_player());
   if(!str)
      message("warshout", this_player()->query_cap_name()+
" bellows forth a huge warshout stunning you!", environment(this_player()),
this_player());
   else
      message("warshout", this_player()->query_cap_name()+" warshouts: "+
        str, environment(this_player()), this_player());
   return 1;
}

is_alive(object ob) {
   if(this_player()->query_name() == ob->query_name()) return 0;
   return (living(ob) ? 1 : 0);
}

void help() {
   write("Syntax: <warshout [optional message]>\n\n"
       "Paralyzes your foes with a powerful warshout.\n");
}
