#include <std.h>

#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

void create(){
   ::create();

  set_no_clean(1);
   set_name("crevise");
   set_short("A crevice in the wall");
   set_long("%^C202%^This is a crevise in the wall here, the ground here is stable and offers protection from the depths "
			"below. The %^C100%^walls %^C202%^are rough and covered with a sparse %^C149%^vegetation%^C202%^, clinging for"
			"life in a mostly inhospitable location.\n");
   set_smell("default","Fumes from the still raging fires outside singe your nose.");
   set_exits((["out":MOUNTAIN+"dhome"]));
}

void init(){
   ::init();
   add_action("squeeze_em","squeeze");
}

int squeeze_em(string str){
   int mysize;
   object dest,mob;
   dest = find_object_or_load("/d/islands/tonerra/mountain/tunnel1");
   if(!str){
      tell_object(TP,"What are you trying to squeeze?");
      return 1;
   }
   if(str != "crack" && str != "through crack" && str != "through the crack"){
      tell_object(TP,"You cannot squeeze through there!");
      return 1;
   }
   mysize = TP->query_size();
   switch(mysize){
      case 2:  tell_object(TP,"You easily slip through the opening "+
                  "in the wall to the cave above.");
               if(!TP->query_invis()){
                  tell_room(TO,""+TPQCN+" slips through the opening "+
                     "in the wall easily.",TP);
                  tell_room(dest,""+TPQCN+" climbs up through a "+
                     "crack in the floor.",TP);
			   TP->move_player(dest);
			   return 1;
               }
               break;
      default: tell_object(TP,"You are confident there is absolutely no way "
					"you are fitting through that small crack.");
               if(!TP->query_invis()){
                  tell_room(TO,""+TPQCN+" inspects the crack on the wall "+
                     "carefully.",TP);
               }
			   return 1;
               break;
   }

}