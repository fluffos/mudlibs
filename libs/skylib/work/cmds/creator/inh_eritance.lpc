/* command, trial out by Turrican for a commands daemon. */

#include <creator.h>

inherit COMMAND_BASE;

string inherith(string ob, string ind, string leaf);

mixed cmd(string str) {
    string fn, fn2;
    object ob;

    seteuid(geteuid(this_player()));
    notify_fail("Syntax: inh[eritance] <filename> [<filename>]\n");
    if (!str) 
      return 0;
    if (sscanf(str, "%s %s", fn, fn2) != 2)
      if (sscanf(str, "%s", fn) != 1)
        return 0;
    // I'd like to use WIZ_PRESENT here, but I'm not sure how to handle
    // the optional filename at the end.
    if (!(ob = find_object(fn))) {
        notify_fail("No such object.\n");
        return 0;
    }
    fn = file_name(ob);
    write(fn + "\n" + inherith(fn, "  ", fn2));
    return 1;
}

/* Print inherit hierarchy */
string inherith(string ob, string ind, string leaf) {
    string *fn, rtn = "", s;
    int i;

    fn = inherit_list(find_object(ob));
    for (i = 0; i < sizeof(fn); i++) {
        //write("*Scanning " + fn[i] + "\n");
        if (leaf && (find_object(fn[i]) == find_object(leaf))) {
            //write("**Leaf match\n");
            rtn += ind + fn[i] + "\n";
        } else {
            //write("**No leaf match\n");
            s = inherith(fn[i], ind + "  ", leaf);
            if (!leaf || (s != "")) {
                //write("***Good branch\n");
                rtn += ind + fn[i] + "\n" + s;
            }
        }
    }
    return rtn;
}
