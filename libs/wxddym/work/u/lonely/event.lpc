/*
* $Revision: 1.3 $
* $Date: 2004/05/10 14:30:46 $
* 
* Purpose: Manage global events
* 
*/

#pragma no_inherit
#pragma no_shadow
#pragma no_clone

nosave mapping global_events; 

void add_event( string name );

void create() {
global_events = ([ ]);
add_event("player_login");
add_event("player_logout");
add_event("new_player");
}

mapping query_events() {
    return copy(global_events);
}

void add_event( string name ) {
if( global_events == 0 )
  global_events = ([ ]);
global_events[name] = ({ });
}

void remove_event( string name ) {
global_events[name] = 0;
}

void subscribe_event( string name ) {
if(!global_events[name])
    add_event(name);
global_events[name] -= ({ previous_object() });
global_events[name] += ({ previous_object() });
}

varargs void unsubscribe_event( string name, object ob ) {
if(ob)
      global_events[name] -= ({ ob });
else 
      global_events[name] -= ({ previous_object() });
}

varargs void event( string name, varargs mixed *args ) {

filter(global_events[name], (: find_object(object_name($1)) :) );

if(!global_events[name])
    return;

foreach( object ob : global_events[name] ) {
      call_other( ob, "event_" + name, args );
}
}
