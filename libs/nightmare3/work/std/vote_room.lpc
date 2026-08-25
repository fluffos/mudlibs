//    vote_room.c
//    Inheritable voting room.
//    From the Nightmare mudlib
//    By Kalinash on Mar 19, 1994.
//    add_pre_exit_funcs() by Pallando, Sep 02, 1994

#include <std.h>
#include <voting.h>
#include <daemons.h>

inherit ROOM;

void add_pre_exit_funcs()
{
    string *dirs;
    int loop;

    loop = sizeof( dirs = query_exits() );
    while( loop-- )
       add_exit( dirs[loop], query_exit( dirs[loop] ), (: "go_west" :) );
}

void create() {
    ::create();
    call_out( "add_pre_exit_funcs", 0 );
}

int go_west() {
    if((int)VOTING_D->is_time_to_vote() && !creatorp(this_player()) && (int)this_player()->query_level() > 1)
    if(!(int)VOTING_D->query_voted(this_player()->query_name(), this_player()->query_class())) {
         message("my_action", "You cannot leave until you vote or abstain.",
           this_player());
        return 0;
    }
    return 1;
}

void init() {
    ::init();
    add_action("abstain_fun", "abstain");
    if(creatorp(this_player())) return;
    if((int)this_player()->query_level() < 2) return;
    add_action("vote_fun", "vote");
    add_action("read_fun", "list");
    add_action("enter_fun", "enter");
}

int abstain_fun() {
    int x;

    if(!(int)VOTING_D->query_voted("abstain", this_player()->query_class()))
        VOTING_D->register_candidate("abstain", this_player()->query_class());
    x = VOTING_D->register_vote(this_player()->query_name(), "abstain", this_player()->query_class());
    if(x != VOTE_OK) 
        return notify_fail("There was an error.\n");
    else
        message("my_action", "You abstain from the vote.", this_player());
    return 1;
}

int vote_fun(string str) {
    int x;

    if(!VOTING_D->election_day())
        return notify_fail(sprintf("You will have to wait until %s.",
          VOTING_D->query_vote_date()));
    x = (int)VOTING_D->register_vote((string)this_player()->query_name(),
      str, (string)this_player()->query_class());
    switch(x) {
      case VOTE_OK :
        message("my_action", "Your vote has been registered.", this_player());
        message("their_action", sprintf("%s registers %s vote.", 
          this_player()->query_cap_name(), this_player()->query_possessive()),
          environment(this_player()), this_player());
        break;
      case VOTE_ERROR :
        message("my_action", "Bad entry.  Try again.", this_player());
        break;
      case NOT_RUNNING :
        message("my_action", "That person is not running.  Vote for "
          "someone else.", this_player());
        break;
      case ALREADY_VOTED :
        message("my_action", "You have already voted.", this_player());
        break;
      case BAD_VOTE :
        message("my_action", "You can only vote for a candidate once.",
          this_player());
        break;
      case TOO_EARLY :
        message("my_action", "You can only 'enter' to run right now.",
          this_player());
        break;
      default : message("my_action", sprintf("Bad entry : %d.", x), this_player());
    }
    return 1;
}

int enter_fun(string str) {
    int x;

    if(!str || str != "race") {
        message("my_action", "Enter what? The race?", this_player());
        return 1;
    }
    if(!VOTING_D->election_day())
        return notify_fail("It is not yet time to enter the election.\n");
    x = (int)VOTING_D->register_candidate(
      (string)this_player()->query_name(), (string)this_player()->query_class());
    switch(x) {
        case VOTE_ERROR :
            message("my_action", "Bad entry.\nTry again.", this_player());
            break;
        case ALREADY_RUNNING :
            message("my_action", "You are already running!", this_player());
            break;
        case VOTE_OK :
            message("my_action", "You enter the race.", this_player());
            message("thier_action", sprintf("%s enters the race.", 
              this_player()->query_cap_name()), environment(this_player()),
              this_player());
            break;
        default :
            message("my_action", "Bad entry.  Try again.", this_player());
    }
    return 1;
}

int read_fun(string str) {
    string *who;
    int i;

    if(!str || str != "candidates") return notify_fail("List what?\n");
    if(!VOTING_D->election_day())
        return notify_fail("It is not currently time for elections.\n");
    who = (string *)VOTING_D->query_candidates((string)this_player()->query_class());
    if(!sizeof(who)) {
        message("my_action", "No one is currently running.", this_player());
        return 1;
    }
    message("my_action", "You may vote for one of the following :", this_player());
    for(i=0;i<sizeof(who);i++)
        if(who[i]) write(capitalize(who[i]));
    message("my_action", "<vote [name]> votes\n<enter race> enters "
      "yourself into the race.", this_player());
    return 1;
}

