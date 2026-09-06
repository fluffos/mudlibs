#include <generic_items.h>
#include "priest_room.h"

#define TP this_player()

void
create_room() {
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_light_level(LT_DIM);
    set_short("The laboratory");
    set_long(
      "This is a small laboratory-like room for priests to practice their skills \
in mixing potions. There's a huge book on a stand in the middle of the \
room, and nailed at the wall is a small plaque.");

    set_items(([
	({ "book", "huge book", "recipies" }) : "It looks just like an enormous \
cooking book, only that the recipies seem a bit weird. It's chained onto \
a stand.",
	"stand" : "The stand is made of red granite.",
	"plaque": "It's a small silver plaque, how about reading it?",
      ]));

    add_object(GENERIC_TRASHCAN,
      "Alchemist says: I forgot to put this in here again.",1);

    add_exit("north", PRIEST_ROOM_DIR "alchemy_chamber");
}

status is_priest_lab() { return 1; }

status
read_cmd(string str)
{
    int page;
    int amount;
    string *recipies;

    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    recipies=get_dir(PRIEST_ALC_DIR "recipies/");
    recipies -= ({ ".ACCESS" });
    amount=sizeof(recipies);
    if(str=="book" || str == "huge book" || str == "recipies") {
	TP->tell_me("This is the book with the basic instructions for \
making potions. There's " + amount + " recipies now, you can read them \
with 'read page <nbr>'.");
	return 1;
    }
    if(str=="plaque") {
	this_player()->tell_me("It says: If you have lost your scalpel, \
just type 'scalpel' to get a new one.");
	return 1;
    }
    if(sscanf(str,"page %d",page)!=1) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(page<1 || page>amount) {
	notify_fail("No such page in the book.\n");
	return 0;
    }
    cat(PRIEST_ALC_DIR+"recipies/"+recipies[page-1]);
    return 1;
}

