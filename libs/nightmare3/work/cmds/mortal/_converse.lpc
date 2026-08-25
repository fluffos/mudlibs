
/*
// This is part of the TMI distribution mudlib.
// Please retain this header for any files you may use the code in.
// written by Sulam(12-12-91)
// Help added by Brian 1/27/92
*/

#include <std.h>

inherit DAEMON;

protected void conv(string text) {
    int i;

    if( text ) {
	for(i=0; text[i] == ' '; i++) { /* empty loop */ }
	if( text == "**" ) return;
	else if( text == "" || i == strlen(text) ) {
	    message("Nsystem","] ",this_player());
	    input_to("conv");
	    return;
	}
	else {say( (string) this_player()->query_cap_name() +
            " says: " + text + "", this_player() );
         write("You say: "+text);
    }
    }
    message("Nsystem","] ",this_player());
    input_to("conv");
    return;
}

int
cmd_converse(string foo) {
    write("To escape from converse type **");
    write("While in converse you may use ! to execute commands.");
    conv(foo);  /* shrug, needs some text...  */
    return 1;
}


int
help() {
  message("help","Syntax: converse\n\n"
        "This command puts you into converse mode, while "
        "in converse mode everything you type is automatically said. "
        "You may precede any commands with a ! to have them executed. "
        "To exit converse mode type ** at the beginning of any line.",this_player());
  return 1;
}
/* EOF */
