//	File	:  /cmds/std/_whisper.c
//	Creator	:  Watcher@TMI-2  (01/93)
//
//	Allows a player to whisper to another player present
//	in the same room without others seeing the message.

#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: whisper [who] [message]\n"

int cmd_whisper(string str) {
    object target;
    string who, message;
    object *people;
    int x;

    notify_fail( SYNTAX );

    people = all_inventory(environment(this_player()));

    if(!str || sscanf(str, "%s %s", who, message) != 2)
	return 0;

    if (environment(this_player())) 
	target = present( who, environment(this_player()) );

    if(!target) {
	write("There is no one named " + capitalize(who) + " here.\n");
	return 1; }

    if(!interactive(target)) {
	write("I don't think that object can understand you.\n");
	return 1; }

    if(target == this_player()) {
	write("You mutter to yourself.\n");
	return 1; }

    write(wrap("You whisper to " + capitalize(who) + ": " + message));

    say(capitalize((string)this_player()->query("name")) + " whispers " +
      "something to " + capitalize((string)target->query("name")) + ".\n",
      ({ this_player(), target }));

    tell_object(target, 
      wrap(capitalize((string)this_player()->query("name")) + " whispers " +
	"to you: " + message));

    target->set("wreply", (string)this_player()->query("name"));

    //this is so read lips works :)  

    for (x=0;x<sizeof(people);x++) {
	if (!living(people[x])) continue;
	if (people[x]==this_player() || people[x]==target) {
	    //  message("say", wrap("You "+verb_a+": "+str+"\n"), this_player() );
	} else {
	    if (visible(TP, people[x]) && (people[x]->query_skill("Read Lips"))) { 
		tell_object(people[x], 
		  wrap(capitalize((string)this_player()->query("name")) + " whispers "+message+" to "+ capitalize((string)target->query("name")) + ".\n"));
	    } 
	}
    }


    return 1; }

string help() {

    return ( SYNTAX + "\n" +
      "This command allows the user to speak with another player in the\n" +
      "same room, without other present hearing the message.\n");
    write("\nSee also: wreply.\n");

}

