#include <textdraw.h>

string query_verb(string str) {
   return "whisper";
}

int main(string str) {
    int i, verbphr, indent;
    object ob, targ, *list;
    string a, b;
    string accent, verb, prep;

    if(!str) {
	notify_fail("What would you like to whisper? Use 'whisper " +
                    "to <name> <message>'\n");
	return 0;
    }

    if (str[0] == ' ' && str[1] != ' ')
	str = str[1..];

    str = recolor( str );

    if( accent = this_player()->query_env_var("accent") ) {
	if( !(ob = find_object(accent)) )
	    catch(ob = load_object(accent));
	if( ob )
	    str = ob->garble(str);
    }

    if ( sscanf(str, "to %s %s", a, b) || sscanf(str, "%s: %s", a, b) ) {
	if( (list = all_present(a, environment(this_player()))) &&
             list[0]->query_is_living() ) {
	    targ = list[0];
	    str = b;
	}
    }


    // a toaded player sees their whisper, no one else does
    if ( this_player()->query_toad() ) {
	if(!environment(this_player())) return 0;
	verb = query_verb(str);
	set_actor(this_player());
        set_listener(this_player());
        msg( "~CLABYou "+verb+"~CDEF: "+str, strlen(verb) + 3 );
        this_player()->add_say("You", str);
        return 1;
    }

    if ( !targ ) {
       	notify_fail("What would you like to whisper to whom? Use 'whisper " +
                    "to <name> <message>'\n");
	return 0;
    }
    else {
	set_target( targ );
	verb = query_verb(str);
	((verb == "ask")?prep="":prep="to ");
	verbphr = strlen(verb) + strlen(prep);

	set_actor( this_player() );
	set_target( targ );
	foreach( ob : all_inventory(environment(this_player())) -
                      ({ query_target(), this_player() }) ) {
	    if( this_player()->query_invis() && !(ob == this_player() ||
                !ob->query_is_living() || ob->query_level() < WIZLEVEL) ) {
               continue;
            }
	    set_listener(ob);
	    indent = strlen(this_player()->query_name()) + verbphr +
                     strlen(targ->query_name()) + 5;
	    if ( indent > 15 ) indent = 15;
	    msg_object(ob, "~CLAB~Name "+verb+"s "+prep+"~targ~CDEF.",
                           indent, this_object() );
	}

	set_actor( this_player() );
	set_target( targ );
	set_listener(targ);
	indent = strlen(this_player()->query_name()) + verbphr + 8;
	if ( indent > 15 ) indent = 15;
	if ( query_actor() != query_target() )
	    msg_object( query_target(), "~CLAB~Name "+verb+"s "+prep+"you~CDEF: " + str, indent );
	query_target()->add_say(this_player()->query_cap_name()+" to you", str);

	set_actor( this_player() );
	set_target( targ );
	indent = verbphr + strlen(targ->query_name()) + 7;
	if ( indent > 15 ) indent = 15;
	set_listener( this_player() );
	msg( "~CLABYou "+verb+" "+prep+"~targ~CDEF: " + str, indent );
	this_player()->add_say("You to "+query_target()->query_cap_name(), str);

	foreach( ob : all_inventory(environment(this_player())) - ({ this_player() }))
	ob->on_talk( str, this_player(), targ );

	if ( query_target()->query_afk() ) {
	    set_actor( query_target() );
	    query_target()->msg_local( "~CLAB~Npos AFK message~CDEF: " + query_target()->query_afk() );
	}
    }

    return 1;
}
