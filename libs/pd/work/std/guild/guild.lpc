//  Guild inheritable

#include <guild.h>
#include <std.h>

inherit "/std/room";

void init() {
    string guild, tmp;
    ::init();
    if(!this_player()->is_player()) return;
    if(sscanf(file_name(this_object()), "/d/guilds/%s", tmp) != 1) return;
    if(sscanf(file_name(this_object()), "/d/guilds/%s/%s/%s", guild, tmp, tmp) != 3) sscanf(file_name(this_object()), "/d/guilds/%s/%s", guild, tmp);
    if(wizardp(this_player())) {
	write("You immortality allows you to step on these grounds.\n");
	return;
    }
    if(guild == "AoD") guild="aod";
    if(guild == "forsaken" || guild == "AoD") {
       if(this_player()->query_original_guild() != "forsaken" && this_player()->query_original_guild() != "aod" && !wizardp(this_player())) {
         message("", "You have unlawfully entered "+guild+".  You hereby are removed from here.", this_player());
       this_player()->move_player("/d/nopk/tirun/square", "away");
       write_file("/d/guilds/illegal_access", this_player()->query_name()+" entered "+guild+" on "+ctime(time())+".\n");
       }
    } else
       if(this_player()->query_original_guild() != guild && !wizardp(this_player())) {
	 message("", "You have unlawfully entered "+guild+".  You hereby are removed from here.", this_player());
       this_player()->move_player("/d/nopk/tirun/square", "away");
       write_file("/d/guilds/illegal_access", this_player()->query_name()+" entered "+guild+" on "+ctime(time())+".\n");
       }
}

