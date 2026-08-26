/*
** File: gum.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("short", "a layer of Trident bubblegum");
    set("long", @EndLong
A piece of Trident bubblegum. 'Chew' on it
and then 'spit' it at someone. You can also make
'bubble' with it.
EndLong
    );
    set("id", ({ "gum", "bubblegum" }) );
    set("mass", 0);
}

void init() {
    add_action("spit_func", "spit");
    add_action("chew", "chew");
    add_action("bubble", "bubble");
}

int spit_func( string str ) {
    string name;
    object target;

    if (!str) {
	write("Spit gum at who?\n");
	return 1;
    }

    // Make sure the syntax is in the form 'throw pie  at blah'
    if (sscanf(str, "%s at %s", str, name) != 2) {
	write("Who do you want to spit the gum at?\n");
	return 1;
    }

    // Here we see if the player is trying to 'shoot' the band,
    // or another object.
    if (str!="gum" && str!="bubblegum") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }
    if (target->query("busy") ) {
	write("That person is busy at the moment...\n");
	return 1;
    }

    // All the cool notifications.
    write("You spit your bubblegum at "+target->query("cap_name")+".\n");
    say(TPN+" spits "+POSS+" bubblegum to a specific target...\n");
    tell_object(target, wrap(
	"A nastily chewed bubblegum comes flying out of nowhere\n"+
	"and sticks to your hair in a messy way. EWWWWW.....\n"+
	"I suggest to you a hair cut, buddy!"));

    // Here we actually move the object.
    move( target );
    say(target->query("cap_name")+"'s hair is plastered by"+
      " a chewed bubblegum. EWWWW....\n", ({ target }) );
    return 1;
}
int chew(string str) {
    say(TPN+" gets a piece of Trident bubblegum, and chews it.\n");
    write("You get a piece of Trident bubblegum, and chew on it.\n");
    return 1;
}
int bubble(string str) {
    say(TPN+" makes a bubble with "+POSS+" bubblegum.\n");
    write("You make a bubble with your bubblegum.\n");
    return 1;
}
/* EOF */
