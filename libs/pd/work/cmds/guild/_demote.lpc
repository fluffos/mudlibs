//  Guild System Version 4
//  Created by Whit

#include <daemons.h>
#include <guild.h>

int cmd_demote(string str) {
    int override;
    string pos, g, g2;
    object user;
   if(GUILD_D->query_locked() && !wizardp(this_player())) return 
     notify_fail(GUILD_D->query_lock_reason());
    if(!this_player()->query_guild()) return 0;
    if(!str) return notify_fail("Demote who?\n");
    g=GUILD_D->query_guild(this_player()->query_name());
    g2=GUILD_D->query_guild(str);
    if(!GUILD_D->check_rights(this_player()->query_name(), g, 
        ({ "leader" }) )) 
        return notify_fail("You are not permitted to do that.\n");

    pos = GUILD_D->query_actual_position(str=lower_case(str));
    if(pos == "none") return notify_fail("They are not part of your guild.\n");
    if(g2!=g) return notify_fail("They are not part of your guild.\n");
    switch(pos) {
    case "main": 
        write("You may not demote them!\n");
        if(find_player(str)) tell_object(find_player(str),
              this_player()->query_cap_name()+" attempted to demote you!\n");
        override=1;
        break;
    case "squire":
        write("They are at the lowest position possible.\n");
        override=1;
        break;
    case "leader":
        GUILD_D->promote(str, "council");
        write("You demote "+capitalize(str)+" to "+GUILD_D->query_position_name(g,"council")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"council")+".");
        break;
    case "council":
        GUILD_D->promote(str, "member");
        write("You demote "+capitalize(str)+" to "+GUILD_D->query_position_name(g,"member")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"member")+".");
        break;
    case "member":
        GUILD_D->promote(str, "squire");
        write("You demote "+capitalize(str)+" to "+GUILD_D->query_position_name(g, "squire")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"squire")+".");
        break;
    default: 
        write("Unknown positions: "+pos+"\n");
        override=1;
        break;
    }
    if(!override) write_file("/d/guilds/progress.log", this_player()->query_name()+
          " : (demote) "+str+" in "+g+" ("+GUILD_D->query_actual_position(str)+")\n");
    if(!override) write_file("/d/guilds/data/progress/"+g, this_player()->query_cap_name()+
          " %^RED%^%^BOLD%^demoted%^RESET%^ "+str+" to "+GUILD_D->query_actual_position(str)+" on "+ctime(time())+".\n");

    return 1;
}

void help() {
    write("Syntax: <demote [member]>\n");
    write("Usage:  This will demote a member to a lower rank "
      "in your guild.\nPosition: leader\n");
}

