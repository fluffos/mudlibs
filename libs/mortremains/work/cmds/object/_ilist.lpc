// file : cmds/refs/_ilist.c
// Shows all files inherited by a particular object
// Written by Guile@Ultimud.
// Ported to TMI-2 by Guile
//

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: ilist [-R -T] <object>\n"

int show_tree(object ob, int indent);

int cmd_ilist(string str) {
    object ob;
    string file, *files;
    int deep_list, i, s;

    notify_fail(SYNTAX);
    if(!str)
        return 0;
    
    seteuid(geteuid(previous_object()));

    if(sscanf(str, "-R %s", file))
        deep_list = 1;
    else if(sscanf(str, "-T %s", file))
        deep_list = 2;
    else 
        file = str;

    ob = ref_ob(file);

    if(!ob || !objectp(ob)) {
        notify_fail("Couldn't find object.\n");
        return 0;
        }

    write(wrap("Files inherited by " + dump_variable(ob)));
    if(!deep_list) files = inherit_list(ob);
    else if(deep_list == 1) files = deep_inherit_list(ob);
    else if(deep_list == 2) return show_tree(ob, 1);
    
    for(i = 0, s = sizeof(files); i < s; i ++)
        printf("     %d: %s\n", i + 1, files[i]);
    return 1;
    } // do_cmd


// show_tree()
int show_tree(object ob, int indent) {
    string *list;
    int i, s;
    object obj;

    s = sizeof(list = inherit_list(ob));
    if(!s) return 1;
    for(i = 0; i < s; i ++) {
        printf("%" + (indent * 4) + "s%d: %s\n", "", i + 1, list[i]);
        if(catch(call_other(list[i], "???"))) {
            write("Failed to load: " + list[i] + "\n");
            return 1;
            }
        obj = find_object(list[i]);
        show_tree(obj, indent + 1);
        }
    return 1;
    } // show_tree


int help(string str) {
    write(SYNTAX);
    write(@END

    Shows the files inherited by another file.  If the object is not loaded,
this command will not work.  Using the optional flag -R will show all files
inherited by this object.  If the flag -T is used, an inheritance tree will
be shown.

See also: ref, refs, call, move
END
        );
    return 1;
    } // do_help
