// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Wizard command "scan"
// list the filenames of objects in an inventory.
// Peregrin@ZorkMUD
// Updated 1995/10/9 by Ohara,

#include <mudlib.h>

inherit CMD;


#define PAD "    "

int deep_scan;

// scan the inventory of an object.
string
scan_object(object ob, int depth) {
    object *inv;
    string tstr, tempstr, retstr, pad;
    int    i, l;

    pad = "";
    i = depth + 1;
    while (i--) {
	pad += PAD;
    }       

    retstr = "";
    inv = all_inventory(ob);
    l = sizeof(inv);
    while (l--) {       
	retstr += pad+file_name(inv[l])+": "
        +(inv[l]->query_is_keeping() ? "<AL> " : "")
	+((tempstr=inv[l]->short()) ? "\""+tempstr+"\" " : "[no short]")
	+"\n"
	+(deep_scan ? scan_object(inv[l],depth+1) : "");
    }
    return retstr;
}

// the actual scan command.
private void main(mixed *arg, mapping flags)
{
    string outstr;
    string objs;
    string itemstr;

    if(flags["d"]) deep_scan = 1;

    if (!arg[0]) arg[0] = environment(this_body());
    outstr = "扫描 " + file_name( arg[0] ) + ":\n";
    objs = scan_object( arg[0], 0 );
    outstr += (objs != "")? objs : "    None\n";
    out( outstr );
    deep_scan = 0;
}
