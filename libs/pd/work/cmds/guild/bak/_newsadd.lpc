//  Guild System 3
//  Whit
//  This will add a news to the login news.

#include <guild.h>
#include <daemons.h>

int cmd_newsadd(string str) {
    string file;
    file = "/d/guilds/data/news/"+this_player()->query_guild();
    if(this_player()->query_guild_position() != "main" && !wizardp(this_player())) return 
	notify_fail("You are not permitted to do that.\n");
    if(!str) {
	if(file_exists(file)) {
	    rm(file);      
	    write("News erased.\n");
	    return 1;
	}
	write("There is currently no news.\n");
	return 1;
    }
    write("News updated.\n");
    if(file_exists(file)) 
	rm(file);
    write_file(file, str);
    return 1;
}

void help() {
    write("Syntax: <newsadd [what]>\nWhatever [what] is will be "
      "shown to members of your guild at startup.  If there is no [what]"
      " then the current news will be erased.\n\nPostion: Owner\n");
}

