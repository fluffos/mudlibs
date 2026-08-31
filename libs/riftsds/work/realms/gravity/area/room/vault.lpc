#include <lib.h>

inherit LIB_ROOM;

void create() {
    room::create();
	SetProperty("light", 2);
    SetClimate("indoors");
    SetShort("A secure room with a keypad entry");
    SetLong("This spacious room is heavily secured with a sophisticated keypad entry system. The walls are lined with reinforced steel and giant bat symbols riveted into the walls, there's a holographic keypad next to the door that requires a code to unlock. The only way to enter is by inputting the correct code.");

    SetItems( ([
        ({ "keypad", "entry system" }) : "A small, numeric keypad mounted on the wall next to the door. It looks like it requires a specific code to grant access.",
        "walls" : "The walls are made of reinforced steel, ensuring the room is highly secure.",
        "door" : "A solid steel door that won't budge without entering the correct code."
    ]) );
    SetSearch( ([ "keypad" : "You find a small etching of a pair of tits." ]) );
    SetSmell( ([ "default" : "You smell combination of balls and farts.",
                 "keypad" : "It smells like....stank pussy and ball cheddar!" ]) );
    SetExits( ([
        "west" : "/realms/gravity/area/room/batcave", // Example exit, adjust as needed
    ]) );


}

int CheckCode() {
    if(this_player()->query_name() == "80085") {
        this_player()->eventPrint("The keypad beeps and the door unlocks, allowing you to enter the secure room.");
        return 1; // Allow the player to enter
    } else {
        this_player()->eventPrint("The keypad beeps with an error. The code you entered is incorrect.");
        return 0; // Disallow the player from entering
    }
}

void init(){
    ::init();
    add_action("enter_code", "enter");
}

int enter_code(string str) {
    if(!str || str == "") {
        write("Enter what?");
        return 1;
    }
    if(str != "80085") {
        write("Incorrect code.");
        return 1;
    }
    write("The door unlocks as you enter the correct code.");
    this_player()->eventMoveLiving("/realms/gravity/area/room/crimealley"); // Adjust the path as needed
    return 1;
	
	    SetEnters( ([
        "crime alley" : (: CheckCode :),
    ]) );
}
