//     /d/standard/booth.c
//     from the Nightmare mudlib
//     voting booth
//     created by Gregon@Nightmare Jan 1994
#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit "/std/room";
int a,b,c;
mapping vote;
void create() {
    ::create();
    set("short", "Voting room");
    set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
	"indoors" : 1, "no magic" : 1, "no castle" : 1, "no attack" : 1 ]));
    set("long",
      "This is the voting system for all the guilds.  If questions arise here "
      "is where they will be settled.  To view the current topic at question "
      "<read question>."); 
    set_exits( (["out" : ALL"meeting"]) );
    vote=([]);
    restore_object("/d/guilds/data/vote/question");
}
void init() {
    ::init();
    add_action("vote", "vote");
    add_action("read", "read");
    if(wizardp(this_player())) add_action("check", "check");
    if(wizardp(this_player())) add_action("clear", "clear");
}
int clear(string str) {
    if(!str) return notify_fail("You must include a reason.\n");
    if(str != "yes") return notify_fail("Invalid reason.\n");
    write("Clearing...\n");
    if(file_exists("/d/guilds/data/vote/question.o"))
	rm("/d/guilds/data/vote/question.o");
    restore_object("/d/guilds/data/vote/question.o");
    vote = ([]);
    a = 0;
    b = 0;
#ifdef C_Q
    c = 0;
#endif
    write("Cleared.\n");
    return 1;
}
int vote(string str) {
    string me;
    me=(string)this_player()->query_name();
#ifdef WIZ
    if(wizardp(this_player())) return notify_fail("Wizards are "
	  "not allowed to interfere.\n");
#endif
#ifdef C_Q
    if(str!="a" && str!="b" && str!="c") {
	notify_fail("You may only vote for a, b, or c.\n");
	return 0;
    }
    if(vote[me]) {
	write("You have already voted.");
	return 1;
    }
    if(str=="a") {
	vote[me]="a";
	a++;
	write("Vote counted.  Thank you.");
	save_object("/d/guilds/data/vote/question");
	return 1;
    }
    if(str=="b") {
	vote[me]="b";
	b++;
	write("Vote counted.  Thank you.");
	save_object("/d/guilds/data/vote/question");
	return 1;
    }
    if(str=="c") {
	vote[me]="c";
	c++;
	write("Vote counted.  Thank you.");
	save_object("/d/guilds/data/vote/question");
	return 1;
    }
#else
    if(str!="a" && str!="b") {
	notify_fail("You may only vote for a or b.\n");
	return 0;
    }
    if(vote[me]) {
	write("You have already voted.");
	return 1;
    }
    if(str=="a") {
	vote[me]="a";
	a++;
	write("Vote counted.  Thank you.");
	save_object("/d/guilds/data/vote/question");
	return 1;
    }
    if(str=="b") {
	vote[me]="b";
	b++;
	write("Vote counted.  Thank you.");
	save_object("/d/guilds/data/vote/question");
	return 1;
    }
#endif
}
int read(string str) {
    if(!str || str != "question") return notify_fail("Read what?\n");
    write("The current topic is:\n");
    write("Do you think the guild system needs improving in any ways.  "
      "If you choose yes, I would for you to mail me your suggestions "
      "on how it can be upgraded.\n\na) Yes, it needs to be upgraded with more features!\n"
      "b) The guild system is good just how it is.\n"
    );
#ifdef C_Q
    write("To vote type <vote a> or <vote b> or <vote c>\n");
#else
    write("To vote type <vote a> or <vote b>.\n");
#endif
    return 1;
}
int check(){
#ifdef C_Q
    write("A: "+a+"\nB: "+b+" \nC: "+c+"\n");
#else
    write("A: "+a+"\nB: "+b+"\n");
#endif
    return 1;
}
