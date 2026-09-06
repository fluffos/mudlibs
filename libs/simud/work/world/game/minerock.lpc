#include <desc.h>
#include <scenedesc.h>
#include <object.h>
#include <shape.h>
#include <spots.h>
#include <coord.h>
#include <saveload.h>
#include <tiledmap.h>
#include <dice.h>

string *mineral;
int start_pos, end_pos;

NAME( "rock" )
DISTANT( "a wall of rock" )
SPECIFIC( "the wall of rock" )
ALT_NAME( ({ "wall of rock", "Minerock" }) )
LOOK( "The walls of the tunnel are made of rock. If you have a pick, you can dig into it." )
PHRASE( sizeof(query_spots())? "The walls show signs of digging." : 0 )

void init() {
   ::init();
   if( environment() && environment(environment()) )
      environment(environment())->reset_idle_time();
}

void set_mineral( mixed x ) {
   if( stringp(x) ) {
      debug("set_mineral(string) is deprecated, please pass an array next time.");
      mineral = ({ x });
   } else if( pointerp(x) ) {
      mineral = x;
   }
}

string query_mineral() {
   int roll, size;
   if( !pointerp(mineral) )
      mineral = ({ mineral });
   size = sizeof(mineral);
   roll = random(size);
   return mineral[roll];
}

string *query_minerals() {
   if (!pointerp(mineral)) {
      mineral = ({ mineral });
   }
   return mineral;
}

int query_start_pos() {
   return start_pos + query_coord();
}

int query_end_pos() {
   return end_pos + query_coord();
}

#define DRYROCK 0
#define DAMPROCK 1
#define WETROCK 2
//#define WATER 3
#define MINERALS 4
#define STARTPOS 5
#define ENDPOS 6
#define NEIGHBOR_BASE 9

void add_water_spot( int pos ) {
   int *adj = ({
      SMAKE_C(-1,0,0),
      SMAKE_C(0,-1,0),
      SMAKE_C(1,0,0),
      SMAKE_C(0,1,0),
   });

   int idelta;

   // Wet rock (i.e. death); was WATER
   set_cell_index( CX(pos), CY(pos), 0, WETROCK );

   // Damp rock (i.e. warning); was WETROCK
   foreach( idelta: adj ) {
      int wetpos = OFFSET_C(pos, idelta);
      if( query_cell_index(CX(wetpos), CY(wetpos), 0) != WETROCK )
         set_cell_index( CX(wetpos), CY(wetpos), 0, DAMPROCK );
   }
}

// Currently only supports square game boards.
void make_level( int num_spots, int xdim, int ydim ) {
   int irock, ix, iy;

   if( xdim < 5 || ydim < 3 )
      raise_error( "Mine boards must be at least 5x3" );
   if( num_spots + 25 >= xdim * ydim )
      raise_error( "Too many spots on this board!" );
   // Make the grid.
   resize_grid( xdim, ydim, 1 );
   // Grid values      0       1            2           3        4           5     6       7       8        9            10           11           12           13           14           15
   set_grid_values( ({ "rock", "damp rock", "wet rock", "water", "minerals", "up", "down", "mark", "blank", "1neighbor", "2neighbor", "3neighbor", "4neighbor", "5neighbor", "6neighbor", "7neighbor" }) );
   // Fill grid with rock
   for( iy = 0; iy < ydim; iy++ )
   for( ix = 0; ix < xdim; ix++ ) {
      set_cell_index( ix, iy, 0, DRYROCK );
      add_spot( MAKE_C(ix, iy, 0) );
   }
   // Add entrance and exit.
   start_pos = end_pos = 0;
   // I am pretty sure this will eventually terminate ;-).
   // If not, congratulations. You found the one in a zillion chance.
   // Tell your grandkids about it.
   while( abs(CX(start_pos) - CX(end_pos)) + abs(CY(start_pos) - CY(end_pos)) < query_xdim() ) {
      start_pos = MAKE_C(random(query_xdim()), random(query_ydim()), 0);
      end_pos = MAKE_C(random(query_xdim()), random(query_ydim()), 0);
   }
   set_cell_index( CX(end_pos), CY(end_pos), 0, ENDPOS );
   for( ix = -1; ix <= 1; ix++ )
   for( iy = -1; iy <= 1; iy++ ) {
      set_cell_index( CX(start_pos) + ix, CY(start_pos) + iy, 0, STARTPOS );
      remove_spot( OFFSET_C(start_pos, SMAKE_C(ix,iy,0)) );
   }

   // Add water and wet spots
   // Some bias for clumping here.
   int rx, ry;
   rx = random(query_xdim());
   ry = random(query_ydim());
   for( irock = 0; irock < num_spots; irock++ ) {

      if( random(4) == 0 ) {
         rx = random( query_xdim() );
         ry = random( query_ydim() );
      }
      else {
         while( query_cell_index(rx, ry, 0) == WETROCK ) {
            if( random(2) )
               rx += random(2) * 2 - 1;
            else
               ry += random(2) * 2 - 1;
         }
      }
      if( abs(rx - CX(start_pos)) + abs(ry - CY(start_pos)) <= 4 ) {
         irock--;
         continue;
      }
      if( abs(rx - CX(end_pos)) + abs(ry - CY(end_pos)) <= 2 ) {
         irock--;
         continue;
      }
      add_water_spot( MAKE_C(rx, ry, 0) );
   }

   int mineral_total = 0;

   // Add minerals
   for( irock = 0; irock < xdim * ydim; irock++ ) {
      rx = random( query_xdim() );
      ry = random( query_ydim() );
      if( query_cell_index(rx,ry,0) != DRYROCK ) continue; // Minerals only in dry places for now.
      set_cell_index( rx, ry, 0, 4 );
      mineral_total++;
      if( mineral_total >= 10 ) break;
   }

   // Offset from room border
   set_x(1);
   set_y(1);
}

void on_map_paint( object painter ) {
   int ix, iy;
   int offx = query_x(), offy = query_y();
   mapping spots = query_spots();

   for( iy = query_ydim(); iy--; )
   for( ix = query_xdim(); ix--; ) {
      if( !query_has_spot(MAKE_C(ix,iy,0)) )
         int cidx = query_cell_index(ix, iy, 0);
         switch( cidx ) {
         // Dug
         case 10 .. 17:
            painter->paint( ix + offx, iy + offy, '0' + (cidx - 10), 0x0C, LAYER_ROUGH ); break;
         }
      else {
         // Undug
         painter->paint( ix + offx, iy + offy, '#', 0x03, LAYER_WALL );
      }
   }
}

// for wizardly use
void cheat() {
   int i, ix, iy;
   int offx = query_x(), offy = query_y();
   mapping spots = query_spots();
   string ret = "";

   for( iy = query_ydim(); iy--; ) {
      for( ix = query_xdim(); ix--; ) {
         ret += " ";
      }
      ret += "\n";
   }

   for( iy = query_ydim(); iy--; )
   for( ix = query_xdim(); ix--; ) {
         switch( query_cell_index(ix, iy, 0) ) {
            case  5: // stairs up
            case  0: ret[ix + iy * query_xdim() + iy] = ' '; break; // empty floor
            case  6: ret[ix + iy * query_xdim() + iy] = '>'; break; // stairs down
            case  4: ret[ix + iy * query_xdim() + iy] = '+'; break; // minerals

         case  1:
         case 10 .. 17: ret[ix + iy * query_xdim() + iy] = '.'; break;
            default: ret[ix + iy * query_xdim() + iy] = '#';
         }
   }

   ix = this_player()->query_x() - 1;
   iy = this_player()->query_y() - 1;
   ret[ix + iy * query_xdim() + iy] = '@';

   msg(ret);
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   return ::destructor(ob);
}

int query_is_diggable() {
   return 1;
}

string query_action_name() {
   return "Dig";
}

void do_flood( object room );

/// Dig in the direction given in \a param, offsetting the player.
int on_dig( int param ) {
   string *res, mineral;
   int i, pos, adjpos;
   object *picks;

   if( !param ) return 0; // Doesn't apply

   picks = filter(all_inventory(this_player()), (: ($1->query_held() && HAS_ASPECT($1, C_PICKAXE)) :));

   if ( !sizeof( picks )) {
      msg("You need to be holding a pickaxe.");
      return 0;
   }

   pos = OFFSET_C(this_player()->query_coord(), param);
   adjpos = OFFSET_C( pos, SINVERT_C(SMAKE_C(query_x(), query_y(), 0)) );

   // Hmm ... this'll break horribly if there are multiple
   // diggable things in the room, but I can't think of
   // a good solution right now, since validity checking has
   // to be procrastinated.
   if( !query_has_spot(adjpos) ) {
      if( !member(FLOOR_CHARS, environment(this_player())->query_zbuf_pos(pos)) ) {
         msg("It's impossible to dig that way.");
         return 1;
      }
      this_player()->set_coord(pos);
      this_player()->msg_local("~CACT~Name ~verbtake a step " +
         ([ SMAKE_C(-1,0,0):"west",
         SMAKE_C(0,-1,0):"north",
         SMAKE_C(1,0,0):"east",
         SMAKE_C(0,1,0):"south" ])[param] + ".~CDEF" );
      this_player()->add_readiness( -100 );
      return 1;
   }

   // 1 in 20 random chance of bonkage
   if ( random(20) == 13 && query_cell_index(CX(adjpos),CY(adjpos),0) == DRYROCK ) {
      object rock;
      rock = clone_object( "/econ/raw/stone" );
      set_target( rock );
      rock->move(environment(this_player()));
      rock->set_coord(pos);
      AUDIO_DAEMON->sfx_room( environment(this_player()), "debris.wav" );
      this_player()->msg_local("~CACT~Atar ~vertfall from the ceiling and bonks ~name on the head!~CDEF");
      this_player()->set_env_var("cause_of_death","got thumped in the head by a falling rock.");
      this_player()->take_damage( (["blunt": 3]), BP_HEAD );
   }

   // Check effect of digging.
   int iwet = 0;
   switch( query_cell_index(CX(adjpos), CY(adjpos), 0) ) {
      case DRYROCK:
         AUDIO_DAEMON->sfx_room( environment(this_player()), "dig.wav" );
         break; // Just rock
      case DAMPROCK: // Get wet neighbor count.
         AUDIO_DAEMON->sfx_room( environment(this_player()), "dig.wav" );
         if( query_cell_index(CX(adjpos)-1, CY(adjpos), 0) == WETROCK ) iwet++;
         if( query_cell_index(CX(adjpos)+1, CY(adjpos), 0) == WETROCK ) iwet++;
         if( query_cell_index(CX(adjpos), CY(adjpos)-1, 0) == WETROCK ) iwet++;
         if( query_cell_index(CX(adjpos), CY(adjpos)+1, 0) == WETROCK ) iwet++;
         if( iwet == 0 )
            set_cell_index(CX(adjpos), CY(adjpos), 0, DRYROCK);
         if( iwet == 8 ) raise_error("iwet==8?"); // Shouldn't be possible to reach?
         set_cell_index(CX(adjpos), CY(adjpos), 0, NEIGHBOR_BASE + iwet);
         break;
      case MINERALS:
         // Give 'em a bunch of this mine's mineral type.
         object stuff;
         AUDIO_DAEMON->sfx_room( environment(this_player()), "dug_something.wav" );
         mineral = query_mineral();
         if( !mineral ) set_mineral( mineral = "/econ/raw/stone" );
         stuff = clone_object(mineral);
         // TODO: modify this for skill
         stuff->set_quantity( roll(3, 6) );
         set_target( stuff );
         stuff->move(environment(this_player()));
         stuff->set_coord(pos);
         this_player()->msg_local("~CACT~Name ~verbfind ~targ!~CDEF");
         // chance of gems
         if( random(200)-1 < 2*this_player()->query_skill("knowledge.science.geology") ) {
            string gemname = "/daemon/gemstone"->query_gem_name(stuff->query_name());
            if( gemname ) {
               stuff = clone_object( "/econ/gem/"+gemname );
               // TODO: chance of getting more than one in terribly rich veins
               stuff->move(environment(this_player()));
               stuff->set_coord(pos);
               set_target(stuff);
               msg("~CTITYou also found ~targ!~CDEF");
            }
         }
         break;
      case WETROCK:
         if (!single_present("mine_flood", environment())) {
            AUDIO_DAEMON->sfx_room( environment(this_player()), "drain.wav" );
            this_player()->msg_local("~CACTAs ~name ~verbstrike the rock ~CWRNwater starts pouring into the passageway~CACT. Get out fast!~CDEF");
            do_flood(environment());
         }
         return 1;
      case ENDPOS:
         if( present("exit_down", environment(this_object())) )
            msg("The seam goes deeper into the ground here.");
         break;
   }

   // damage axe one point
   picks[0]->add_condition(-1);
   // practice skill
   this_player()->practice_skill("craft.mining");

   this_player()->set_coord(pos);
   this_object()->remove_spot(adjpos);
   environment(this_player())->clear_map();
   this_player()->msg_local("~CACT~Name ~verbdig " +
      ([ SMAKE_C(-1,0,0):"west",
      SMAKE_C(0,-1,0):"north",
      SMAKE_C(1,0,0):"east",
      SMAKE_C(0,1,0):"south" ])[param] + " into the rock.~CDEF" );
   this_player()->add_readiness( -325 + 50 * this_player()->skill_check("combat.weapon.axe", 15, 25) );

   switch( iwet ) {
      case 1: msg("The rock here is ~[120DAMP~CDEF (1)."); break;
      case 2: msg("The rock here is ~[120WET~CDEF (2)."); break;
      case 3: msg("The rock here is ~[120DRIPPING~CDEF (3)."); break;
      case 4: msg("The rock here is ~[120TRICKLING~CDEF (4)."); break;
      case 5: msg("The rock here is ~[120LEAKING~CDEF (5)."); break;
      case 6: msg("The rock here is ~[120LEAKING BADLY~CDEF (6)."); break;
      case 7: msg("The rock here is ~[120POOLING~CDEF (7)."); break;
   }

   if (sizeof(query_spots()) <= 0)
      destruct(this_object());

   return 1;
}

mapping query_hotspots() {
   int my_x = query_x(), my_y = query_y();

   return mkmapping( map(m_indices(query_spots()), (: SMAKE_C(CX($1)+$2,CY($1)+$3,CZ($1)) :), my_x, my_y) );
}

void on_hotspot( int pos ) {
   int player = this_player()->query_coord();
   this_object()->on_dig( SMAKE_C(SCX(pos)-CX(player),
      SCY(pos)-CY(player), SCZ(pos)-CZ(player)) );
   object ob;
   foreach( ob : all_inventory(environment()) )
      ob->update_client_map();
}

void do_flood(object room) {
   object ob;
   object flood;

   if (!room) {
      room = environment();
   }

   flood = clone_object("/world/game/mineflood");
   flood->move( room );
   flood->start_flood();

   foreach( ob : all_inventory(room) ) {
      if( ob->query_is_exit() && ob->query_dir() == "down" ) {
         do_flood( ob->get_destination() );
      }
   }
}
