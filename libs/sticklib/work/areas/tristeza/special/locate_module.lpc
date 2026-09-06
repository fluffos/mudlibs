// Note to me: unique map set up like this:
// "unique_filename" : ({ max_num, clones out })
#include <daemons.h>
void find_unique() {
    mapping u_list;
    string where, oshort, rndunique;
    object ob;
    int i, j;
    mixed *k, *l;
    u_list = UNIQUE_D->query_unique_list();
    rndunique = m_indices(u_list)[random(sizeof(m_indices(u_list)))];
    if(u_list[rndunique]) {
	l = UNIQUE_D->get_unique(rndunique);
	if(sizeof(l) >= 2) {
	    for(j=0;j<sizeof(l);j++) {
		if(objectp(l[j])) {
		    ob = l[j];
		    if(environment(ob)) {
			if(!where = environment(ob)->query_short())
			    if(!where = environment(ob)->query_real_name())
				where = "Private home";
		    }
		    if(!oshort = ob->query_short())
			if(!oshort = ob->query_name())
			    oshort = "Unknown Object";
		    this_player()->tell_me(
		      "You visualize "+oshort+" in your mind. "
		    );
		    if(oshort)
			this_player()->tell_me(
			  "You believe it is in ... \n"+
			  where+". \n"
			);
		}
	    }
	}
    }
}
