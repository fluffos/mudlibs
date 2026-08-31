#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;
int cmd_start(string str);
mapping leader, council;
string *leaders, *councils;
int i;
void create() {
    object oi;
    ::create();
    restore_object("/d/guilds/save/darksoul");
    set_no_clean(1);
    set_name("Darksouls Hall");
    set_items((["corpses"   : "%^RESET%^%^ORANGE%^A pile of roting corpses%^WHITE%^",
	"blood"  : "%^RESET%^%^RED%^Pools of blood all over%^RESET%^"]));
   set_properties((["light" :2, "indoors":1, "no attack"   : 1,
        "no magic"    : 1, "no teleport":1, "no steal"    : 1]));
    set_short("Dark Souls");
    set_long("%^BOLD%^%^BLACK%^This is the meeting spot of the D%^WHITE%^a%^BLACK%^r%^WHITE%^k%^BLACK%^ S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s. This is where "
      "%^BOLD%^%^BLACK%^they come to go over the kills of the day, or problems that "
      "%^BOLD%^%^BLACK%^have arisen in the guild. Tons of corpses are strewn "
      "%^BOLD%^%^BLACK%^haphazardly on the floor. Pools of %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^ are all over the "
      "%^BOLD%^%^BLACK%^ground. The message for all people who are not part of this "
      "%^BOLD%^%^BLACK%^group that happen to set foot in here is %^WHITE%^You Do Not "
      "%^BOLD%^%^BLACK%^%^WHITE%^Have To Fear Us Unless %^WHITE%^You Are Alive.");
    set_exits( ([ "north" : ROOMS"darksoul/mainportal",
	//              "south" : ROOMS"darksoul/room3",               
	//              "east" : ROOMS"darksoul/room5",
	"hall" : ROOMS"meeting",
	"south" : ROOMS"darksoul/treasury",
	"up" : ROOMS"darksoul/entrance",
	"down" : ROOMS"darksoul/dungeon",
      ]));
    oi = new("/std/bboard");
    oi->set_name("Dark Souls Board");
    oi->set_id( ({ "board", "dark board", "souls board" }) );
    oi->set_board_id("Dark_Souls_Board");
    oi->set_max_posts(100);
    oi->set_edit_ok(GUILD_D->post_able("darksoul"));
    oi->set_location(ROOMS"darksoul/hall");
    oi->set("short", "%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^%^k%^BLACK%^ S%^WHITE%^o%^WHITE%^u%^BLACK%^l%^WHITE%^s%^BLACK%^ B%^WHITE%^o%^BLACK%^a%^WHITE%^r%^BLACK%^d%^RESET%^");
    oi->set("long", "This board is for the members of Dark souls");
}
void reset() {
    ::reset();
    if(!present("pit"))
	new("/d/nopk/tirun/obj/misc/pit")->move(this_object());
}
void init() {
    ::init();
    add_action("cmd_drop", "drop");
    add_action("cmd_start", "start");
}
int reclaim() {
    if(!present("guild ring", this_player())) {
	write("A ring appears in your hand.\n");
	say("A ring appears in "
	  +this_player()->query_cap_name()+"'s hand.");
	new("/d/guilds/darksoul/ring")->move(this_player());
	return 1;
    }
    write("You already have your ring.\n");
    return 1;
}
int cmd_drop(string str)
{
    this_player()->force_me("put "+str+" in pit");
    return 1;
}

int cmd_start(string str)
{
    if (!str || str=="")
    {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")
    {
	notify_fail("You cannot start there.\n");
	return 0;
    }


    this_player()->set_primary_start("/d/guilds/darksoul/hall");
    write("You are now set to start here.");
    return 1;
}
