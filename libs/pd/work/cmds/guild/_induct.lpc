//  Guild System 4
//  Whit
// changed by Daboura to limit number of people in the guild
#include <guild.h>
#include <daemons.h>
#define GUILDCAP 12

int guild_size(object);
    string *squire, *member, *council, *leader;

int cmd_induct(string str) {
    object ob;
    string guild, g2;
    
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());
    
    if(!this_player()->query_guild()) return 0;
    
    guild=this_player()->query_guild();
    g2 = GUILD_D->query_guild(this_player()->query_name());
    
    if(!str) return notify_fail("Induct who?\n");
    
    str=lower_case(str);
    
/*
    if(guild_size(this_player()) >= GUILDCAP)
    {
        return notify_fail("Your guild is full.\n");
    }
*/
    
    if(!GUILD_D->check_rights(this_player()->query_name(), 
        g2, ({"council", "leader"}) ))
        return notify_fail("You are not permitted to do that!\n");
    
    if(!ob=find_player(str)) return notify_fail("No such person in this reality.\n");
    
    if(ob->query_guild() == this_player()->query_guild()) return
        notify_fail("They are already part of your guild.\n");
    
    if(ob->query_guild()) return notify_fail("You may only induct those "
          "without affiliation!\n");
    
    write("You induct "+ob->query_cap_name()+" into your guild.\n");
    tell_object(ob, "You have been inducted into "+guild+".\n");
    
    ob->set_guild(g2);
    ob->register_channels();
    
    write_file("/d/guilds/progress.log", this_player()->query_name()+" : "
      "(induct) "+str+" in "+g2+".\n");
    
    write_file("/d/guilds/data/progress/"+g2, this_player()->query_cap_name()+" inducted "
      ""+str+" on "+ctime(time())+".\n");

    ob->add_search_path("/cmds/guild");
    return 1;
}

int guild_size(object tp) {
    string g;

    int all = 0;
    
    g=GUILD_D->query_guild(tp->query_name());
    
    restore_object(SAVE+g);
    
    all = sizeof(leader);
    all += sizeof(council);
    all += sizeof(member);
    all += sizeof(squire);
    
    return all;
}

void help() {
    write("Syntax: <induct [player]>\n");
    write("Usage:  This will add a player to your guild.");
    write("Position: Council, Leader\n");
}

