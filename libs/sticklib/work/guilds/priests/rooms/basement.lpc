#include "priest_room.h"
#include <areas.h>
#include <conditions.h>
#include <city_name.h>
#include <generic_rooms.h>

#define TP this_player()

#define GAZE_COST 20

mapping blocked, places;

string places_details()
{
    return "The places represented on the map in the most detail are the "+
    implode(m_indices(places), ", the ", ", and the ")+".";
}

void create_room() {
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set_short("The basement of the Cathedral");
    set_long(
      "You are in the basement of the Cathedral. This room is paneled all in \
exquisite cherry wood. There is a cheery fire burning a in black granite \
fireplace in the room. A small scale map hangs on the wall. Many chairs \
and tables are about, along with some soft chairs. Many of the officers \
of the guild have their offices here.");        

    set_items(([
	"map" : "This map reflects many places in and around "+CITY_NAME+". It is \
amazingly, almost magically realistic. You reach out to touch it, but your \
hand touches nothing, just goes cold and numb.",
	"places" : #'places_details,
	"fireplace" : "It is constructed from black granite and it is placed in \
the center of the other shorter wall. There is a fire burning in it, warming \
the fireplace and the whole room.",
	"fire" : "The fire burns in the fireplace, crackling and dancing. It \
creates a warm yellow light to this room. You could just 'gaze' to the flames \
forgetting the world around you.",
	"chairs" : "The chairs are placed around the tables so that some small \
scale meetings can be arranged here among the Members of the Holy Order. \
They are constructed from birch and they fit nicely to this room with the \
light coming from the fireplace.",
      ]));

    add_monster(PRIEST_MON_DIR "outer_guard",
      "Templar arrives from his break.",1);

    set_exits(([
	"north" : PRIEST_ROOM_DIR "treasury",
	"south" : PRIEST_ROOM_DIR "em_office",
	"east"          : PRIEST_ROOM_DIR "pre_templar",
	"west"          : PRIEST_ROOM_DIR "pre_hospit",
	"northwest" : PRIEST_ROOM_DIR "inquisitor",
	"up"            : PRIEST_ROOM_DIR "nave",
	"down" : 0, // down is handled elsewhere
      ]));

    set_commands(([
	"enter" : "enter_map",
	"gaze"          : "gaze_cmd",
	"down"          : "down_cmd",
	"north" : "block_pl",
	"northwest" : "block_pl",
	"south" : "block_pl",
	"east"          : "block_pl",
	"west"          : "block_pl"
      ]));

    blocked = ([
      "south"           : 3; "Elector Medico",
      "north"           : 4; "Elector Secularus",
      "east"                    : 5; "Preceptor Templar",
      "west"                    : 6; "Preceptor Hospitilar",
      "northwest"       : 2; "Inquisitor",
    ]);

    places = ([
#ifdef AREA_TRISTEZA
      "well"            : AREA_TRISTEZA "rooms/well",
#endif
#ifdef AREA_WEST
      "clearing"        : AREA_WEST "forest/clearing",
      "mines"           : AREA_WEST "mountain/mount_pass",
#endif
#ifdef AREA_FROBOZZ_INN
      "inn"                     : AREA_FROBOZZ_INN "inn/lobby",
#endif
#ifdef AREA_ISLANDS
      "herb hut"          : AREA_ISLANDS "r/m1/woods_s5",
#endif
#ifdef GENERIC_ROOM_CHURCH
      "church"          : "/room/church",
#endif
    ]);

    add_permanent(PRIEST_OBJ_DIR "officer_list");
}


status
enter_map(string str) {
    string what, where;

    if(!str)
	return notify_fail("Enter what?\n"),0;

    if(!IS_PRIEST(this_player())) {
	notify_fail("You feel " GOD_NAME "'s displeasure at your affront.");
	return 0;
    }
    if(sscanf(str, "%s to %s", what, where) != 2)
	return notify_fail("Enter what to where?\n"),0;

    if(what != "map")
	return notify_fail("You cannot enter that!\n"),0;

    if(!member(places,where))
	return notify_fail("That is not painted on the map yet!"),0;

    this_player()->move_player("into the map", places[where]);
    return 1;
}


status
block_pl(string s){
    object ob, sym;
    string dir;
    status is_guest;
    int rank;

    if(TP->is_npc()) return 1;
    if(s) { TP->tell_me("North WHAT?"); return 1; }
    if(!present("templar", this_object())) { return 0; }

    dir = query_verb();

    if(!IS_PRIEST(TP) && !GUEST_D->query_guest(TP->query_real_name())) {
	TP->tell_me("Templar spits on you, saying: Filthy heathen!");
	return 1;
    }

    sym = TP->query_guild_object();
    rank = sym->query_rank();
    is_guest = query_exits()[dir]->is_allowed(TP->query_real_name());
    if(rank != blocked[dir,0] && rank < VG_RANK && TP->query_coder_level()<10 &&

      !is_guest) {
	TP->tell_me(sprintf("Templar says: Only the %s may enter. \
Please speak to him for admittance.", blocked[dir,1]));
	return 1;
    }
    return 0;
}


status down_cmd() {
    int i;
    string name;

    if(TP->is_npc()) return 1;
    name = TP->query_real_name();
    if((OFFICER_D->my_rank(name) < VG_RANK)  &&
      !TP->query_coder_level() ) {
	TP->tell_me("The Fear of Boccob's wrath fills you, and "
	  "you suddenly have no desire to see what waits below.");
	return 1; 
    }
    TP->move_player("down", PRIEST_ROOM_DIR "diet");
    return 1;
}


void do_gaze(object me, object room) {
    if(!me) return;
    if(!room) {
	me->tell_me("Somehow you can't see nothing but the flames.");
	return;
    }
    me->tell_me("\n\n" + (string) room->query(ROOM_LONG_DESC));
}

status gaze_cmd(string who) {
    object tar_room, target, sym;

    if(!TP->query_coder_level() && (TP->query_guild() != GN_PRIEST
	|| !(sym = TP->query_guild_object())
	|| sym->query_rank() < IG_RANK))
    {
	notify_fail("You gaze to the flames...\nYour thoughts flow away \
and you begin to feel yourself very tired. You lose the sense of time, \
and perhaps you even sleep for awhile.");
	this_player()->add_condition(C_STUNNED, 10+random(10));
	return 0;
    }

    if(!who) return notify_fail("Gaze what?\n"),0;
    if(who == "flames") {
	TP->tell_me("As you gaze to the flames, you see \
people that could very well be from this world, but something makes \
you not so sure. You get the feeling that if you tried to gaze \
someone of them a bit harder, you could even see where she is.");
	return 1;
    }

    if(!(target=find_player(lower_case(who)))
      || !interactive(target)
      || target->query_ghost()
      || !(tar_room=environment(target))
      || tar_room->query(ROOM_PREVENT_WHERE)
      || target->query_prevent_where())
    {
	notify_fail("You see just the flames dancing.\n");
	return 0;
    }

    if(target->query_coder_level() || (TP->query_sp() < GAZE_COST))
	return notify_fail("For some reason you only get a headache.\n"),0;

    TP->add_sp(-GAZE_COST);
    if(TP->query_sp() < random(300))
	return notify_fail("You can't quite focus your eyes.\n"),0;

    TP->tell_me("You gaze to the flames.\n\n\
The image begins to sharpen...\n\n");

    call_out(#'do_gaze, 2, TP, tar_room);
    return 1;
}

