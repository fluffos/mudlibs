//  Plague Device.

#include <std.h>
inherit OBJECT;

int time_out;

void create() {
    ::create();
    set_name("");
    set_short("");
    set_id(({ "plague_obj" }));
    call_out("heart_beat", 4);
}

void init() {
   ::init();
   if(this_player()->is_player()) { remove_call_out("heart_beat"); call_out("heart_beat", 6);  }
}

mixed heart_beat() {
    int i;
    object *e;
    if(!environment()) { remove(); return 1; }
    if(!environment(this_object())->is_player()) { remove(); return 1; }
    if(!interactive(environment(this_object()))) {
       call_out("heart_beat", 20);
       return 1;
    }
    call_out("heart_beat", 6);
    if(random(2)) {
	if(!random(3))
	    if(random(2)) {
		message("", "You cough loudly.", environment(this_object()));
		message("", environment(this_object())->query_cap_name()+" coughs loudly.", 
		  environment(environment(this_object())), ({ environment(this_object()) }));
		environment(this_object())->damage(20);
	    } else {
		message("", "You dont feel so good.", environment(this_object()));
		message("", environment(this_object())->query_cap_name()+" doesnt look so good.", 
		  environment(environment(this_object())), ({ environment(this_object()) }));
		environment(this_object())->damage(15);
	    }
	i=sizeof(e=all_inventory(environment(environment(this_object()))));
	while(i--) {
	    if(!present("plague_obj", e[i]) && random(2) && e[i]->is_player()) {
		new("/std/obj/plague")->move(e[i]);
		message("", "You suddenly feel very hot.\nYou have been "
		  "infected with the %^MAGENTA%^%^BOLD%^plague%^RESET%^!", e[i]);
		message("", e[i]->query_cap_name()+" doesnt look so good.", environment(e[i]), ({ e[i] }));
	    }
	}
    }
    return;
}

string extra_look() {
    return environment(this_object())->query_cap_name()+" looks a little sick.\n";
}

int put() { return 0; }
int drop() { return 0; }

string query_long() {
    return "You shouldnt see this.  \nHB="+
    query_heart_beat(this_object())+". \nENV="+identify(environment(this_object()))
    +"\nTime_Out="+time_out;
}

