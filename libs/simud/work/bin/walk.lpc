#include <const.h>

string query_action_name( mixed * action ) {
   return "Walk";
}

int parse_path( string path ) {
   int i, j, x, y, dx, dy, rep;

   x = this_player()->query_x();
   y = this_player()->query_y();
  rep = 0;
   for( i = 0; i < strlen(path); i++ ) {
      switch( path[i] ) {
      case 'n':
      case 'N':
        if (rep == 0) { rep = 1; }
         dx = 0; dy = -1;
         break;
      case 'w':
      case 'W':
        if (rep == 0) { rep = 1; }
         dx = -1; dy = 0;
         break;
      case 's':
      case 'S':
        if (rep == 0) { rep = 1; }
         dx = 0; dy = 1;
         break;
      case 'e':
      case 'E':
        if (rep == 0) { rep = 1; }
         dx = 1; dy = 0;
         break;
      case '0'..'9':
         rep *= 10;
         rep += path[i] - '0';
      default:
         dx = dy = 0;
         break;
      }

      for( j = 0; j < rep; j++ ) {
         x += dx;
         y += dy;
         if( !environment(this_player())->query_valid_square(x, y) ) {
            x -= dx; y -= dy;
            return MAKE_C( x, y, 1 );
         }
      }
      if( dx || dy )
         rep = 0;
   }
   return MAKE_C( x, y, 0 );
}

int random_position() {
   int x = this_player()->query_x();
   int y = this_player()->query_y();
   int dx = random(5)-2;
   int dy = random(5)-2;
   return MAKE_C( x+dx, y+dy, 0 );
}

string path_dir( int xold, int yold, int xnew, int ynew ) {
   string ret;

   ret = "";
   if( ynew < yold ) ret += "north";
   if( ynew > yold ) ret += "south";
   if( xnew < xold ) ret += "west";
   if( xnew > xold ) ret += "east";
   if( ret == "" ) return 0;
   return ret;
}

int main( string param ) {
   string dest;
   int new_pos;

   if( !stringp(param) ) {
      notify_fail("Ok, you walk nowhere. Poetically, you end up where you started.\n");
      return 0;
   }


   if ( param == "north" || param == "south" || param == "east" || param == "west" ) {
      notify_fail("The walk comand is more involved than that, please read 'help walk'.\n");
      return 0;
   }

   if( sscanf(param, "to %s", dest) ) {
      object *obs;
      mapping shape;

      if( !(obs = all_present(dest, environment(this_player()))) ) {
         notify_fail("I don't know what you mean by '"+dest+"'.\n");
         return 0;
      }
      if( sizeof(obs) > 1 ) {
         notify_fail("Trying to walk to more than one thing confuses me. Pick just one (use first, second, etc).\n");
         return 0;
      }
      set_target(obs[0]);
      this_player()->set_pronoun( obs[0] );
      if( shape = obs[0]->query_border() )
         WALK_DAEMON->init_walk_action(
            shape, obs[0]->query_coord(),
            ({ 0, this_object(), obs[0], ST_STANDING, 0 })
         );
      else
         WALK_DAEMON->init_walk_action(
            WALK_DAEMON->shape_adjacent(),
            obs[0]->query_coord(),
            ({ 0, this_object(), obs[0], ST_STANDING, 0 })
         );
      return 1;
   }
   if( param == "random" )
      new_pos = random_position();
   else
      new_pos = parse_path( param );
   dest = path_dir( this_player()->query_x(), this_player()->query_y(), CX(new_pos), CY(new_pos) );
   if( !dest ) {
      notify_fail("All right, you go nowhere. Then you come back.\n");
      return 0;
   }
   if( CZ(new_pos) ) {
      msg("You can only go partway on that path.");
      new_pos -= MAKE_C(0,0,1);
   }
      WALK_DAEMON->init_walk_action(
         WALK_DAEMON->shape_point(),
         new_pos,
         ({ 0, this_object(), this_object(), ST_STANDING, dest })
      );
   return 1;
}

void on_action( object target, string dest ) {
   if( target == this_object() ) {
      this_player()->msg_local( "~CACT~Name ~verbwalk "+dest+".~CDEF" );
   }
   else {
      set_target( target );
      this_player()->msg_local( "~CACT~Name ~verbwalk to ~targ.~CDEF" );
   }
}
