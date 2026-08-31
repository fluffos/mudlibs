# 1 "room/quest_room.c" 
# 1 "room/room.h" 1
inherit "room/room";
























# 2 "room/quest_room.c" 2
# 1 "room/tune.h" 1





















































# 3 "room/quest_room.c" 2


# 16 "room/quest_room.c" 
reset(arg) { if (!arg) { set_light( 1); short_desc =  	 "Room of quests"; long_desc =  "This is the room of quests. Every wizard can make at most one quest.\n" + "When he has made a quest, he should have it approved by an arch wizard.\n" + "When it is approved, put a permanent object in this room, wich has as\n"+ "short description the name of the wizard. All objects in this room will be\n"+ "checked when a player wants to become a wizard. The player must have\n"+ "solved ALL quests. To mark that a quest is solved, call 'set_quest(\"name\")'\n"+ "in the player object. The objects must all accept the id 'quest' and the\n"+ "name of the wizard. The objects must also define a function hint(),\n"+ "that should return a message giving a hint of where to start the quest.\n"+ "Note that players never can come here. set_quest(str) will return 1 if\n"+ "this is the first time it was solved by this player, otherwise 0.\n"; dest_dir = ({ "room/wiz_hall",  "south" }); }  }

count(silently) {
    object ob;
    int i;

    ob = first_inventory(this_object());
    while(ob) {
	if (call_other(ob, "id", "quest")) {
	    string str;
	    str = call_other(ob, "short");
	    if (!call_other(this_player(), "query_quests", str))
		i += 1;
	}
	ob = next_inventory(ob);
    }
    if (!silently) {
	if (i == 0)
	    write("You have solved all quests!\n");
	else {
	    write("You have " + i + " quests unsolved.\n");
	    if (i - 3 <= 0)
		write("You don't have to solve any more quests.\n");
	    else
		write("You must solve " + (i - 3) + " of these.\n");
	}
    }
    if (i - 3 < 0)
	return 0;
    return i - 3;
}

list(i) {
    object ob;

    ob = first_inventory(this_object());
    while(ob) {
	if (call_other(ob, "id", "quest")) {
	    string str;
	    str = call_other(ob, "short");
	    if (!call_other(this_player(), "query_quests", str))
		i -= 1;
	    if (i == 0) {
		write(call_other(ob, "hint") + "\n");
		return;
	    }
	}
	ob = next_inventory(ob);
    }
}
