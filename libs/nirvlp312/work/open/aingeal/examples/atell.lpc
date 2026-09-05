/* Aingeal's teller to players */

#include "/players/aingeal/ansi.h"
inherit "/obj/treasure";

reset(arg){
	if(arg) return;
	set_id("halo");
	set_alias("teller");
	set_short(""+BOLD+WHT+"Glowing Halo"+NORM+"");
	set_long("This is Aingeal's special teller.\n");

	set_weight(0);
	set_value(0);
	}

drop(){
	write("You may not drop your halo.\n");
	return 1;
	}

init(){
    ::init();
    add_action("halo","halo");
    add_action("haloe","haloe"); 
    add_action("halof","halof");
}


halo(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Tell what?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target, BOLD+BLU+"[invis] Aingeal softly says: "+BOLD+WHT+what+NORM+" \n");
             write(BOLD+BLU+"You tell "+capitalize(who)+": "+BOLD+WHT+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);

	return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,BOLD+BLU+"Aingeal softly says: "+BOLD+WHT+what+NORM+" \n");
             write(""+BOLD+BLU+"You tell "+capitalize(who)+": "+BOLD+WHT+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);

	return 1; 
            }
   return 1;
     }
return 1;
}


haloe(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target,BOLD+BLU+"[invis] Aingeal "+BOLD+WHT+what+NORM+" \n");
             write(""+BOLD+BLU+"You faremote to " +capitalize(who)+": "+BOLD+WHT+what+NORM+"\n");
             
    return 1; 
            }

    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+BOLD+BLU+"Aingeal "+BOLD+WHT+what+NORM+" \n");
             write(""+BOLD+BLU+"You faremote to " +capitalize(who)+": "+BOLD+WHT+what+NORM+"\n");
    return 1; 
            }
  return 1;
     }
return 1;
  }


halof(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target,""+BOLD+YEL+what+NORM+" \n");
             write(""+BOLD+YEL+"You echo to " +capitalize(who)+": "+what+NORM+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+BOLD+YEL+what+NORM+" \n");
             write(""+BOLD+YEL+"You echo to " +capitalize(who)+": "+what+NORM+"\n");

    return 1; 
         }
   return 1;
     }
return 1;
   }


