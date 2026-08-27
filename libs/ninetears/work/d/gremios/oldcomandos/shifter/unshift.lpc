/* The main Shapeshifter command only to be used by that guild
 * Raskolnikov Oct 96
 */
void unshift() {
    int delay;
    string delay_string;

    if(!(shadow(this_player(), 0))) {
	tell_object(this_player(), "No estas transformado ahora.\n");
	return 1;
    }

    delay = this_player()->query_shift_delay();
    if(delay) {
	delay_string = this_player()->query_unshift_delay_message();
	tell_object(this_player(), delay_string+"\n");
	this_player()->delay_unshift(delay);
	return 1;
    }
   this_player()->setmin("@$N llega de $F.");
   this_player()->setmout("@$N se va hacia $T.");
// ^^ Added by Timion to facilitate the entrace/exit messages ^^
    this_player()->dest_shift();
    return 1;
}

string help(string str) {
    return "Syntax: unshift\n\n"
    "This command allows the shapeshifter to return to its natural "
    "state of being.\n\n";
}
