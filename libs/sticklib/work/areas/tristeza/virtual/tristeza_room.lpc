// Version 1.0 29-sep-95 by Doomdark. To be used by _virtual_ Main Town

#include <room.h>
#include <npc_defs.h>
#include <treasure_defs.h>
#include <city_name.h>
#include <mud_name.h>
#include <generic_rooms.h>
#include <generic_items.h>
#include <guild.h>

#include "../DEFS.h"

#define	MAP_STRING \
"\
*wwwDww+wwwwww*\
w.............w\
w.#a.##.##.b#.w\
w.j#.##.##.##.w\
w.............w\
w.#C.PlTRB.##.w\
w.HW.S,,:G.c#.w\
+.....,,,.....+\
w.MA.#,,,y.F#.w\
w.##.LP.hf.#e.w\
w.............w\
w.s#.OO.##.t#.w\
w.##.OO.i#.##.w\
w.............w\
*wwwwww+wwwwww*\
"

// .:	Street
// ,:	Market square
// ::	Tool shop
// +:	Gate
// *:	Tower
// #:	Unidentified building...

// A:	Armour shop
// a:	Amos building
// B:	Bank
// b:	Brotherhood vs. lords
// C:	Courthouse
// c:	Cathedral of boccob
// D:	Duel office
// e:	Empty house
// F:	Finnish club
// f:	Flower shop
// G:	adventurers' Guild
// H:	guard Hq
// h:	Healer
// j:	Joe's
// L:	Lords' pub/guild
// l:	town halL
// M:	Magic shop
// O:	player hOmes
// P:	Pub
// R:	Race guild
// S:	general Shop
//	/ Simo's cloth room
// T:	Temple & graveyard
// t:	Temple of skert
// W:	Weapon shop
//	/ royal tailor
// w:	city Wall
// y:	bakerY
// s:   Smoke shop
// i:   don't come Inn

private int
base_MAP(int x, int y)
{
    if (x < SMALLEST_X || x > LARGEST_X || y < SMALLEST_Y || y > LARGEST_Y)
	return '#';
    return MAP_STRING[y * 15 + x];
}

string
query_map()
{
    return MAP_STRING;
}

private mixed *
base_count_dir(int x, int y, int dir)
{
    string str;
    switch (dir) {
    case 0: x++;      str = "east";      break;
    case 1: x++; y--; str = "northeast"; break;
    case 2: y--;      str = "north";     break;
    case 3: x--; y--; str = "northwest"; break;
    case 4: x--;      str = "west";      break;
    case 5: x--; y++; str = "southwest"; break;
    case 6: y++;      str = "south";     break;
    case 7: x++; y++; str = "southeast"; break;
    }
    return ({ x, y, str });
}

private string *
type_dir(int x, int y, int type)
{
    string *dir;
    int a;
    mixed *XY;
    dir = ({});
    for (a = 0; a < 8; a++) {
	XY = base_count_dir(x,y,a);
	if (base_MAP(XY[0],XY[1]) == type)
	    dir += ({ XY[2] });
    }
    return dir;
}

void
setup_room(int x, int y)
{
    int *itms, type, room, size;
    int i, j;
    string *dir;
    mixed *XY;
    string temp, short, long;

#ifdef UIDS
    seteuid(getuid());
#endif
    type = base_MAP(x,y);

    // First, let's add exits:

    for (i = 0; i < 8; i++) {
	XY = base_count_dir(x,y,i);
	j = base_MAP(XY[0],XY[1]);
	if (i & 1) {
	    if (type == ',') {
		if (j == type) 
		    add_exit(XY[2], CITY_DIR+"S"+XY[0]+"_"+XY[1]);
	    } else if (type == '.' && j == '*')
		add_exit(XY[2], CITY_DIR+"tower_"+XY[0]+"x"+XY[1]);
	} else switch (j) {
	case ',':
	case '.':
	case ':':
	    add_exit(XY[2], CITY_DIR+"S"+XY[0]+"_"+XY[1]);
	}
    }

    // Then, let's set descriptions, and add some miscellaneous objects if
    // needed.

    switch (x) {
    case 1:
	short = "Wall Street";
	switch (y) {
	case 1:
	    short = "Fighters' Square";
	    long =
	    "You are on the Fighters' Square. The Lords' Street runs east and the\
 Wall Street to the south. In the northwest corner stands a tall tower.";
	    add_permanent(GENERIC_FROBOZZ_STATUE);
	    break;
	case 2:
	    long = "You are on the Wall Street which goes north\
 and south. In the north you see the Fighters' Square.";
	    break;
	case 3:
	    long = "You are on the Wall Street which goes north\
 and south.";
	    break;
	case 4:
	    long = "You are on the Wall Street which goes north\
 and south. The Ladywell goes east from here.";
	    break;
	case 5:
	    long = "You are on the Wall Street which goes north\
 and south.";
	    break;
	case 6:
	    long = "You are on the Wall Street which goes north\
 and south.";
	    break;
	case 7:
	    short = "Wall Street, near the West Gate";
	    long = "You are on the Wall Street which goes north\
 and south. The Main Street goes east from here. To the west you can see\
 the West Gate of " + CITY_NAME + ".";
	    add_exit("west", CITY_DIR+"gate_west");
	    break;
	case 8:
	    long = "You are on the Wall Street which goes north and south.";
	    break;
	case 9:
	    long = "You are on the Wall Street which goes north and south.";
	    break;
	case 10:
	    long = "You are on the Wall Street which goes north\
 and south. The Secret Street goes east from here.";
	    break;
	case 11:
	    long = "You are on the Wall Street which goes\
 north and south.";
	    break;
	case 12:
	    long = "You are on the Wall Street which goes north\
 and south. You can see the Mages' Square to the south.";
	    break;
	    // S1_13 is a non-virtual room.
	    // This room has a file; not virtual one!
	}
	break;

    case 2:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west\
 and east. To the west is the Fighters' Square.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and east. Joe's restaurant is to the north.";
	    add_exit("north", JOES);
	    break;
	case 7:
	    short = "Main Street, at the Guard HQ and Magick Shop";
	    long = "You are on the Main Street which goes west\
 and east. To the north is the building of Guard Headquarters. To the south\
 is Ye Olde Magick Shoppe.";
	    add_exit("north", GUARD_HQ);
	    add_exit("south", MAGIC_SHOP);
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.\
 There's a room filled with smoke to the south.";
	    add_exit("south",SMOKE_SHOP);
	    break;
	    // S2_13 is a non-virtual room (must be due cityguard block)
	    // This room has a file; not virtual one!
#if 0
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east \
and west. You can see the Mages' Square to the west. There is also \
a garden to the north. You can see a house behind the garden.";
#ifdef AREA_GARDEN
	    add_exit("north", AREA_GARDEN "garden_port");
#endif
	    break;
#endif
	}
	break;

    case 3:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west\
 and east. There is a building to the south.";
#ifdef AREA_ZOO
	    add_item("building", "It's a building made of stone.\
 You don't see any entrance to it here, but there is a window in it facing north.");
	    call_other(AMOS2, "xyz");
#endif
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and\
 east. There is a building to the north. The " CITY_NAME " Court Hall is to the\
 south.";
	    add_exit("south", COURT_HOUSE);
#ifdef AREA_ZOO
	    add_item("building", "It's a building made of stone.\
 You don't see any entrance to it here, but there is a window in it facing\
 south.");
	    call_other(AMOS3, "xyz");
#endif
	    break;
	case 7:
	    short = "Main Street";
	    long = "You are on the Main Street which goes west\
 and east. To the north is the Armour Shop, and to the south is the Weapon Shop.";
	    add_exit("north", ARMOUR_SHOP);
	    add_exit("south", WEAPON_SHOP);
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.";
	    break;
	}
	break;

    case 4:

	short = "Dragon Street";
	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west\
 and east. The Dragon Street goes south from here. There is a Dueling Office\
 to the north.";
	    add_exit("north", GENERIC_ROOM_DUEL_OFFICE);
	    break;
	case 2:
	    long = "You are on the Dragon Street which goes north\
 and south. To the west you see a building and an entrance to it.";
#ifdef AREA_ZOO
	    add_exit("west", AMOS_BUILDING);
	    add_item("building", "There is an entrance to it.");
	    add_item("entrance", "Looks like you could enter\
 the building through it.");
#else
	    add_item("entrance", "Maybe not.");
#endif
	    break;
	case 3:
#ifdef AREA_SEWERS
	    short = "Dragon Street, at a smelly hole";
#else
	    short = "Dragon Street";
#endif
	    long = "You are on the Dragon Street which goes north\
 and south."
#ifdef AREA_SEWERS
	    " A smelly hole leads down into the darkness."
#endif
	    ;
#ifdef AREA_SEWERS
	    //add_exit("down", SEWERS1);
	    add_exit("down", AREA_SEWERS "lvl1/wide1");
	    add_command("down", "check_goers");
#endif
	    break;
	case 4:
	    short = "Crossing of Ladywell and Dragon Street";
	    long = "You are at the crossing of the Dragon Street,\
 which goes north and south, and the Ladywell which goes east and west.";
	    break;
	case 5:
	    long = "You are on the Dragon Street which goes north\
 and south. The "+CITY_NAME+" Court Hall is to the west. There is a new building\
 to the east. The large sign above the door says: Bounty Shop.";
	    add_exit("east", GENERIC_ROOM_BOUNTY_SHOP);
	    add_exit("west", COURT_HOUSE);
	    break;
	case 6:
	    long = "You are on the Dragon Street, which continues\
 to the north and south. The Royal Tailor of " CITY_NAME " is to the west, and\
 the \"Simo's Clothroom\" is to the east.";
	    add_exit("east", SIMOS_CLOTHROOM);
	    add_exit("west", ROYAL_TAILOR);
	    break;
	case 7:
	    short = "Crossing of Main Street and Dragon Street";
	    long = "You are at the crossing of the Dragon Street,\
 which goes north and south, and the Main Street which goes east and west.";
	    break;
	case 8:
	    long = "You are on the Dragon Street which goes north and south.";
	    break;
	case 9:
	    long = "You are on the Dragon Street which goes north and south.";
	    break;
	case 10:
	    short = "Crossing of Secret Street and Dragon Street";
	    long = "You are at the crossing of the Dragon Street,\
 which goes north and south, and the Secret Street which goes east and west.";
	    break;
	case 11:
	    long = "You are on the Dragon Street which goes north and south.";
	    break;
	case 12:
	    long = "You are on the Dragon Street which goes north and south.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.\
 The Dragon Street goes north from here.";
	    break;
	}
	break;

    case 5:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west and east.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and east.";
	    break;
	case 7:
	    short = "Main Street";
	    long = "You are on the Main Street, which continues east\
 and west. The Common Shop is to the north, and the Market Square is to the east.";
	    add_exit("north", GENERAL_SHOP);
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west\
 and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.";
	    break;
	}
	break;

    case 6:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west and east.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and east.\
 The Town Hall is to the south, but there are no doors on this side.";
	    break;
	case 6:
	    short = "Market Square of " + CITY_NAME;
	    long = "Northwestern corner of the market square. The\
 Town Hall is to the north, the Common Shop to the west, and the Post Office\
 to the northwest.";
	    add_exit("north", TOWN_HALL);
	    add_exit("west", GENERIC_ROOM_SHOP);
	    add_exit("northwest", GENERIC_ROOM_POST_OFFICE);
	    add_command("north", "check_goers2");
	    add_command("northwest", "check_goers2");
	    break;
	case 7:
	    short = "Market Square of " + CITY_NAME;
	    long = "You are on the Main Street in the western part\
 of the Market Square. To the south you can see a bench.";
	    break;
	case 8: break;
	    // S6_8 is a non-virtual room!
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.";
	    break;
	}
	break;

    case 7:

	switch (y) {
	case 1:
	    short = "Lords' Street, near the North Gate";
	    long =
	    "You are on the Lords' Street which goes west and east. The Zombie Alley\
 goes south from here. To the north you can see the North Gate of "+CITY_NAME+".";
	    add_exit("north", CITY_DIR+"gate_north");
	    break;
	case 2:
	    short = "Zombie Alley";
	    long = "You are on the gloomy Zombie Alley. There's\
 something evil in this place. It makes you feel uneasy and alert.";
	    add_monster(NPC_DIR + "beggar", "A beggar arrives.", 1);
	    break;
	case 3:
	    short = "Zombie Alley";
	    long = "You are on the gloomy Zombie Alley. There's\
 something evil in this place. It makes you feel uneasy and alert. Alley goes\
 north and to the south you see the Ladywell.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and\
 east. The gloomy Zombie Alley goes north from here. The " + CITY_NAME
	    + " graveyard is to the south, but a high fence blocks entry from this side.\
 There's a pool here, in the middle of which is a pedestal.";
	    add_monster(NPC_DIR + "duck", "A duck arrives.", 1);
	    add_object(({ TREASURE_FILE,
		({ "set_name", "huge metal statue" }),
		({ "set_id", ({ "statue", "metal statue" }) }),
		({ "set_short", "A huge metal statue" }),
		({ "set_long", "It describes a heavily muscled,\
 extermely ugly half-orc warrior with a two-handed... or rather a three-handed\
 sword.\nA plaque on the pedestal contains just the name \"Graah\"." }),
		({ "set_read", "The only writing on the\
 statue you can see reads \"Graah\"" }),
		({ "set_weight", 2000 })
	      }), 0, 1);
	    break;
	case 6:
	    short = "Market Square of " + CITY_NAME;
	    long = "Northern part of the market square. The "
	    + CITY_NAME+ " Temple is to the north, and the Well is to the south.";
	    add_exit("north", GENERIC_ROOM_CHURCH);

	    // Thank priests for the kludges!
	    add_command("holocaust", "disallow");
	    add_command("purify", "disallow");

	    break;
	case 7: break;
	    // S7_7 is a non-virtual room.
	case 8:
	    short = "Market Square of " + CITY_NAME;
	    long = "You are on the Newbie Road, in the southern part\
 of the "+CITY_NAME+" market square. Newbie Road continues to the south.";
	    break;
	case 9:
	    short = "Newbie Road";
	    long = "You are on the Newbie Road, which continues\
 north and south. The Market Square is to the north, a pub to the west, and the "
	    + CITY_NAME  + " Sanatorium to the east.";
	    add_exit("east", GENERIC_ROOM_HOSPITAL);
	    add_exit("west", PUB);
	    add_command("west", "check_west");
	    break;
	case 10: break;
	    // S7_10 is a non-virtual room.
	case 11:
	    short = "Newbie Road";
	    long = "You are on the Newbie Road which goes north\
 and south. There are some carvings on the west wall.";
	    add_item(({ "west wall", "carvings", "portal" }),
	      "It looks like some portal but not a very active one.");
	    add_item("wall", "Which wall?");
	    add_command("enter", "enter_portal");
	    break;
	case 12:
	    short = "Newbie Road";
	    long = "You are on the Newbie Road which goes north\
 and south.";
	    break;
	case 13:
	    short = "Godshire, near the South Gate";
	    long = "You are on the Godshire which goes west and east.\
 The Newbie Road goes north from here. To the south you can see the South Gate\
 of " + CITY_NAME + ".";
	    add_exit("south", CITY_DIR+"gate_south");
	    break;
	}
	break;

    case 8:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west and east.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and east.";
	    break;
	case 6: break;
	    // S8_6 is a non-virtual room.
	case 7:
	    short = "Market Square of " + CITY_NAME;
	    long = "You are on the Main Street, in the eastern part of\
 the "+CITY_NAME+" market square. The street continues both east and west.";
	    break;
	case 8:
	    short = "Market Square of "+ CITY_NAME;
	    long =
	    "Southeastern corner of the Market Square. The New Flower Shop is in\
 the southeast, and the Baker's shop in the east.";
	    add_exit("southeast", FLOWER_SHOP);
	    add_exit("east", BAKERY);
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.\
 The famous Don't Come Inn is to the north.";
	    //                        add_exit("north", DONT_COME_INN);
	    break;
	}
	break;

    case 9:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west and east.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and\
 east. The strong stone walls of the " + CITY_NAME + " Bank are to the south,\
 but there is no way to enter the bank itself from this side.";
	    break;
	case 7:
	    short = "Main Street";
	    long = "You are on the Main Street, which continues\
 east and west. The Market Square is to the west, and the Baker's Shop is\
 to the south.";
	    add_exit("south", BAKERY);
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.";
	    break;
	}
	break;

    case 10:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west\
 and east. The Demon Avenue goes south from here.";
	    break;
	case 2:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north\
 and south. To the east there is a mysterious, large stone building.";
	    add_exit("east", BVL_LOBBY);
	    break;
	case 3:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north\
 and south. To the west there is some new shop.";
	    add_exit("west", JEWELLERY);
	    break;
	case 4:
	    short = "Crossing of Ladywell and Demon Avenue";
	    long = "You are at the crossing of the Demon Avenue,\
 which goes north and south, and the Ladywell which goes east and west.";
	    break;
	case 5:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north\
 and south. To the west is the Bank of " + CITY_NAME + ".";
	    add_exit("west", GENERIC_ROOM_BANK);
	    break;
	case 6:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north and south.";
	    break;
	case 7:
	    short = "Crossing of Main Street and Demon Avenue";
	    long = "You are at the crossing of the Demon Avenue,\
 which goes north and south, and the Main Street which goes east and west.";
	    break;
	case 8:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north and south.";
	    break;
	case 9:
	    short = "Demon Avenue";
	    long = "You are on the Demon Avenue which goes north and south.";
	    add_monster(NPC_DIR+"beggar", "A beggar arrives.", 1);
	    break;
	case 10:
	    short = "Crossing at Secret Street";
	    long = "You are at the crossing in the Secret Street.\
 The Demon Avenue goes north and the Dagger Alley goes south while the Secret\
 Street continues to east and west.";
	    break;
	case 11:
	    short = "Dagger Alley, at a temple";
	    long ="You are on the Dagger Alley which goes north\
 and south. There's a huge black building to the east, certainly a temple\
 of some kind, but there seems to be no entrance inside. Pity.";
	    add_exit("east", GUILD_PATH_THIEF+"rooms/temple");
	    break;
	case 12:
	    short = "Dagger Alley";
	    long = "You are on the Dagger Alley which goes north\
 and south.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and\
 west. The Dagger Alley goes north from here.";
	    break;
	}
	break;

    case 11:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west and east.";
	    break;
	case 4:
#ifdef AREA_SEWERS
	    short = "Ladywell, at a hole";
#else
	    short = "Ladywell";
#endif
	    long = "You are on the Ladywell which goes west and\
 east."
#ifdef AREA_SEWERS
	    " There is a hole on the ground, leading down into the city sewers."
#endif
	    ;
#ifdef AREA_SEWERS
	    //add_exit("down", SEWERS3);
	    add_exit("down", AREA_SEWERS "lvl1/narrow4");
	    add_command("down", "check_goers");
#endif
	    break;
	case 7:
	    short = "Main Street, at the Cathedral of Boccob";
	    long = "You are on the Main Street which goes west \
and east. The great Cathedral of Boccob, a proud monument of " CITY_NAME ", \
lies to the north. To the south, in stark contrast, \
lies the rambunctios Finnish club, famous for its sauna and kossu.";
	    add_exit("north", BOCCOB_CATHEDRAL_ENTRANCE);
	    add_exit("south", FINNISH_CLUB);
	    add_item(({ "white and blue flag", "flag" }),
	      "It's the famous flag of Finland, a blue cross on white bottom.");
	    add_item("building", "It's the legendary Finnish Guild of " MUD_NAME ".");
	    add_item("flagpole", "In the flagpole you can see the famous flag of Finland,\
 a blue cross on white bottom.");
	    add_item("cathedral", "To the north you can see a huge cathedral of Boccob.");
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.";
	    break;
	}
	break;

    case 12:

	switch (y) {
	case 1:
	    short = "Lords' Street";
	    long = "You are on the Lords' Street which goes west\
 and east. To the east is the Priests' Square.";
	    break;
	case 4:
	    short = "Ladywell";
	    long = "You are on the Ladywell which goes west and east.";
	    add_exit("north", CASINO);
	    break;
	case 7:
	    short = "Main Street";
	    long = "You are on the Main Street which goes west and east.";
	    break;
	case 10:
	    short = "Secret Street";
	    long = "You are on the Secret Street which goes west and east.";
	    break;
	case 13:
	    short = "Godshire";
	    long = "You are on the Godshire which goes east and west.\
 To the east is the Thieves' Square.";
	    break;
	}
	break;

    case 13:

	switch (y) {
	case 1:
	    short = "Priests' Square";
	    long = "You are on the Priests' Square. The Lords'\
 Street runs west and the Promenade to the south. In the northeast corner\
 stands a tall tower.";
	    break;
	case 2:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and\
 south. To the north is the Priests' Square.";
	    break;
	case 3:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north\
 and south.";
	    break;
	case 4:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and\
 south. The Ladywell goes west from here.";
	    break;
	case 5:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and south.";
	    break;
	case 6:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and south.";
	    break;
	case 7:
	    short = "Promenade, near the East Gate";
	    long = "You are on the Promenade which goes north and\
 south. The Main Street goes west from here. To the east you can see the East\
 Gate of "+ CITY_NAME + ".";
	    add_exit("east", CITY_DIR+"gate_east");
	    break;
	case 8:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and south.";
	    break;
	case 9:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and\
 south. To the west there is a building, and through the doorway, you can\
 hear people talking with some strange language. Odd.";
	    add_exit("west", SWEDISH_CLUB);
	    break;
	case 10:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and\
 south. The Secret Street goes west from here.";
	    break;
	case 11:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and south.";
	    break;
	case 12:
	    short = "Promenade";
	    long = "You are on the Promenade which goes north and\
 south. To the south is the Thieves' Square.";
	    break;
	case 13:
	    short = "Thieves' Square";
	    long = "You are on the Thieves' Square. The Promenade\
 runs north and the Godshire to the west. In the southeast corner stands a\
 tall tower. In the middle of the square rests an old, dusty guillotine.";
	    add_item("guillotine", "An old wooden guillotine, served\
 once in need, now forgotten, rotten and rusty. Someone has even stolen the\
 razor-sharp blade which horrified even the most hardened thieves in the past.\
 Yet the basket where the heads used to drop in is still nailed on the device.");
	    add_item("basket", "Dried blood on it's edges tell it\
 hasn't always been without use...");
	    add_monster(NPC_DIR+"beggar", "A beggar arrives.", 1);
	    break;
	}
	break;
    }

    set_short(short);
    set_long(long);

    // Wandering monsters
    if (random(100) < 10)
    {
	switch(random(6))
	{
	case 0:
	    add_monster(NPC_DIR + "fido", "Beastly Fido arrives.", 1);
	    break;
	case 1:
	    add_monster(NPC_DIR + "cat", "You suddenly notice a cat here.",
	      1);
	case 2:
	    add_monster(NPC_DIR + "dog", "Dog arrives.", 1);
	    break;
	case 3:
	    add_monster(NPC_DIR + "mouse", "A little mouse arrives.", 1);
	    break;
	case 4:
	    add_monster(NPC_DIR + "pigeon", "A pigeon lands here.", 1);
	    break;
	default:
	    add_monster(NPC_DIR + "leper",
	      "A hooded, cloaked figure arrives and cries: UNCLEAN!", 1);
	    break;
	}
    }
}

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_OUTDOORS);
    set(IN_CITY);
    set(NO_PK);
}

#ifdef AREA_SEWERS
// To prevent NPCs to go to sewers...
status
check_goers()
{
    return interactive(this_player()) ? 0 : 1;
}
#endif

// To prevent NPCs to enter shops etc.; except mayor and controlled NPCs.
status
check_goers2()
{
    if (interactive(this_player())) return 0;
    if (this_player()->query_ctrl()) return 0;
    if ((string) this_player()->query_real_name() == "mayor") return 0;
    return 1;
}

// To check that pub is open...
status
check_west()
{
    int hour;
    if ((hour = (int) nature() -> query_24_hour()) >= 4 && hour < 8) {
	this_player()->tell_me(
	  "The pub is closed. A sign on the door says: CLOSED 4.00 AM - 8.00 AM.");
	return 1;
    }
    return 0;
}

// This used to be a portal for mages...
int
enter_portal(string str)
{
    if (str != "portal") return notify_fail("Enter what?\n"), 0;

    this_player()->tell_me(
      "You try to read the words inscribed on the side of the portal, but they have\
 disappeared a long time ago...");
    return 1;
}

status
disallow(string arg)
{
    this_player()->tell_me("Tim the Enchanter glares at you.");
    return 1;
}
