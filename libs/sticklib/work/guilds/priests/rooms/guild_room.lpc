#include "priest_room.h"
#include "../skills.h"
#include <curse.h>
#include <gender.h>
#include "/areas/tristeza/DEFS.h"


inherit PSKILLS;

void
create_room()
{
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set_short("The Inner Sanctum of the cathedral");

    set_long(
      "This is the inner sanctum of the cathedral: The holiest of places ever \
known to mankind. Walls are decorated with many paintings, mostly presenting \
" GOD_NAME" and His two sons in their various forms. You can see chambers \
to the north where there seems to be some kind of a room in the middle of \
them. You feel the presence of " GOD_NAME " here.");

    set_exits(([
	"north": PRIEST_ROOM_DIR "nave",
	"south": PRIEST_ROOM_DIR "hallway",
      ]));

    add_command("north", "north_cmd");
    add_command("south", "south_cmd");

    set_items(([
	({"painting", "paintings"}): "Most of the paintings are \
portraits of " GOD_NAME "'s various forms. There's pictures of His \
two sons, " FORCE_DEMIGOD_NAME " and " NATURE_DEMIGOD_NAME " too. \
Between some paintings there is a lever on the wall.",
	"lever": "It's a lever, usually you pull these.",
      ]));
    set_commands(([
	"beseech" : "beseech_cmd",
	"south" : "south_cmd",
	"pull" : "pull_lever",
      ]));
    add_permanent(PRIEST_OBJ_DIR "priest_bench");
    add_permanent(PRIEST_OBJ_DIR "charity_box");

    add_monster(PRIEST_MON_DIR "drak",
      "Drak salutes you as he walks in.",1);
}

status is_priest_sanctum() { return 1; }

status
south_cmd(){
    if(IS_PRIEST(this_player()) && this_player()->query_npc()) return 1;
    return 0;
}


#define HALL PRIEST_ROOM_DIR "hall"

status
pull_lever(string str) {
    object who;

    who = this_player();
    if(!str || str != "lever")
	return notify_fail("Pull what?\n"),0;
    if(!IS_PRIEST(who)) return 
	notify_fail("However hard you try to pull the lever, \
nothing happens.\n"),0;

    return 1;
}


int
calculate_average_rank(object sym) {
    int i, *pexes, t;

    if(stringp(sym) && find_player(sym))
	sym = find_player(sym)->query_guild_object();
    pexes = sym->query_pexes();
    for(t = 0,i=sizeof(pexes);--i>=0;)
	t += to_int(pex2skill(pexes[i]));
    t /= sizeof(pexes);
    t = get_skill_rank(skill2pex(t));
    return t;
}

void
choose_god(object who, string god) {
    object sym;
    string cap_god;

    cap_god = capitalize(god);
    sym = who->query_guild_object();
    if(sym->query_faith() < 9) {
	who->tell_me(sprintf("You hear a voice of %s telling you: \
Thy faith is weak. Thou should pray and strengthen thy faith.", cap_god));
	return; // Did I write that correctly?
    }
    if(!ORDER_CHANGE_D->can_change_order(who)) {
	who->tell_me(sprintf("You hear a voice of %s telling you: \
It has not been long enough since you changed your deity last time. \
Go and serve your God.", cap_god));
	return;
    }
    switch(cap_god) {
    case NATURE_DEMIGOD_NAME:
	sym->set_order(1);
	break;

    case FORCE_DEMIGOD_NAME:
	sym->set_order(-1);
	break;

    default:
	if(calculate_average_rank(sym) < 12) {
	    who->tell_me("You hear the voice of " GOD_NAME " saying: \
I do not care for thee yet. Thou should learn more, before I will take \
thee as my disciplin.");
	    return;
	}
	sym->set_order(0);
    }
    ORDER_CHANGE_D->order_changed(who);
    who->tell_me(sprintf("You hear the voice of %s saying to you: Thou are \
now serving me. Hopefully I shall be proud of thee.", cap_god));
}

void remove_curse(object who) {
    object ob;

    ob = first_inventory(who);
    while(ob) {
	if(ob->is_cursed())
	    ob->set_curse(CT_NONE, 0);
	ob = next_inventory(ob);
    }
    tell_here(":%<me.capname>% kneels and prays for Boccob.",0,0,who,who,0,0);
    who->tell_me("You feel somehow refreshed.");
}


void
beseech_staff(object who) {
    string cap_name;
    cap_name = capitalize(who->query_real_name());
    who->tell_me(
      "You kneel on the floor and humbly beseech " GOD_NAME " for the staff.");
    tell_here(":%<me.capname>% humbly kneels down and beseeches " GOD_NAME
      " for something.",0,0,who,who,0,0);
    switch ((int) STAFF_D->beseech(who)) {
    case 0:
	tell_here(sprintf("You hear a thunderous voice saying: You are \
not worthy of getting the staff yet, %s.",cap_name));
	break;
    case 5:
	tell_here(sprintf("You hear a thunderous voice saying: You \
don't need another staff, you already have one, %s.",cap_name));
	break;
    case 2:
	tell_here(sprintf("You hear a thunderous voice saying: Very well, \
%s, my faithful follower! Go to the carpenter, and he will carve you \
the staff!",cap_name));
	STAFF_D->set_staff(who, 0);
	break;
    case 3:
	tell_here(sprintf("You hear a thunderous voice saying angrily: \
I'm disappointed in you, %s! You have broken the precious artifact \
I granted you! You hear a thunderous voice saying: Well, I hope you \
learnt from your mistake... You can go now and order a new staff from \
the carpenter.",cap_name));
	STAFF_D->set_staff(who, 1);
	break;
    case 4:
	tell_here(
	  "You hear a thunderous voice saying: Here you are, my child!");
	move_object((object) STAFF_D->get_staff(who), who);
	who->tell_me("The staff falls from the skies to your hands!");
	break;
    default:
	tell_here(sprintf("You hear a thunderous voice saying: Go and \
ask the carpenter about the staff, %s.",cap_name));
    }
}

status
beseech_cmd(string s)
{
    string what, cap_name, god;
    object who;

    who = this_player();
    cap_name = capitalize(who->query_real_name());
    if(!s || !IS_PRIEST(who)) return 0;
    s = lower_case(s);
    if(sscanf(s, "%s from %s", what, god) != 2 &&
      sscanf(s, "%s for %s", god, what) != 2) return 0;
    if(member(ORDERS, capitalize(god)) == -1) return
	notify_fail("You can only beseech for " GOD_NAME ", " 
	  FORCE_DEMIGOD_NAME " or " NATURE_DEMIGOD_NAME ".\n"),0;

    switch(what) {
    case "guidance": // invite somethings better
	choose_god(who, god);
	break;

    case "blessing":
	remove_curse(who);
	break;

    case "staff" : case "the staff":
	beseech_staff(who);
	break;

    default:
	return notify_fail(sprintf("Beseech %s for what?\n", capitalize(god))),0;

    }
    return 1;
}

int 
north_cmd() 
{
    object me;
    string my_guild;
    me = this_player();
    //}

    if(present("drak", this_object())
      && (!this_player()->query_coder_level()))
    {
	my_guild = (string) me->query_guild();

	if((!my_guild) || (my_guild == GN_PRIEST))
	    return 0;
	if(GUEST_D->query_guest(me->query_real_name()))
	    return 0;

	me->tell_me("Drak tells you: Heathens like you are not \
allowed to go any further.");
	tell_here(":Drak says something to %<me.capname>%.",
	  0,0,me,me,0,0);
	return 1;
    }
    return 0;
}

