/* form table for the shapeshifter guild
 * Raskolnikov Oct 96
 */

string *immorts_allowed = ({
  "santino",
  "messier",
  "titan",
  "arclight",
  "kodiak",
  "raskolnikov",
});

mixed lookup_valid_forms(object player, mixed form) {
    int level;
    string *valid_forms;

    if(player->query_creator() == 1)
	if((member_array(player->query_name(), immorts_allowed) == -1)  
	  && (player->query_lord() != 1))
	    return ({ });
    valid_forms = ({ });
    /* broken...goes back when fixed
    if(player->query_property("STUDY_QUEST") == 1)
	valid_forms += ({ "player" });
    */
    if(player->query_name() == "raskolnikov")
	valid_forms += ({ "player" });
   if(player->query_property("KEEP"))
	valid_forms+=({ "skunk" });
   if(player->query_property("CITADEL"))
	valid_forms+=({ "skunk" });
    level = player->query_level();
    switch(level) {
    case 25..1000:
/*
    case 25:
	valid_forms += ({
	  "race",
	});
*/
    case 24:
	valid_forms += ({
	  "demon",
	});
    case 23:
	valid_forms += ({
	  "gargoyle",
	});
    case 22:
	valid_forms += ({
	  "shadow",
	});
    case 21:
	valid_forms += ({
	  "parasite",
	});
    case 20:
	valid_forms += ({
	  "tree",
	});
    case 19:
	valid_forms += ({
	  "vine",
	});
    case 18:
	valid_forms += ({
	  "ogre",
	});
    case 17:
	valid_forms += ({
	  "octopus",
	});
    case 16:
	valid_forms += ({
	  "bear",
	});
    case 15:
	valid_forms += ({
	  "lion",
	});
    case 14:
	valid_forms += ({
	  "tiger",
	});
    case 13:
	valid_forms += ({
	  "wolf",
	});
    case 12:
	valid_forms += ({
	  "dog",
	});
    case 11:
	valid_forms += ({
	  "fox",
	});
    case 10:
	valid_forms += ({
	  "hawk",
	});
    case 9:
	valid_forms += ({
	  "pigeon",
	});
    case 8:
	valid_forms += ({
	  "snake",
	});
    case 7:
	valid_forms += ({
	  "bumblebee",
	});
/*
    case 6:
	valid_forms += ({
	  "rock",
	});
*/
    case 5..6:
	valid_forms += ({
	  "mosquito",
	});
	break;
    }
    if(form == "all")
	return valid_forms;
    if(member_array(form, valid_forms) != -1)
	return 1;
    return 0;
}


void list_valid_forms(object player) {
    string output;
    string *valid_forms;

    valid_forms = lookup_valid_forms(player, "all");
    tell_object(player, "You can change into the following forms:\n\n");
    output = implode(valid_forms, "\n");
    printf("%-#*s", player->query_cols(), output+"\n");
    write("\n");
    return 1;
}
