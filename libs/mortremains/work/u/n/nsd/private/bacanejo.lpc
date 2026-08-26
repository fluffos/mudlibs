/*
** File: bacanejo.c
** Author: Lady Nsd
** Side comments: this file was created to goof off with Chronos...
*/

inherit OBJECT ;

void create() {
    set("author", "nsd");
    set ("short", "a bottle of Bacardi Anejo");
    set ("long", @EndText
A bottle of Bacardi Anejo rum. This is a Puertorrican rum.
It will surely blast you and leave you almost comatose.
Drink it at your own risk... ;-P
EndText);
    set ("id", ({ "bottle", "rum", "bottle of bacardi", "bacardi",
      "anejo", "bacardi anejo", "bottle of rum" }) ) ;
}
void init() {
    add_action ("drink", "drink");
}
int drink(string str) {
    if(TP->query("drunk")) {
	write("You fail to reach the bottle with your lips...\n");
	say(TPN+" fails to reach the bottle with "+POSS+" lips...\n");
	return 1;
    }
    say(TPN+" drinks "+POSS+" Bacardi rum and gets blasted....\n");
    say(TPN+" looks awfully drunk... *oO*\n");
    write("YOUCH!!!!... That certainly blasted you, buddy!!!\n");
    TP->add("drunk", 8);
    return 1;
}
/* End of file */
