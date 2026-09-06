inherit "/ai/module";

nosave object master;
string master_name;

object query_master_ob() {
   if( master ) return master;
   else return master = find_player(master_name);
}

void set_master( string x ) {
   master_name = x;
}

string query_master() {
   return master_name;
}

void on_depart( object who, string moveverb, string direction, object destination ) {
   debug("on_depart " + moveverb);
   if( who == query_master_ob() ) {
      say( "My master is leaving! I ought to follow.");
   }
}