#include "../../priest.h"

status
update_symbols_cmd(object who, object sym, string str) {
    object *players, pl, ob;
    int i, n;

    if(!who->query_coder_level())
	return 0;

    players = users();
    i=sizeof(players);
    while(--i>=0) {
	pl = players[i];
	if(pl && (pl->query_guild_object_name() == PRIEST_SYMBOL)) {
	    ob = pl->query_guild_object();
	    pl->set_guild_save(ob->query_guild_save());
	    destruct(ob);
	    pl->initialize_guild();
	    //            pl->tell_me("Your guild object is updated.");
	    // let's not tell the players... why should they know this anyway?
	    n++;
	}
    }
    who->tell_me(sprintf("%d symbols updated.",n));
    return 1;
}
