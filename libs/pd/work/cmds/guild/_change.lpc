//  Guild System 4
//  Whit

#include <daemons.h>
#include <guild.h>

int help();

int list(string g) {
    write("Listing Positions: \n");
    write("%^BOLD%^%^BLUE%^Leader%^RESET%^: "+
      GUILD_D->query_position_name(g,"leader"));
    write("\n%^BOLD%^%^RED%^Council%^RESET%^: "+
      GUILD_D->query_position_name(g,"council"));
    write("\n%^BOLD%^Member%^RESET%^: "+
      GUILD_D->query_position_name(g,"member"));
    write("\n%^BOLD%^%^GREEN%^Squire%^RESET%^: "+
      GUILD_D->query_position_name(g,"squire")+"\n");
    return 1;
}

int cmd_change(string str) {
    string guild, pos, name;
    if(!this_player()->query_guild()) return 0;
    guild=GUILD_D->query_guild(this_player()->query_name());
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

    if(!str) return help();
    if(GUILD_D->query_actual_position(this_player()->query_name())!="main" &&
      !GUILD_D->valid_master(this_player()->query_name()))
        return 0;
    if(str == "list") return list(guild);
    if(sscanf(str, "%s to %s", pos, name) != 2) return notify_fail("Syntax: "
          "<change [position] [name]>\n");
    pos=lower_case(pos);
    if(member_array(pos, VALID_POSITIONS) == -1) return 
        notify_fail("Unknown position: "+pos+".\n");
    if(strlen(name) > 17) return notify_fail("Name exceeds the maximum "
          "amount for a position name.  Max=17\n");
    name=TERMINAL_D->no_colours(name);
    write("The position "+pos+"'s name has been changed to "+name+".\n");
    GUILD_D->set_position_name(guild, pos, name);
    write_file("/d/guilds/change.log", 
      capitalize(this_player()->query_name())+" changed Pos: "+pos+" to "
      ""+name+". "+ctime(time())+"\n");
    return 1;
}

int help() {
    write("Syntax: <change [position] to [name]> or <change list>\n");
    write(@TEXT
Usage: 
The valid positions are:
   Squire,  Member, Council, and Leader.

This command will change the name of a position in 
your guild.  If you use "list" as the argument, it
will show you a list of the current settings.

Position: Owner

TEXT);   
    return 1;
}

