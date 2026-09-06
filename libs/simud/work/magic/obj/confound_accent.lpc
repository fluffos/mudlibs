#include <object.h>

#define V ({ 'a', 'e', 'i', 'o', 'u', 'w', 'y' })
#define C ({ 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z' })

int duration;
int original_duration;

string query_name() {
	return "confound_object";
}

int query_degree() {
	int x = 100 * duration / original_duration;
	if ( x > 50 )
		x = 100 - x;
	if ( x < 10 )
		return 10;
	if ( x < 40)
		return (x-10) * 3 + 10;
	return 100;
}

void set_duration(int x) {
	original_duration = duration = x;
}

void set_victim(object who) {
	move(who);
	who->set_env_var("accent",explode(object_name(),"#")[0]);
	call_out("do_tick",2);
}

void do_tick() {
	remove_call_out("do_tick");
	duration -= 2;
	if( duration < 1 ) {
		destruct(this_object());
	} else {
		if( random(1000) < query_degree() ) {
			string *msgs = ({ "Your mind is clouded.",
							  "You feel confused.",
							  "You are having trouble remembering things.",
							  "You have the feeling that you just forgot something.",
							  "You are confused.",
							  "You can't remember..." });
			msg_object(environment(this_object()), msgs[random(sizeof(msgs))] );
		}
	}
	call_out("do_tick",2);
}

string destructor( object ob ) {
	msg_object(environment(this_object()), "~CBRTYour mind has become clear again.~CDEF");
	environment(this_object())->remove_env_var("accent");
	return 0;
}

string garble(string arg) {
	string out = "";
	object ob = present_clone(this_object(), this_player());
	int x, degree = 100;

	if( !ob )
		debug(this_player()->query_name()+" is garbled.","magic");
	else
		degree = ob->query_degree();
		
	foreach( x in lower_case(arg) ) {
		if( random(100) > degree ) {
			out += to_string( ({ x }) );
			continue;
		}
		if( member(V, x) != -1 )
			out += to_string( ({ V[random(7)] }) );
		else if( member(C, x) != -1 )
			out += to_string( ({ C[random(19)] }) );
		else if( out[<1] != ' ' )
			out += " ";
	}
	
	return out;
}
