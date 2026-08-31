/*    /cmds/system/_cat.c
 *    from Nightmare Mudlib 3.2
 *    command to display file contents
 *    created by Descartes of Borg 940124
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_cat(string str) {
    string tmp;
    int max, a=0;

    if(!str) return notify_fail("Usage: <cat [file]>\n");
    str = resolv_path((string)this_player()->get_path(), str);
    seteuid(geteuid(previous_object()));
//    if(!(max = sizeof(lines=explode(read_file(str), "\n")))) 
//     return notify_fail("File not found.\n");
// if(!(tmp = read_file(str))) return notify_fail("File not found.\n");
  if ((max = file_size(str)) < 0) return notify_fail("File not found.\n");
     for (a = 0; a < max; a += 1025)
     {
        if( max - a < 1024 )
            tmp = read_bytes(str, a, max - a);
        else
            tmp = read_bytes(str, a, 1024);
        write(tmp);
     } 
    seteuid(getuid());
    IMSTAT_D->add_stat(this_player()->query_name(), "cat", time());

    return 1;
}

int help() {
    message("help", "Syntax: <cat [file]>\n\n"
      "Displays the contents of the file mentioned all ate once.",
      this_player());
}
