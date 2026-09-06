#include <room.h>
#include <areas.h>
#include <city_name.h>

#define BASE_DIR AREA_TRISTEZA "special/"

#define ABJURATION_FILE BASE_DIR+"abjure_scroll"
#define RESET_FILE BASE_DIR+"reset_scroll"
#define FIND_UNIQUE_FILE BASE_DIR+"locate_scroll"
#define EARMUFFS_FILE BASE_DIR+"earmuffs"

#define LOCATE_FILE BASE_DIR+"locate_scroll"

#define ABJURATION_SCROLL "scroll of abjuration"
#define FIND_UNIQUE_SCROLL "scroll of location"
#define RESET_SCROLL "scroll of time distortion"
#define EARMUFFS "earmuffs"

#define ABJURATION_MAX 5
#define FIND_UNIQUE_MAX 12
#define RESET_MAX 1
#define EARMUFFS_MAX 12

#define ABJURATION_COST 7500
#define FIND_UNIQUE_COST 1000
#define RESET_COST 50000
#define EARMUFFS_COST 500

#define ABJURATION_LEFT ABJURATION_MAX
#define FIND_UNIQUE_LEFT FIND_UNIQUE_MAX
#define RESET_LEFT RESET_MAX
#define EARMUFFS_LEFT EARMUFFS_MAX

string desc_plaque();

mapping items;

void create_room() {
    set_short("Top of the Sage's Tower in " CITY_NAME);
    set_long(
      "You have reached the top of the Sage's Tower, a large "
      "spacious room devoted to displaying the different shelves "
      "and barrels of odd items the sage sells for a living. "
      "A small plaque is on the west wall. "
    );
    set_items(([
	"plaque" : #'desc_plaque,
      ]));
    items = ([
      ABJURATION_SCROLL : ({ ABJURATION_MAX, ABJURATION_COST, ABJURATION_LEFT }),
      FIND_UNIQUE_SCROLL : ({ RESET_MAX, FIND_UNIQUE_COST, FIND_UNIQUE_LEFT }),
      RESET_SCROLL : ({ RESET_MAX, RESET_COST, RESET_LEFT }),
      EARMUFFS : ({ EARMUFFS_MAX, EARMUFFS_COST, EARMUFFS_LEFT }),
    ]);
    set_exits(([
	"down" : AREA_TRISTEZA+"virtual/tower_0x14",
      ]));
    add_monster(AREA_TRISTEZA+"npc/sage", "Sage arrives", 1);
}

string desc_plaque()
{
    int i;
    string *inames;
    inames = m_indices(items);
    this_player()->tell_me("The Sage of " CITY_NAME);
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
    case ABJURATION_SCROLL : what = clone_object(ABJURATION_FILE); break;
    case FIND_UNIQUE_SCROLL : what = clone_object(FIND_UNIQUE_FILE); break;
    case RESET_SCROLL : what = clone_object(RESET_FILE); break;
    case EARMUFFS : what = clone_object(EARMUFFS_FILE); break;
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
