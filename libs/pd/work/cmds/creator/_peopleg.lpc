//  Whit
#include <daemons.h>
string align(int x, string what) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
	out = what[0..x-1] + " ";
	return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}


int cmd_peopleg() {
    int i;
    object *user;
    string ret;
    write("The following people are in a guild:\n");
    i = sizeof(user = users());
    ret = "User name:           Guild Name:         Position:\n";
    ret += "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    while(i--) {
	if(user[i]->query_guild()) {
	    if(user[i]->query_cap_name()=="A shadow") 
		ret += align(20, "("+user[i]->query_name()+")");
	    else ret += align(20, user[i]->query_cap_name());
	    ret += align(20, user[i]->query_guild());
	    if(GUILD_D->valid_master(user[i]->query_name())) 
		ret += align(10, "Master"); else
	    if(!user[i]->query_guild_position()) 
		align(10, "Cannot Find");
	    else ret += align(10, user[i]->query_guild_position());
	    ret += "\n";
	}
    }
    write(ret);
    return 1;
}

void help() {
    write("Syntax: <peopleg>");
    write("Usage: This will show the users online that are in guilds and "
      "what position they are.");
    write("\nNote:  If the position is master they are an immortal and "
      "should be removed.");
}

