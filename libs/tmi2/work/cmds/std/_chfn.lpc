// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Coded by Sulam (12-8-91)
// Fixed to accept defaults correctly by Jubal (Dec15/91)
// Help added by Brian (1/27/92)
// Revised by Buddha for new variable access (6-21-92)
// Fixed a typo (posted by Bonzo) (6-3-93)  Fix put in by Guile
//  Inspiral@TMI-2 (03-09-94) added admin chfn feature.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON ;

object link ;

int cmd_chfn( string arg ) {
    if((string)this_player()->query("name") == "guest") {
    write("You cannot change the Guest character's finger information.\n");
    return 1; }
 
   if( !arg || !adminp(geteuid( previous_object() )) )
      link = this_player()->query_link() ;
    else link = FINGER_D -> restore_data( arg );

   if( !link ) return notify_fail( "Chfn:  Unable to restore link!\n" );

    write("Changing finger information on " +
	(string) link->query("name") + " at " + mud_name() + ".\n");
    write("Default values are printed inside '[]'.\n");
    write("To accept the default, type <return>.\n");
    write("\n");
    write("Name ["+(string)link->query("real_name")+"] : ");
    input_to("new_name");
    return 1;
}

protected void new_name(string rname) {
    if( rname && strlen( rname ) > 0 ) {
	link->set("real_name", rname);
	link->save_data() ;
    }
    write("Email address ["+link->query("email")+"] : ");
    input_to("new_email");
}

protected void new_email(string e) {
    if( e && strlen( e ) > 0 ) {
	link->set("email", e);
	link->save_data() ;
    }
}

string help() {
	return(@HELP
Syntax: chfn

This askes for and updates your information for
the finger command. Please use it if you have
not yet.

See also: finger
HELP
  );
}
/* EOF */
