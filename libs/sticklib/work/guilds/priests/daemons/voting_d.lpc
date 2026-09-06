#include "../priest.h"

#define VOTES PRIEST_SAVE_DIR "VOTE_SAVE"
#define ME this_player()
#define RN this_player()->query_real_name()
#define VG "Vicegerant"
#define PH "Hospitilar"
#define PT "Templar"
#define ERR(x) return notify_fail(x),0

int voting_started, duration;
status voting;
string *vg_voters,*ph_voters,*pt_voters;
mapping vg_votes,ph_votes,pt_votes;
string *vg_candidates, *ph_candidates, *pt_candidates;


// prototypes:
status valid_vote(object who,string office);
void check_voting();


// query functions:
status query_voting() { return voting; }
int query_voting_started() { return voting_started; }
int query_duration() { return duration; }


void
reset(int arg) {
    if(arg) {
	check_voting();
	return;
    }
    vg_candidates = ({});
    ph_candidates = ({});
    pt_candidates = ({});
    restore_object(VOTES);
}

status check_candidate(string name) {
    notify_fail("You are already a candidate!");
    if(member(vg_candidates, name)>=0) return 0;
    if(member(ph_candidates, name)>=0) return 0;
    if(member(pt_candidates, name)>=0) return 0;
    return 1;
}

status add_vg_candidate(string name) {
    if(check_candidate(name)) {
	vg_candidates += ({ name });
	save_object(VOTES);
	return 1;
    }
    return 0;
}

status add_ph_candidate(string name) {
    if(check_candidate(name)) {
	ph_candidates += ({ name });
	save_object(VOTES);
	return 1;
    }
    return 0;
}

status add_pt_candidate(string name) {
    if(check_candidate(name)) {
	pt_candidates += ({ name });
	save_object(VOTES);
	return 1;
    }
    return 0;
}

void set_duration(int dur) { duration = dur; }

// duration in seconds
status start_voting(int dur) {
    if(voting) ERR("But elections are already open.\n");

    voting = 1;
    voting_started = time();
    duration = dur;
    vg_votes = ([]);
    ph_votes = ([]);
    pt_votes = ([]);
    vg_voters = ({});
    ph_voters = ({});
    vg_candidates = ({});
    ph_candidates = ({});
    pt_candidates = ({});
    pt_voters = ({});
    save_object(VOTES);
    check_voting();
}


status
vote(string str) {
    string who, what;

    if(!str)
	ERR("You must use the proper vote technique.\n");

    if(sscanf(str,"%s for %s",who,what) !=2)
	ERR("vote <name> for <office>.\n");

    who = lower_case(who);
    what = capitalize(what);

    if(!valid_vote(ME, what))
	return 0;
    switch(what) {
    case VG:
	if(member(vg_candidates, who) == -1)
	    ERR("The candidates are: " + implode(vg_candidates, ", ", " and ")
	      + ". Please vote for one of them.\n");
	vg_votes[who]++;
	vg_voters += ({RN});
	break;

    case PH:
	if(member(ph_candidates, who) == -1)  
	    ERR("The candidates are: " + implode(ph_candidates, ", ", " and ")
	      + ". Please vote for one of them.\n");
	ph_votes[who]++;
	ph_voters += ({RN});
	break;

    case PT:
	if(member(pt_candidates, who) == -1)  
	    ERR("The candidates are: " + implode(pt_candidates, ", ", " and ")
	      + ". Please vote for one of them.\n");
	pt_votes[who]++;            
	pt_voters += ({RN});
	break;

    default:
	ERR("Invalid vote. Please try again.\n");
    }
    ME->tell_me(sprintf("You voted %s for %s.", capitalize(who), what));
    save_object(VOTES);
    return 1;
}


status
valid_vote(object who, string office) {
    if(!voting)
	ERR("Vote for what...no elections are begin held.\n");

    if(!who || !query_ip_name(who))
	ERR("Are you trying to cheat?\n");

    if(who->query_level() < 2)
	ERR("You have to be at least level 2 to vote.\n");

    if (who->query_age() < 17400)
	ERR("You are not old enough to vote yet.\n");

    if(who->query_guild() != GN_PRIEST)
	ERR("You are not a Priest.\n");

    switch(office){
    case VG:
	if(member(vg_voters, RN) >=0)
	    ERR("You have already voted for "+VG+".\n");
	break;

    case PH:
	if(member(ph_voters, RN) >=0)
	    ERR("You have already voted for "+PH+".\n");
	break;

    case PT:
	if(member(pt_voters, RN) >=0)
	    ERR("You have already voted for "+PT+".\n");
	break;

    default:
	ERR("Invalid vote. Please try again.\n");
    }
    return 1;
}


string
find_winner(mapping votes) {
    int *t,i,max,winner_n;

    t = m_values(votes);
    i = sizeof(t);
    max = 0;
    winner_n = -1;
    while(--i>=0)
	if(t[i]>max) {
	    max = t[i];
	    winner_n = i;
	}
    if(winner_n == -1) return "";
    return m_indices(votes)[winner_n];
}


void
end_voting() {
    string vg_name, pt_name, ph_name;

    vg_name = find_winner(vg_votes);
    if(member(pt_votes, vg_name)) pt_votes -= ([ vg_name ]);
    if(member(ph_votes, vg_name)) ph_votes -= ([ vg_name ]);

    pt_name = find_winner(pt_votes);
    if(member(ph_votes, pt_name)) ph_votes -= ([ pt_name ]);

    ph_name = find_winner(ph_votes);

    OFFICER_D->clear_officers();
    OFFICER_D->add_officer(vg_name, VG_RANK);
    OFFICER_D->add_officer(pt_name, PT_RANK);
    OFFICER_D->add_officer(ph_name, PH_RANK);

    SERVER->inform("*** Elections are over ***");
    SERVER->inform(sprintf("The new Vicegerant is %s, new Preceptor \
Templar is %s and new Preceptor Hospitilar is %s.",
	capitalize(vg_name), capitalize(pt_name), capitalize(ph_name)));
    SERVER->inform("Congratulations for the winners!");
    voting = 0;
    save_object(VOTES);
}

void
inform_players() {
    while(remove_call_out("inform_players") != -1);
    SERVER->inform("Elections are open, please vote.");
}

void
check_voting() {
    if(!voting) return;

    if(time() > (voting_started + duration))
	end_voting();
    else
	call_out("inform_players", 5);
}

string
query_candidates() {
    return sprintf("The candidates are:\n\n\
Vicegerant candidates: %s\n\
Preceptor Hospitilar candidates: %s\n\
Preceptor Templar candidates: %s",
      implode(vg_candidates, ", ", " and "), implode(ph_candidates, ", ", " and "),
      implode(pt_candidates, ", ", " and "));
}

void
debug() {
    printf("voting: %d\nvg_voters: %O\nph_voters: %O\npt_voters: %O\n\
vg_votes: %O\nph_votes: %O\n pt_votes: %O\nstart time: %O\nend time: %O\n",
      voting, vg_voters, ph_voters, pt_voters, vg_votes, ph_votes, pt_votes,
      ctime(voting_started), ctime(voting_started+duration));
}
