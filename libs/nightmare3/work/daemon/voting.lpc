//    /daemon/voting.c
//    from the Nightmare Mudlib
//    daemon to handle democracy on the mud
//    original by Descartes of Borg
//    re-written to use mappings by Kalinash 031394

#include <security.h>
#include <voting.h>
#include <daemons.h>
#define DAY 86400
#include <std.h>

inherit DAEMON;

void save_totals(string drow);

private mapping elections;
int running, start_date;
string next_vote_date;

void create() {
    elections = ([]);
    running = 0;
    restore_object(VOTE_SAVE);
}

int register_vote(string who, string whom, string Class) {
    if(!running) return NOT_ELECTION_DAY;
    if((time() - start_date) < (DAY * 4)) return TOO_EARLY;
    if(!who || !whom || !Class) return VOTE_ERROR;
    if(!elections["voted"]) elections["voted"] = ([]);
    if(!elections["voted"][Class]) elections["voted"][Class] = ({});
    if(!elections["candidates"]) elections["candidates"] = ([]);
    if(!elections["candidates"][Class]) elections["candidates"][Class] = ({});
    if(member_array(whom, elections["candidates"][Class]) == -1)
        return NOT_RUNNING;
    if(member_array(who, elections["voted"][Class]) != -1) 
        return ALREADY_VOTED;
    if(MULTI_D->non_voter(who)) return ALREADY_VOTED;
    if((member_array(who, elections["voted"][Class]) != -1) 
      && (member_array(whom, elections["voted"][Class]) != -1))
        return BAD_VOTE;
    elections["voted"][Class] += ({ who });
    if(!elections["votes"]) elections["votes"] = ([]);
    if(!elections["votes"][Class]) elections["votes"][Class] = ([]);
    if(!elections["votes"][Class][whom])
        elections["votes"][Class][whom] = 0;
    ++elections["votes"][Class][whom];
    save_object(VOTE_SAVE);
    save_totals("normal");
    return VOTE_OK;
}

int register_candidate(string who, string Class) {
    if(!running) return NOT_ELECTION_DAY;
    if(!who || !Class) return VOTE_ERROR;
    if(member_array(Class, CLASSES) == -1) return VOTE_ERROR;
    if(!elections["candidates"])
        elections["candidates"] = ([]);
    if(!elections["candidates"][Class])
        elections["candidates"][Class] = ({});
    if(member_array(who, elections["candidates"][Class]) != -1)
        return ALREADY_RUNNING;
    elections["candidates"][Class] += ({ who });
    save_object(VOTE_SAVE);
    return VOTE_OK;
}

string *query_candidates(string Class) {
    if(!running) return ({});
    return elections["candidates"][Class];
}

void set_vote_date(string date) {
    next_vote_date = date;
    save_object(VOTE_SAVE);
    return;
}

string query_vote_date() {
    return next_vote_date;
}

int query_voted(string who, string Class) {
    if(!elections["voted"]) return 0;
    if(!elections["voted"][Class]) elections["voted"][Class] = ({});
    if(member_array(who, elections["voted"][Class]) != -1 ||
      MULTI_D->non_voter(who))
        return 1;
    else
        return 0;
}

int election_day() {
    return running;
}

int is_time_to_vote() {
    if(!running) return 0;
    if((time() - start_date) < (DAY * 4))
        return 0;
    else
        return 1;
}

void start_elections() {
    restore_object(VOTE_SAVE);
    running = 1;
    start_date = time();
    save_object(VOTE_SAVE);
    return;
}

void end_elections() {
    save_totals("normal");
    save_totals("archive");
    running = 0;
    elections = ([]);
    save_object(VOTE_SAVE);
}

void save_totals(string drow) {
    string *magi, *who;
    int x, z, q;

    if(drow == "normal") {
        rm(DIR_VOTES+"/votes");
        magi = keys(elections["votes"]);
        x = sizeof(magi);
        if(magi)
            for(z=0;z<x;++z) {
                who = keys(elections["votes"][magi[z]]);
            for(q=0;q<sizeof(who);++q)
                write_file(DIR_VOTES+"/votes", sprintf("%s - %s : %d\n", magi[z], who[q], elections["votes"][magi[z]][who[q]]));
            }
    }
    if(drow == "archive") {
        rm("/log/archive/votes");
        magi = keys(elections["votes"]);
        x = sizeof(magi);
        if(magi)
            for(z=0;z<x;++z) {
                who = keys(elections["votes"][magi[z]]);
            for(q=0;q<sizeof(who);++q)
                write_file(DIR_VOTES+"/votes", sprintf("%s - %s : %d\n", magi[z], who[q], elections["votes"][magi[z]][who[q]]));
            }
    }
}
