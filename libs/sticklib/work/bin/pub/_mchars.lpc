// /bin/pub/_ping.c    Bull, Sun Jun 1, 1997
//
// Allows players to check their _own_ multiple characters. Just so that
// they can't simply say: "I did not know it was not registered."


#include <cmd.h>
//#include <invis_levels.h>
#include <daemons.h>

int sort_alpha(string first, string second) {
    return (( first > second ) ? 1 : -1);
}

varargs nomask status
mchars_cmd(string s, object me) {
    string tmp, result;
    string *mchars;
    int    i, ie;

    if (!me && !(me = this_player())) return 0; 

    result = "Your current multiple chars are:";
    tmp = (string)MCHAR_D->query_multiple_char(
      (string)this_player()->query_real_name());
    if( tmp ) {
	mchars = explode(tmp , "#");
	mchars = sort_array(mchars, "sort_alpha", this_object());
	for( i = 0, ie = sizeof(mchars); i < ie; i++ ) {
	    result += " "+capitalize(mchars[i]);
	    if( i + 2 < ie ) result += ",";
	    if( i + 1 == ie - 1 ) result += " and";
	}
	result += ".\n";
	this_player()->tell_me(result);
	return 1;
    }

    this_player()->tell_me("You do not have registered multiple-characters.");
    return 1;
}
