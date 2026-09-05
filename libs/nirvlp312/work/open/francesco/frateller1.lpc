#include "/players/eurale/closed/ansi.h"

id(str)  { return str == "fratell"; }
short() {return "Francesco's teller (mounted)";}

drop()   { return 1; }
get()    { return 1;}

init(){
    
    add_action("fratell","fratell");
    add_action("fratelle","fratelle"); 
    add_action("fratelli","fratelli");
}


fratell(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Tell what?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, HIW+"Francesco (invis) politely speaks to you: "+NORM+what+" \n");
             write(HIW+"You invisibly fratell "+capitalize(who)+NORM+": "+what+"\n");
	     player->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
/*             add_tellhistory(this_player()->query_real_name()+" tells you: "+what);*/
             return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player, HIW+"Francesco politely speaks to you: "+NORM+what+" \n");
	     write(HIW+"You fratell "+capitalize(who)+NORM+": "+what+"\n");
             player->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
/*	     add_tellhistory(capitalize(this_player())->query_real_name()+" tells you: "+what);*/
    return 1; 
            }
    return 1;
            }
    return 1;
            }

fratelle(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, "Francesco (invis) "+what+" \n");
             write("You invisibly fraemote to " +capitalize(who)+": "+what+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player, "Francesco "+what+" \n");
	     write("You fraemote to " +capitalize(who)+": "+what+"\n");
    return 1; 
            }
    return 1;
            }
    return 1;
            }

fratelli(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, what+" \n");
             write("You echo to " +capitalize(who)+": "+what+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player,what+" \n");
	     write("You echo to " +capitalize(who)+": "+what+"\n");
    return 1; 
            }
    return 1;
            }
    return 1;
            }


