// This room shows how to use an item in a command, and
// to dest that said item in the course of its usage (such
// as throwing something in a fire)
//
// Cyanide wrote this example, 28 May 2000
//
// In this case, only torches will be destroyed.

inherit ROOM;

void create() {
    ::create();

    set("author", "cyanide");
    set("short", "Example room");
    set("long", @EndLong
You are in a featureless room without doors or windows. in the
center of the room is a large hole in the floor.
EndLong
    );
    set("light", 1);
    set("item_desc", ([
      "hole" : @EndHole
It is a large hole in the floor designed to eat torches, and
nothing else. Any torch thrown into the hole will be destroyed.
EndHole
      ,
    ]) );
}

void init() {
    add_action("throw", "throw");
}

int throw( string str ) {
    object torch;
    string str2;

    if (!str || sscanf(str, "%s in %s", str, str2)!=2) {
	write("Throw what in where?\n");
	return 1;
    }

    // The article() function figures out the gramatically correct
    // article (i.e., "a" or "an") for the string passed to it.
    if (str2 != "hole") {
	write("You don't see "+article(str2)+" "+str2+" here.\n");
	return 1;
    }

    torch = present(str, TP);
    if (!torch) {
	write("You don't have "+article(str)+" "+str+"!\n");
	return 1;
    }

    if (!torch->id("torch")) {
	write("The hole spits it back out, and you manage to catch it.\n");
	return 1;
    }

    write("You gleefully drop the torch in the hole, never "+
      "to see it again.\n");
    say(TPN+" drops a torch in the hole.\n");

    // This is the important line for desting the torch
    torch->remove();
    return 1;
}

/* EOF */
