#include <sys/regexp.h>
#include <saveload.h>
inherit "/ai/module";

string *messages;

string *query_messages() { return messages; }
void add_message(string txt) {
	if( !messages || !pointerp(messages) )
		messages = ({});
	messages += ({ txt });
}
void set_messages(string *txt) { messages = txt; }

string query_module_name() {
	return "crier";
}

void on_sight( object ob, object source ) {
	if( ob == environment(this_object()) )
		return;
	call_out( "do_greet", 2+random(4), ob );
}

void do_greet( object who ) {
	object mob = environment(this_object());
	if( !mob->query_recognize(who) ) {
		//command( "bow "+who->query_name(), mob );
		call_out( "do_cry", 2+random(4), who );
	}	
}

varargs void do_cry( object who ) {
	string buf;
   	if( !sizeof(messages) ) {
		buf = "Oh Yay! Oh Yay! I've forgotten what to say!";
	} else {
		int k = random(sizeof(messages));
		buf = messages[k];
	}
	if( who )
		buf = "say " + who->query_name() + ": " + buf + "!";
	else
		buf = "say " + buf + "!";
	command( buf, environment(this_object()) );
}
