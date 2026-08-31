// TODO: add a private status report to just this_player()
//       add a subcommand to review all q/a's (pub and priv)
//       add a subcommand to show a specific q/a pair
#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define TRIVIA_TIMEOUT 20
#define BAIL(s) return notify_fail(s);
#define DISPUTE_FILE "/tmp/trivia_disputes"

string *trivcmds = ({"start", "q", "a", "dispute", "status", "addpoint", "delpoint", "end"});
mapping players;
object imm;
string *questions;
string *answered;
int currentq;
int playing;
int lasttime;


int triv_start(string opt);
int triv_q(string opt);
int triv_a(string opt);
int triv_addpoint(string opt);
int triv_delpoint(string opt);
int triv_dispute(string opt);
int triv_status(string opt);
int triv_end(string opt);

int cmd_triv(string str);
int sort_scores(string str1, string str2);
void trivia_line(string str);
void clear_vars();
void do_end();
void do_status(string pre);
void do_addpoint(string who, int points);
void do_delpoint(string who, int points);
void check_timeout();
void help();


void check_timeout() {
    if (!playing) return;

    if (time()-lasttime > 60*TRIVIA_TIMEOUT) {
        trivia_line("Game timed out after "+(string)TRIVIA_TIMEOUT+" minutes idle.");
        do_end();
    }
    else
        call_out("check_timeout", 60*2);
}


void clear_vars() {
    players=([]);
    questions=({});
    answered=({});
    imm=0;
    currentq=0;
    playing=0;
    lasttime=time();
}


int cmd_triv(string str) {

    string cmd, opt;
    string *ex;

    if (playing) {
        if (imm && this_player() != imm) {
        BAIL("The game is being run by "+capitalize(imm->query_name())+".\n");
        }
        else {

            lasttime=time();
        }
    }

    if (!str)
        BAIL("Triv commands: "+implode(trivcmds," ")+"\n");

    ex=explode(str," ");
    cmd=ex[0];
    opt=implode(ex[1..]," ");

    if (!cmd || member_array(cmd,trivcmds) == -1)
        BAIL("Triv commands: "+implode(trivcmds," ")+"\n");

    return call_other(this_object(),"triv_"+cmd,opt);
}


int triv_start(string opt) {

    string *p;
    int i;

    if (playing)
        BAIL("There is already a game in progress.\n");

    clear_vars();

    trivia_line("Game started.");

    playing=1;

    imm=this_player();

    check_timeout();

    return 1;
}


int triv_q(string opt) {

    if (!playing)
        BAIL("The game has not been started.\n");

    if (sizeof(questions) > sizeof(answered))
        BAIL("The last question has not been answered yet.\n");

    if (replace_string(opt," ","") == "")
        BAIL("No question specified.\n");

    questions += ({opt});

    trivia_line(""+(currentq+1)+". "+opt+"");

    return 1;
}


int triv_a(string opt) {

    string who, ans;

    if (!playing)
        BAIL("The game has not been started.\n");

    if (replace_string(opt," ","") == "")
        BAIL("No player specified.\n");

    if (sscanf(opt, "%s %s", who, ans) < 2)
        BAIL("No answer specified.\n");

    who=lower_case(who);

    if (sizeof(questions) <= sizeof(answered))
        BAIL("There is no question to answer yet.\n");


    if (who != "none")
        do_addpoint(who, 1);

    answered += ({who+" "+ans});
    currentq++;

    if (who == "none")
        trivia_line("The answer was: "+ans+"");
    else
        trivia_line("Correct, "+capitalize(who)+": "+ans+"");

    return 1;
}


int triv_addpoint(string opt) {
    string who;
    int points;

    if (!opt || opt == "")
        BAIL("No player specified.\n");

    if (sscanf(opt, "%s %d", who, points) != 2) {
        who=opt;
        points=1;
    }

    if (who == "none" || points < 1)
        BAIL("You can't do that.\n");

    do_addpoint(who,points);

    trivia_line("Added "+(string)points+" point"+(points==1?"":"s")+" to "+capitalize(who)+".");

    return 1;
}


void do_addpoint(string who, int points) {

    if (!(players[who]))
        players[who]=points;
    else
        players[who]=players[who]+points;

}


int triv_delpoint(string opt) {
    string who;
    int points;

    if (!opt || opt == "")


        BAIL("No player specified.\n");

    if (sscanf(opt, "%s %d", who, points) != 2) {
        who=opt;
        points=1;
    }

    if (who == "none" || points < 1)
        BAIL("You can't do that.\n");

    if (!(players[who]))
        BAIL("They already have 0 points.\n");

    do_delpoint(who,points);

    trivia_line("Removed "+(string)points+" point"+(points==1?"":"s")+" from "+capitalize(who)+".");

    return 1;
}


void do_delpoint(string who, int points) {


    if (!(players[who])) return;

    players[who]=players[who]-points;
    if (players[who] < 1) 
        map_delete(players,who);

}


int triv_dispute(string opt) {

    string last_who, last_question, last_answer;

    if (!opt || opt == "")
        opt="none";

    if (!playing)
        BAIL("The game has not been started.\n");

    if (!sizeof(questions))
        BAIL("There are not yet any questions to dispute.\n");

    if (!(last_question=questions[<1]))
        BAIL("The last question was not found, this is a bug.\n");

    if (sizeof(questions) > sizeof(answered)) {
        write_file(DISPUTE_FILE,
          "Question: "+last_question+"\n"+
          "Not answered\n"+
          "Notes: "+opt+"\n\n");
        trivia_line("Dispute over question, skipping it.");
    }
    else {
        if (sscanf(answered[<1],"%s %s", last_who, last_answer) != 2)
            BAIL("The last answer was not found, this is a bug.\n");
        write_file(DISPUTE_FILE,
          "Question: "+last_question+"\n"+
          "Answer from "+capitalize(last_who)+": "+last_answer+"\n"+
          "Notes: "+opt+"\n\n");
        do_delpoint(last_who,1);
        trivia_line("Dispute over answer, point removed from "+capitalize(last_who)+".");
        answered=answered[0..<1];
        currentq--;
        if (currentq < 0) currentq=0;
    }


    questions=questions[0..<1];

    return 1;
}


int triv_status(string opt) {

    if (!playing)
        BAIL("The game has not been started.\n");

    do_status("Game stats: "+currentq+" question"+(currentq==1?"":"s")+" so far, ");

    return 1;
}


void do_status(string pre) {

    string blah;
    string *k;
    int i;

    blah=pre;

    if (sizeof(players)) {
        k=keys(players);
        k=sort_array(k,"sort_scores");
        blah+="Scores: ";


        blah+=capitalize(k[0])+" - "+players[k[0]];
        for (i=1;i<sizeof(k);i++)
            blah+=", "+capitalize(k[i])+" - "+players[k[i]];
    }
    else {
        blah+="No points scored";
    }

    trivia_line(""+blah+"");

}


int triv_end(string opt) {

    if (!playing)
        BAIL("The game has not been started.\n");

    trivia_line("The game has ended.");

    do_end();

    return 1;
}


void do_end() {

    do_status("Final stats: "+currentq+" question"+(currentq==1?"":"s")+", ");

    clear_vars();

}


int sort_scores(string str1, string str2) {
    if (players[str1] < players[str2]) return 1;
    else if (players[str1] > players[str2]) return -1;
    else return 0;
}


void trivia_line(string str) {
    CHAT_D->do_chat("trivia", ""+str+"");
}


void help() {
    message("help","Syntax: triv start\n"+
      "        triv q <Question>\n"+
      "        triv a <Player|none> <Answer>\n"+
      "        triv addpoint <Player> [n]\n"+
      "        triv delpoint <Player> [n]\n"+
      "        triv dispute [Notes]\n"+
      "        triv status\n"+
      "        triv end\n\n"+
      "Helps run a trivia game.\n"+
      "Triv will keep track of all nonzero scores as well as\n"+
      "tracking the questions and answers. A few notes:\n\n"+
      "Player names can be anything but must be a single world.\n"+
      "Use \"none\" as the Player name for answers nobody gets right.\n"+
      "Dispute will log and forget the last question (if not yet answered) or q/a pair.\n"+
      "Triv will timeout and end the game if not used for "+(string)TRIVIA_TIMEOUT+" minutes.",
      this_player());
}
