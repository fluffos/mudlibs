//ed.c

//Byre @ LPUniversity
//05-APR-05
//File editor

//Last edited on October 6th, 2006 by Tacitus

#include <logs.h>

int main(string file)
{
    if (!file) 
    {
        if(!this_player()->query("cwf"))
            return notify_fail("Error [ed]: No argument supplied.\n");
        file = this_player()->query("cwf");
    }

    file=resolve_path(this_player()->query("cwd"),file);
    this_player()->set("cwf", file);

    if(directory_exists(file)) 
    return notify_fail("Error: Can not edit a directory.\n");

    write(file + "\n");
    ed(file);
    log_file(LOG_ED, capitalize(query_privs(this_player())) + " edited " + file 
        + " on " + ctime(time()) + "\n");
    return 1;
}
string help() {
    return (HIW + " SYNTAX: " + NOR + "ed <file>\n\n" +
    "This command lets you edit a specified file in the mud editor. To\n"
    "access editor specific help, type 'h' while in the editor.\n\n" + 
    HIW + " See also: " + NOR + "rm, more, mv, cp, etc.\n");
}
