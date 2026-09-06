inherit "/lib/room";

#include "tune.h"

void create_room() {
    set_lumens(1);

    set_brief("Room of quests");

    set_description(
"This is the room of quests. Every wizard can make at most one quest. "
"When they have made a quest, they should have it approved by an arch wizard. "
"When it is approved, put a permanent object in this room, which has as a "
"short description the name of the wizard. All objects in this room will be "
"checked when a player wants to become a wizard. The player must have "
"solved ALL quests. To mark that a quest is solved, call 'set_quest(\"name\")' "
"in the player object. The objects must all accept the id 'quest' and the "
"name of the wizard. The objects must also define a function hint(), "
"that should return a message giving a hint of where to start the quest. "
"Note that players never can come here. set_quest(str) will return 1 if "
"this is the first time it was solved by this player, otherwise 0."
       );

    add_exit("south", "/room/wiz_hall");
}

int count(int silently) {
    object ob;
    int i;

    ob = first_inventory(this_object());

    while (ob) {
	if (ob->id("quest")) {
	    string str = ob->short();

	    if (!this_player()->query_quests(str)) {
		i += 1;
	    }
	}

	ob = next_inventory(ob);
    }

    if (!silently) {
	if (i == 0) {
	    write("You have solved all quests!\n");
	} else {
	    write("You have " + i + " quests unsolved.\n");

	    if (i - FREE_QUESTS <= 0) {
		write("You don't have to solve any more quests.\n");
	    } else {
		write("You must solve " + (i - FREE_QUESTS) + " of these.\n");
	    }
	}
    }

    if (i - FREE_QUESTS < 0) {
	return 0;
    }

    return i - FREE_QUESTS;
}

void list(int i) {
    object ob = first_inventory(this_object());

    while (ob) {
	if (ob->id("quest")) {
	    string str = ob->short();

	    if (!this_player()->query_quests(str)) {
		i -= 1;
	    }

	    if (i == 0) {
		write(ob->hint() + "\n");
		return;
	    }
	}

	ob = next_inventory(ob);
    }
}
