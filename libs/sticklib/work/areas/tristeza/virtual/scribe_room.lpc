#include <room.h>
#include <areas.h>
#include <city_name.h>

#define BASE_DIR "/std/obj/"

#define HEALING_FILE BASE_DIR+"scroll_of_healing"
#define RECALL_FILE BASE_DIR+"scroll_of_recall"

#define HEALING_SCROLL "scroll of healing"
#define RECALL_SCROLL "scroll of recall"

#define HEALING_MAX 15
#define RECALL_MAX 20

#define HEALING_COST 5000
#define RECALL_COST 4000

#define HEALING_LEFT HEALING_MAX
#define RECALL_LEFT RECALL_MAX

string desc_plaque();

mapping items;

void create_room() {
    set_short("Top of the Priest Tower in " CITY_NAME);
    set_long(
      "You have reached the top of the Priests Tower, a large "
      "spacious room devoted to displaying the different shelves "
      "and barrels of odd items the scribe sells for a living. "
      "A small plaque is on the west wall. "
    );
    set_items(([
	"plaque" : #'desc_plaque,
      ]));
    items = ([
      HEALING_SCROLL : ({ HEALING_MAX, HEALING_COST, HEALING_LEFT }),
      RECALL_SCROLL : ({ RECALL_MAX, RECALL_COST, RECALL_LEFT }),
    ]);
    set_exits(([
	"down" : AREA_TRISTEZA+"virtual/tower_14x0",
      ]));
    set_light_level(LT_LIGHTS);
    add_monster(AREA_TRISTEZA+"npc/scribe", "Scribe arrives", 1);
}

string desc_plaque()
{
    int i;
    string *inames;
    inames = m_indices(items);
    this_player()->tell_me("The Scribe of " CITY_NAME);
    for(i=0;i<sizeof(inames);i++) {
	this_player()->tell_me(
	  capitalize(inames[i])+" ("+items[inames[i]][2]+" remaining) "
	  +items[inames[i]][1]+" gold coins. "
	);
    }
    this_player()->tell_me(
      "If you wish to make a purchase, simply <buy itemname>. "
    );
}

void init_room() {
    add_action("buy", "buy");
}

int buy(string str) {
    int amt;
    string *inames, *purchase;
    object what;
    inames = m_indices(items);
    if(!str) return notify_fail("Buy what? \n"), 0;
    str = lower_case(str);
    if(member(inames, str) == -1) {
	return notify_fail(capitalize(str)+" is not sold here. \n"), 0;
    }
    purchase = items[str];
    if(purchase[1] > this_player()->query_money()) {
	return notify_fail("You don't have enough gold coins! \n"), 0;
    }
    if(purchase[2] <= 0) {
	this_player()->tell_me(
	  "There aren't any "+str+"s left! "
	);
	return 1;
    }
    this_player()->tell_me("You purchase a "+str+". ");
    items[str][2] -= 1;
    this_player()->add_money( -(items[str][1]) );
    switch(str) {
    case HEALING_SCROLL : what = clone_object(HEALING_FILE); break;
    case RECALL_SCROLL : what = clone_object(RECALL_FILE); break;
    }
    move_object(what, this_player());
    return 1;
}

mapping query_items() { return items; }

void reset_room() {
    int i;
    string *inames;
    inames = m_indices(items);
    for(i=0;i<sizeof(inames);i++) {
	if(items[inames[i]][2] < items[inames[i]][0]) {
	    items[inames[i]][2] += 1;
	}
    }
}
