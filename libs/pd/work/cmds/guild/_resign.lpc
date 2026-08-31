//  Guild System Version 3
//  Created by Whit
//  /doc/guild/readme
#include <daemons.h>
#include <guild.h>

int cmd_resign() {
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

    if(!this_player()->query_guild()) return 0;
    if(GUILD_D->query_actual_position(this_player()->query_name())=="main") {
        write("You are not allowed to resign.\n");
        return 1;
    }
    write("You resign from your guild.\n");
    write_file("/d/guilds/progress.log", 
      this_player()->query_cap_name()+" : (resign) "+
      this_player()->query_guild()+"\n");
    write_file("/d/guilds/data/progress/"+this_player()->query_original_guild(), 
      this_player()->query_cap_name()+" %^BOLD%^%^RED%^resigned%^RESET%^ on "+ctime(time())+
      ".\n");

    GUILD_D->remove_player(this_player()->query_name(), 
      GUILD_D->query_guild(this_player()->query_name()));
    this_player()->register_channels();
    return 1;
}
void help() {
    write(@TEXT
Syntax: <resign>
Usage:  This will remove you from your guild.
Position: squire, member, council, leader
TEXT);
}

