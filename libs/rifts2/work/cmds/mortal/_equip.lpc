/*  /cmds/mortal/_equip.c
 *  Made for DarkeMUD
 *  Created by Geldron 030996
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */
// Modified heavily by Drizzt 10/15/96
// It is actually worth a shit now!

inherit DAEMON;

int cmd_equip(string arg) {
    object *tmp;
    int i;
    string hand, race;

    if(arg) {
	write(syntax("equip"));
	return 1;
    }
    write("You begin power equipping...");
    hand = (string)this_player()->query_property("handedness");
    race = (string)this_player()->query_race();
    tmp = all_inventory(TP);
    for(i = 0; i < sizeof(tmp); i++) {
	if(tmp[i]->is_weapon()) {
	    if(strlen((string)tmp[i]->query_type()) > 10 &&
	      ((string)tmp[i]->query_type())[0..9] == "two handed")
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand "
		  "and left hand");
	    else {     	      
     if(hand == "left hand") {
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in left hand");
    TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in right hand");
       }  else 
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " in right hand");
     TP->force_me("wield " + ((string *)tmp[i]->query_id())[0] + " 2 in left hand");
	    }
	}
	if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "shield") {
	      if(hand == "right hand") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on left hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
	    }     
            else
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on left hand");
	    }
        if(tmp[i]->is_armour())
	  if((string)tmp[i]->query_type() == "bracer") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right arm");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left arm");
	    } 
        if(tmp[i]->is_armour())
	    if((string)tmp[i]->query_type() == "glove") {
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " on right hand");
      TP->force_me("wear " + ((string *)tmp[i]->query_id())[0] + " 2 on left hand");
	    }  else
                TP->force_me("wear " + ((string *)tmp[i]->query_id())[0]);
    }        
    write("Done Equiping.");
    return 1;
}
	

void help() {
    message("equip_help", syntax("equip") + "\n\n"
      "Equips all your armour and weapons in order.  It isn't "
      "very accurate as to getting things worn the best possible way.", TP);
}
