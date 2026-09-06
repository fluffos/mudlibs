/* Gm/voting Daemon for thieves guild 01/16/96 --Colt */
#include "thief.h"
#include "dirs.h"

#define GUILD_SAVE "/guilds/thieves/GM_SAVE"
#define GM_MAX_GONE 1209600

#define BIN_CHANNEL_D "/bin/daemons/channel_d"

string gm, *co_gm, *enforcers, *demons;
int gm_last_on;
mapping votes;

status resign_gm(status which);

status start_vote(string who)
{
    object voter;

#ifndef OLD_GOVERNMENT
    return 0;
#endif
    BIN_CHANNEL_D->send_channel_message("SKERT","thief",capitalize(who) + " has slain your \
GM and is ready to take over the position with your support.");
    BIN_CHANNEL_D->send_channel_message("SKERT","thief", "Voting has begun in the guild hall.  \
(thelp voter)");

    voter = clone_object(GDIR+"voter");
    move_object(voter,GDIR+"rooms/guild");
    voter->set_type(who);
    return 1;
}

string *query_co_gm()
{
#ifndef OLD_GOVERNMENT
    return ({});
#endif
    if (!co_gm)
	restore_object(GUILD_SAVE);
    if(!co_gm)
	co_gm = ({ });
    return co_gm;
}

string *query_enforcers()
{
    if (!enforcers)
	restore_object(GUILD_SAVE);
    if(!enforcers)
	enforcers = ({ });
    return enforcers;
}

string query_gm()
{
#ifndef OLD_GOVERNMENT
    return 0;
#endif
    if (!gm)
	restore_object(GUILD_SAVE);
    if (!gm) 
	start_vote(gm);
    if ((time() - gm_last_on) >= GM_MAX_GONE)
	resign_gm(0);
    return gm;
}
status set_gm_last_on()
{
#ifndef OLD_GOVERNMENT
    return 0;
#endif
    if (!gm_last_on)
	restore_object(GUILD_SAVE);
    gm_last_on = time();
    save_object(GUILD_SAVE);
    return 1;
}

status set_gm(string who)
{
    object old_gm,person,tm;
#ifndef OLD_GOVERNMENT
    return 0;
#endif

    restore_object(GUILD_SAVE);
    if (old_gm = find_player(gm))
    {
	old_gm->tell_me("You have lost your guildmaster status to " + 
	  capitalize(who) + ".");
	tm = (object) old_gm->query_guild_object();
	tm->set_guildmaster(0);
	CHANNEL_D->add_channel_member(tm,1,-1,-1);
    }

    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object)person->query_guild_object();
    }
    gm = who;
    co_gm = ({});
    enforcers = ({});
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("SKERT","thief",
      "You will obey " + gm + " as your new GM!");
    if (person)
    {
	tm->set_guildmaster(TR_GM);
	CHANNEL_D->add_channel_member(tm,1,1,-1);
    }
    return 1;
}

status add_co_gm(string who)
{
    object person,tm;
#ifndef OLD_GOVERNMENT
    return 0;
#endif

    who = lower_case(who);
    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }
    if (!who) 
	return 1;
    if (!co_gm)
	restore_object(GUILD_SAVE);
    if (sizeof(co_gm) >= 3)
	return 0;
    if (member(co_gm, who) == -1)
	co_gm += ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("GUILDMASTER","thief",
      capitalize(who) + " has been \
PROMOTED to ASSISTANT GUILDMASTER!");
    if (person)
    {   
	tm->set_guildmaster(TR_CO_GM);
	CHANNEL_D->add_channel_member(tm,1,1,-1);
    }
    return 1;
}

status remove_co_gm(string who)
{
    object person,tm;
#ifndef OLD_GOVERNMENT
    return 0;
#endif

    who = lower_case(who);
    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }

    if (!who)
	return 1;
    if (!co_gm)
	restore_object(GUILD_SAVE);
    if (member(co_gm, who) != -1)
	co_gm -= ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("GUILDMASTER","thief",
      capitalize(who) + " has been \
DEMOTED from ASSISTANT GUILDMASTER!");
    if (person)
    {   
	tm->set_guildmaster(0);
	CHANNEL_D->add_channel_member(tm,1,-1,-1);
    }
    return 1;
}

status add_enforcer(string who)
{
    object person,tm;

    who = lower_case(who);
    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }

    if (!who)
	return 1;
    if (!enforcers)
	restore_object(GUILD_SAVE);
    //if (sizeof(enforcers) >= 6) Necros - thelp guildmaster says 7
    if (sizeof(enforcers) >= 7)
	return 0;
    if(!enforcers)
	enforcers = ({ });
    if (member(enforcers, who) == -1)
	enforcers += ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("GUILDMASTER","thief",
      capitalize(who) + " has been \
PROMOTED to ENFORCER!");
    if (person)
    {   
	tm->set_guildmaster(TR_ENFORCER);
	CHANNEL_D->check_channels(person);
    }
    return 1;
}

status remove_enforcer(string who)
{
    object person,tm;

    who = lower_case(who);
    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }

    if (!who)
	return 1;
    if (!enforcers)
	restore_object(GUILD_SAVE);
    if (member(enforcers, who) != -1)
	enforcers -= ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("GUILDMASTER","thief",
      capitalize(who) + " has been \
DEMOTED from ENFORCER!");
    if (person)
    {   
	tm->set_guildmaster(0);
	CHANNEL_D->check_channels(person);
    }
    return 1;
}
status add_demon(string who)
{
    object person,tm;

    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }

    if (!who)
	return 0;
    if (co_gm  &&  member(co_gm, who) != -1)
	remove_co_gm(who);
    if (enforcers  &&  member(enforcers, who)!=-1)
	remove_enforcer(who);
    if (!demons)
	restore_object(GUILD_SAVE);
    if(!demons)
	demons = ({ });
    if (member(demons, who) == -1)
	demons += ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("SKERT",
      "thief","Having met the requirements, " +
      capitalize(who) + " will now serve me as a DEMON!");
    if (person)
    {
	tm->set_guildmaster(TR_DEMON);
	CHANNEL_D->check_channels(person);
    }
    return 1;
}

status remove_demon(string who)
{
    object person,tm;

    if (person = find_player(who))
    {
	if ((string)person->query_guild() != GN_THIEF)
	    return 0;
	tm = (object) person->query_guild_object();
    }

    if (!who)
	return 0;
    if (!demons)
	restore_object(GUILD_SAVE);
    if (member(demons, who) != -1)
	demons -= ({ who });
    save_object(GUILD_SAVE);
    BIN_CHANNEL_D->send_channel_message("SKERT",
      "thief","DEMON " + capitalize(who) + 
      " has disgraced me and will no longer serve me as a DEMON!");
    if (person)
    {
	tm->set_guildmaster(0);
	CHANNEL_D->check_channels(person);
    }
    return 1;
}
string *query_demons()
{
    if (!demons)
	restore_object(GUILD_SAVE);
    if(!demons)
	demons = ({ });
    return demons;
}
status resign_gm(status which)
{
    object voter,old_gm,tm;
#ifndef OLD_GOVERNMENT
    return 0;
#endif

    if (!gm)
	restore_object(GUILD_SAVE);
    if (!gm)
	return 0;
    if (old_gm = find_player(gm))
    {
	tm = (object) old_gm->query_guild_object();
	tm->set_guildmaster(0);
    }
    gm = "";
    save_object(GUILD_SAVE);

    if (which)
	BIN_CHANNEL_D->send_channel_message("SKERT","thief",
	  "Your GM has resigned, you may vote \
for a new GM in the guild hall. (thelp vote)");
    else
	BIN_CHANNEL_D->send_channel_message("SKERT",
	  "thief","Your GM has been gone for \
the maximum two weeks.  You may now vote for a new GM in the guild hall.");

    voter = find_object(GDIR+"voter");
    if (!voter)
    {
	voter = clone_object(GDIR + "voter");
	move_object(voter, GDIR + "rooms/guild");
	voter->set_type(1);
    }

    return 1;
}

string
query_runner()
{
    object voter;
#ifdef OLD_GOVERNMENT
    return 0;
#endif
    voter = find_object(GDIR+"voter");
    if(voter)
	return (string)voter->query_cands();
    else return "";
}

status add_vote(string topic, string person) {
    if(!topic || !person) return 0;
    if(!votes[topic]) {
	votes += ([ topic : ({ person }) ]);
    }
    else { votes[topic] += ({ person }); }
    save_object(GUILD_SAVE);
    return 1;
}

status remove_vote(string topic, string person) {
    if(!topic || !person) return 0;
    if(!votes[topic]) return 0;
    if(member(votes[topic], person) == -1) return 0;
    votes[topic] += ({ person });
    save_object(GUILD_SAVE);
    return 1;
}

mixed query_votes(string topic) {
    if(!topic) return votes;
    if(!votes[topic]) return ({ });
    return votes[topic];
}

