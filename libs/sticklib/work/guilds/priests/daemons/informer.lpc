/*
 * GUILD INFORMER
 *
 * Was guild's channel daemon, but because of this new system I removed most funktions
 * and left the informer and resign functions.
 */

#include <room_defs.h>
#include <tell_me.h>
#include "../priest.h"
#include <daemons.h>


#define TP this_player()
#define ENV environment

varargs void inform(string msg, status no_log);

status is_active(object who);
status on_channel(object who);

void
create() {
}


varargs void
inform(string msg, status no_log) {
    CHANNEL_D->send_channel_message("Guild Informer", "priest", msg);
}



status
resign(mixed who, status convert) {
    string name;
    int fee;
    object ob, pret;

    if(stringp(who)) {
	who = find_player(who);
	if(!who) return 0;
    }
    name = who->query_real_name();
    ob = who->query_guild_object();
    if(pret = ob->query_pretitle_object())
	destruct(pret);
    SKILL_SAVER->save_my_skills(who, ob, 1);
    destruct(ob);

    CHANNEL_D->remove_from_channel("priest", who);

    BOOKKEEPER->remove_me(name);
    OFFICER_D->add_officer(name,0);
    DELAY_D->remove_delays(who);
    SHIELD_D->remove_pl(who);
    if(!who->query_coder_level() && !convert) { //We're not converting skills
	who->set_title("the former member of the fraternity of " GOD_NAME);
	inform(sprintf("%s has forsaken the Holy Church. \
Requist en pas.", capitalize(who->query_real_name())));
	fee = (who->query_ep() / 10);
	if(fee > 300000) fee=300000;
	who->add_exp(-fee);
    }
    if(ob = present("s_scalpel",who))
	destruct(ob);
    if(ob = present(STAFF_ID, who))
	destruct(ob);
    who->set_guild(0);
    who->set_guild_object_name(0);
    who->set_guild_object(0);
    who->set_guild_commands(0);
    who->set_guild_hook( ([]) );
    if(!who->query_coder_level() && !who->query_testplayer())
	write_file(JOINLOG, sprintf("%s %s resigned.\n",
	    ctime(time()), capitalize(who->query_real_name())));

    return 1;
}
