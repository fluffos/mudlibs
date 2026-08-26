/**
 * Generalised voting room intended to be inherited into rooms in the mud that
 * will setup the parameters and settings for votes.
 * <p>
 * The room does not inherantly support player initiated votes, however it is
 * a fairly simple matter to add this to your own room and have your room add
 * votes when players initiate them.
 *
 * @author Ceres
 */

#include <board.h>

#define DEFAULT_VOTE_DURATION 2600*24*7

inherit ROOM_OBJ;


/**
 * @class
 *  This class stores the essential information about a vote. It is only used
 *  internally to the voting room.
 */
class vote {
    string type;                  /* used to setup vote types */
    string desc;                  /* description of the vote */
    string *choices;              /* options in the vote */
    int *votes;
    int ending;                   /* when the vote ends */
    string *voted;                /* people who've voted */
}

/*
 * @class
 *  This class stores the essential information about an election during the
 *  setup phase. It is only used internally to the voting room.
 */
class election {
    mixed *candidates;            /* who are the candidates */
    int closes;                   /* when does acceptance of nominees close */
}

private int vote_counter;               /* Used to give each vote a unique number */

private mapping votes;                  /* the votes themselves */
private mapping elections;              /* the elections being setup */

private nosave string vote_file;        /* Controls which vote file to use */
private nosave mixed vote_cond;
private nosave mixed comp_action;       /* Completion action */
private nosave int vote_duration;       /* The normal duration for a vote */

private nosave mixed stand_cond;
private nosave mixed second_cond;

private nosave mixed election_announcement; /* The board, person and subject */

int list_votes();
int cast_vote( string words, int num );
int stand_for_election(string position);
int second_candidate(string who, string position);
int list_elections();

/**
 * @ignore
 */
void create() {
    do_setup++;
    add_help_file("voting_room");
    ::create();
    do_setup--;
    if ( !do_setup ) {
        TO->setup();
        TO->reset();
    }
    seteuid("Room");
}

/**
 * @ignore
 */
void init() {
    ::init();

    // commands for votes
    add_command("vote", "<string> on <number>", (: cast_vote($4[0], $4[1]) :) );
    add_command("votes", "", (: list_votes :));

    // commands for elections
    add_command( "stand", "[for] <string>", (: stand_for_election($4[0]) :));
    add_command( "second", "<string> [for] <string>",
      (: second_candidate($4[0], $4[1]) :) );
    add_command("elections", "", (: list_elections :));
} /* init() */

/**
 * This method is called by the inheriting object to determine which save file
 * to use for votes.
 *
 * @param str The name of the file you want the voting info saved to
 * (without the .o)
 */
void set_save_file(string file) {
    int *vote_ids, i;
    string election;

    vote_file = file;
    if( file_size( vote_file + ".o" ) > 0 ) {
        unguarded( (: restore_object, vote_file :) );

        if(!votes)
            votes = ([ ]);
        if(!elections)
            elections = ([ ]);

        vote_ids = m_indices( votes );

        for ( i = 0; i < sizeof( vote_ids ); i++ )
            if ( votes[ vote_ids[ i ] ]->ending < time() )
                call_out( "end_vote", 10 * ( i + 1 ), vote_ids[ i ] );
            else
                call_out( "end_vote", votes[ vote_ids[ i ] ]->ending - time(),
                  vote_ids[ i ] );

        foreach(election in keys(elections)) {
            if(elections[election]->closes < time())
                call_out( "start_election_vote", 30 * random(5), election);
            else
                call_out( "start_election_vote", elections[election]->closes - time(),
                  election);
        }
    } else {
        votes = ([ ]);
        elections = ([ ]);
    }
}

/**
 * This method returns the save file currently used for the room.
 * @return the current save file
 */
string query_save_file() { return vote_file; }

/**
 * Private function to save the rooms data file.
 */
private void save_room() {
    unguarded( (: save_object, vote_file :) );
}

/**
 * This function defines a function to be called to determine if a player
 * is eligible to vote.
 *
 * @param cond This will usually be a mixed array of an object and a function.
 * It could also be a function pointer.
 *
 * Your function should return 1 if the player is eligible to vote or 0 if
 * they are not.
 */
void set_vote_conditions(mixed cond) { vote_cond = cond; }

/**
 * This function defines a function to be called when the vote is complete.
 * Typically your function will post the vote results somewhere or somesuch.
 *
 * @param cond This will usually be a mixed array of an object and a function.
 * It could also be a function pointer.
 */
void set_completion_action(mixed cond) { comp_action = cond; }

/**
 * This function is used to set the normal vote and election duration. It can
 * be overridden when calling add_vote. If it is not set and no duration is
 * given in add_vote then the default value of DEFAULT_VOTE_DURATION is used.
 *
 * @param duraction The number of seconds the vote should be open.
 *
 * @see add_vote()
 */
void set_vote_duration(int duration) { vote_duration = duration; }

/**
 * This function defines a function to be called to determine if a player
 * is eligible to stand for election to a position.
 *
 * @param cond This will usually be a mixed array of an object and a function.
 * It could also be a function pointer.
 *
 * Your function should return 1 if the player is eligible to stand or 0 if
 * they are not.
 */
void set_stand_conditions(mixed cond) { stand_cond = cond; }

/**
 * This function defines a function to be called to determine if a player
 * is eligible to second a canditate for election.
 *
 * @param cond This will usually be a mixed array of an object and a function.
 * It could also be a function pointer.
 *
 * Your function should return 1 if the player is eligible to second or 0 if
 * they are not.
 */
void set_second_conditions(mixed cond) { second_cond = cond; }

/**
 * This function defines the board, person and subject for announcements
 * of elections.
 *
 * @param board This is the board to post to.
 * @param person This is who to post as.
 * @param subject This is the subject line to use.
 * @param prefix The text to preceed the message.  The default is
 *               "All eligible persons are requested to vote for the position "
 *               "of "
 * @param suffix The text to follow the message.
 */
void set_election_announcement(string board, string person, string subject,
  string prefix, string suffix) {
    election_announcement = ({ board, person, subject, prefix, suffix });
}

/**
 * This function is called when a player votes. The syntax is
 * "vote <choice> on <vote>".
 *
 * @see set_vote_conditions()
 */
int cast_vote( string which_str, int vote_id ) {
    string pname;
    int which, ok;
    class vote this_vote;

    if ( undefinedp(votes[vote_id])) {
        add_succeeded_mess(({"There is no vote " + vote_id + ".\n", ""}));
        return 1;
    }

    if(strlen(which_str) > 1) {
        add_succeeded_mess(({"There is no choice " + which_str + " for vote id " +
            vote_id + ".\n", ""}));
        return 1;
    }

    this_vote = votes[vote_id];
    which = upper_case( which_str )[ 0 ] - 65;
    if(which < 0 || which > sizeof(this_vote->choices) -1) {
        add_succeeded_mess(({"There is no choice " + which_str + " for vote id " +
            vote_id + ".\n", ""}));
        return 1;
    }

    ok = 1;
    if (functionp(vote_cond)) {
        ok = evaluate(vote_cond, TP);
    }
    if(arrayp(vote_cond)) {
        ok = call_other(vote_cond[0], vote_cond[1], TP);
    }

    if(!intp(ok)) {
        ok = 0;
    }

    if(!ok) {
        add_failed_mess("Sorry, but you are not allowed to vote on this "
          "subject.\n");
        return 0;
    }

    pname = TP->query_name();
    if(member_array(pname, this_vote->voted) != -1) {
        add_succeeded_mess(({"You have already voted on this subject.\n", ""}));
        return 1;
    }

    this_vote->voted += ({ pname });
    this_vote->votes[which]++;
    save_room();

    add_succeeded_mess(({ "You cast your vote for "+which_str + " on " +
        vote_id+".\n",
        "$N casts a vote.\n" }));

    return 1;
} /* cast_vote() */

/**
 * This function is called when a player types 'list'. It lists the currently
 * open votes.
 */
int list_votes() {
    int i, j, *vote_ids;
    string text;
    class vote this_vote;

    if ( !m_sizeof( votes ) ) {
        write( "There are no votes in progress.\n" );
        return 1;
    }

    vote_ids = m_indices( votes );
    if ( sizeof( vote_ids ) > 1 )
        write( "The following votes are in progress:\n" );
    else
        write( "The following vote is in progress:\n" );
    text = "";

    for ( i = 0; i < sizeof( vote_ids ); i++ ) {
        this_vote = votes[vote_ids[i]];
        text += "  "+ vote_ids[i] + ". " + this_vote->desc +"\n Choices are :\n";

        for(j=0; j<sizeof(this_vote->choices); j++) {
            text += sprintf("    %c. %s\n", 'A'+j, this_vote->choices[j]);
        }
        text += " Voting closes in "+ time_string( (this_vote->ending)-time() ) +".\n\n";
    }

    TP->more_string(sprintf( "%-=*s",
        (int)TP->query_cols(),
        text ));
    return 1;
}

/**
 * This function is called to add a vote to the system.
 *
 * @param type Freeform string giving the type of vote. This is typically used
 * by your completion function so that it can perform different actions for
 * different types of votes.
 *
 * @param description The description of the vote as shown to the player.
 *
 * @param choices An array of vote options eg. ({"Yes", "No" })
 *
 * @param ending An integer time of when the vote should be terminated.
 *
 * @see set_completion_action()
 */
void add_vote(string type, string description, string *choices, int ending) {
    class vote new_vote;

    vote_counter++;

    new_vote = new(class vote);
    new_vote->type = type;
    new_vote->desc = description;
    new_vote->choices = choices;
    new_vote->votes = allocate(sizeof(choices));
    if(ending)
        new_vote->ending = ending;
    else if(vote_duration)
        new_vote->ending = (vote_duration + time());
    else
        new_vote->ending = (DEFAULT_VOTE_DURATION + time());
    new_vote->voted = ({ });

    votes[ vote_counter ] = new_vote;

    call_out( "end_vote", new_vote->ending - time(), vote_counter );

}

/**
 * @ignore
 */
mapping query_votes() { return votes + ([ ]); }

/**
 * @ignore
 */
mapping query_elections() { return elections + ([ ]); }

/**
 * This function is called to terminate a vote. It calls your completion
 * action.
 *
 * @see set_completion_action()
 */
void end_vote( int which ) {
    tell_creator("shaydz", "Ending vote " + which + "\n");
    if ( !votes[ which ] )
        return;
    TCRE("shaydz",sprintf("votes[which]->type:%O votes[which]->desc:%O "
        "votes[which]->choices:%O votes[which]->votes:%O "
        "votes[which]->voted:%O",votes[which]->type, votes[which]->desc,
        votes[which]->choices, votes[which]->votes,
        votes[which]->voted));
    if(functionp(comp_action))
        evaluate(comp_action, votes[which]->type, votes[which]->desc,
          votes[which]->choices, votes[which]->votes,
          votes[which]->voted);
    else if(arrayp(comp_action))
        call_other(comp_action[0], comp_action[1], votes[which]->type,
          votes[which]->desc, votes[which]->choices, votes[which]->votes,
          votes[which]->voted);

    map_delete(votes, which);

    save_room();
}

/**
 * This function is provided for convenience to make it easy for your vote
 * end function to post to a board.
 *
 * @param board The name of the board to post to.
 * @param name The name of the person to post as.
 * @param subject The subject line to use.
 * @param message The message to post.
 */
void make_announcement(string board, string name, string subject,
  string message ) {
    BOARD_HAND->add_message(board, name, subject,
      sprintf( "%-=*s", 64, message));
}

/**
 * This function is used to initiate an election.
 * It sets up the election class and adds it to the mapping.
 *
 * @param position The name of the position the election is for.
 */
void initiate_election(string position) {
    class election tmp;

    if(elections[position])
        return;

    tmp = new(class election);
    tmp->candidates = ({});
    if(vote_duration) {
        tmp->closes = time() + vote_duration;
    } else {
        tmp->closes = time() + DEFAULT_VOTE_DURATION;
    }

    elections[position] = tmp;

    call_out("start_election_vote", time() + tmp->closes, position);

    save_room();
} /* initiate_election() */

/**
 * This method determines if there is already an election of the
 * specified type in progress.
 * @param position the name of the election in progress
 * @return 1 if there is an election in progress
 */
int query_election_in_progress(string position) {
    if (classp(elections[position])) {
        return 1;
    }
    return 0;
} /* query_election_in_progress() */

/**
 * This function is used by players to stand for election. The syntax is:
 * "stand for <position>".
 *
 * @see set_stand_conditions()
 */
int stand_for_election(string position) {
    int ok, i;

    // check if they're eligible.
    ok = 1;
    if(functionp(stand_cond)) {
        ok = evaluate(stand_cond, TP, position);
    } else if(arrayp(stand_cond)) {
        ok = call_other(stand_cond[0], stand_cond[1], TP, position);
    }

    if(!intp(ok))
        ok = 0;

    if(!ok) {
        add_succeeded_mess(({ "Sorry, but you are not allowed to stand for this "
            "election.\n", ""}));
        return 1;
    }

    // check if there is an election for this position.
    if(!elections[position]) {
        add_succeeded_mess(({"There is no election in progress for the post of " +
            position + ".\n", ""}));
        return 1;
    }

    // check if they're already a candidate for this position.
    for(i=0; i<sizeof(elections[position]->candidates); i++) {
        if(elections[position]->candidates[i][0] == TP->query_name()) {
            add_succeeded_mess(({"You are already standing in this "
                "election.\n", ""}));
            return 1;
        }
    }

    // add them to the list of candidates.
    elections[position]->candidates += ({({ TP->query_name(), "" })});
    save_room();
    add_succeeded_mess(({"You have been added to the list of candidates for "
        "the position of " + position + ".  You must now "
        "find someone to second your candidacy.\n",
        "$N stands for election.\n"}));
    return 1;
}

/**
 * This function is used by players to second candidates for election. If a
 * candidates isn't seconded he/she won't be in the election. The syntax is:
 * "second <player> for <position>".
 *
 * @see set_second_conditions()
 */
int second_candidate(string who, string position) {
    mixed *candidates;
    int i, found, ok;

    // check if they're eligible.
    ok = 1;
    if(functionp(second_cond)) {
        ok = evaluate(second_cond, TP, position);
    } else if(arrayp(second_cond)) {
        ok = call_other(second_cond[0], second_cond[1], TP, position);
    }

    if(!intp(ok))
        ok = 0;

    if(!ok) {
        add_succeeded_mess(({"Sorry, but you are not allowed to second candidates "
            "in this election.\n", ""}));
        return 1;
    }

    // check the position is up for election
    if(!elections[position]) {
        add_succeeded_mess(({"There is no election in progress for " + position +
            ".\n", ""}));
        return 1;
    }

    // check the candidate is standing
    candidates = (elections[position])->candidates;
    for(i=0; i< sizeof(candidates); i++) {
        if(candidates[i][0] == who)
            found = i+1;
    }

    if(!found) {
        add_succeeded_mess(({who + " is not standing for the position of " +
            position + ".\n", ""}));
        return 1;
    }

    if(TP->query_name() == who) {
        add_succeeded_mess(({"You cannot second yourself.\n", ""}));
        return 1;
    }

    if(candidates[found-1][1] != "") {
        add_succeeded_mess(({candidates[found-1][0] +
            " has already been seconded by " +
            candidates[found-1][1] + ".\n", ""}));
        return 1;
    }

    // mark the candidate as seconded (supported).
    candidates[found-1][1] = TP->query_name();

    save_room();

    add_succeeded_mess(({candidates[found-1][0] +
        " has been seconded in the election for "+
        position+".\n", ""}));
    return 1;
}

/**
 * Once the candidacy phase is over this function starts the election vote
 * itself by taking all eligible candidates, setting them as choices in the
 * election and then posting an announcemment.
 */
void start_election_vote(string post) {
    string str, *choices;
    int i;

    if(!elections[post])
        return;


    if(election_announcement[3])
        str = election_announcement[3];
    else
        str = "All eligible persons are requested to vote for the position of ";

    str += post + "\n\nThe candidates are:\n";

    choices = ({ });
    for(i=0; i<sizeof(elections[post]->candidates); i++) {
        if(elections[post]->candidates[i][1] != "") {
            str += sprintf("  %s seconded by %s.\n",
              elections[post]->candidates[i][0],
              elections[post]->candidates[i][1]);
            choices += ({ elections[post]->candidates[i][0] });
        }
    }

    if(!sizeof(choices)) {
        str = "In the election for the position of " + post +
        " no candidate stood for election therefore the election "
        "is null and void.\n";
    } else if(sizeof(choices) < 2) {
        str = "In the election for the position of " + post +
        " only one candidate stood for election therefore the election "
        "is null and void.\n";
    } else {

        if(election_announcement[4])
            str += election_announcement[4];

        add_vote("election", "Election for the post of " + post + "\n", choices,
          0);
    }

    make_announcement(election_announcement[0], election_announcement[1],
      election_announcement[2], str);

    map_delete(elections, post);
    save_room();
}

/**
 * This function is called when a player types 'elections'. It lists the
 * elections currently accepting candidates.
 */
int list_elections() {
    class election this_election;
    string *posts, text;
    int i, j;

    if ( !m_sizeof( elections ) ) {
        write( "There are no elections in progress.\n" );
        return 1;
    }

    posts = m_indices( elections );
    if ( sizeof( posts ) > 1 )
        write( "The following elections are in progress:\n" );
    else
        write( "The following election is in progress:\n" );
    text = "";

    for ( i = 0; i < sizeof( posts ); i++ ) {
        this_election = elections[posts[i]];
        text += "  Election to the post of "+ posts[i] + ".\n";

        if(!sizeof(this_election->candidates)) {
            text += "  No candidates have declared yet.\n";
        } else {
            text += "    Current candidates are :\n";

            for(j=0; j<sizeof(this_election->candidates); j++) {
                if(this_election->candidates[j][1] != "")
                    text += sprintf("    %c. %s seconded by %s.\n", 'A'+j,
                      this_election->candidates[j][0],
                      this_election->candidates[j][1]);
                else
                    text += sprintf("    %c. %s not yet seconded.\n", 'A'+j,
                      this_election->candidates[j][0]);

            }
        }
        text += " Candidacies must be declared by "+
        ctime( this_election->closes ) +".\n\n";
    }

    TP->more_string(sprintf( "%-=*s", (int)TP->query_cols(), text ));
    return 1;
}

/**
 * This is an administrative function to allow the removal/cancellation
 * of an election.
 * @param election The name of the election to be cancelled
 * @return Returns 1 for success, 0 for failure.
 */
int delete_election(string election) {
    if(!elections[election])
        return 0;
    map_delete(elections, election);
    save_room();
    return 1;
}

/**
 * This is an administrative function to allow the removal/cancellation
 * of a vote.
 * @param vote_id The id number of the vote to be cancelled.
 * @return Returns 1 for success, 0 for failure.
 */
int delete_vote(int vote_id) {
    if(!votes[vote_id])
        return 0;

    map_delete(votes, vote_id);
    save_room();
    return 1;
}
