//  Weapon Fixer
//  Whit

#include <std.h>
inherit MONSTER;

int guard;

void create() {
    ::create();
    set_name("a man");
    set_short("fixer of weapons");
    set_long("I dunno,  <fix [weapon]>.\n");
    set_id(({ "man", "a man", "fixer", "fixer of weapons" }));
}

void init() {
    ::init();
    add_action("fix_weapon", "fix");
}

int force(string str) {
    this_object()->force_me(str);
    return 1;
}

int fix_weapon(string str) {
    object ob, ob2;
    int ac, oac, x;
    string fname;
    if(this_player()->query_recent_outlaw()) {
	force("say Aha!  Call the guards!  The criminal "+
	  this_player()->query_cap_name()+" is here!");
	if(!guard) new("/d/tirun/obj/mon/townguard")->move(environment(this_object()));
	message("", "%^BOLD%^%^GREEN%^The guard enters.%^RESET%^", environment(this_object()));
	call_out("remove_guard", 5);
	guard=1;
	return 1;
    }
    if(!str) return force("say What weapon would you like me "
	  "to fix?");
    if(!ob = present(str, this_player())) return force("say You do "
	  "not have that!");
    if(!ob->is_weapon()) return force("say That is not a weapon!");
    if(ob->query_wielded()) return force("say Unwield your weapon "
	  "first!");
    fname = base_name(ob);
    ac = ob->query_wc();
    oac = ob->query_original_wc();
    if(ac==oac) return force("say There is no need to repair that weapon!");
    x = oac-ac;
    x = x*100;
    if(this_player()->query_money("gold") < x) return 
	force("say It will cost you "+x+" gold peices of which you don't "
	  "have!");
    ob2 = new(fname);
    if(!ob2) return force_me("say I cant seem to repair your weapon!");
    force("say Here is your repaired "+ob2->query_short()+"!");
    ob2->move(this_object());
    force("give "+ob2->query_name()+" to "+this_player()->query_name());
    this_player()->add_money("gold", -x);
    ob->move("/d/standard/void");
    ob->remove();
    return 1;
}

int remove_guard() {
    object ob;
    if(ob=present("guard")) {
	present("guard")->force_me("say Criminals these days,  they think "
	  "they can get away with anything!");
	message("", "%^BOLD%^%^GREEN%^The guard leaves west.%^RESET%^", environment(this_object()));
	ob->move("/d/standard/void");
	ob->remove();
    }
    guard=0;
}

