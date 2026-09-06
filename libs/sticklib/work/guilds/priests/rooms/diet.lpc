#include "priest_room.h"
#include <guild.h>
#include <mud_name.h>
#include <bboard_defs.h>
#include <generic_items.h>

#define GAZE_COST 15

string short;

int valid_board_access(object me);

void blur_sight() {
    string *tmp;
    tmp = ({ "Boccob prevents you from seeing that.", "A shimmering mist", 
      "A blinding light", "An endless plain", "A deserted city street", 
      "A ruined castle", "A dark forest", "A foolish hope", 
      "Beyond mortal sight", "On a dark river" });
    short = tmp[random(sizeof(tmp))];
    call_out("blur_sight", 30);
}

string query_short() {
    return short;
}

void create_room()
{
    set_light(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    short = "";
    set_long(
      "This chamber is done throughout in black walnut, and black marble. \
A slab of six inch thick leaded crystal floats in the centre of the \
room, with no visible means of support. Light is provided by glowing \
orbs cleverly inset into the marble walls.");   
    add_exit("up", PRIEST_ROOM_DIR "basement");
    /* Bulletin board */
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, ([
	    BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access,
	  ]), "priest_guild_diet", 0 }),
      }), 0, 1);

    add_item("slab", "As you look at the slab for a moment, you get a blurred \
vision of several places in the world of "+MUD_NAME+". Maybe, if you concentrated \
more and gazed through it, you would have a clearer vision.");
    add_command("gaze", "gaze");
    blur_sight();
}

gaze(string who){
    object tar_room, target;

    if(!who){
	notify_fail("You must <gaze someone>.\n");
	return 0;
    }

    if(this_player()->query_guild() != GN_PRIEST){
	notify_fail("A spike of blue light momentarily blinds you. \n");
	this_player()->hit_player(25);
	return 0;
    }

    if(!(target=find_player(lower_case(who)))){
	notify_fail("No such player is active.\n");
	return 0;
    }

    if(target->query_coder_level() || (this_player()->query_sp() < GAZE_COST))
    {
	notify_fail("For some reason you only get a headache.\n");
	return 0;
    }

    tar_room=environment(target);

    this_player()->add_sp(-GAZE_COST);
    if(this_player()->query_sp() < random(300))
	return notify_fail("You can't quite focus your eyes.\n"),0;

    this_player()->tell_me("You gaze through the slab thinking of "
      +capitalize((target->query_real_name()))+".");
    this_player()->tell_me("The image begins to sharpen...");
    this_player()->tell_me("\n\n\n\n");

    this_player()->tell_me((string) tar_room->query(ROOM_LONG_DESC));
    return 1;
}

int valid_board_access(object me)
{
    if(IS_PRIEST(me) || GUEST_D->query_guest(me) || me->query_coder_level())
	return 1;
    return 0;
}
