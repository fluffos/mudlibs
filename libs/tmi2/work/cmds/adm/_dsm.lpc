// File: /cmds/adm/_dsm.c
//  - front end to dump_prog()

#include <priv.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_dsm(string str) {
    object what;
    string *text;
    int i, j; 

    if (!str || str == "") {
        notify_fail("Dsm: What object do you want to dump/disassemble?\n");
        return 0;
    }

    str = lower_case(str);
    if (sscanf(str, "-v %s", str) == 1)
        j = 1;
 
    what = get_object(str);

    if (!what) {
       notify_fail("Dsm: Could not locate that object.\n");
       return 0;
    }

    dump_prog(what, 1);
    i = file_size("/PROG_DUMP");
    if (i > 0) {
        text = explode( read_file("/PROG_DUMP"), "\n");
        if (!j && (j = member_array(";;;  *** Disassembly ***", text)) != -1)
            text = text[j .. sizeof(text)];
        this_player()->more(text, 1);
    }
    return 1;
}

string help() {
    write( @ENDHELP
Syntax: dsm [-v] object

This command provides a disassembly of the specified object.  If the -v
option is given, a complete dump of the object is provided.
ENDHELP
    );
}
