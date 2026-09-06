/* TOBACCO STORE - Coded by MacLeod */

#include <room.h>
#include <areas.h>
#include <pipe_defs.h>
#include "../DEFS.h"

#define LOCATION AREA_TRISTEZA+"virtual/S2_10"
#define TM(x)        this_player()->tell_me(x)
#define TH(x)        environment(this_player)->tell_here(x, this_player)
#define ERROR(x)       { this_player()->tell_me(x); return 1; }

mapping stuff;

void reset_room() {
    int i;
    if(!stuff) stuff = ([
	  1: "Smoking Pipe (Saveable)"; 5; 150,
	  2: "Chewing Gum"; 10; 500,
	  3: "Western Lily"; 40; 300,
	  4: "Dried Horse Dung"; 35; 900,
	  5: "Altairian Sentient Hop Weed"; 25; 2700,
	  6: "Slugger's Used Socks"; 20; 4950,
	  7: "Egyptian Pharao Dust"; 15; 9999,
	]);
    for(i=0;i<sizeof(stuff);i++) {
	if(stuff[i, AMOUNT] == 0) switch(i) {
	case 1: stuff[i, AMOUNT] += (random(2) + 2); break;
	case 2: stuff[i, AMOUNT] += (random(10) + 5); break;
	case 3: stuff[i, AMOUNT] += (random(15) + 25); break;
	case 4: stuff[i, AMOUNT] += (random(20) + 15); break;
	case 5: stuff[i, AMOUNT] += (random(15) + 10); break;
	case 6: stuff[i, AMOUNT] += (random(10) + 10); break;
	case 7: stuff[i, AMOUNT] += (random(10) + 10); break;
	default: break;
	}
    }
}

void create_room() {
    set_short("Ben's tobacco store");
    set_long(
      "You are in Ben's tobacco store, even though you propably knew it by now. The\
 room is filled with thick smoke, and the once almost white walls have\
 turned pitch black. Through the smoke you can see a counter at the end of\
 the room, and a list of some kind attached to it.");
    set_items(([
	"counter" : "It propably serves as a sales table. There's something\
 engraved on the top, and a list of somekind has been attached to the end\
 of the counter.",
	({ "engraving", "text", "something" }) : "\"MacLeod was here.\"",
	"list" : "It looks like there was something written on it."
      ]));
    set_exits(([ "north" : LOCATION ]));
    set_commands(([
	"read": "read_cmd",
	"buy" : "buy_cmd"
      ]));
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_DIM);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "ben" }),
	({ "set_id", ({ "ben", "shopkeeper" }) }),
	({ "set_short", "Ben the shopkeeper is here" }),
	({ "set_race", "hobbit" }),
	({ "set_long", "Old ben is a fat, merry hobbit.\
 He is puffing his pipe with great enjoyment." }),
	({ "set_random_pick", 0 })
      }), "Suddenly you notice that the shopkeeper was here all\
 along, you just didn't see him through the smoke.", 1 );
    reset_room();
}

status read_cmd(string what) {
    int i;
    string text;
    if(!what || what != "list") return 0;
    if(!present("shopkeeper", this_object())) ERROR("The list is covered with\
 blood, so you can't make out what it says.");
    text = "\nNr\tCost\tItem\n----------------------------------------";
    for(i=1;i<sizeof(stuff)+1;i++) {
	text += "\n" + i + ".\t" + (int) stuff[i, COST] + "\t" + stuff[i, DESC];
	if(stuff[i, AMOUNT] == 0) text += " (sold out)";
    }
    text += "\n";
    TM(text);
    return 1;
}

status buy_cmd(string what) {
    object item, shopkeeper;
    int i, value, cash;
    string str;

    if(!(shopkeeper=present("shopkeeper", this_object())))
	ERROR("But the shopkeeper isn't even here.");

    if(sscanf(what, "%d%s", i, str) == 2 && str == "" && i > 0 && i < 8) {
	value = stuff[i, COST];
	cash = this_player()->query_money();
	if(cash < value) ERROR(sprintf("Ben tells you: Get that %d gold coins first,\
 and then we'll talk.", value));
	if(stuff[i, AMOUNT] == 0) ERROR("Ben says: Sorry, those are out of the\
 stock.");
	switch(i) {
	case 1: item = clone_object(PIPE_FILE); break;
	case 2: item = clone_object(OBJ_DIR+"gum");  break;
	case 3: item = clone_object(OBJ_DIR+"lily"); break;
	case 4: item = clone_object(OBJ_DIR+"dung"); break;
	case 5: item = clone_object(OBJ_DIR+"weed"); break;
	case 6: item = clone_object(OBJ_DIR+"sock"); break;
	case 7: item = clone_object(OBJ_DIR+"dust"); break;
	default: ERROR("Ben says: Hmm.. What was I doing here anyway? Could you\
 ask MacLeod come here please."); break;
	}
	if(!item) ERROR("Ben says: Hmm... Was I doing something anyway? Could you\
 ask MacLeod to come here please.");
	if(!this_player()->add_weight((int)item->query_weight())) ERROR("Ben sighs.\
 \nBen says: Drop something first. You can't carry this.");
	TM(sprintf(":You give %d gold coins to Ben.", value));
	this_player()->add_money(-value);
	tell_here(":%<him.capname>% give%<him.ending_s>% %<it.name>% to %<me.capname>%.",
	  0, 0, 0, this_player(), shopkeeper, item);
	move_object(item, this_player());
	stuff[i, AMOUNT] -= 1;
	return 1;
    }
    else ERROR("Ben says: Pick a number that's between 1 and 7.");
}
