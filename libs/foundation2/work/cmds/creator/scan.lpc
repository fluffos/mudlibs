/*    /cmds/creator/scan.c
 *    from the Foundation II LPC Library
 *    scans an object
 *    created by Descartes of Borg 950516
 */

#include <lib.h>

#define OPT_E       (1 << 1)
#define OPT_D       (1 << 2)

inherit LIB_DAEMON;

string inventory(object ob, int level, int deep);

mixed cmd(string args) {
    object *inv;
    object ob;
    string tmp;
    int scan, i, maxi;

    if( args == "" || !args ) {
	ob = this_player();
	scan = 0;
    }
    else {
	while(args[0] == '-') {
	    switch(args[1]) {
		case 'd': scan |= OPT_D; break;
		case 'e': scan |= OPT_E; break;
	    }
	    if( strlen(args) > 3 ) args = trim(args[2..]);
	    else args = "";
	}
	if( args != "" ) ob = to_object(args);
	if( !ob ) ob = this_player();
    }
    if( scan & OPT_E ) ob = environment(ob);
    if( !ob ) return "No environment for requested object.";
    if( scan & OPT_D ) tmp = "Deep scanning " + identify(ob) + ":\n";
    else tmp = "Scanning " + identify(ob) + ":\n";
    for(i=0, maxi = sizeof(inv = all_inventory(ob)); i<maxi; i++) 
      tmp += inventory(inv[i], 1, scan & OPT_D);
    this_player()->more(explode(tmp, "\n"), "system");
    return 1;
}

string inventory(object ob, int level, int deep) {
    object *inv;
    string ret;
    int i, maxi;

    for(i = 1, ret = ""; i <= level; i++) ret += "\t";
    ret += identify(ob);
    if( deep && (maxi = sizeof(inv = all_inventory(ob))) ) ret += ":\n";
    else ret += "\n";
    if( !deep ) return ret;
    for(i=0; i<maxi; i++) 
      ret += inventory(inv[i], level + 1, 1);
    return ret;
}

void help() {
    message("help", "Syntax: <scan (-e) (-d) ([object])>\n\n"
	    "Scans the inventory of the object you name.  If you do "
	    "not specify an object, then it gives you your inventory.  "
	    "If you specify the -e option, the command does the "
	    "environment of the object which is targeted.  If the -d "
	    "option is specified, then a deep scan is done.\n\n"
	    "See also: inventory, stat", this_player());
}
