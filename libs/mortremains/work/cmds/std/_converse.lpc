
/*
// This is part of the TMI distribution mudlib.
// Please retain this header for any files you may use the code in.
// written by Sulam(12-12-91)
// Help added by Brian 1/27/92
*/

inherit "/std/cmd_m";

protected void conv(string text) {
    int i;

    if( text ) {
	for(i=0; text[i] == ' '; i++) { /* empty loop */ } 
	if(text == "**" || text == ".") return;
	else if( text == "" || i == strlen(text) ) {
	    write("] ");
	    input_to("conv");
	    return;
	} 
	else say( iwrap( (string) this_player()->query("cap_name") +
            " says: " + text + "\n"), this_player() );
    }
    write("] ");
    input_to("conv");
    return;
}
  
int cmd_converse(string foo) {
    write("To escape from converse type **\n");
    write("While in converse you may use ! to execute commands.\n");
    conv(foo);  /* shrug, needs some text...  */
    return 1;
}

string help() {
  return(@HELP
Syntax: converse

This command puts you into converse mode, while
in converse mode, everything you type is automatically said.
You may precede any commands with a "!" to have them executed.
To exite converse mode, type "**" or "." at the begining of a line.

See also: say
HELP
  );
}
/* EOF */
