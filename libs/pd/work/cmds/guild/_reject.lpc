//  Guild System 4
//  Whit

#include <guild.h>
#include <daemons.h>

int cmd_reject(string str) {
    object ob;
    string guild, guild2;
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
	notify_fail(GUILD_D->query_lock_reason());

    if(!this_player()->query_guild()) return 0;
    guild=GUILD_D->query_guild(this_player()->query_name());
    if(!str) return notify_fail("Reject who?\n");
    str=lower_case(str);
    if(this_player()->query_name() == str) return 
	notify_fail("You may not reject yourself.  Use <resign> instead.\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), guild, ({"council",
	  "leader"}) ))
	return notify_fail("You are not permitted to do that!\n");
    guild2=GUILD_D->query_guild(str);
    if(guild2!=guild) return notify_fail("You may only reject those "
	  "in your guild.\n");
    if(GUILD_D->query_actual_position(str)=="main") return notify_fail("You cannot "
	  "remove the owner of the guild!\n");
    if(GUILD_D->query_position(str) == "leader" && 
      GUILD_D->query_position(this_player()->query_name()) == "council" 
      && this_player()->query_guild_position() != "master") return 
	notify_fail("You may not reject someone out-ranking you.\n");
    if(GUILD_D->query_position(this_player()->query_name()) == "council")
	if(!find_player(str)) return notify_fail("You are not allowed "
	      "to reject offline players.\n");
    write("You reject "+capitalize(str)+" from your guild.\n");
    if(ob=find_player(str)) tell_object(ob, "You have been rejected from "+
	  guild+".\n");
    if(find_player(str)) find_player(str)->set_guild();
    GUILD_D->remove_player(str, guild2);
    if(find_player(str)) find_player(str)->register_channels();
    write_file("/d/guilds/data/progress/"+guild, this_player()->query_cap_name()+
      " %^BOLD%^%^RED%^rejected%^RESET%^ "+str+" on "+ctime(time())+".\n");
    return 1;
}

void help() {
    write("Syntax: <reject [player]>\n");
    write("Usage:  This will remove a player from your guild.");
    write("Position: Council, Leader\n");
}

