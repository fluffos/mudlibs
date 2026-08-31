//  Keep Room Inherits
//  Must set_property("keep", 1); for this to work
inherit "/std/room";
string long;
void set_long(string str) { long=str; }
string query_long() {
    if(!this_object()->query_property("keep")) return long;
    if(!present("keep_orb", this_player())) 
	return "A strange magical force seems to be emitting "
	"around everything here.  Darkness seems to cover "
	"everything preventing you from seeing anything.";
    else return long;
}
string *query_long_exits() {
    if(!this_object()->query_property("keep")) return ::query_long_exits();
    if(!present("keep_orb", this_player())) return 0;
    return ::query_long_exits();
}
