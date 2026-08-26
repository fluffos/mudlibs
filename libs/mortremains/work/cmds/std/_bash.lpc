// bash.c
// (09-03-96) Adapted from the knock command since Chronos is a bit lazy.
// (09-04-96) Chronos plays with the code until it works perfectly.
// (04-04-98) Chronos begins porting code to the new lib.
// (04-11-98) Ilzarion D&D ized the bashing with the # being a neg mod
//            - Reminder - Don't forget to define the std broken door!

#include <mudlib.h>

#define BROKEN_DOOR_PATH "/obj/std/broken_door"
inherit DAEMON ;

int cmd_bash(string str) {
    string dir, linked ;
    object env, linked_env, *bashed ;
    int bash, strength, roll;
    mapping doors, exits ;

    /* This isn't needed anymore since it's the wrong mud.
      if ((string)TP->query("race")!="half-ogre" && !wizardp(TP)) return 0;
      if ((int)TP->query_rest_status()==2) {
      write("You cannot bash doors while sleeping.\n") ;
      return 1;
      }
      if ((int)TP->query_rest_status()==1) {
      write("You cannot bash doors while resting.\n") ;
       return 1;
      }
    */

    if (!str) { 
	write("Bash what?\n");
	return 1;
    }
    if (str != "door" && str != "down the door" &&
      str != "down door" && 
      sscanf(str, "%s door", dir) != 1 &&
      sscanf(str, "down the %s door", dir) != 1 && 
      sscanf(str, "down %s door", dir) != 1) {
	write("Bash what?\n");
	return 1;
    } 
    env = environment(this_player()) ;
    if (!env) {
	notify_fail ("The void has no doors.\n") ;
	return 0 ;
    }
    doors = env->query("doors") ;
    if (!doors) {
	notify_fail ("There are no doors here.\n") ;
	return 0 ;
    }
    if(!dir) {
	if(sizeof(keys(doors)) > 1) {
	    notify_fail("Which door do you wish to bash down?\n");
	    return 0; }
	dir = keys(doors)[0];
    }
    if (!doors[dir]) {
	notify_fail ("There is no "+dir+" door.\n") ;
	return 0 ;
    }
    bashed =  environment(TP)->query("bashed");
    if (member_array(TP, bashed) != -1){
	notify_fail ("This door has defeated you for now... maybe another day.\n") ;
	return 0 ;
    }
    linked = environment(TP)->query("doors/"+dir+"/linked");
    write ("You run at the "+dir+" door and slam into it with all your might!\n") ;
    say (wrap(TPN+" runs at the "+dir+" door and slams into it with all "+
	TP->query_possessive()+" might!")) ;
    exits = env->query("exits") ;
    find_object_or_load(exits[dir]) ;
    tell_room (exits[dir], "You hear a loud CRASH from the "+linked+" door!\n") ;
    strength=(int) TP->query("stat/strength");

    /*
    //Ilz hacks here tis a 5% per str above one
// Cyanide "unhacked" it.
	bash = ((strength-1) *5);
	bash -= (environment(TP)->query("doors/"+dir+"/bash" * 2);
    */

    bash = strength - 
    (int)environment(TP)->query("doors/"+dir+"/bash");
    bash *= 5;

    roll = random(100);
    //write ("bash % "+bash+" Roll "+roll+".\n");

    if (roll > bash) {
	write("You seem to have no effect on the door.\n");
	say("The door remains intact.\n");
	environment(TP)->add("bashed", ({TP}));
	return 1;
    }
    write("The door goes flying off into the adjoining room!\n");
    say("The door goes flying off into the adjoining room!\n");
    tell_room (exits[dir], 
      "The "+linked+" door suddenly comes flying off it's hinges!\n") ;
    map_delete(doors,dir);
    environment(TP)->set("doors", doors);
    environment(TP)->set("long", (string)environment(TP)->query("long") + 
      "The "+dir+" door has been smashed off it's hinges.\n");
    environment(TP)->set("item_desc/"+dir+" door", 
      "The "+dir+" door has been smashed off it's hinges.\n");
    environment(TP)->set("item_desc/door", 
      "The "+dir+" door has been smashed off it's hinges.\n");
    linked_env=find_object_or_load(exits[dir]);
    if (!linked_env) {
	write("* Could not load adjoining room.\n");
	if (wizardp(TP)) write("  ["+exits[dir]+"]\n");
	return 1;
    }
    doors=linked_env->query("doors");
    dir = linked;
    if (sizeof(doors)==1) linked_env->delete("doors");
    else {  
	if (doors) map_delete(doors, dir);
	linked_env->set("doors", doors);
    }
    linked_env->set("long", (string)linked_env->query("long") +
      "The "+dir+" door has been smashed off it's hinges.\n");
    linked_env->set("item_desc/"+dir+" door", 
      "The "+dir+" door has been smashed off it's hinges.\n");
    linked_env->set("item_desc/door", 
      "The "+dir+" door has been smashed off it's hinges.\n");
    clone_object(BROKEN_DOOR_PATH)->move(linked_env) ;
    return 1 ;
}

string help() {
    /* Wrong mud again.
      if ((string)TP->query("race")!="half-ogre" && !wizardp(TP)) {
      write(@ENDHELP

    This command is only available to half-ogres.

    ENDHELP
      );
      return 1;
      }
       */
    return(@ENDHELP

Usage: bash door
       bash down door
       bash <direction> door
       bash down <direction> door

This command allows you to attempt to bash your way through a door.
ENDHELP  
    );
}
