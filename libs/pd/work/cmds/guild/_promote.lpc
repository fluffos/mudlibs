//  Guild System Version 4
//  Created by Whit

#include <daemons.h>
#include <guild.h>

int Pcheck(object);
    string *squire, *member, *council, *leader;
int cmd_promote(string str) {
    string pos, g, g2;
    object user;
    int o;
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

    if(!str) return notify_fail("Promote who?\n");
    g2=GUILD_D->query_guild(this_player()->query_name());
    if(!GUILD_D->check_rights(this_player()->query_name(), 
        g2, ({ "leader" }) )) 
        return notify_fail("You are not permitted to do that.\n");

    pos = GUILD_D->query_actual_position(lower_case(str));
    g=this_player()->query_guild();
    if(GUILD_D->query_guild(str) != g2) return notify_fail("They are "
          "not part of your guild.\n");
    if(pos == "none") return notify_fail("They are not part of your guild.\n");
    switch(pos) {
    case "leader":
        write("They are at the highest position possible.\n");
        o=1;
        break;
    case "council":
        //if(!Pcheck(this_player())) return notify_fail("You can not have that many leaders.\n");
        GUILD_D->promote(str, "leader");
        write("You promote "+capitalize(str)+" to "+GUILD_D->query_position_name(g,"leader")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"leader")+".");
        break;
    case "member":
        GUILD_D->promote(str, "council");
        write("You promote "+capitalize(str)+" to "+GUILD_D->query_position_name(g,"council")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"council")+".");
        break;
    case "squire":
        GUILD_D->promote(str, "member");
        write("You promote "+capitalize(str)+" to "+GUILD_D->query_position_name(g, "member")+".\n");
        if(user = find_player(lower_case(str))) tell_object(user, "You "
              "have been promoted to "+GUILD_D->query_position_name(g,"member")+".");
        break;
    default: 
        write("Unknown positions: "+pos+"\n");
        o=1;
        break;
    }
    if(!o) write_file("/d/guilds/progress.log", this_player()->query_name()+
          " : (promote) "+str+" to "+GUILD_D->query_actual_position(str)+" ("+g2+")\n");
    if(!o) write_file("/d/guilds/data/progress/"+g2, this_player()->query_cap_name()+
          " %^BOLD%^%^GREEN%^promoted%^RESET%^ "+str+" to "+GUILD_D->query_actual_position(str)+" on "+ctime(time())+".\n");
    return 1;
}

int Pcheck(object tp) {

    string g;

    int all = 0;
    
    g=GUILD_D->query_guild(tp->query_name());
    
    restore_object(SAVE+g);
    
    all = sizeof(leader);
    if(all > 1)
      return 0;   
    return 1;
}
void help() {
   write("Syntax: <promote [member]>\n");
    write("Usage:  This will promote a member to a higher rank "
      "in your guild.\nPosition: leader\n");
}

