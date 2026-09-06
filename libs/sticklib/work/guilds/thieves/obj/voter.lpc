
#include <treasure.h>
#include <guild.h>

#define TP this_player()
/* 48 hours */
#define KILL_LENGTH 172800
/* 6 days */
#define NORMAL_LENGTH (6 * 24 * 60 * 60)
#define PERCENT_WIN 73 /* Necros - 80 is tough to pull. really tough. */
#define VOTE_SAVE "/guilds/thieves/GM_VOTES"
#define GM_D "/guilds/thieves/gm_d"
#define CHANNEL_D "/bin/daemons/channel_d"
#define TR_DEMON 500

int calc_end();
mapping votes;
string *voted;
int type, vote_started;

void
create_treasure()
{
    int remaining;

    set_name("voter");
    set_short("GM Voting Box");
    set_long("Here you can vote for GM");
    set_id( ({ "voting box", "box", "gm voting box" }) );
    votes = ([]);
    voted = ({});
    type = -1;
    vote_started = 0;
    restore_object(VOTE_SAVE);
    if (!vote_started)
	vote_started = time();
    save_object(VOTE_SAVE);
    remaining = calc_end();
    remove_call_out("end_vote");
    call_out("end_vote", remaining);
}

status get() { return 0; }

void
long(string what)
{
    string mesg, *ppl;
    int i;

    ppl = m_indices(votes);
    if (type == 1)
    {
	mesg = "General vote for new GM.  To vote type 'vote <candidate>'."+
	"  The candidates so far are:\n";
    }
    else
    {
	if (pointerp(ppl) && ppl[0])
	    mesg = "Forceful takeover vote.  To vote type 'vote <yes/no>'."+
	    "Voting yes votes for "+capitalize(ppl[0])+", and voting no votes "
	    "for "+capitalize(GM_D->query_gm())+". "+
	    "  The candidate is:\n";
    }


    if (type == 1)
    {
	if (!ppl || sizeof(ppl) < 1)
	    mesg += "(no candidates yet)\n";
	else
	    for(i=0;i < sizeof(ppl);i++)
		mesg += capitalize(ppl[i]) + "\n";

	mesg += "To add yourself as a candidate type 'add'.  ";
    }
    else
    {
	if (!ppl || sizeof(ppl) < 1) mesg += "No one??!? (BUG???)\n";
	else mesg += capitalize(ppl[0]) + "\n";
    }

    mesg += "There are ";
    i = (int) calc_end();
    mesg += i / 3600 + " hours, " + (i%3600)/60 + " minutes, and " +
    (i%3600)%60 + " seconds ";
    /*
      mesg += i > 59 ? i / 60 + " minutes and " + i % 60 + " seconds " :
      i + " seconds ";
      */
    mesg += "time remaining for voting.";
    this_player()->tell_me(mesg);
}

void init_treasure()
{
    add_action("vote_cmd", "vote");
    add_action("add_list", "add");
}

status set_type(mixed which)
{
    if (intp(which))
    {
	if (which < 0 && which > 1)
	{
	    write("Invalid Type\n");
	    destruct(this_object());
	}
	type = which;
    }
    else
	type = 0;
    if (type == 0)
    {
	votes = ([ which : 0; 0]);
	save_object(VOTE_SAVE);
    }
    return 1;
}

int calc_end()
{
    int current;

    current = time();

    if (type == 1)
	return (NORMAL_LENGTH - (current - vote_started));
    else
	return (KILL_LENGTH - (current - vote_started));
}

status vote_cmd(string who)
{
    int num_who;
    string *cand;
    object tm;

    if (member(voted, TP->query_real_name()) != -1)
    {
	notify_fail("You can only vote once.\n");
	return 0;
    }
    if ((string)TP->query_guild() != GN_THIEF)
	return 0;
    if (TP->query_level() < 5)
    {
	notify_fail("You must be at least level 5 to vote.\n");
	return 0;
    }
    if (TP->query_age() < 86400)
    {
	notify_fail("You must be at least 2 days old.\n");
	return 0;
    }
    tm = (object)TP->query_guild_object();
    if ((int)tm->query_guildmaster() == TR_DEMON)
    {
	notify_fail("Demons may not vote.\n");
	return 0;
    }

    if (type == 1)
    {
	if (!who)
	{
	    notify_fail("Vote for who?\n");
	    return 0;
	}
	if (!votes)
	    restore_object(VOTE_SAVE);

	cand = m_indices(votes);

	if (member(cand, who) == -1)
	{
	    notify_fail(capitalize(who) + " is not a candidate.\n");
	    return 0;
	}

	votes[who,0] += 1;
	save_object(VOTE_SAVE);
    }
    else
    {

	if (who != "yes" && who != "no")
	{
	    notify_fail("You must vote yes or no.\n");
	    return 0;
	}
	cand = m_indices(votes);
	if (who == "yes")
	    votes[cand[0],0] += 1;
	votes[cand[0],1] += 1;
	save_object(VOTE_SAVE);
    }
    voted += ({ TP->query_real_name() });
    save_object(VOTE_SAVE);
    TP->tell_me("Thanx for voting pal!");
    return 1;
}

status add_list()
{
    string *cand;
    object tm;

    if ((string)TP->query_guild() != GN_THIEF)
	return 0;
    tm = (object)TP->query_guild_object();
    if ((int)tm->query_guildmaster() == TR_DEMON)
    {
	notify_fail("Demons can't add themselves as candidates!\n");
	return 0;
    }
    if (type != 1)
    {
	notify_fail("This is not a general vote, therefore you \
may not add your name as a candidate.\n");
	return 0;
    }
    if (!votes)
	restore_object(VOTE_SAVE);
    if ((string)TP->query_guild() != GN_THIEF)
	return 0;

    cand = m_indices(votes);

    if (member(cand, TP->query_real_name()) != -1)
    {
	notify_fail("You are already a candidate!\n");
	return 0;
    }

    TP->tell_me("You add your name to the list of candidates.");
    environment(TP)->tell_here(TP->query_name() + " adds " +
      TP->query_possessive() + " name to the list of candidates.",TP);


    votes += ([ TP->query_real_name() : 0 ]);

    /* Was missing :(... */
    save_object(VOTE_SAVE);

    return 1;
}

status end_vote()
{
    string *cand, *tied, new_gm;
    int i, *votes_received;

    if (type == 1)
    {
	cand = m_indices(votes);
	votes_received = m_values(votes);
	new_gm = cand[0];
	for (i=1;i<sizeof(cand);i++)
	{
	    if (votes_received[i] > votes_received[i-1])
		new_gm = cand[i];
	}
	tied = ({ new_gm });
	for(i=1;i < sizeof(cand);i++)
	{
	    if (votes_received[i] == votes_received[i-1])
		tied += ({ cand[i] });
	}
	if (sizeof(tied) > 1)
	{ 
	    /* tie! */
	    CHANNEL_D->send_channel_message("SKERT","thief",
	      "The vote has ended in a tie.  Voting will continue for \
1 more hour.");
	    call_out("end_vote", 3600);
	    return 1;
	}
	else
	{
	    CHANNEL_D->send_channel_message("SKERT","thief",
	      "The voting time has ended.");
	    GM_D->set_gm(new_gm);
	}
    }
    else
    {
	cand = m_indices(votes);
	if (!cand || sizeof(cand) < 1) return 0;
	i = votes[cand[0],1];
	if (i < 10)
	{
	    CHANNEL_D->send_channel_message("SKERT","thief",
	      capitalize(cand[0]) + " did not receive the minimum amount \
of votes required to become GM.  " + capitalize((string)GM_D->query_gm())+
	      " will retain the position.");
	    rename(VOTE_SAVE+".o", VOTE_SAVE+".old");
	    destruct(this_object());
	    return 0;
	    /* (above) nope not enough voters */
	}
	i = (i * PERCENT_WIN) / 100;
	if (votes[cand[0],0] >= i)
	{
	    /* Won */
	    CHANNEL_D->send_channel_message("SKERT","thief",
	      capitalize(cand[0]) + " received the required " +
	      PERCENT_WIN + "% vote.");
	    GM_D->set_gm(cand[0]);
	}
	else
	{
	    /* lost */
	    CHANNEL_D->send_channel_message("SKERT","thief",
	      capitalize(cand[0]) + " did not receive the required " +
	      PERCENT_WIN + "% Vote.  " + capitalize((string)GM_D->query_gm())+
	      " will retain the position of GM.");
	}
    }
    rename(VOTE_SAVE+".o", VOTE_SAVE+".old");
    destruct(this_object());
    return 1;
}
string *query_cands()
{
    return m_indices(votes);
}
