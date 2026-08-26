//Started by Shya 8-5-00 to be finished by Sophia how ever she wants.

#include <mudlib.h>
inherit OBJECT;

string owner;
string mate;
string expires;

void create ()
{
set("id",({"license","marriage license"}));
set("short","marriage license");
set("long","If you can see this please send a bug report to Shya.");
set("mass",0);
set ("prevent_drop", 1);
set ("prevent_insert", 1);
set ("prevent_move", 1);
set ("prevent_clean", 1);
set ("prevent_pull", 1);
set ("prevent_give", 1);
}

int query_auto_load() {
return 1;
}

// Call this after cloning, with the bride and groom player objects as parameters.
// And before moving the object into the puchaser's inventory.
void set_long(string o, string m)
{
	owner = tolower(o);
	mate = tolower(m);
	set("long", "This license entitles "
		+ capitalize(owner)
		+ " to marry "
		+ capitalize(mate)
		+ ".\n"
		+ "This license expires on "
		+ capitalize(expires);
		+ ".\n");
}

void init(){
if (expires != "") {
	if (expires <= the current time) {
		dest();
		say("You marriage license has expired and crumbles to dust.\n");
		return;
	}
} else {
	expires = today() ;// plus 14 days
}

	add_action("begin_func", "begin");
	add_action("revoke_func", "revoke");
}


int begin_func(string str) {
	object priest_obj;
	object mate_obj;
	object mate_license_obj;
	object recorder_obj;

	if (str != "ceremony") return 0;
	priest_obj = present(enviroment(TP), "priest");
	if (priest_obj)
		mate_obj = present(environment(TP), mate);
		if (mate_obj) {
		    recorder_obj = clone("recorder");
		    if (recorder_obj) {
		        recorder_obj->do_married(today());
			  recorder_obj->dest();
		    } else {
			  say("Please report marriage license bug #1 to Shya.\n");
		    }
		    priest->do_ceremony();
		    mate_license_obj = present(mate_obj, "license");
		    if (mate_license_obj) {
		        mate_license_obj->dest();
		    }
		    dest();
		} else {
		    say ("You fiancee does not seem to be present.\n"
			   "The ceremony cannot begin.\n");
		    return 1;
		}
	} else {
	    say("The priest does not appear to be present.\n"
		  "The ceremony cannot begin without him.\n");
	    return 1;
	}
}



int revoke_func(string str) {
	object mate_obj;
	object mate_license_obj;
	object recorder_obj;

	if (str != "license") return 0;
	recorder_obj = present(enviroment(TP), "recorder");
	if (recorder_obj)
		mate_obj = present(environment(TP), mate);
		if (mate_obj) {
		    recorder_obj->do_revoked(today());
		    mate_license_obj = present(mate_obj, "license");
		    if (mate_license_obj) {
		        mate_license_obj->dest();
		    }
		    dest();
		} else {
		    say ("You fiancee does not seem to be present.\n"
			   "Your marriage license cannot be revoked.\n");
		    return 1;
		}
	} else {
	    say("The recorder does not appear to be present.\n"
			   "Your marriage license cannot be revoked.\n");
	    return 1;
	}
}
