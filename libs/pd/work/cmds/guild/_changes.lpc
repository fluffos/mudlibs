//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>
int cmd_changes(string str) {
    string *f, path;
    int i;
    path="/d/guilds/data/progress/"+this_player()->query_original_guild();
    if(!file_exists(path)) return notify_fail("There are no recorded roster changes.\n");
    f=explode(read_file(path), "\n");
    i=sizeof(f);
    while(i--) {
       write_file("/tmp/changes", f[i]+"\n");
    }
    this_player()->more("/tmp/changes");
    rm("/tmp/changes");
    return 1;
}
void help() {
    write(@TEXT
Syntax: <changes>
Usage:  This will show you a log of all roster changes.
Position: leader
TEXT);
}

