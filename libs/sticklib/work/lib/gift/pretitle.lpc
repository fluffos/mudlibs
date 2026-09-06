// Simple little object to create customized pretitles for players.
// By Bull in September, 1997
//
// Usage: Clone this object to the player, call the function set_pretitle
//        with the new pretitle as a parameter and we should be all set.
//
// NOTE:  These babies WILL cost a LOT!
//        == 1 million to buy the object + 100 000 per one letter in pretitle.

#include "/sys/object_info.h"

#include <treasure.h>
#define TIT_SHADOW "/lib/gift/title_shadow"

object title_shadow;
string pretit;
int    mode;

void create_treasure() {
    set_name("Title tool");
    set_id(({"tool","titletool", "title tool"}));
    set_short("Tiny title tool");
    set_long("It seems to be a tiny title tool.\n"+
      "Command \"pretitle\" toggles your pretitle on/off.");
    mode   = 0;
    pretit = "Pinhead";
    return;
}

void init_treasure() {
    add_action("titleshadow", "pretitle");
}

// A coder needs to call this function in order to customize the object.
// (The title must be bought and is not freely configurable, and this
//  prevents us from having obscene/offensive titles around.)

status set_pretitle( string pret ) {
    if(pret) { pretit = pret; return 1; }
    return 0;
}

status titleshadow() {
    object ob, shd;

    ob = this_player();
    if(!title_shadow) {
	if((int)ob->query_coder_level() > 0)
	    ob->force_us("allowshadow YES");

	// Just to be sure...
	shd = ob;
	while(shd=object_info(ob, OI_SHADOW_PREV)) {
	    if(strstr(object_name(shd),"lib/gift/title_shadow")!=-1) shd->end_shadow();
	    else break; // if it wasn't another title_shadow, we had an infinite loop!
	    // Chopin
	}

	title_shadow = clone_object(TIT_SHADOW);
	title_shadow->do_shadow(ob, pretit, 0);
	if((int)ob->query_coder_level() > 0)
	    ob->force_us("allowshadow NO");
	ob->tell_me("You turn your personal pretitle on.");
    }
    else {
	title_shadow->end_shadow();
	title_shadow = 0;

	shd = ob;
	while(shd=object_info(ob, OI_SHADOW_PREV)) {
	    if(strstr(object_name(shd),"lib/gift/title_shadow")!=-1) shd->end_shadow(); 
	    else break;
	}

	ob->tell_me("You turn your personal pretitle off.");
    }
    return 1;
}

string query_auto_load() {
    int    dummy;
    string chainname;
    status active;

    if(title_shadow) active = 1;
    else             active = 0;

    sscanf(object_name(this_object()),"%s#%d",chainname,dummy);

    return chainname+":"+pretit+"#"+active+"#"+mode;
}

void init_arg(string arg) {
    string v;
    int t;
    status u;

    sscanf(arg,"%s#%d#%d", v, u, t);
    pretit = v;
    mode   = t;
    if(u) {
	// This will not work for coders..
	call_out( "pass_along", 1, pretit, mode );
    }
}

void pass_along( string pretit, int mode ) {
    title_shadow = clone_object(TIT_SHADOW);
    title_shadow->do_shadow(environment(this_object()), pretit, mode);
}

int get() { return 1; }

int drop() { return 1; }
