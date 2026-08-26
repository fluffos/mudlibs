// File: anvil.c
// Author: Lady Nsd, Mistress of Darkness (mind Seductress)

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("short", "a heavy anvil");
    set("long", @EndLong
This is a heavy black anvil. Used to be thrown at someone
just for the fun of it. Will make that someone be calmed
and dizzy for a bit. Throw it at any player.
EndLong
    );
    set("id", ({ "anvil", "heavy anvil" }) );
    set("mass", 5);
}

void init() {
    add_action("throw_func", "throw");
}

int throw_func( string str ) {
    string name;
    object target;

    if (!str) {
	write("Throw anvil at who?\n");
	return 1;
    }

    // Make sure the syntax is in the form 'throw pie  at blah'
    if (sscanf(str, "%s at %s", str, name) != 2) {
	write("Who do you want to throw the anvil at?\n");
	return 1;
    }

    // Here we see if the player is trying to 'shoot' the band,
    // or another object.
    if (str!="anvil" && str!="heavy anvil") {
	return 0;
    }

    target = find_player(name);
    if (!target) {
	write("There's no player named "+capitalize(name)+
	  " on the mud!\n");
	return 1;
    }

    // All the cool notifications.
    write("You throw the anvil at "+target->query("cap_name")+".\n");
    say(TPN+" Throws a horribly heavy anvil.\n");
    tell_object(target, wrap(
	"An ordinary black and heavy anvil comes flying out of nowhere\n"+
	"and smashes you upside the head... *@#&* You feel a bit dizzy...") );

    // Here we actually move the object.
    move( target );
    say(target->query("cap_name")+"'s head is smashed by"+
      " a heavy anvil. Ouch!\n", ({ target }) );
    return 1;
}
