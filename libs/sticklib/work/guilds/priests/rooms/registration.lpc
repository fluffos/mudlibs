#include "priest_room.h"
#include <guild.h>
#include <daemons.h>

#define __NO_FORM__

#define SHORT_DEITY_INFO PRIEST_HELP_DIR "short_deity_info"

mapping players_joining;


void create_room()
{
    set(ROOM_GUILD);
    set(IN_CITY);
    set(NO_PK);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("The registration room");
    set_long(
      "This is the registration-room of the cathedral. This room is very, \
very empty, in fact, there's nothing in this room except the walls. \
The communication between you and your god needs no material stuff \
to work.");
    players_joining = ([]);
    add_exit("west",PRIEST_ROOM_DIR "hall");
    add_command("join", "join_cmd");
    add_command("resign", "resign_cmd");
}


void
choose_order(int order) {
    object who;

    who = this_player();
    who->tell_me(
      "You are momentarily blinded by the utter radiance...\n\
When you can see again, you gasp for breath in awe. Before you stands \
Zagyg, the second hand of " GOD_NAME ".\n\
Zagyg says: So, you have chosen to join the priesthood, the One and \
Only guild, that can save your afterlife. Therefore, I grant you this \
symbol, use it wisely. And remember you choose your own path, hopefully \
it isn't a path of darkness. \n\
After saying that, Zagyg disappears, and you wonder if he ever was here. \
But a quick look to your neck reveals the truth; you are now carrying \
the sacred holy symbol of " GOD_NAME "!\n\n\
Use command: 'advice' to get help about spells.");

    who->set_guild(GN_PRIEST);
    who->set_guild_object(0);
    who->set_guild_hook( ([]) );
    who->set_guild_save(0);
    who->set_guild_object_name(PRIEST_SYMBOL);
    who->initialize_guild();
    if(who->query_level() >= 20 && !who->query_coder_level())
	EXCOM_D->ban_me(who->query_real_name(),0);
    SKILL_SAVER->restore_my_skills(who, who->query_guild_object(), 1);
    who->query_guild_object()->set_order(order);
    command("save",who);
    if(!who->query_coder_level() && !who->query_testplayer())
    {
	write_file(JOINLOG, sprintf("%s %s joined, \
approved by %s.\n",
	    ctime(time()), capitalize(who->query_real_name()),
	    capitalize(players_joining[who->query_real_name()])));
	who->set_title("the new member of the priesthood");
	SERVER->inform(sprintf("%s has joined the priesthood!",
	    capitalize(who->query_real_name())));
    }
    CHANNEL_D->check_channels(who);
}

void
choose_loop(string s) {
    object who;

    who = this_player();
    s = capitalize(lower_case(s));
    switch(s) {
    case FORCE_DEMIGOD_NAME:
	choose_order(-1);
	return;
    case NATURE_DEMIGOD_NAME:
	choose_order(1);
	return;
    case "Exit":
	who->tell_me("You decide not to join the priest guild yet.");
	return;
    case "Deities":
	cat(SHORT_DEITY_INFO);
	break;
    default:
	who->tell_me("The possible choices are '" FORCE_DEMIGOD_NAME "' \
and '"NATURE_DEMIGOD_NAME"'. Just type one or the other of those names \
to choose. If you are uncertain, type 'deities', and if you decide \
not to join, type 'exit'.");
    }
    write("Enter name of deity: ");
    input_to("choose_loop");
}


status join_cmd(string s)
{
    object who;
    string gobj_name;
    mixed data;
    object ob;

    if(s) return
	notify_fail("Just type 'join' to join the priest guild.\n"),0;

    who = this_player();
    /* 'Guest' no longer allowed to join.. //Haw */
    if(who == find_player("guest"))
	return notify_fail("Get in with a real char first.\n"),0;

    /*Check for excommunicants too! -Kel */
    if(EXCOM_D->excomed(who->query_real_name())) {
	return notify_fail("Heathen, the Church has decreed thee \
excommunicant and outcast! Be gone from this Holy Place!"),0;
    }
    gobj_name = who->query_guild_object_name();
    if(gobj_name && gobj_name != PRIEST_SYMBOL)
	return notify_fail("You are already a member of a false guild. \
Shame on you!!\n"),0;
    if(gobj_name) {
	return notify_fail("Your god whispers to you in a soft voice: \
You are a member already...\n"),0;
    }
    if((who->query_coder_level()>0) || (who->query_testplayer())) {
	choose_order(0);
	return 1;
    }
#ifndef __NO_FORM__
    if(!ob = present("_priest_application_form", who)) {
	ob = clone_object(PRIEST_OBJ_DIR "form");
	ob->set_applicant(who);
	move_object(ob, who);
	who->tell_me("An application form appears from thin air in your hand. \
You hear a voice saying: You have to ask a priest officer to sign that form \
before you can join.");
	return 1;
    }
    if(!ob->query_signed()) {
	who->tell_me("You have to ask one of the priest guild's officers \
to sign your application form before you can join.");
	return 1;
    }
    players_joining[who->query_real_name()] = ob->query_signer();
    destruct(ob);
#else  // __NO_FORM__
    players_joining[who->query_real_name()] = "Boccob";
#endif // __NO_FORM__
    who->tell_me("Now you have to choose your deity. The possible choices \
are '" FORCE_DEMIGOD_NAME "' and '"NATURE_DEMIGOD_NAME"'. To get more \
information, type 'deities'. After you have decided, which one of them \
you want to follow, just type the name of that deity.");
    write("Enter name of deity: ");
    input_to("choose_loop");
    return 1;
}

status
resign_cmd(string s)
{
    object who, ob, pret;
    string name;
    int fee;

    who = this_player();
    if(who->query_guild_object_name() != PRIEST_SYMBOL)
	return notify_fail("But you are not a member of the priest guild.\n"),0;


    who->tell_me("You tell your God that you no longer feel need to \
walk his path. Your God understands your mortal wish and blesses you by \
taking your holy symbol away. You feel less experienced.");

    SERVER->resign(who);
    return 1;
}
