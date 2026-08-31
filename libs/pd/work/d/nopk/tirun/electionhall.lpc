//     /d/standard/booth.c
//     from the Nightmare mudlib
//     voting booth
//     created by Gregon@Nightmare Jan 1994

#include <daemons.h>
#include <security.h>
#include <std.h>
#include <tirun.h>
#include <voting.h>
inherit ROOM;

void save();

mapping c;
mapping voters;
int tmp_clear; 
string * caught;

void create() {
    ::create();
    set("short", "Election Hall");
    set_property("light", 2);
    set_property("indoors", 1);
    set("long",
	"This is the election hall of Tirun.  Here players can vote who they would like to "
	"become mayors of our city.  If a player would like to run for mayor, they should "
	"<run> for office.  To see a list of candidates currently in the race, <view running>."
	"  You may vote for someone by <vote [person]>.  Players may not vote for themselves "
	"and administration may not run.  If you would like to remove your vote, you may "
	"<abstain>, however you may not vote again.");
    set_exits( (["west" : "/d/nopk/tirun/pubstart"]) );
    c=([]);
    voters=([]);
    caught=({});
    seteuid(UID_VOTESAVE);
    restore_object(DIR_VOTES+"/election");
    seteuid(getuid());
}
void init() {
    ::init();
    add_action("vote", "vote");
    add_action("read", "read");
    add_action("view", "view");
    add_action("run", "run");
    add_action("abstain", "abstain");
    if(wizardp(this_player())) add_action("check", "check");
    if(archp(this_player())) add_action("clear", "clear");    
}

int run(string s) {
    string me = this_player()->query_name();
    if(member_array(me, keys(c)) != -1) return write("You have already entered the race.");
    write("You enter the race.");
    c[me] = 0;
    save();
    return 1;
}

int vote(string str) {
    string me, *k, ip;
    int i;
    me=(string)this_player()->query_name();
    if(member_array(str, keys(c)) == -1) {
        notify_fail("That person isnt running.\n");
        return 0;
    }
    if(str == me) {
	notify_fail("You may not vote for yourself.");
	return 0;
    }
    if(this_player()->query_level() < 10 && !wizardp(this_player())) {
        write("You are too small of an adventurer to partake in such events.");
        return 1;
    }
    ip = MULTI_D->get_user_ip(this_player()->query_name());
    if(MULTI_D->get_user_ip(str) == MULTI_D->get_user_ip(this_player()->query_name())) {
	write("You are attempting to vote for a character that has logged on from the same "
	"ip address as you are.  We are sorry but you may not vote for this player.");
	caught += ({ me });
	return 1;
    }
    i=sizeof(k = keys(voters));
    while(i--) {
	if(MULTI_D->get_user_ip(k[i]) == ip) {
        write("You have already voted on an alt and may not vote again.  This atempt has been logged.");
        caught += ({ me });
        return 1;
	}
    }
    if(MULTI_D->non_voter(me)) {
        write("You are listed as a second character.  You may not vote.");
        return 1;
    }
    if(voters[me]) {
        write("You have already voted.");
        return 1;
    }
    voters[me] = str;
    write("Your vote has been submitted.  Thank you.");
    c[str]++;
    save();
    return 1;
}

int view(string s) {
    if(!s || s != "running") return notify_fail("View what?\n");
    write("The following players are currently running: \n----------------------------------------------");
    write(format_page(keys(c), 4));
    return 1;
}

int check(){
    int i, x, ct;
    string *k;
    mapping ip=([]);
    i=sizeof(k = keys(voters));
    while(i--) {
	if(!ip[MULTI_D->get_user_ip(k[i])]) ip[MULTI_D->get_user_ip(k[i])] = ({});
	ip[MULTI_D->get_user_ip(k[i])] += ({k[i]});
    }
    i = sizeof(k = keys(ip));
      while(i--) {
	if(x = sizeof(ip[ k[i] ]) > 1) {
	   while(x--) {
		c[ voters[ ip[ k[i] ][x] ] ] -= 1;
		map_delete(voters, ip[ k[i] ][x] );
	        ct ++;
	   }
	}
      }
save();
    write("Fixed: "+ct+"\n");
    write("Candidates: \n"+identify(c));
    write("\nVoters: \n"+identify(voters));
    write("\nCaught: \n"+identify(caught));
    return 1;
}

int clear() {
    if(!tmp_clear) {
        write("Type clear again to clear the votes.");
        tmp_clear=1;
        return 1;
    }
    voters=([]);
    c=([]);
    caught=({});
    save();
    write("Election system cleared.");
}

void save() {
    seteuid(UID_VOTESAVE);
    save_object(DIR_VOTES+"/election");
    seteuid(geteuid());
}

int abstain(string s) {
   if(s != "vote") return notify_fail("Abstain what?\n");
   if(!voters[this_player()->query_name()]) return notify_fail("You have not yet voted.\n");
   c[voters[this_player()->query_name()]] --;
   write("You vote has been removed.\n");
   return 1;
}
