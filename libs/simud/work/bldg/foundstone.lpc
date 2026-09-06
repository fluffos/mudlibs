#include <const/cityconst.h>
#include <shape.h>
inherit "/econ/building";

// there is deliberately no set_ method for city_name, so that
// it can't get out-of-sync with the city daemon
string city_name;
// ANYONE CAUGHT ACCESSING voters DIRECTLY GETS BEAT
// See query_voters() for why -- needs to check for new/missing buildings
protected mapping voters = ([ ]);

#define NO_VOTE		0
#define VOTE_AYE	1
#define VOTE_NAY	2

NAME( "foundstone" )
ALT_NAME( ({ "found", "stone" }) )
PHRASE( "a foundstone" )
SPECIFIC( "the foundstone" )

/// Makes it possible to build with a construction site.
int query_is_building() { return 1; }

mapping query_shape() {
   return SHAPE_BOX(5,3);
}

void on_map_paint( object painter ) {
//   __ __
//   || ||
//  _||_||_
// |)||=||(|
// |\'' ''/|
// |_\___/_|
// |_______|
//   painter->paint_shape( query_x()+2, query_y()-2, "__\t__", 0x8E, LAYER_TERRAIN );
//   painter->paint_shape( query_x()+2, query_y()-1, "|\t\t|\n|\t\t|", 0x6F, LAYER_OVERLAY );
//   painter->paint_shape( query_x()+2, query_y()+1, "|\t\t|\n''\t''", 0x6F, LAYER_WALL );
//   painter->paint_shape( query_x()+3, query_y()-1, "|\t\t|\n|\t\t|", 0x6C, LAYER_OVERLAY );
//   painter->paint_shape( query_x()+3, query_y()+1, "|\t\t|\n'\t\t'", 0x6C, LAYER_WALL );
//   painter->paint( query_x()+4, query_y()+1, '=', 0x0f, LAYER_WALL );
//   painter->paint_shape( query_x()+1, query_y(), "_\t\t_\t\t_", 0x80, LAYER_TERRAIN );
//   painter->paint_shape( query_x(), query_y()+1, "|\n|\n|_\n|_______|", 0x70, LAYER_WALL );
//   painter->paint_shape( query_x()+7, query_y()+1, "\t|\n\t|\n_|", 0x70, LAYER_WALL );
//   painter->paint_shape( query_x()+1, query_y()+1, ")\t\t\t\t\t(\n\\\t\t \t\t/\n\t\\___/", 0x7B, LAYER_TERRAIN );
   painter->paint_shape( query_x(), query_y(), " ___.", 0x87, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "/__/|", 0x07, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "|\t\t|/", 0x07, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+2, "[]", 0x0B, LAYER_WALL );
}

string query_city_name() {
   return city_name;
}

/// Returns an array of all the buildings in the room
object* buildings() {
   object *ret;

   ret = filter(all_inventory(environment(this_object())), (: ($1->query_is_building() && $1 != this_object()) && !$1->query_is_wall() :));

   return ret;
}

/// Returns an array of all the building owners in the room
string* owners() {
   mapping ret=([ ]);
   object ob;

   foreach( ob : buildings() )
      ret[ob->query_owner()] = 1;

   return m_indices(ret);
}

string* query_voters(int match) {
   // always have to check for new or missing buildings
   string *current_owners;
   string owner;

   current_owners = owners();

   // first, add anyone that's not in yet
   foreach( owner : current_owners )
      if (!member(voters, owner))
         voters[owner] = NO_VOTE;

  // then, remove anyone who doesn't still have a building
  foreach( owner : m_indices(voters) )
      if (member(current_owners, owner) == -1)
         voters -= ([ owner ]);

   // and return all that match the criterea
   return filter( m_indices(voters), (: stringp($1) && voters[$1] == match :) );
}

string query_look() {
   string str;

   str = "This is a large, elegant monument, built to commemorate the ";
   if (CITYD->query_city_type(city_name) == UNBUILT)
      str += "possible future ";
   str += "founding of ";
   switch( CITYD->query_city_type(city_name) ) {
   default:
      str += "the settlement ";
      break;
   case VILLAGE:
      str += "the village ";
      break;
   case TOWN:
      str += "the town ";
      break;
   case CITY:
      str += "the city ";
      break;
   }
   str += "of ~CBRT" + capitalize(city_name) + "~CDEF.";

   if (CITYD->query_city_type(city_name)== UNBUILT) {
      str += "\n\n";
      str += "To be founded:";
      if (sizeof(query_voters(VOTE_AYE)) + sizeof(query_voters(VOTE_NAY))) {
         str += "\n" + cap_comma_list(sort_array(query_voters(VOTE_AYE) + query_voters(VOTE_NAY), #'>)) + " has/have already voted on the founding.";
      }
	  if (sizeof(query_voters(NO_VOTE))) {
         str += "\n" + cap_comma_list(query_voters(NO_VOTE)) + " need(s) to ~CCOMvote~CDEF on the founding.";
      }
      if (sizeof(buildings()) < 5)
         str += "\n" + (5 - sizeof(buildings())) + " more building(s) need to be built.";
      }

   return str;
}

int on_raze() {
   this_player()->msg_local( "~CACT~Name ~verbtear up ~targ.~CDEF" );
   CITYD->remove_city( city_name );
   destruct(this_object());
   return 1;
}

string destructor( object ob ) {
   CITYD->remove_city( city_name );
   return ::destructor( ob );
}

int on_vote( string arg ) {
   if( !arg ) arg = "";
   arg = trim(arg);

   if (member(query_voters(NO_VOTE), this_player()->query_name()) == -1) {
      notify_fail("You can't vote on founding unless you own a building here.\n");
      return 0;
   }

   if (arg != "aye" && arg != "nay") {
      notify_fail("You can vote 'aye' for founding, or 'nay' against founding.\n");
      return 0;
   }

   // this is the only code that's allowed to directly access voters
   // and it has to call query_voters() before here
   if (arg == "aye")
      voters[this_player()->query_name()] = VOTE_AYE;
   if (arg == "nay")
      voters[this_player()->query_name()] = VOTE_NAY;
   this_player()->msg_local( "~CACT~Name ~verbvote.~CDEF" );

   if (sizeof(query_voters(NO_VOTE))) {
      msg( (sizeof(query_voters(NO_VOTE)) ) + " vote(s) left to be made." );
      return 1;
   }

   if (sizeof(query_voters(VOTE_NAY))) {
      this_player()->msg_local( "The vote for founding ~CBRT" + capitalize(city_name) + "~CDEF was not unanimously in favor." );
      this_player()->msg_local( "~CACTWith a solid ~CBRTcrack~CACT the foundstone splits, then crumbles to dust.~CDEF" );
      destruct(this_object());
   } else if (sizeof(buildings()) >= 5) {
      CITYD->set_city_type(city_name, SETTLEMENT);
      this_player()->msg_local( "~CACTThe vote passes, and ~CBRT" + capitalize(city_name) + "~CACT is founded.~CDEF" );
      string pname;
      foreach( pname : voters )
         CITYD->add_citizen( city_name, pname );
      remove_action("vote");
   }

   return 1;
}

void get_city_name( string line ) {
   line = lower_case( trim( line ) );
   if( "" == line ) {
   } else if (CITYD->city_exists( line )) {
      msg("That name is taken, please give a new one:");
   } else {
      msg("Set.");
      city_name = line;
      CITYD->add_city(city_name, this_player()->query_name());
      CITYD->add_room(city_name, get_location(environment(environment(this_object()))));
      CITYD->set_city_type(city_name, UNBUILT);
      drop_interface();
   }
}

void on_craft() {
   add_interface( "get_city_name", "[Enter name of settlement] " );
}

void init() {
   ::init();

   add_action("on_vote", "vote");
}

