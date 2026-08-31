#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Forsaken Mist Room");
    set_short("Forsaken Mist Room");
    set_long("The atmosphere of this small room is somewhat darker than "
      "that of the rest of the guild. The walls seem to "
      "multiple shades of black and red simultaneously, and are "
      "accompanied by the otherworldly light of a large intense "
      "black fire in the center of the room. The fire is surrounded "
      "by a circle of glowing arcane runes, and emits a swirling, "
      "almost living azure smoke.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );
    set_exits(([
	"down" : "/d/guilds/forsaken/room1",
      ]));
    set_items( ([
	"fire" : "view <person>"
      ]) );
}

void init() {
    ::init();
    add_action("view", "view");
}
int view(string str) {
    object ob;
    int i;  
    object *inv;
    string desc;

    if(!str) 
    {
	notify_fail("View who?\n");
	return 0;
    } 
    ob = find_living(str);
    if(!ob || !ob->is_player()) 
    {
	notify_fail("You see only mist in your mind's eye.\n");
	return 0;
    }
    if(environment(ob)->query_property("no scry") || environment(ob)->query_property("no teleport"))
    {
	notify_fail("The smoke blocks your view.\n");
	return 0;
    }
    if(wizardp(ob)) 
    {
	notify_fail("The smoke blocks your view.\n");
	return 0;
    }     
    write("Through the mists of other dimensions you see:\n");
    ob = environment(ob);
    if (!ob) write("An empty void.");  
    else
    {
	desc = (string)ob->query_long()+"\n";  
	inv = all_inventory(ob);
	for (i=0;i<sizeof(inv);i++) {
	    if(inv[i]->query_invis()) continue;
	    desc += inv[i]->query_short()+"\n";
	}
	write(desc);  
    }
    return 1;
}
